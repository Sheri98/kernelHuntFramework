#!/usr/bin/env python3
"""
IOCTL Analyzer for Decompiled Code
Analyzes decompiled C code to extract IOCTL codes
"""

import os
import sys
import re
import json
import argparse
from pathlib import Path
from collections import defaultdict

class IOCTLAnalyzer:
    def __init__(self, decompiled_dir):
        self.decompiled_dir = Path(decompiled_dir)
        self.ioctls = {}  # {ioctl_code: [locations]}
        
        if not self.decompiled_dir.exists():
            raise FileNotFoundError(f"Directory not found: {decompiled_dir}")
    
    def analyze(self):
        """Analyze all decompiled C files for IOCTL codes."""
        print(f"\n[*] Analyzing decompiled code in: {self.decompiled_dir}")
        print(f"[*] Searching for IOCTL patterns...\n")
        
        c_files = list(self.decompiled_dir.glob("*.c"))
        print(f"[*] Found {len(c_files)} C files to analyze")
        
        for c_file in c_files:
            self.analyze_file(c_file)
        
        self.save_results()
        self.display_results()
    
    def analyze_file(self, filepath):
        """Analyze a single C file for IOCTL codes."""
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()

            # Pattern 1: Hex constants that look like IOCTLs (common patterns)
            # IOCTL codes typically: 0x80000000 - 0xFFFFFFFF, often 0x9C... or 0x22...
            hex_pattern = r'(?:0x|0X)([0-9A-Fa-f]{6,8})\b'

            for match in re.finditer(hex_pattern, content):
                hex_value = match.group(1)
                value = int(hex_value, 16)

                # Get context FIRST for validation
                start = max(0, match.start() - 200)
                end = min(len(content), match.end() + 200)
                context = content[start:end]

                # Basic IOCTL structure check + context validation
                if self.is_likely_ioctl(value, context):
                    ioctl_hex = f"0x{hex_value.upper()}"

                    if ioctl_hex not in self.ioctls:
                        self.ioctls[ioctl_hex] = []

                    self.ioctls[ioctl_hex].append({
                        'file': filepath.name,
                        'value': value,
                        'context': context.replace('\n', ' ')[:200],  # First 200 chars
                        'confidence': self.calculate_confidence(value, context)
                    })

        except Exception as e:
            pass  # Skip files that can't be read
    
    def is_likely_ioctl(self, value, context):
        """
        Check if a value looks like an IOCTL code with context-based validation.
        This dramatically reduces false positives from jump tables, addresses, etc.
        """
        # Basic range check
        if value < 0x10000 or value > 0xFFFFFFFF:
            return False

        # IOCTL structure: bits 31-16 = device type, bits 1-0 = method
        device_type = (value >> 16) & 0xFFFF
        method = value & 0x3
        function_code = (value >> 2) & 0xFFF

        # Basic structural validation
        if device_type == 0 or device_type > 0xFFFF:
            return False
        if method > 3:
            return False
        if function_code == 0:
            return False

        # CONTEXT-BASED FILTERING (Critical for accuracy!)
        context_lower = context.lower()

        # REJECT: Jump table addresses (major source of false positives)
        reject_patterns = [
            'jumptable',
            'warning:',
            'switchd:',
            '->',  # Function pointers, struct members
            'ldrh', 'ldrb', 'strh', 'strb',  # ARM instructions
            'offset',
            '_offset_',
            'address',
        ]

        for pattern in reject_patterns:
            if pattern in context_lower:
                return False

        # ACCEPT: Strong IOCTL indicators
        accept_patterns = [
            'case',  # Switch case (very common for IOCTL dispatch)
            '==',    # Comparison (IOCTL validation)
            '!=',    # Comparison
            'switch',
            'ioctl',
            'deviceiocontrol',
            'irpsp->parameters.deviceiocontrol.iocontrolcode',
        ]

        for pattern in accept_patterns:
            if pattern in context_lower:
                return True  # High confidence

        # NEUTRAL: Might be IOCTL, needs more validation
        # Only accept if it has reasonable device type patterns
        # Common device types: 0x22 (FILE_DEVICE_UNKNOWN), 0x9C (custom)
        common_device_types = [0x0001, 0x0002, 0x0007, 0x0009, 0x0022, 0x002D, 0x9C40, 0x9C41, 0x9C42]

        if device_type in common_device_types:
            return True

        # If device type is reasonable (not too high), accept with low confidence
        if device_type < 0xA000:
            return True

        return False

    def calculate_confidence(self, value, context):
        """Calculate confidence score (0-100) that this is a real IOCTL."""
        score = 50  # Start neutral
        context_lower = context.lower()

        # Boost confidence
        if 'case' in context_lower:
            score += 30
        if '==' in context_lower or '!=' in context_lower:
            score += 20
        if 'switch' in context_lower:
            score += 20
        if 'ioctl' in context_lower or 'deviceiocontrol' in context_lower:
            score += 30

        # Reduce confidence
        if 'jumptable' in context_lower:
            score -= 40
        if 'warning' in context_lower:
            score -= 30
        if '->' in context_lower:
            score -= 10

        # Device type patterns
        device_type = (value >> 16) & 0xFFFF
        common_device_types = [0x0001, 0x0002, 0x0007, 0x0009, 0x0022, 0x002D, 0x9C40, 0x9C41, 0x9C42]

        if device_type in common_device_types:
            score += 15

        return max(0, min(100, score))  # Clamp to 0-100
    
    def save_results(self):
        """Save results to JSON with confidence scoring."""
        output_file = self.decompiled_dir / "extracted_ioctls.json"

        # Calculate average confidence for each IOCTL
        filtered_ioctls = {}
        for ioctl_code, locations in self.ioctls.items():
            avg_confidence = sum(loc['confidence'] for loc in locations) / len(locations)

            # Filter: Only keep IOCTLs with confidence >= 40
            if avg_confidence >= 40:
                filtered_ioctls[ioctl_code] = {
                    'locations': locations,
                    'confidence': avg_confidence
                }

        results = {
            'total_ioctls': len(filtered_ioctls),
            'total_raw_detections': len(self.ioctls),
            'filtered_low_confidence': len(self.ioctls) - len(filtered_ioctls),
            'ioctls': []
        }

        for ioctl_code, data in sorted(filtered_ioctls.items()):
            locations = data['locations']
            value = locations[0]['value']

            device_type = (value >> 16) & 0xFFFF
            access = (value >> 14) & 0x3
            function = (value >> 2) & 0xFFF
            method = value & 0x3

            results['ioctls'].append({
                'code': ioctl_code,
                'decimal': value,
                'device_type': f"0x{device_type:04X}",
                'function_code': f"0x{function:03X}",
                'method': method,
                'access': access,
                'confidence': round(data['confidence'], 1),
                'found_in': [loc['file'] for loc in locations],
                'contexts': [loc['context'] for loc in locations[:3]]  # First 3 contexts
            })

        with open(output_file, 'w') as f:
            json.dump(results, f, indent=2)

        print(f"\n[+] Results saved to: {output_file}")
        print(f"[+] Filtered {results['filtered_low_confidence']} low-confidence false positives")
    
    def display_results(self):
        """Display found IOCTLs with confidence scores."""
        print(f"\n{'='*80}")
        print("IOCTL CODES FOUND (FILTERED BY CONFIDENCE)")
        print(f"{'='*80}\n")

        # Calculate filtered IOCTLs (same logic as save_results)
        filtered_ioctls = {}
        for ioctl_code, locations in self.ioctls.items():
            avg_confidence = sum(loc['confidence'] for loc in locations) / len(locations)
            if avg_confidence >= 40:
                filtered_ioctls[ioctl_code] = {
                    'locations': locations,
                    'confidence': avg_confidence
                }

        if not filtered_ioctls:
            print("[!] No high-confidence IOCTL codes found")
            print(f"[*] {len(self.ioctls)} low-confidence detections filtered out (likely false positives)")
            print("\nTry manually reviewing the important dispatch functions.")
            return

        print(f"Total unique IOCTL codes (confidence >= 40%): {len(filtered_ioctls)}")
        print(f"Filtered false positives: {len(self.ioctls) - len(filtered_ioctls)}\n")

        method_names = ["METHOD_BUFFERED", "METHOD_IN_DIRECT", "METHOD_OUT_DIRECT", "METHOD_NEITHER"]
        access_names = ["FILE_ANY_ACCESS", "FILE_READ_ACCESS", "FILE_WRITE_ACCESS", "FILE_READ_WRITE_ACCESS"]

        for i, (ioctl_code, data) in enumerate(sorted(filtered_ioctls.items()), 1):
            locations = data['locations']
            value = locations[0]['value']
            confidence = data['confidence']

            device_type = (value >> 16) & 0xFFFF
            access = (value >> 14) & 0x3
            function = (value >> 2) & 0xFFF
            method = value & 0x3

            # Color code by confidence
            if confidence >= 80:
                conf_color = "HIGH"
            elif confidence >= 60:
                conf_color = "MEDIUM"
            else:
                conf_color = "LOW"

            print(f"[{i}] {ioctl_code} (decimal: {value}) [Confidence: {confidence:.0f}% - {conf_color}]")
            print(f"    Device Type:   0x{device_type:04X}")
            print(f"    Function Code: 0x{function:03X}")
            print(f"    Method:        {method_names[method]}")
            print(f"    Access:        {access_names[access]}")
            print(f"    Found in:      {', '.join(set([loc['file'] for loc in locations]))}")
            print()
    
    def create_ai_analysis_file(self):
        """Create a file ready for AI analysis."""
        summary_file = self.decompiled_dir / "ANALYSIS_SUMMARY.txt"
        if not summary_file.exists():
            return
        
        # Find dispatch/ioctl related functions
        dispatch_files = []
        for c_file in self.decompiled_dir.glob("*.c"):
            name_lower = c_file.stem.lower()
            if any(keyword in name_lower for keyword in ['dispatch', 'ioctl', 'devicecontrol', 'driverentry']):
                dispatch_files.append(c_file)
        
        if not dispatch_files:
            print("\n[!] No dispatch functions found")
            return
        
        # Create combined file for AI
        ai_file = self.decompiled_dir / "FOR_AI_ANALYSIS.txt"
        
        with open(ai_file, 'w') as out:
            out.write("=" * 80 + "\n")
            out.write("DRIVER IOCTL ANALYSIS - FOR AI\n")
            out.write("=" * 80 + "\n\n")
            
            out.write("TASK: Analyze these decompiled functions and extract all IOCTL codes\n\n")
            out.write("Look for:\n")
            out.write("- Hex constants (0x...) that appear in comparisons\n")
            out.write("- Switch/case statements with hex values\n")
            out.write("- Function calls that check IRP control codes\n\n")
            out.write("=" * 80 + "\n\n")
            
            for c_file in dispatch_files[:10]:  # Limit to first 10 files
                out.write(f"\n{'='*80}\n")
                out.write(f"FILE: {c_file.name}\n")
                out.write(f"{'='*80}\n\n")
                
                with open(c_file, 'r', encoding='utf-8', errors='ignore') as f:
                    out.write(f.read())
                
                out.write("\n\n")
        
        print(f"[+] AI analysis file created: {ai_file}")
        print(f"[+] Upload this file to Claude/ChatGPT for detailed analysis")


def main():
    parser = argparse.ArgumentParser(
        description='Analyze decompiled driver code to extract IOCTLs',
        epilog='Example: python ioctl_analyzer.py -d ./decompiled_output'
    )
    
    parser.add_argument('-d', '--dir', required=True, 
                       help='Directory containing decompiled C files')
    
    args = parser.parse_args()
    
    try:
        analyzer = IOCTLAnalyzer(args.dir)
        analyzer.analyze()
        analyzer.create_ai_analysis_file()
        
    except Exception as e:
        print(f"\n[!] Error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()
