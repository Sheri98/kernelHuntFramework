#!/usr/bin/env python3
"""
KernelHunt Framework - Advanced Windows Driver 0-Day Hunter
By Shravan Kumar Sheri (SSK)

Automated security analysis and vulnerability discovery for Windows kernel drivers
"""

import os
import sys
import time
import argparse
from pathlib import Path
from datetime import datetime

class Colors:
    """ANSI color codes for terminal output"""
    RESET = '\033[0m'
    BOLD = '\033[1m'
    DIM = '\033[2m'

    # Regular colors
    BLACK = '\033[30m'
    RED = '\033[31m'
    GREEN = '\033[32m'
    YELLOW = '\033[33m'
    BLUE = '\033[34m'
    MAGENTA = '\033[35m'
    CYAN = '\033[36m'
    WHITE = '\033[37m'

    # Bright colors
    BRIGHT_BLACK = '\033[90m'
    BRIGHT_RED = '\033[91m'
    BRIGHT_GREEN = '\033[92m'
    BRIGHT_YELLOW = '\033[93m'
    BRIGHT_BLUE = '\033[94m'
    BRIGHT_MAGENTA = '\033[95m'
    BRIGHT_CYAN = '\033[96m'
    BRIGHT_WHITE = '\033[97m'

    # Background colors
    BG_RED = '\033[41m'
    BG_GREEN = '\033[42m'
    BG_YELLOW = '\033[43m'
    BG_BLUE = '\033[44m'
    BG_MAGENTA = '\033[45m'
    BG_CYAN = '\033[46m'


class KernelHunt:
    """Main KernelHunt Framework controller"""

    VERSION = "1.0.0"
    AUTHOR = "Shravan Kumar Sheri (SSK)"

    def __init__(self):
        self.base_dir = Path(__file__).parent.absolute()
        self.analysis_dir = self.base_dir / "analysis_results"
        self.drivers_dir = self.base_dir / "drivers"

    def print_banner(self):
        """Display the KernelHunt banner"""
        banner = f"""
{Colors.BRIGHT_CYAN}╔══════════════════════════════════════════════════════════════════════════════╗
║                                                                              ║
║  {Colors.BRIGHT_RED}██╗  ██╗███████╗██████╗ ███╗   ██╗███████╗██╗     ██╗  ██╗██╗   ██╗███╗   ██╗{Colors.BRIGHT_CYAN}║
║  {Colors.BRIGHT_RED}██║ ██╔╝██╔════╝██╔══██╗████╗  ██║██╔════╝██║     ██║  ██║██║   ██║████╗  ██║{Colors.BRIGHT_CYAN}║
║  {Colors.BRIGHT_RED}█████╔╝ █████╗  ██████╔╝██╔██╗ ██║█████╗  ██║     ███████║██║   ██║██╔██╗ ██║{Colors.BRIGHT_CYAN}║
║  {Colors.BRIGHT_RED}██╔═██╗ ██╔══╝  ██╔══██╗██║╚██╗██║██╔══╝  ██║     ██╔══██║██║   ██║██║╚██╗██║{Colors.BRIGHT_CYAN}║
║  {Colors.BRIGHT_RED}██║  ██╗███████╗██║  ██║██║ ╚████║███████╗███████╗██║  ██║╚██████╔╝██║ ╚████║{Colors.BRIGHT_CYAN}║
║  {Colors.BRIGHT_RED}╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝{Colors.BRIGHT_CYAN}║
║                                                                              ║
║             {Colors.BRIGHT_YELLOW}Advanced Windows Driver 0-Day Hunting Framework{Colors.BRIGHT_CYAN}               ║
║                                                                              ║
║  {Colors.BRIGHT_WHITE}Version:{Colors.RESET} {Colors.BRIGHT_GREEN}{self.VERSION}{Colors.BRIGHT_CYAN}                                  {Colors.BRIGHT_WHITE}Author:{Colors.RESET} {Colors.BRIGHT_MAGENTA}{self.AUTHOR}{Colors.BRIGHT_CYAN}  ║
║                                                                              ║
╚══════════════════════════════════════════════════════════════════════════════╝{Colors.RESET}

{Colors.BRIGHT_WHITE}[{Colors.BRIGHT_GREEN}+{Colors.BRIGHT_WHITE}] Automated Driver Security Analysis{Colors.RESET}
{Colors.BRIGHT_WHITE}[{Colors.BRIGHT_GREEN}+{Colors.BRIGHT_WHITE}] IOCTL Surface Mapping{Colors.RESET}
{Colors.BRIGHT_WHITE}[{Colors.BRIGHT_GREEN}+{Colors.BRIGHT_WHITE}] Dangerous Function Detection{Colors.RESET}
{Colors.BRIGHT_WHITE}[{Colors.BRIGHT_GREEN}+{Colors.BRIGHT_WHITE}] Exploitation Primitive Discovery{Colors.RESET}
{Colors.BRIGHT_WHITE}[{Colors.BRIGHT_GREEN}+{Colors.BRIGHT_WHITE}] Smart Fuzzing Wordlist Generation{Colors.RESET}

"""
        print(banner)

    def print_menu(self):
        """Display main menu"""
        menu = f"""
{Colors.BRIGHT_CYAN}╔════════════════════════ {Colors.BRIGHT_WHITE}MAIN MENU{Colors.BRIGHT_CYAN} ═══════════════════════════╗{Colors.RESET}

  {Colors.BRIGHT_YELLOW}[1]{Colors.RESET} {Colors.BRIGHT_WHITE}Analyze Single Driver{Colors.RESET}      - Complete analysis of one driver
  {Colors.BRIGHT_YELLOW}[2]{Colors.RESET} {Colors.BRIGHT_WHITE}Batch Analysis{Colors.RESET}            - Analyze multiple drivers automatically
  {Colors.BRIGHT_YELLOW}[3]{Colors.RESET} {Colors.BRIGHT_WHITE}Generate HTML Report{Colors.RESET}      - Create visual security report
  {Colors.BRIGHT_YELLOW}[4]{Colors.RESET} {Colors.BRIGHT_WHITE}Extract IOCTLs Only{Colors.RESET}       - Quick IOCTL extraction
  {Colors.BRIGHT_YELLOW}[5]{Colors.RESET} {Colors.BRIGHT_WHITE}Find Dangerous Functions{Colors.RESET}  - Scan for vulnerable functions
  {Colors.BRIGHT_YELLOW}[6]{Colors.RESET} {Colors.BRIGHT_WHITE}View Results{Colors.RESET}              - Browse previous analysis
  {Colors.BRIGHT_YELLOW}[7]{Colors.RESET} {Colors.BRIGHT_WHITE}Settings{Colors.RESET}                  - Configure framework
  {Colors.BRIGHT_YELLOW}[8]{Colors.RESET} {Colors.BRIGHT_WHITE}About / Credits{Colors.RESET}           - Framework information

  {Colors.BRIGHT_RED}[0]{Colors.RESET} {Colors.BRIGHT_WHITE}Exit{Colors.RESET}

{Colors.BRIGHT_CYAN}╚═══════════════════════════════════════════════════════════════╝{Colors.RESET}
"""
        print(menu)

    def print_section_header(self, title):
        """Print a section header"""
        width = 70
        print(f"\n{Colors.BRIGHT_CYAN}{'═' * width}{Colors.RESET}")
        print(f"{Colors.BRIGHT_WHITE}{title.center(width)}{Colors.RESET}")
        print(f"{Colors.BRIGHT_CYAN}{'═' * width}{Colors.RESET}\n")

    def print_status(self, status_type, message):
        """Print status message with appropriate color"""
        icons = {
            'success': (Colors.BRIGHT_GREEN, '✓'),
            'error': (Colors.BRIGHT_RED, '✗'),
            'info': (Colors.BRIGHT_BLUE, 'ℹ'),
            'warning': (Colors.BRIGHT_YELLOW, '⚠'),
            'progress': (Colors.BRIGHT_CYAN, '▶'),
            'critical': (Colors.BRIGHT_MAGENTA, '⚡')
        }

        color, icon = icons.get(status_type, (Colors.WHITE, '•'))
        print(f"{color}[{icon}]{Colors.RESET} {message}")

    def analyze_single_driver(self, driver_path, ghidra_path):
        """Analyze a single driver"""
        self.print_section_header("SINGLE DRIVER ANALYSIS")

        driver_path = Path(driver_path)
        if not driver_path.exists():
            self.print_status('error', f"Driver not found: {driver_path}")
            return False

        driver_name = driver_path.stem
        output_dir = self.analysis_dir / driver_name
        output_dir.mkdir(parents=True, exist_ok=True)

        self.print_status('info', f"Target: {Colors.BRIGHT_WHITE}{driver_path.name}{Colors.RESET}")
        self.print_status('info', f"Output: {Colors.BRIGHT_WHITE}{output_dir}{Colors.RESET}")
        print()

        # Step 1: Decompilation
        self.print_status('progress', f"{Colors.BRIGHT_YELLOW}Step 1/4:{Colors.RESET} Decompiling driver with Ghidra...")
        decompile_cmd = f'python3 "{self.base_dir}/driver_decompiler.py" -g "{ghidra_path}" -d "{driver_path}" -o "{output_dir}"'

        result = os.system(decompile_cmd)
        if result != 0:
            self.print_status('error', "Decompilation failed!")
            return False
        self.print_status('success', "Decompilation complete")
        print()

        # Step 2: IOCTL Extraction
        self.print_status('progress', f"{Colors.BRIGHT_YELLOW}Step 2/4:{Colors.RESET} Extracting IOCTL codes...")
        ioctl_cmd = f'python3 "{self.base_dir}/ioctl_analyzer.py" -d "{output_dir}"'

        result = os.system(ioctl_cmd)
        if result != 0:
            self.print_status('warning', "IOCTL extraction had issues (may be normal)")
        else:
            self.print_status('success', "IOCTL extraction complete")
        print()

        # Step 3: HTML Report
        self.print_status('progress', f"{Colors.BRIGHT_YELLOW}Step 3/4:{Colors.RESET} Generating security report...")
        report_cmd = f'python3 "{self.base_dir}/html_report_generator.py" -d "{output_dir}"'

        result = os.system(report_cmd)
        if result != 0:
            self.print_status('error', "Report generation failed!")
            return False
        self.print_status('success', "HTML report generated")
        print()

        # Step 4: Summary
        self.print_status('progress', f"{Colors.BRIGHT_YELLOW}Step 4/4:{Colors.RESET} Analysis complete!")
        print()

        # Show results
        html_report = output_dir / "security_report.html"
        ioctls_json = output_dir / "extracted_ioctls.json"
        dangerous_json = output_dir / "dangerous_functions.json"

        self.print_section_header("ANALYSIS RESULTS")

        if html_report.exists():
            self.print_status('success', f"HTML Report: {Colors.BRIGHT_CYAN}file://{html_report.absolute()}{Colors.RESET}")

        if ioctls_json.exists():
            import json
            with open(ioctls_json, 'r') as f:
                data = json.load(f)
                ioctl_count = data.get('total_ioctls', 0)
                self.print_status('info', f"IOCTLs Found: {Colors.BRIGHT_YELLOW}{ioctl_count}{Colors.RESET}")

        if dangerous_json.exists():
            import json
            with open(dangerous_json, 'r') as f:
                data = json.load(f)
                total = data.get('total', 0)
                critical = len(data.get('by_severity', {}).get('critical', {}).get('functions', []))

                self.print_status('info', f"Dangerous Functions: {Colors.BRIGHT_RED}{total}{Colors.RESET}")
                if critical > 0:
                    self.print_status('critical', f"CRITICAL Functions: {Colors.BRIGHT_RED}{critical}{Colors.RESET}")

        print()
        return True

    def batch_analysis(self, drivers_dir, ghidra_path):
        """Analyze all drivers in a directory"""
        self.print_section_header("BATCH DRIVER ANALYSIS")

        drivers_dir = Path(drivers_dir)
        if not drivers_dir.exists():
            self.print_status('error', f"Directory not found: {drivers_dir}")
            return

        # Find all .sys files
        drivers = list(drivers_dir.glob("*.sys"))

        if not drivers:
            self.print_status('warning', "No .sys files found in directory")
            return

        self.print_status('info', f"Found {Colors.BRIGHT_YELLOW}{len(drivers)}{Colors.RESET} drivers to analyze")
        print()

        results = {
            'success': [],
            'failed': []
        }

        for i, driver in enumerate(drivers, 1):
            print(f"{Colors.BRIGHT_CYAN}{'─' * 70}{Colors.RESET}")
            print(f"{Colors.BRIGHT_WHITE}Analyzing {i}/{len(drivers)}: {driver.name}{Colors.RESET}")
            print(f"{Colors.BRIGHT_CYAN}{'─' * 70}{Colors.RESET}\n")

            success = self.analyze_single_driver(driver, ghidra_path)

            if success:
                results['success'].append(driver.name)
            else:
                results['failed'].append(driver.name)

            print()

        # Final summary
        self.print_section_header("BATCH ANALYSIS SUMMARY")
        self.print_status('success', f"Successful: {Colors.BRIGHT_GREEN}{len(results['success'])}{Colors.RESET}")
        self.print_status('error', f"Failed: {Colors.BRIGHT_RED}{len(results['failed'])}{Colors.RESET}")
        print()

    def generate_report_only(self, analysis_dir):
        """Generate HTML report for existing analysis"""
        self.print_section_header("GENERATE HTML REPORT")

        analysis_dir = Path(analysis_dir)
        if not analysis_dir.exists():
            self.print_status('error', f"Analysis directory not found: {analysis_dir}")
            return

        report_cmd = f'python3 "{self.base_dir}/html_report_generator.py" -d "{analysis_dir}"'
        result = os.system(report_cmd)

        if result == 0:
            html_report = analysis_dir / "security_report.html"
            self.print_status('success', f"Report: {Colors.BRIGHT_CYAN}file://{html_report.absolute()}{Colors.RESET}")
        else:
            self.print_status('error', "Report generation failed")

    def view_results(self):
        """List and view previous analysis results"""
        self.print_section_header("PREVIOUS ANALYSIS RESULTS")

        if not self.analysis_dir.exists():
            self.print_status('warning', "No analysis results found")
            return

        results = [d for d in self.analysis_dir.iterdir() if d.is_dir()]

        if not results:
            self.print_status('warning', "No analysis results found")
            return

        print(f"{Colors.BRIGHT_WHITE}Found {len(results)} analyzed drivers:{Colors.RESET}\n")

        for i, result_dir in enumerate(results, 1):
            html_report = result_dir / "security_report.html"
            if html_report.exists():
                print(f"  {Colors.BRIGHT_YELLOW}[{i}]{Colors.RESET} {Colors.BRIGHT_WHITE}{result_dir.name}{Colors.RESET}")
                print(f"      {Colors.BRIGHT_CYAN}file://{html_report.absolute()}{Colors.RESET}")
            else:
                print(f"  {Colors.BRIGHT_YELLOW}[{i}]{Colors.RESET} {Colors.DIM}{result_dir.name} (no report){Colors.RESET}")
        print()

    def show_settings(self):
        """Show framework settings"""
        self.print_section_header("FRAMEWORK SETTINGS")

        print(f"{Colors.BRIGHT_WHITE}Base Directory:{Colors.RESET}     {self.base_dir}")
        print(f"{Colors.BRIGHT_WHITE}Analysis Output:{Colors.RESET}    {self.analysis_dir}")
        print(f"{Colors.BRIGHT_WHITE}Python Version:{Colors.RESET}     {sys.version.split()[0]}")
        print()

        # Check for required tools
        self.print_status('info', "Checking required tools...")

        tools = {
            'driver_decompiler.py': self.base_dir / 'driver_decompiler.py',
            'ioctl_analyzer.py': self.base_dir / 'ioctl_analyzer.py',
            'html_report_generator.py': self.base_dir / 'html_report_generator.py'
        }

        for name, path in tools.items():
            if path.exists():
                self.print_status('success', f"{name}")
            else:
                self.print_status('error', f"{name} - MISSING!")
        print()

    def show_about(self):
        """Show about information"""
        self.print_section_header("ABOUT KERNELHUNT FRAMEWORK")

        about = f"""
{Colors.BRIGHT_WHITE}KernelHunt Framework v{self.VERSION}{Colors.RESET}
{Colors.BRIGHT_MAGENTA}Developed by: {self.AUTHOR}{Colors.RESET}

{Colors.BRIGHT_YELLOW}Purpose:{Colors.RESET}
  Automated discovery of 0-day vulnerabilities in Windows kernel drivers
  through systematic analysis of attack surfaces and dangerous operations.

{Colors.BRIGHT_YELLOW}Capabilities:{Colors.RESET}
  • Automated driver decompilation using Ghidra
  • IOCTL attack surface enumeration and categorization
  • Detection of 40+ dangerous kernel functions
  • Security risk scoring and exploitation primitive identification
  • Beautiful HTML reports with visual categorization
  • Smart fuzzing wordlist generation

{Colors.BRIGHT_YELLOW}Research Focus:{Colors.RESET}
  • Arbitrary memory read/write primitives
  • MSR manipulation for protection bypass
  • Physical memory access vulnerabilities
  • Input validation weaknesses
  • Privilege escalation vectors

{Colors.BRIGHT_RED}⚠ For authorized security research only ⚠{Colors.RESET}

{Colors.BRIGHT_CYAN}GitHub:{Colors.RESET} https://github.com/Sheri98/kernelHuntFramework
"""
        print(about)

    def interactive_mode(self):
        """Run in interactive mode"""
        os.system('clear' if os.name == 'posix' else 'cls')
        self.print_banner()

        while True:
            self.print_menu()

            try:
                choice = input(f"{Colors.BRIGHT_YELLOW}kernelhunt>{Colors.RESET} ").strip()

                if choice == '0':
                    print(f"\n{Colors.BRIGHT_CYAN}Thank you for using KernelHunt Framework!{Colors.RESET}")
                    print(f"{Colors.BRIGHT_WHITE}Happy hunting! - SSK{Colors.RESET}\n")
                    break

                elif choice == '1':
                    driver_path = input(f"\n{Colors.BRIGHT_WHITE}Driver path:{Colors.RESET} ").strip()
                    ghidra_path = input(f"{Colors.BRIGHT_WHITE}Ghidra path:{Colors.RESET} ").strip()
                    self.analyze_single_driver(driver_path, ghidra_path)
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '2':
                    drivers_dir = input(f"\n{Colors.BRIGHT_WHITE}Drivers directory:{Colors.RESET} ").strip()
                    ghidra_path = input(f"{Colors.BRIGHT_WHITE}Ghidra path:{Colors.RESET} ").strip()
                    self.batch_analysis(drivers_dir, ghidra_path)
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '3':
                    analysis_dir = input(f"\n{Colors.BRIGHT_WHITE}Analysis directory:{Colors.RESET} ").strip()
                    self.generate_report_only(analysis_dir)
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '4':
                    analysis_dir = input(f"\n{Colors.BRIGHT_WHITE}Decompiled code directory:{Colors.RESET} ").strip()
                    ioctl_cmd = f'python3 "{self.base_dir}/ioctl_analyzer.py" -d "{analysis_dir}"'
                    os.system(ioctl_cmd)
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '5':
                    analysis_dir = input(f"\n{Colors.BRIGHT_WHITE}Analysis directory:{Colors.RESET} ").strip()
                    report_cmd = f'python3 "{self.base_dir}/html_report_generator.py" -d "{analysis_dir}"'
                    os.system(report_cmd)
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '6':
                    self.view_results()
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '7':
                    self.show_settings()
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                elif choice == '8':
                    self.show_about()
                    input(f"\n{Colors.DIM}Press Enter to continue...{Colors.RESET}")
                    os.system('clear' if os.name == 'posix' else 'cls')
                    self.print_banner()

                else:
                    self.print_status('error', 'Invalid choice')
                    time.sleep(1)

            except KeyboardInterrupt:
                print(f"\n\n{Colors.BRIGHT_CYAN}Thank you for using KernelHunt Framework!{Colors.RESET}\n")
                break
            except Exception as e:
                self.print_status('error', f'Error: {e}')
                time.sleep(2)


def main():
    parser = argparse.ArgumentParser(
        description='KernelHunt Framework - Advanced Windows Driver 0-Day Hunter',
        epilog=f'Developed by Shravan Kumar Sheri (SSK) | v{KernelHunt.VERSION}',
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument('-i', '--interactive', action='store_true',
                        help='Run in interactive mode (default)')
    parser.add_argument('-d', '--driver', help='Driver file to analyze')
    parser.add_argument('-g', '--ghidra', help='Ghidra installation path')
    parser.add_argument('-b', '--batch', help='Directory of drivers for batch analysis')
    parser.add_argument('-r', '--report', help='Generate HTML report for analysis directory')
    parser.add_argument('--version', action='version', version=f'KernelHunt v{KernelHunt.VERSION}')

    args = parser.parse_args()

    kh = KernelHunt()

    # Command-line mode
    if args.driver and args.ghidra:
        kh.print_banner()
        kh.analyze_single_driver(args.driver, args.ghidra)
    elif args.batch and args.ghidra:
        kh.print_banner()
        kh.batch_analysis(args.batch, args.ghidra)
    elif args.report:
        kh.print_banner()
        kh.generate_report_only(args.report)
    else:
        # Interactive mode (default)
        kh.interactive_mode()


if __name__ == "__main__":
    main()
