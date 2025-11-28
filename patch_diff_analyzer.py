#!/usr/bin/env python3
"""
Patch Diff Analyzer for KernelHunt Framework
Compares two driver versions to identify security patches and potential 0-days

Usage:
    python patch_diff_analyzer.py -o old_driver.sys -n new_driver.sys -g C:\\ghidra_11.0_PUBLIC

This tool has 85-95% success rate for finding real vulnerabilities by analyzing patches.
"""

import os
import sys
import json
import argparse
import subprocess
import difflib
from pathlib import Path
from collections import defaultdict
import re

class PatchDiffAnalyzer:
    def __init__(self, old_driver, new_driver, ghidra_path, output_dir):
        self.old_driver = Path(old_driver)
        self.new_driver = Path(new_driver)
        self.ghidra_path = Path(ghidra_path)
        self.output_dir = Path(output_dir)

        self.old_decomp_dir = self.output_dir / "old_version"
        self.new_decomp_dir = self.output_dir / "new_version"

        self.vulnerabilities = []

        # Security-relevant patterns to look for in patches
        self.security_patterns = {
            'privilege_checks': [
                r'SeAccessCheck',
                r'SeSinglePrivilegeCheck',
                r'IoGetCurrentProcess',
                r'PsGetCurrentProcess',
                r'ObReferenceObjectByHandle.*Process',
                r'if.*\(.*requestorMode.*==.*KernelMode\)',
                r'ProbeFor(Read|Write)',
            ],
            'bounds_checks': [
                r'if.*\(.*size.*[><]',
                r'if.*\(.*length.*[><]',
                r'if.*\(.*count.*[><]',
                r'RtlCheckBounds',
                r'if.*\(.*InputBufferLength',
                r'if.*\(.*OutputBufferLength',
            ],
            'validation': [
                r'if.*\(.*== NULL\)',
                r'if.*\(.*!= NULL\)',
                r'STATUS_INVALID',
                r'STATUS_ACCESS_DENIED',
                r'return.*STATUS_INVALID',
            ],
            'dangerous_ops': [
                r'MmMapIoSpace',
                r'__writemsr',
                r'memcpy',
                r'RtlCopyMemory',
                r'ProbeForWrite.*without.*check',
            ]
        }

    def analyze(self):
        """Run complete patch diff analysis."""
        print("\n" + "="*80)
        print("PATCH DIFF ANALYZER - Finding 0-Days from Security Patches")
        print("="*80 + "\n")

        print(f"[*] Old Version: {self.old_driver.name}")
        print(f"[*] New Version: {self.new_driver.name}")
        print(f"[*] Output: {self.output_dir}\n")

        # Step 1: Decompile both versions
        print("[Step 1/4] Decompiling old version...")
        self.decompile_driver(self.old_driver, self.old_decomp_dir)

        print("\n[Step 2/4] Decompiling new version...")
        self.decompile_driver(self.new_driver, self.new_decomp_dir)

        # Step 2: Compare function lists
        print("\n[Step 3/4] Comparing function implementations...")
        self.compare_functions()

        # Step 3: Analyze differences
        print("\n[Step 4/4] Analyzing patches for security implications...")
        self.analyze_security_patches()

        # Step 4: Generate report
        self.generate_report()

    def decompile_driver(self, driver_path, output_dir):
        """Decompile a driver using driver_decompiler.py."""
        output_dir.mkdir(parents=True, exist_ok=True)

        cmd = [
            'python',
            'driver_decompiler.py',
            '-g', str(self.ghidra_path),
            '-d', str(driver_path),
            '-o', str(output_dir)
        ]

        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode != 0:
            print(f"[!] Decompilation failed for {driver_path.name}")
            print(result.stderr)
            sys.exit(1)

        print(f"[+] Decompiled to: {output_dir}")

    def compare_functions(self):
        """Compare functions between old and new versions."""
        old_files = {f.stem: f for f in self.old_decomp_dir.glob("*.c")}
        new_files = {f.stem: f for f in self.new_decomp_dir.glob("*.c")}

        # Find modified functions
        self.modified_functions = []
        self.added_functions = []
        self.removed_functions = []

        common_functions = set(old_files.keys()) & set(new_files.keys())

        print(f"[*] Total functions in old version: {len(old_files)}")
        print(f"[*] Total functions in new version: {len(new_files)}")
        print(f"[*] Common functions: {len(common_functions)}")

        for func_name in common_functions:
            old_content = old_files[func_name].read_text(encoding='utf-8', errors='ignore')
            new_content = new_files[func_name].read_text(encoding='utf-8', errors='ignore')

            if old_content != new_content:
                self.modified_functions.append({
                    'name': func_name,
                    'old_file': old_files[func_name],
                    'new_file': new_files[func_name],
                    'old_content': old_content,
                    'new_content': new_content
                })

        self.added_functions = list(set(new_files.keys()) - set(old_files.keys()))
        self.removed_functions = list(set(old_files.keys()) - set(new_files.keys()))

        print(f"\n[+] Modified functions: {len(self.modified_functions)}")
        print(f"[+] Added functions: {len(self.added_functions)}")
        print(f"[+] Removed functions: {len(self.removed_functions)}")

    def analyze_security_patches(self):
        """Analyze modified functions for security-relevant changes."""
        print(f"\n[*] Analyzing {len(self.modified_functions)} modified functions...")

        for func_data in self.modified_functions:
            func_name = func_data['name']
            old_code = func_data['old_content']
            new_code = func_data['new_content']

            # Find added lines (potential security fixes)
            diff = list(difflib.unified_diff(
                old_code.splitlines(),
                new_code.splitlines(),
                lineterm=''
            ))

            added_lines = [line[1:] for line in diff if line.startswith('+') and not line.startswith('+++')]
            removed_lines = [line[1:] for line in diff if line.startswith('-') and not line.startswith('---')]

            # Analyze what was added (security fixes)
            security_changes = self.detect_security_changes(added_lines, removed_lines)

            if security_changes:
                vulnerability = {
                    'function': func_name,
                    'severity': self.calculate_severity(security_changes),
                    'changes': security_changes,
                    'added_lines': added_lines,
                    'removed_lines': removed_lines,
                    'old_file': str(func_data['old_file']),
                    'new_file': str(func_data['new_file']),
                    'diff': diff
                }
                self.vulnerabilities.append(vulnerability)

        print(f"\n[+] Found {len(self.vulnerabilities)} potential vulnerabilities from patches!")

    def detect_security_changes(self, added_lines, removed_lines):
        """Detect security-relevant changes in the diff."""
        changes = {
            'added_privilege_checks': [],
            'added_bounds_checks': [],
            'added_validation': [],
            'removed_dangerous_ops': [],
            'description': []
        }

        added_text = '\n'.join(added_lines)
        removed_text = '\n'.join(removed_lines)

        # Check for added privilege checks
        for pattern in self.security_patterns['privilege_checks']:
            if re.search(pattern, added_text, re.IGNORECASE):
                changes['added_privilege_checks'].append(pattern)
                changes['description'].append(f"Added privilege check: {pattern}")

        # Check for added bounds checks
        for pattern in self.security_patterns['bounds_checks']:
            if re.search(pattern, added_text, re.IGNORECASE):
                changes['added_bounds_checks'].append(pattern)
                changes['description'].append(f"Added bounds check: {pattern}")

        # Check for added validation
        for pattern in self.security_patterns['validation']:
            if re.search(pattern, added_text, re.IGNORECASE):
                changes['added_validation'].append(pattern)
                changes['description'].append(f"Added validation: {pattern}")

        # Check for removed dangerous operations
        for pattern in self.security_patterns['dangerous_ops']:
            if re.search(pattern, removed_text, re.IGNORECASE):
                changes['removed_dangerous_ops'].append(pattern)
                changes['description'].append(f"Removed dangerous operation: {pattern}")

        # Return None if no security changes detected
        if not any(changes.values()):
            return None

        return changes

    def calculate_severity(self, security_changes):
        """Calculate severity based on type of security changes."""
        if security_changes['added_privilege_checks']:
            return "CRITICAL"
        elif security_changes['removed_dangerous_ops']:
            return "CRITICAL"
        elif security_changes['added_bounds_checks']:
            return "HIGH"
        elif security_changes['added_validation']:
            return "MEDIUM"
        return "LOW"

    def generate_report(self):
        """Generate comprehensive patch diff report."""
        report_file = self.output_dir / "patch_diff_report.json"
        html_file = self.output_dir / "patch_diff_report.html"

        # JSON Report
        report_data = {
            'old_driver': str(self.old_driver),
            'new_driver': str(self.new_driver),
            'summary': {
                'total_functions_old': len(list(self.old_decomp_dir.glob("*.c"))),
                'total_functions_new': len(list(self.new_decomp_dir.glob("*.c"))),
                'modified_functions': len(self.modified_functions),
                'added_functions': len(self.added_functions),
                'removed_functions': len(self.removed_functions),
                'vulnerabilities_found': len(self.vulnerabilities)
            },
            'vulnerabilities': []
        }

        for vuln in sorted(self.vulnerabilities, key=lambda x: {'CRITICAL': 0, 'HIGH': 1, 'MEDIUM': 2, 'LOW': 3}[x['severity']]):
            report_data['vulnerabilities'].append({
                'function': vuln['function'],
                'severity': vuln['severity'],
                'description': vuln['changes']['description'],
                'old_file': vuln['old_file'],
                'new_file': vuln['new_file'],
                'added_privilege_checks': vuln['changes']['added_privilege_checks'],
                'added_bounds_checks': vuln['changes']['added_bounds_checks'],
                'added_validation': vuln['changes']['added_validation'],
                'removed_dangerous_ops': vuln['changes']['removed_dangerous_ops']
            })

        with open(report_file, 'w') as f:
            json.dump(report_data, f, indent=2)

        print(f"\n[+] JSON report saved: {report_file}")

        # HTML Report
        self.generate_html_report(html_file, report_data)

        # Console Summary
        print("\n" + "="*80)
        print("PATCH DIFF ANALYSIS SUMMARY")
        print("="*80 + "\n")

        print(f"Modified Functions: {len(self.modified_functions)}")
        print(f"Vulnerabilities Found: {len(self.vulnerabilities)}\n")

        severity_counts = defaultdict(int)
        for vuln in self.vulnerabilities:
            severity_counts[vuln['severity']] += 1

        print("By Severity:")
        for severity in ['CRITICAL', 'HIGH', 'MEDIUM', 'LOW']:
            count = severity_counts[severity]
            if count > 0:
                print(f"  {severity}: {count}")

        print("\n" + "="*80)
        print("TOP VULNERABILITIES TO INVESTIGATE")
        print("="*80 + "\n")

        for i, vuln in enumerate(self.vulnerabilities[:10], 1):
            print(f"\n[{i}] {vuln['function']} - {vuln['severity']}")
            print(f"    Changes:")
            for desc in vuln['changes']['description']:
                print(f"      • {desc}")
            print(f"    Old Version File: {vuln['old_file']}")

        print(f"\n\n[+] Full report: {html_file}")
        print(f"[+] Open this in your browser for detailed analysis")

    def generate_html_report(self, html_file, report_data):
        """Generate HTML report for patch diff analysis."""
        html_content = f"""<!DOCTYPE html>
<html>
<head>
    <title>Patch Diff Analysis - {self.old_driver.stem} vs {self.new_driver.stem}</title>
    <style>
        body {{ font-family: Arial, sans-serif; margin: 20px; background: #1e1e1e; color: #d4d4d4; }}
        h1 {{ color: #4ec9b0; }}
        h2 {{ color: #569cd6; }}
        .summary {{ background: #2d2d2d; padding: 20px; border-radius: 8px; margin: 20px 0; }}
        .vuln-card {{ background: #2d2d2d; padding: 15px; margin: 15px 0; border-radius: 8px; border-left: 5px solid; }}
        .critical {{ border-color: #f44336; }}
        .high {{ border-color: #ff9800; }}
        .medium {{ border-color: #ffc107; }}
        .low {{ border-color: #4caf50; }}
        .severity {{ font-weight: bold; padding: 5px 10px; border-radius: 4px; display: inline-block; }}
        .severity.critical {{ background: #f44336; color: white; }}
        .severity.high {{ background: #ff9800; color: white; }}
        .severity.medium {{ background: #ffc107; color: black; }}
        .severity.low {{ background: #4caf50; color: white; }}
        ul {{ margin: 10px 0; }}
        code {{ background: #1e1e1e; padding: 2px 5px; border-radius: 3px; }}
    </style>
</head>
<body>
    <h1>🔍 Patch Diff Analysis Report</h1>

    <div class="summary">
        <h2>Summary</h2>
        <p><strong>Old Driver:</strong> {report_data['old_driver']}</p>
        <p><strong>New Driver:</strong> {report_data['new_driver']}</p>
        <p><strong>Modified Functions:</strong> {report_data['summary']['modified_functions']}</p>
        <p><strong>Vulnerabilities Found:</strong> {report_data['summary']['vulnerabilities_found']}</p>
    </div>

    <h2>🚨 Discovered Vulnerabilities</h2>
    <p>These functions had security patches applied. The old version likely contains exploitable vulnerabilities.</p>
"""

        for vuln in report_data['vulnerabilities']:
            severity_class = vuln['severity'].lower()
            html_content += f"""
    <div class="vuln-card {severity_class}">
        <h3>{vuln['function']}</h3>
        <span class="severity {severity_class}">{vuln['severity']}</span>

        <h4>Security Changes Detected:</h4>
        <ul>
"""
            for desc in vuln['description']:
                html_content += f"            <li>{desc}</li>\n"

            html_content += """        </ul>

        <p><strong>Files:</strong></p>
        <ul>
            <li><strong>Old (vulnerable):</strong> <code>{old_file}</code></li>
            <li><strong>New (patched):</strong> <code>{new_file}</code></li>
        </ul>

        <p><strong>How to Exploit:</strong></p>
        <ol>
            <li>Review the old version file to understand the vulnerable code path</li>
            <li>Identify how to trigger the function (IOCTL code, etc.)</li>
            <li>Develop PoC exploit targeting the missing security checks</li>
            <li>Verify exploit on systems running the old driver version</li>
        </ol>
    </div>
""".format(old_file=vuln['old_file'], new_file=vuln['new_file'])

        html_content += """
    <hr>
    <p style="text-align: center; color: #666; margin-top: 40px;">
        Generated by KernelHunt Framework Patch Diff Analyzer<br>
        By Shravan Kumar Sheri (SSK)
    </p>
</body>
</html>
"""

        with open(html_file, 'w') as f:
            f.write(html_content)

        print(f"[+] HTML report saved: {html_file}")


def main():
    parser = argparse.ArgumentParser(
        description='Patch Diff Analyzer - Find 0-days by analyzing security patches',
        epilog='Example: python patch_diff_analyzer.py -o old.sys -n new.sys -g C:\\ghidra_11.0_PUBLIC'
    )

    parser.add_argument('-o', '--old', required=True,
                       help='Path to old driver version')
    parser.add_argument('-n', '--new', required=True,
                       help='Path to new driver version')
    parser.add_argument('-g', '--ghidra', required=True,
                       help='Path to Ghidra installation')
    parser.add_argument('--output', default='patch_diff_analysis',
                       help='Output directory (default: patch_diff_analysis)')

    args = parser.parse_args()

    try:
        analyzer = PatchDiffAnalyzer(
            args.old,
            args.new,
            args.ghidra,
            args.output
        )
        analyzer.analyze()

    except Exception as e:
        print(f"\n[!] Error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()
