#!/usr/bin/env python3
"""
HTML Report Generator for KernelHuntFramework
Generates beautiful visual HTML reports with IOCTL compartmentalization and dangerous function detection
"""

import os
import sys
import json
import re
import argparse
from pathlib import Path
from collections import defaultdict
from datetime import datetime

class HTMLReportGenerator:
    # Dangerous functions that indicate potential vulnerabilities
    DANGEROUS_FUNCTIONS = {
        'critical': [
            'MmMapIoSpace', 'MmMapIoSpaceEx', 'MmMapLockedPages', 'MmMapLockedPagesSpecifyCache',
            '__writemsr', '__readmsr', 'wrmsr', 'rdmsr',
            'WRITE_PORT_UCHAR', 'WRITE_PORT_USHORT', 'WRITE_PORT_ULONG',
            'READ_PORT_UCHAR', 'READ_PORT_USHORT', 'READ_PORT_ULONG',
            '__outbyte', '__outword', '__outdword', '__inbyte', '__inword', '__indword',
            'ZwMapViewOfSection', 'ZwOpenProcess', 'ZwOpenThread',
            'SePrivilegeCheck', 'SeSinglePrivilegeCheck',
        ],
        'high': [
            'memcpy', 'RtlCopyMemory', 'memmove', 'RtlMoveMemory',
            'strcpy', 'wcscpy', 'strncpy', 'wcsncpy',
            'sprintf', 'vsprintf', 'swprintf', 'vswprintf',
            'strcat', 'wcscat', 'strncat', 'wcsncat',
            'gets', 'scanf', 'sscanf', 'fscanf',
            'ProbeForRead', 'ProbeForWrite',
            'ZwCreateFile', 'ZwWriteFile', 'ZwReadFile',
            'IoCreateDevice', 'IoCreateSymbolicLink',
        ],
        'medium': [
            'ExAllocatePool', 'ExAllocatePoolWithTag', 'ExFreePool', 'ExFreePoolWithTag',
            'IoAllocateMdl', 'IoFreeMdl', 'MmBuildMdlForNonPagedPool',
            'KeStackAttachProcess', 'KeUnstackDetachProcess',
            'PsLookupProcessByProcessId', 'PsLookupThreadByThreadId',
            'ObReferenceObjectByHandle', 'ObDereferenceObject',
            '_vsnprintf', '_vsnwprintf', 'RtlStringCbPrintf', 'RtlStringCchPrintf',
        ],
        'low': [
            'DbgPrint', 'DbgPrintEx', 'KdPrint',
            'IoGetCurrentIrpStackLocation', 'IofCompleteRequest',
            'KeAcquireSpinLock', 'KeReleaseSpinLock',
            'ExAcquireFastMutex', 'ExReleaseFastMutex',
        ]
    }

    METHOD_NAMES = {
        0: 'METHOD_BUFFERED',
        1: 'METHOD_IN_DIRECT',
        2: 'METHOD_OUT_DIRECT',
        3: 'METHOD_NEITHER'
    }

    ACCESS_NAMES = {
        0: 'FILE_ANY_ACCESS',
        1: 'FILE_READ_ACCESS',
        2: 'FILE_WRITE_ACCESS',
        3: 'FILE_READ_WRITE_ACCESS'
    }

    def __init__(self, analysis_dir):
        self.analysis_dir = Path(analysis_dir)
        self.driver_name = self.analysis_dir.name
        self.ioctls_data = None
        self.dangerous_funcs_found = defaultdict(list)
        self.total_functions = 0
        self.c_files = []

        if not self.analysis_dir.exists():
            raise FileNotFoundError(f"Analysis directory not found: {analysis_dir}")

    def load_data(self):
        """Load existing analysis data."""
        # Load IOCTLs
        ioctls_file = self.analysis_dir / "extracted_ioctls.json"
        if ioctls_file.exists():
            with open(ioctls_file, 'r') as f:
                self.ioctls_data = json.load(f)
        else:
            self.ioctls_data = {'total_ioctls': 0, 'ioctls': []}

        # Get C files
        self.c_files = list(self.analysis_dir.glob("*.c"))
        self.total_functions = len(self.c_files)

        # Parse ANALYSIS_SUMMARY.txt for function count
        summary_file = self.analysis_dir / "ANALYSIS_SUMMARY.txt"
        if summary_file.exists():
            with open(summary_file, 'r') as f:
                content = f.read()
                match = re.search(r'Total Functions:\s*(\d+)', content)
                if match:
                    self.total_functions = int(match.group(1))

    def detect_dangerous_functions(self):
        """Scan all C files for dangerous function calls."""
        print(f"[*] Scanning {len(self.c_files)} C files for dangerous functions...")

        for c_file in self.c_files:
            try:
                with open(c_file, 'r', encoding='utf-8', errors='ignore') as f:
                    content = f.read()

                for severity, funcs in self.DANGEROUS_FUNCTIONS.items():
                    for func in funcs:
                        # Match function calls
                        pattern = rf'\b{re.escape(func)}\s*\('
                        matches = re.findall(pattern, content)
                        if matches:
                            for _ in matches:
                                self.dangerous_funcs_found[severity].append({
                                    'function': func,
                                    'file': c_file.name,
                                    'severity': severity
                                })
            except Exception as e:
                pass

    def categorize_ioctls(self):
        """Categorize IOCTLs by device type, method, and access."""
        categories = {
            'by_device_type': defaultdict(list),
            'by_method': defaultdict(list),
            'by_access': defaultdict(list)
        }

        for ioctl in self.ioctls_data.get('ioctls', []):
            device_type = ioctl.get('device_type', 'Unknown')
            method = ioctl.get('method', -1)
            access = ioctl.get('access', -1)

            categories['by_device_type'][device_type].append(ioctl)

            method_name = self.METHOD_NAMES.get(method, f'Unknown ({method})')
            categories['by_method'][method_name].append(ioctl)

            access_name = self.ACCESS_NAMES.get(access, f'Unknown ({access})')
            categories['by_access'][access_name].append(ioctl)

        return categories

    def calculate_security_score(self):
        """Calculate security risk score (0-100, lower is more secure)."""
        score = 0

        # IOCTLs contribute to risk
        num_ioctls = self.ioctls_data.get('total_ioctls', 0)
        score += min(num_ioctls * 0.5, 20)  # Max 20 points from IOCTLs

        # Dangerous functions
        critical_count = len(self.dangerous_funcs_found.get('critical', []))
        high_count = len(self.dangerous_funcs_found.get('high', []))
        medium_count = len(self.dangerous_funcs_found.get('medium', []))

        score += critical_count * 5  # 5 points per critical
        score += high_count * 2      # 2 points per high
        score += medium_count * 0.5  # 0.5 points per medium

        # METHOD_NEITHER is riskier
        categories = self.categorize_ioctls()
        neither_count = len(categories['by_method'].get('METHOD_NEITHER', []))
        score += neither_count * 2  # 2 points per METHOD_NEITHER

        return min(int(score), 100)

    def get_risk_level(self, score):
        """Get risk level description based on score."""
        if score >= 70:
            return ('CRITICAL', '#dc3545')
        elif score >= 50:
            return ('HIGH', '#fd7e14')
        elif score >= 30:
            return ('MEDIUM', '#ffc107')
        else:
            return ('LOW', '#28a745')

    def generate_html(self):
        """Generate the HTML report."""
        self.load_data()
        self.detect_dangerous_functions()

        categories = self.categorize_ioctls()
        security_score = self.calculate_security_score()
        risk_level, risk_color = self.get_risk_level(security_score)

        # Count totals
        total_ioctls = self.ioctls_data.get('total_ioctls', 0)
        total_dangerous = sum(len(v) for v in self.dangerous_funcs_found.values())
        critical_funcs = len(self.dangerous_funcs_found.get('critical', []))

        html = f'''<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Security Report - {self.driver_name}</title>
    <style>
        * {{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }}

        body {{
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, sans-serif;
            background: linear-gradient(135deg, #1a1a2e 0%, #16213e 100%);
            color: #e0e0e0;
            min-height: 100vh;
            padding: 20px;
        }}

        .container {{
            max-width: 1400px;
            margin: 0 auto;
        }}

        .header {{
            text-align: center;
            padding: 30px 0;
            margin-bottom: 30px;
        }}

        .header h1 {{
            font-size: 2.5rem;
            color: #fff;
            margin-bottom: 10px;
        }}

        .header .subtitle {{
            color: #888;
            font-size: 1.1rem;
        }}

        .dashboard {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-bottom: 30px;
        }}

        .card {{
            background: rgba(255, 255, 255, 0.05);
            border-radius: 12px;
            padding: 20px;
            border: 1px solid rgba(255, 255, 255, 0.1);
        }}

        .stat-card {{
            text-align: center;
        }}

        .stat-card .value {{
            font-size: 3rem;
            font-weight: bold;
            color: #fff;
        }}

        .stat-card .label {{
            color: #888;
            margin-top: 5px;
            font-size: 0.9rem;
        }}

        .score-card {{
            background: linear-gradient(135deg, {risk_color}22, {risk_color}11);
            border-color: {risk_color}44;
        }}

        .score-card .value {{
            color: {risk_color};
        }}

        .section {{
            margin-bottom: 30px;
        }}

        .section h2 {{
            font-size: 1.5rem;
            margin-bottom: 20px;
            color: #fff;
            display: flex;
            align-items: center;
            gap: 10px;
        }}

        .section h2::before {{
            content: '';
            display: inline-block;
            width: 4px;
            height: 24px;
            background: #667eea;
            border-radius: 2px;
        }}

        .category-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
        }}

        .category-card {{
            background: rgba(255, 255, 255, 0.05);
            border-radius: 12px;
            overflow: hidden;
            border: 1px solid rgba(255, 255, 255, 0.1);
        }}

        .category-header {{
            background: rgba(102, 126, 234, 0.2);
            padding: 15px 20px;
            font-weight: 600;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }}

        .category-count {{
            background: #667eea;
            color: #fff;
            padding: 4px 12px;
            border-radius: 20px;
            font-size: 0.85rem;
        }}

        .category-content {{
            padding: 15px 20px;
            max-height: 300px;
            overflow-y: auto;
        }}

        .ioctl-item {{
            padding: 10px;
            margin-bottom: 10px;
            background: rgba(255, 255, 255, 0.03);
            border-radius: 8px;
            border-left: 3px solid #667eea;
        }}

        .ioctl-code {{
            font-family: 'Consolas', monospace;
            font-weight: bold;
            color: #667eea;
        }}

        .ioctl-details {{
            font-size: 0.85rem;
            color: #888;
            margin-top: 5px;
        }}

        .danger-card {{
            border-left-color: #dc3545;
        }}

        .danger-card .category-header {{
            background: rgba(220, 53, 69, 0.2);
        }}

        .danger-card .category-count {{
            background: #dc3545;
        }}

        .warning-card {{
            border-left-color: #fd7e14;
        }}

        .warning-card .category-header {{
            background: rgba(253, 126, 20, 0.2);
        }}

        .warning-card .category-count {{
            background: #fd7e14;
        }}

        .func-item {{
            padding: 8px 12px;
            margin-bottom: 8px;
            background: rgba(255, 255, 255, 0.03);
            border-radius: 6px;
            font-family: 'Consolas', monospace;
            font-size: 0.9rem;
        }}

        .func-file {{
            color: #666;
            font-size: 0.8rem;
            margin-top: 3px;
        }}

        .method-buffered {{ border-left-color: #28a745; }}
        .method-in-direct {{ border-left-color: #17a2b8; }}
        .method-out-direct {{ border-left-color: #ffc107; }}
        .method-neither {{ border-left-color: #dc3545; }}

        .table-container {{
            overflow-x: auto;
        }}

        table {{
            width: 100%;
            border-collapse: collapse;
            margin-top: 10px;
        }}

        th, td {{
            padding: 12px;
            text-align: left;
            border-bottom: 1px solid rgba(255, 255, 255, 0.1);
        }}

        th {{
            background: rgba(102, 126, 234, 0.2);
            font-weight: 600;
        }}

        tr:hover {{
            background: rgba(255, 255, 255, 0.05);
        }}

        .badge {{
            display: inline-block;
            padding: 3px 8px;
            border-radius: 4px;
            font-size: 0.75rem;
            font-weight: 600;
        }}

        .badge-critical {{ background: #dc3545; color: #fff; }}
        .badge-high {{ background: #fd7e14; color: #fff; }}
        .badge-medium {{ background: #ffc107; color: #000; }}
        .badge-low {{ background: #28a745; color: #fff; }}

        .footer {{
            text-align: center;
            padding: 30px 0;
            color: #666;
            font-size: 0.9rem;
        }}

        @media (max-width: 768px) {{
            .dashboard {{
                grid-template-columns: 1fr 1fr;
            }}
            .category-grid {{
                grid-template-columns: 1fr;
            }}
        }}
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Security Analysis Report</h1>
            <p class="subtitle">{self.driver_name}</p>
        </div>

        <!-- Dashboard Stats -->
        <div class="dashboard">
            <div class="card stat-card score-card">
                <div class="value">{security_score}/100</div>
                <div class="label">Security Score ({risk_level})</div>
            </div>
            <div class="card stat-card">
                <div class="value">{total_ioctls}</div>
                <div class="label">IOCTL Codes Found</div>
            </div>
            <div class="card stat-card">
                <div class="value">{total_dangerous}</div>
                <div class="label">Dangerous Functions</div>
            </div>
            <div class="card stat-card">
                <div class="value">{critical_funcs}</div>
                <div class="label">Critical Issues</div>
            </div>
            <div class="card stat-card">
                <div class="value">{self.total_functions}</div>
                <div class="label">Total Functions</div>
            </div>
        </div>

        <!-- IOCTLs by Method -->
        <div class="section">
            <h2>IOCTLs by Transfer Method</h2>
            <div class="category-grid">
'''

        # Add IOCTL method categories
        method_classes = {
            'METHOD_BUFFERED': 'method-buffered',
            'METHOD_IN_DIRECT': 'method-in-direct',
            'METHOD_OUT_DIRECT': 'method-out-direct',
            'METHOD_NEITHER': 'method-neither'
        }

        for method_name, ioctls in sorted(categories['by_method'].items()):
            method_class = method_classes.get(method_name, '')
            html += f'''
                <div class="category-card {method_class}">
                    <div class="category-header">
                        <span>{method_name}</span>
                        <span class="category-count">{len(ioctls)}</span>
                    </div>
                    <div class="category-content">
'''
            for ioctl in ioctls[:10]:  # Show first 10
                html += f'''
                        <div class="ioctl-item">
                            <div class="ioctl-code">{ioctl['code']}</div>
                            <div class="ioctl-details">
                                Device: {ioctl['device_type']} | Func: {ioctl['function_code']} |
                                {self.ACCESS_NAMES.get(ioctl['access'], 'Unknown')}
                            </div>
                        </div>
'''
            if len(ioctls) > 10:
                html += f'<div style="color: #666; text-align: center; padding: 10px;">... and {len(ioctls) - 10} more</div>'
            html += '''
                    </div>
                </div>
'''

        html += '''
            </div>
        </div>

        <!-- IOCTLs by Device Type -->
        <div class="section">
            <h2>IOCTLs by Device Type</h2>
            <div class="category-grid">
'''

        for device_type, ioctls in sorted(categories['by_device_type'].items()):
            html += f'''
                <div class="category-card">
                    <div class="category-header">
                        <span>Device Type {device_type}</span>
                        <span class="category-count">{len(ioctls)}</span>
                    </div>
                    <div class="category-content">
'''
            for ioctl in ioctls[:8]:
                html += f'''
                        <div class="ioctl-item">
                            <div class="ioctl-code">{ioctl['code']}</div>
                            <div class="ioctl-details">
                                Method: {self.METHOD_NAMES.get(ioctl['method'], 'Unknown')} |
                                Func: {ioctl['function_code']}
                            </div>
                        </div>
'''
            if len(ioctls) > 8:
                html += f'<div style="color: #666; text-align: center; padding: 10px;">... and {len(ioctls) - 8} more</div>'
            html += '''
                    </div>
                </div>
'''

        html += '''
            </div>
        </div>

        <!-- Dangerous Functions -->
        <div class="section">
            <h2>Dangerous Functions Detected</h2>
            <div class="category-grid">
'''

        # Critical functions
        if self.dangerous_funcs_found.get('critical'):
            html += '''
                <div class="category-card danger-card">
                    <div class="category-header">
                        <span>CRITICAL</span>
                        <span class="category-count">''' + str(len(self.dangerous_funcs_found['critical'])) + '''</span>
                    </div>
                    <div class="category-content">
'''
            # Group by function name
            func_groups = defaultdict(list)
            for item in self.dangerous_funcs_found['critical']:
                func_groups[item['function']].append(item['file'])

            for func, files in func_groups.items():
                html += f'''
                        <div class="func-item">
                            {func}
                            <div class="func-file">Found in: {', '.join(list(set(files))[:3])}</div>
                        </div>
'''
            html += '''
                    </div>
                </div>
'''

        # High severity functions
        if self.dangerous_funcs_found.get('high'):
            html += '''
                <div class="category-card warning-card">
                    <div class="category-header">
                        <span>HIGH SEVERITY</span>
                        <span class="category-count">''' + str(len(self.dangerous_funcs_found['high'])) + '''</span>
                    </div>
                    <div class="category-content">
'''
            func_groups = defaultdict(list)
            for item in self.dangerous_funcs_found['high']:
                func_groups[item['function']].append(item['file'])

            for func, files in list(func_groups.items())[:10]:
                html += f'''
                        <div class="func-item">
                            {func}
                            <div class="func-file">Found in: {', '.join(list(set(files))[:3])}</div>
                        </div>
'''
            if len(func_groups) > 10:
                html += f'<div style="color: #666; text-align: center; padding: 10px;">... and {len(func_groups) - 10} more</div>'
            html += '''
                    </div>
                </div>
'''

        # Medium severity
        if self.dangerous_funcs_found.get('medium'):
            html += '''
                <div class="category-card">
                    <div class="category-header">
                        <span>MEDIUM SEVERITY</span>
                        <span class="category-count">''' + str(len(self.dangerous_funcs_found['medium'])) + '''</span>
                    </div>
                    <div class="category-content">
'''
            func_groups = defaultdict(list)
            for item in self.dangerous_funcs_found['medium']:
                func_groups[item['function']].append(item['file'])

            for func, files in list(func_groups.items())[:8]:
                html += f'''
                        <div class="func-item">
                            {func}
                            <div class="func-file">Found in: {', '.join(list(set(files))[:3])}</div>
                        </div>
'''
            if len(func_groups) > 8:
                html += f'<div style="color: #666; text-align: center; padding: 10px;">... and {len(func_groups) - 8} more</div>'
            html += '''
                    </div>
                </div>
'''

        html += '''
            </div>
        </div>

        <!-- Full IOCTL Table -->
        <div class="section">
            <h2>Complete IOCTL Reference</h2>
            <div class="card">
                <div class="table-container">
                    <table>
                        <thead>
                            <tr>
                                <th>IOCTL Code</th>
                                <th>Device Type</th>
                                <th>Function</th>
                                <th>Method</th>
                                <th>Access</th>
                                <th>Found In</th>
                            </tr>
                        </thead>
                        <tbody>
'''

        for ioctl in self.ioctls_data.get('ioctls', [])[:50]:  # Show first 50
            method_name = self.METHOD_NAMES.get(ioctl['method'], 'Unknown')
            access_name = self.ACCESS_NAMES.get(ioctl['access'], 'Unknown')
            files = ', '.join(ioctl.get('found_in', [])[:2])

            html += f'''
                            <tr>
                                <td><code>{ioctl['code']}</code></td>
                                <td>{ioctl['device_type']}</td>
                                <td>{ioctl['function_code']}</td>
                                <td>{method_name}</td>
                                <td>{access_name}</td>
                                <td>{files}</td>
                            </tr>
'''

        if len(self.ioctls_data.get('ioctls', [])) > 50:
            html += f'''
                            <tr>
                                <td colspan="6" style="text-align: center; color: #666;">
                                    ... and {len(self.ioctls_data['ioctls']) - 50} more IOCTLs
                                </td>
                            </tr>
'''

        html += f'''
                        </tbody>
                    </table>
                </div>
            </div>
        </div>

        <div class="footer">
            <p>Generated by KernelHuntFramework on {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}</p>
            <p>For security research purposes only</p>
        </div>
    </div>
</body>
</html>
'''

        return html

    def save_dangerous_functions_json(self):
        """Save dangerous functions to JSON file."""
        security_score = self.calculate_security_score()
        risk_level, _ = self.get_risk_level(security_score)

        output = {
            'security_score': security_score,
            'risk_level': risk_level,
            'total': sum(len(v) for v in self.dangerous_funcs_found.values()),
            'by_severity': {}
        }

        for severity, items in self.dangerous_funcs_found.items():
            func_groups = defaultdict(list)
            for item in items:
                func_groups[item['function']].append(item['file'])

            output['by_severity'][severity] = {
                'count': len(items),
                'functions': [
                    {'name': func, 'files': list(set(files))}
                    for func, files in func_groups.items()
                ]
            }

        output_file = self.analysis_dir / "dangerous_functions.json"
        with open(output_file, 'w') as f:
            json.dump(output, f, indent=2)

        print(f"[+] Dangerous functions saved to: {output_file}")

    def generate(self):
        """Generate the complete HTML report."""
        print(f"\n[*] Generating HTML report for: {self.driver_name}")

        html = self.generate_html()

        # Save HTML report
        output_file = self.analysis_dir / "security_report.html"
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(html)

        print(f"[+] HTML report saved to: {output_file}")

        # Save dangerous functions JSON
        self.save_dangerous_functions_json()

        # Print summary
        security_score = self.calculate_security_score()
        risk_level, _ = self.get_risk_level(security_score)
        total_dangerous = sum(len(v) for v in self.dangerous_funcs_found.values())

        print(f"\n{'='*60}")
        print("REPORT SUMMARY")
        print(f"{'='*60}")
        print(f"Security Score:      {security_score}/100 ({risk_level})")
        print(f"Total IOCTLs:        {self.ioctls_data.get('total_ioctls', 0)}")
        print(f"Total Functions:     {self.total_functions}")
        print(f"Dangerous Functions: {total_dangerous}")
        print(f"  - Critical:        {len(self.dangerous_funcs_found.get('critical', []))}")
        print(f"  - High:            {len(self.dangerous_funcs_found.get('high', []))}")
        print(f"  - Medium:          {len(self.dangerous_funcs_found.get('medium', []))}")
        print(f"{'='*60}\n")

        return output_file


def main():
    parser = argparse.ArgumentParser(
        description='Generate HTML security report for analyzed drivers',
        epilog='Example: python html_report_generator.py -d analysis_results/driver_name'
    )

    parser.add_argument('-d', '--dir', required=True,
                        help='Directory containing analysis results')

    args = parser.parse_args()

    try:
        generator = HTMLReportGenerator(args.dir)
        output_file = generator.generate()
        print(f"[+] Report generation complete!")
        print(f"[+] Open in browser: file://{output_file.absolute()}")

    except Exception as e:
        print(f"\n[!] Error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()
