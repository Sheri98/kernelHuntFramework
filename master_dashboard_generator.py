#!/usr/bin/env python3
"""
Master Dashboard Generator
Creates a single HTML dashboard aggregating all analyzed drivers
Organized by severity: Critical, High, Medium, Low
"""

import os
import sys
import json
import argparse
from pathlib import Path
from datetime import datetime

class MasterDashboardGenerator:
    def __init__(self, analysis_dir):
        self.analysis_dir = Path(analysis_dir)
        self.drivers = []

    def scan_analysis_results(self):
        """Scan analysis_results directory for all analyzed drivers."""
        if not self.analysis_dir.exists():
            print(f"[!] Analysis directory not found: {self.analysis_dir}")
            return []

        print(f"\n[+] Scanning {self.analysis_dir} for analyzed drivers...")

        for driver_dir in self.analysis_dir.iterdir():
            if not driver_dir.is_dir():
                continue

            driver_info = self.extract_driver_info(driver_dir)
            if driver_info:
                self.drivers.append(driver_info)

        print(f"[+] Found {len(self.drivers)} analyzed drivers\n")
        return self.drivers

    def extract_driver_info(self, driver_dir):
        """Extract security information from a driver's analysis directory."""
        driver_name = driver_dir.name

        # Look for key files
        dangerous_funcs_file = driver_dir / "dangerous_functions.json"
        extracted_ioctls_file = driver_dir / "extracted_ioctls.json"
        primitives_file = driver_dir / "exploitation_primitives.json"
        security_report_file = driver_dir / "security_report.html"

        # Initialize driver info
        info = {
            'name': driver_name,
            'path': str(driver_dir),
            'report_path': str(security_report_file) if security_report_file.exists() else None,
            'security_score': 0,
            'severity': 'UNKNOWN',
            'ioctl_count': 0,
            'dangerous_functions': 0,
            'primitives': [],
            'has_report': security_report_file.exists()
        }

        # Extract dangerous functions data
        if dangerous_funcs_file.exists():
            try:
                with open(dangerous_funcs_file, 'r') as f:
                    data = json.load(f)
                    info['security_score'] = data.get('security_score', 0)
                    info['dangerous_functions'] = len(data.get('dangerous_functions', []))
            except Exception as e:
                print(f"[!] Warning: Could not read {dangerous_funcs_file.name}: {e}")

        # Extract IOCTL data
        if extracted_ioctls_file.exists():
            try:
                with open(extracted_ioctls_file, 'r') as f:
                    data = json.load(f)
                    info['ioctl_count'] = len(data.get('ioctls', []))
            except Exception as e:
                print(f"[!] Warning: Could not read {extracted_ioctls_file.name}: {e}")

        # Extract exploitation primitives
        if primitives_file.exists():
            try:
                with open(primitives_file, 'r') as f:
                    data = json.load(f)
                    primitives = data.get('primitives', {})
                    info['primitives'] = [
                        ptype for ptype, instances in primitives.items()
                        if instances and len(instances) > 0
                    ]
            except Exception as e:
                print(f"[!] Warning: Could not read {primitives_file.name}: {e}")

        # Determine severity based on security score
        score = info['security_score']
        if score >= 70:
            info['severity'] = 'CRITICAL'
        elif score >= 50:
            info['severity'] = 'HIGH'
        elif score >= 30:
            info['severity'] = 'MEDIUM'
        else:
            # Score is 0-29 or no score found
            info['severity'] = 'LOW'

        # Only skip if directory has NO analysis files at all
        has_any_analysis = (
            dangerous_funcs_file.exists() or
            extracted_ioctls_file.exists() or
            primitives_file.exists() or
            security_report_file.exists()
        )

        if not has_any_analysis:
            # Completely empty driver folder - skip it
            return None

        return info

    def categorize_drivers(self):
        """Categorize drivers by severity."""
        categories = {
            'CRITICAL': [],
            'HIGH': [],
            'MEDIUM': [],
            'LOW': []
        }

        for driver in self.drivers:
            severity = driver['severity']
            if severity in categories:
                categories[severity].append(driver)

        # Sort each category by security score (descending)
        for severity in categories:
            categories[severity].sort(key=lambda x: x['security_score'], reverse=True)

        return categories

    def generate_html(self, output_file):
        """Generate master HTML dashboard."""
        categories = self.categorize_drivers()

        # Calculate statistics
        total_drivers = len(self.drivers)
        total_ioctls = sum(d['ioctl_count'] for d in self.drivers)
        total_dangerous_funcs = sum(d['dangerous_functions'] for d in self.drivers)
        drivers_with_primitives = sum(1 for d in self.drivers if d['primitives'])

        html = f"""<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>KernelHunt - Master Dashboard</title>
    <style>
        * {{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }}

        body {{
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #1e1e1e 0%, #2d2d2d 100%);
            color: #e0e0e0;
            padding: 20px;
            min-height: 100vh;
        }}

        .container {{
            max-width: 1400px;
            margin: 0 auto;
        }}

        header {{
            text-align: center;
            padding: 30px 0;
            border-bottom: 2px solid #00ff41;
            margin-bottom: 30px;
        }}

        h1 {{
            font-size: 2.5em;
            color: #00ff41;
            text-shadow: 0 0 10px rgba(0, 255, 65, 0.5);
            margin-bottom: 10px;
        }}

        .subtitle {{
            color: #888;
            font-size: 1.1em;
        }}

        .stats-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-bottom: 40px;
        }}

        .stat-card {{
            background: rgba(255, 255, 255, 0.05);
            border: 1px solid rgba(255, 255, 255, 0.1);
            border-radius: 10px;
            padding: 25px;
            text-align: center;
            transition: transform 0.3s, box-shadow 0.3s;
        }}

        .stat-card:hover {{
            transform: translateY(-5px);
            box-shadow: 0 10px 30px rgba(0, 255, 65, 0.2);
        }}

        .stat-number {{
            font-size: 2.5em;
            font-weight: bold;
            color: #00ff41;
            margin-bottom: 10px;
        }}

        .stat-label {{
            color: #aaa;
            font-size: 1em;
        }}

        .severity-section {{
            margin-bottom: 40px;
        }}

        .severity-header {{
            display: flex;
            align-items: center;
            padding: 15px 20px;
            border-radius: 10px 10px 0 0;
            font-size: 1.5em;
            font-weight: bold;
            cursor: pointer;
            transition: all 0.3s;
        }}

        .severity-header:hover {{
            transform: translateX(5px);
        }}

        .severity-critical {{
            background: linear-gradient(135deg, #ff0000 0%, #cc0000 100%);
            border: 2px solid #ff0000;
        }}

        .severity-high {{
            background: linear-gradient(135deg, #ff6600 0%, #cc5200 100%);
            border: 2px solid #ff6600;
        }}

        .severity-medium {{
            background: linear-gradient(135deg, #ffaa00 0%, #cc8800 100%);
            border: 2px solid #ffaa00;
        }}

        .severity-low {{
            background: linear-gradient(135deg, #00aaff 0%, #0088cc 100%);
            border: 2px solid #00aaff;
        }}

        .severity-count {{
            margin-left: auto;
            background: rgba(0, 0, 0, 0.3);
            padding: 5px 15px;
            border-radius: 20px;
            font-size: 0.8em;
        }}

        .drivers-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(350px, 1fr));
            gap: 20px;
            padding: 20px;
            background: rgba(255, 255, 255, 0.02);
            border-radius: 0 0 10px 10px;
            border: 1px solid rgba(255, 255, 255, 0.1);
            border-top: none;
        }}

        .driver-card {{
            background: rgba(255, 255, 255, 0.05);
            border: 1px solid rgba(255, 255, 255, 0.1);
            border-radius: 8px;
            padding: 20px;
            transition: all 0.3s;
            position: relative;
            overflow: hidden;
        }}

        .driver-card:hover {{
            transform: scale(1.02);
            box-shadow: 0 5px 20px rgba(0, 255, 65, 0.3);
            border-color: #00ff41;
        }}

        .driver-name {{
            font-size: 1.2em;
            font-weight: bold;
            color: #00ff41;
            margin-bottom: 15px;
            word-break: break-word;
        }}

        .driver-stats {{
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 10px;
            margin-bottom: 15px;
        }}

        .driver-stat {{
            background: rgba(0, 0, 0, 0.3);
            padding: 10px;
            border-radius: 5px;
            text-align: center;
        }}

        .driver-stat-value {{
            font-size: 1.5em;
            font-weight: bold;
            color: #00ff41;
        }}

        .driver-stat-label {{
            font-size: 0.85em;
            color: #888;
            margin-top: 5px;
        }}

        .primitives-list {{
            margin-bottom: 15px;
        }}

        .primitive-badge {{
            display: inline-block;
            background: rgba(255, 0, 0, 0.2);
            border: 1px solid #ff0000;
            color: #ff6666;
            padding: 3px 8px;
            border-radius: 12px;
            font-size: 0.75em;
            margin: 2px;
        }}

        .view-report-btn {{
            display: block;
            width: 100%;
            padding: 12px;
            background: linear-gradient(135deg, #00ff41 0%, #00cc33 100%);
            color: #000;
            text-align: center;
            text-decoration: none;
            border-radius: 5px;
            font-weight: bold;
            transition: all 0.3s;
            border: none;
            cursor: pointer;
        }}

        .view-report-btn:hover {{
            background: linear-gradient(135deg, #00cc33 0%, #009926 100%);
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(0, 255, 65, 0.4);
        }}

        .view-report-btn:disabled {{
            background: #666;
            cursor: not-allowed;
            opacity: 0.5;
        }}

        .no-drivers {{
            text-align: center;
            padding: 40px;
            color: #888;
            font-style: italic;
        }}

        .search-box {{
            width: 100%;
            padding: 15px;
            margin-bottom: 30px;
            background: rgba(255, 255, 255, 0.05);
            border: 1px solid rgba(255, 255, 255, 0.1);
            border-radius: 10px;
            color: #e0e0e0;
            font-size: 1.1em;
            outline: none;
            transition: all 0.3s;
        }}

        .search-box:focus {{
            border-color: #00ff41;
            box-shadow: 0 0 20px rgba(0, 255, 65, 0.3);
        }}

        footer {{
            text-align: center;
            padding: 30px 0;
            margin-top: 50px;
            border-top: 1px solid rgba(255, 255, 255, 0.1);
            color: #888;
        }}

        .timestamp {{
            color: #666;
            font-size: 0.9em;
            margin-top: 10px;
        }}
    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>🔍 KernelHunt Framework</h1>
            <div class="subtitle">Master Analysis Dashboard</div>
            <div class="timestamp">Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}</div>
        </header>

        <div class="stats-grid">
            <div class="stat-card">
                <div class="stat-number">{total_drivers}</div>
                <div class="stat-label">Total Drivers Analyzed</div>
            </div>
            <div class="stat-card">
                <div class="stat-number">{total_ioctls}</div>
                <div class="stat-label">IOCTLs Discovered</div>
            </div>
            <div class="stat-card">
                <div class="stat-number">{total_dangerous_funcs}</div>
                <div class="stat-label">Dangerous Functions</div>
            </div>
            <div class="stat-card">
                <div class="stat-number">{drivers_with_primitives}</div>
                <div class="stat-label">Drivers with Primitives</div>
            </div>
        </div>

        <input type="text" id="searchBox" class="search-box" placeholder="🔍 Search drivers by name...">

        <div id="driversContainer">
"""

        # Add each severity section
        for severity in ['CRITICAL', 'HIGH', 'MEDIUM', 'LOW']:
            drivers = categories[severity]
            count = len(drivers)

            if count == 0:
                continue

            severity_class = f"severity-{severity.lower()}"

            html += f"""
            <div class="severity-section">
                <div class="severity-header {severity_class}">
                    <span>🚨 {severity}</span>
                    <span class="severity-count">{count} driver{'s' if count != 1 else ''}</span>
                </div>
                <div class="drivers-grid">
"""

            for driver in drivers:
                primitives_html = ""
                if driver['primitives']:
                    primitives_html = '<div class="primitives-list">'
                    for prim in driver['primitives']:
                        primitives_html += f'<span class="primitive-badge">{prim}</span>'
                    primitives_html += '</div>'

                report_btn = ""
                if driver['has_report']:
                    # Make path relative for HTML
                    relative_path = os.path.relpath(driver['report_path'], os.path.dirname(output_file))
                    report_btn = f'<a href="{relative_path}" class="view-report-btn" target="_blank">📄 View Security Report</a>'
                else:
                    report_btn = '<button class="view-report-btn" disabled>No Report Available</button>'

                html += f"""
                    <div class="driver-card" data-name="{driver['name'].lower()}">
                        <div class="driver-name">{driver['name']}</div>
                        <div class="driver-stats">
                            <div class="driver-stat">
                                <div class="driver-stat-value">{driver['security_score']}</div>
                                <div class="driver-stat-label">Security Score</div>
                            </div>
                            <div class="driver-stat">
                                <div class="driver-stat-value">{driver['ioctl_count']}</div>
                                <div class="driver-stat-label">IOCTLs</div>
                            </div>
                        </div>
                        {primitives_html}
                        {report_btn}
                    </div>
"""

            html += """
                </div>
            </div>
"""

        html += """
        </div>

        <footer>
            <div>KernelHunt Framework v2.0 - Windows Kernel Driver Security Analysis</div>
            <div style="margin-top: 10px; color: #666;">Developed for authorized security research and vulnerability discovery</div>
        </footer>
    </div>

    <script>
        // Search functionality
        const searchBox = document.getElementById('searchBox');
        const driverCards = document.querySelectorAll('.driver-card');

        searchBox.addEventListener('input', function() {
            const searchTerm = this.value.toLowerCase();

            driverCards.forEach(card => {
                const driverName = card.getAttribute('data-name');
                if (driverName.includes(searchTerm)) {
                    card.style.display = 'block';
                } else {
                    card.style.display = 'none';
                }
            });

            // Hide empty severity sections
            document.querySelectorAll('.severity-section').forEach(section => {
                const visibleCards = section.querySelectorAll('.driver-card[style="display: block;"], .driver-card:not([style])');
                if (searchTerm === '' || visibleCards.length > 0) {
                    section.style.display = 'block';
                } else {
                    section.style.display = 'none';
                }
            });
        });
    </script>
</body>
</html>
"""

        # Write HTML file
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(html)

        print(f"[+] Master dashboard generated: {output_file}")
        print(f"\n{'='*80}")
        print("SUMMARY BY SEVERITY:")
        print(f"{'='*80}")
        for severity in ['CRITICAL', 'HIGH', 'MEDIUM', 'LOW']:
            count = len(categories[severity])
            if count > 0:
                print(f"  {severity:10s}: {count:3d} drivers")
        print(f"{'='*80}\n")

        return output_file


def main():
    parser = argparse.ArgumentParser(
        description='Generate master HTML dashboard for all analyzed drivers',
        epilog='Example: python master_dashboard_generator.py -d analysis_results'
    )

    parser.add_argument('-d', '--directory', default='analysis_results',
                        help='Analysis results directory (default: analysis_results)')
    parser.add_argument('-o', '--output', default='master_dashboard.html',
                        help='Output HTML file (default: master_dashboard.html)')

    args = parser.parse_args()

    try:
        generator = MasterDashboardGenerator(args.directory)
        drivers = generator.scan_analysis_results()

        if not drivers:
            print("[!] No analyzed drivers found")
            print(f"[!] Make sure {args.directory} contains driver analysis subdirectories")
            sys.exit(1)

        output_file = generator.generate_html(args.output)

        print(f"[+] Dashboard successfully created!")
        print(f"[+] Open in browser: {os.path.abspath(output_file)}\n")

        sys.exit(0)

    except Exception as e:
        print(f"\n[!] Fatal error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()
