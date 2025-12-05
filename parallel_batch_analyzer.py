#!/usr/bin/env python3
"""
Parallel Batch Driver Analysis
Analyzes multiple drivers simultaneously using all CPU cores
Much faster than sequential analysis for large driver sets
"""

import os
import sys
import json
import argparse
import subprocess
import multiprocessing as mp
from pathlib import Path
from datetime import datetime
from concurrent.futures import ProcessPoolExecutor, as_completed

class ParallelBatchAnalyzer:
    def __init__(self, driver_source, ghidra_path, output_base, max_workers=None, is_directory=False):
        self.driver_source = Path(driver_source)
        self.is_directory = is_directory
        self.ghidra_path = ghidra_path
        self.output_base = Path(output_base)
        self.max_workers = max_workers or mp.cpu_count()

        # Get the directory where this script is located (for absolute paths to other scripts)
        self.script_dir = Path(__file__).parent.resolve()

        self.output_base.mkdir(parents=True, exist_ok=True)

        print(f"\n{'='*80}")
        print("PARALLEL BATCH DRIVER ANALYSIS")
        print(f"{'='*80}\n")
        print(f"[+] CPU Cores Available: {mp.cpu_count()}")
        print(f"[+] Using {self.max_workers} parallel workers")
        print(f"[+] Output Directory: {self.output_base}\n")

    def scan_directory_for_drivers(self, directory):
        """Scan directory for .sys driver files."""
        directory = Path(directory)
        if not directory.exists():
            raise FileNotFoundError(f"Directory not found: {directory}")

        if not directory.is_dir():
            raise NotADirectoryError(f"Not a directory: {directory}")

        # Find all .sys files
        drivers = list(directory.glob("*.sys"))
        driver_paths = [str(d.absolute()) for d in drivers]

        print(f"[+] Scanned directory: {directory}")
        print(f"[+] Found {len(driver_paths)} .sys driver files\n")

        return driver_paths

    def load_drivers(self):
        """Load driver list from JSON file or directory."""
        if self.is_directory:
            # Scan directory for .sys files
            return self.scan_directory_for_drivers(self.driver_source)
        else:
            # Load from JSON file
            if not self.driver_source.exists():
                raise FileNotFoundError(f"Driver JSON not found: {self.driver_source}")

            with open(self.driver_source, 'r') as f:
                data = json.load(f)

            # Handle both formats: driver.json and all_drivers.json
            if 'drivers' in data:
                if isinstance(data['drivers'], list):
                    # Check if it's all_drivers.json format
                    if data['drivers'] and isinstance(data['drivers'][0], dict):
                        drivers = [d['path'] for d in data['drivers']]
                    else:
                        drivers = data['drivers']
                else:
                    drivers = []
            else:
                drivers = []

            print(f"[+] Loaded {len(drivers)} drivers from {self.driver_source.name}\n")
            return drivers

    def analyze_single_driver(self, driver_info):
        """Analyze a single driver (runs in separate process)."""
        driver_path, index, total = driver_info

        try:
            # Extract driver name
            driver_name = Path(driver_path).stem
            output_dir = self.output_base / driver_name
            output_dir.mkdir(parents=True, exist_ok=True)

            result = {
                'driver': driver_name,
                'path': driver_path,
                'index': index,
                'total': total,
                'status': 'processing',
                'steps_completed': 0,
                'errors': []
            }

            # Step 1: Decompile
            try:
                cmd = [
                    'python', str(self.script_dir / 'driver_decompiler.py'),
                    '-g', self.ghidra_path,
                    '-d', driver_path,
                    '-o', str(output_dir)
                ]
                proc = subprocess.run(cmd, capture_output=True, text=True, timeout=1800)
                if proc.returncode == 0:
                    result['steps_completed'] += 1
                else:
                    result['errors'].append(f"Decompilation failed: {proc.stderr[:200]}")
                    result['status'] = 'failed'
                    return result
            except subprocess.TimeoutExpired:
                result['errors'].append("Decompilation timeout (30min)")
                result['status'] = 'timeout'
                return result
            except Exception as e:
                result['errors'].append(f"Decompilation error: {str(e)}")
                result['status'] = 'failed'
                return result

            # Step 2: IOCTL Analysis
            try:
                cmd = ['python', str(self.script_dir / 'ioctl_analyzer.py'), '-d', str(output_dir)]
                subprocess.run(cmd, capture_output=True, timeout=300)
                result['steps_completed'] += 1
            except Exception as e:
                result['errors'].append(f"IOCTL analysis warning: {str(e)}")

            # Step 3: HTML Report
            try:
                cmd = ['python', str(self.script_dir / 'html_report_generator.py'), '-d', str(output_dir)]
                subprocess.run(cmd, capture_output=True, timeout=300)
                result['steps_completed'] += 1
            except Exception as e:
                result['errors'].append(f"HTML report warning: {str(e)}")

            # Step 4: Exploit Primitives
            try:
                cmd = ['python', str(self.script_dir / 'exploit_primitive_detector.py'), '-d', str(output_dir)]
                subprocess.run(cmd, capture_output=True, timeout=300)
                result['steps_completed'] += 1
            except Exception as e:
                result['errors'].append(f"Primitive detection warning: {str(e)}")

            # Determine final status
            if result['steps_completed'] == 4:
                result['status'] = 'success'
            elif result['steps_completed'] >= 2:
                result['status'] = 'partial'
            else:
                result['status'] = 'failed'

            return result

        except Exception as e:
            return {
                'driver': Path(driver_path).stem,
                'path': driver_path,
                'index': index,
                'total': total,
                'status': 'error',
                'steps_completed': 0,
                'errors': [str(e)]
            }

    def run(self):
        """Run parallel batch analysis."""
        drivers = self.load_drivers()

        if not drivers:
            print("[!] No drivers found in JSON file")
            return

        total = len(drivers)
        driver_info = [(driver, i+1, total) for i, driver in enumerate(drivers)]

        # Statistics
        stats = {
            'total': total,
            'completed': 0,
            'success': 0,
            'partial': 0,
            'failed': 0,
            'timeout': 0,
            'error': 0
        }

        results = []
        start_time = datetime.now()

        print(f"{'='*80}")
        print("PARALLEL ANALYSIS STARTED")
        print(f"{'='*80}\n")

        # Process in parallel
        with ProcessPoolExecutor(max_workers=self.max_workers) as executor:
            # Submit all jobs
            futures = {executor.submit(self.analyze_single_driver, info): info
                      for info in driver_info}

            # Process results as they complete
            for future in as_completed(futures):
                result = future.result()
                results.append(result)
                stats['completed'] += 1
                stats[result['status']] += 1

                # Calculate progress and time estimates
                driver_name = result['driver']
                status = result['status'].upper()
                steps = result['steps_completed']
                progress = (stats['completed'] / total) * 100

                # Time estimates
                elapsed = (datetime.now() - start_time).total_seconds()
                avg_time = elapsed / stats['completed']
                remaining = (total - stats['completed']) * avg_time
                eta_mins = int(remaining / 60)
                eta_secs = int(remaining % 60)

                status_color = {
                    'success': '\033[92m',  # Green
                    'partial': '\033[93m',  # Yellow
                    'failed': '\033[91m',   # Red
                    'timeout': '\033[95m',  # Magenta
                    'error': '\033[91m'     # Red
                }.get(result['status'], '\033[97m')

                # Progress bar
                bar_width = 30
                filled = int(bar_width * progress / 100)
                bar = '█' * filled + '░' * (bar_width - filled)

                print(f"\n[{stats['completed']}/{total}] {status_color}{status}\033[0m - {driver_name}")
                print(f"Progress: [{bar}] {progress:.1f}%")
                print(f"Steps completed: {steps}/4 | ETA: {eta_mins}m {eta_secs}s")
                print(f"Stats: ✓{stats['success']} ⚠{stats['partial']} ✗{stats['failed']+stats['error']+stats['timeout']}")

                if result['errors']:
                    for error in result['errors'][:1]:  # Show first error
                        print(f"    ⚠ {error[:80]}...")

        end_time = datetime.now()
        duration = end_time - start_time

        # Save results
        results_file = self.output_base / "parallel_analysis_results.json"
        with open(results_file, 'w') as f:
            json.dump({
                'start_time': start_time.isoformat(),
                'end_time': end_time.isoformat(),
                'duration_seconds': duration.total_seconds(),
                'statistics': stats,
                'results': results
            }, f, indent=2)

        # Print summary
        print(f"\n{'='*80}")
        print("PARALLEL ANALYSIS COMPLETE")
        print(f"{'='*80}\n")
        print(f"Duration: {duration}")
        print(f"Average: {duration.total_seconds()/total:.1f} seconds per driver\n")
        print("SUMMARY:")
        print(f"  Total Drivers:      {stats['total']}")
        print(f"  \033[92mFully Successful:   {stats['success']}\033[0m (all 4 steps)")
        print(f"  \033[93mPartial Success:    {stats['partial']}\033[0m (some steps)")
        print(f"  \033[91mFailed:             {stats['failed']}\033[0m (decompilation failed)")
        print(f"  \033[95mTimeout:            {stats['timeout']}\033[0m (exceeded time limit)")
        print(f"  \033[91mError:              {stats['error']}\033[0m (critical error)")
        print(f"\n[+] Results saved to: {results_file}")
        print(f"[+] Output directory: {self.output_base}")
        print(f"\n{'='*80}\n")

        # Show successful drivers
        if stats['success'] > 0:
            print("\n✓ SUCCESSFUL ANALYSES:")
            for r in results:
                if r['status'] == 'success':
                    driver_name = r['driver']
                    print(f"  • {driver_name}")
                    print(f"    Report: {self.output_base / driver_name / 'security_report.html'}")

        # Generate master dashboard
        if stats['success'] > 0 or stats['partial'] > 0:
            print(f"\n{'='*80}")
            print("GENERATING MASTER DASHBOARD")
            print(f"{'='*80}\n")

            try:
                cmd = [
                    'python', str(self.script_dir / 'master_dashboard_generator.py'),
                    '-d', str(self.output_base),
                    '-o', 'master_dashboard.html'
                ]
                subprocess.run(cmd, check=True)
                print(f"\n[+] Master dashboard: {Path('master_dashboard.html').absolute()}")
                print(f"[+] Open this file in your browser to see all analyzed drivers!\n")
            except Exception as e:
                print(f"[!] Warning: Could not generate master dashboard: {e}")

        return stats


def main():
    parser = argparse.ArgumentParser(
        description='Parallel batch driver analysis using all CPU cores',
        epilog='Examples:\n'
               '  From JSON: python parallel_batch_analyzer.py -j driver.json -g C:\\ghidra_11.0_PUBLIC\n'
               '  From directory: python parallel_batch_analyzer.py -d C:\\VulnerableDrivers -g C:\\ghidra_11.0_PUBLIC',
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    # Create mutually exclusive group for JSON or directory input
    input_group = parser.add_mutually_exclusive_group(required=True)
    input_group.add_argument('-j', '--json',
                        help='Driver JSON file (driver.json or all_drivers.json)')
    input_group.add_argument('-d', '--directory',
                        help='Directory containing .sys driver files')

    parser.add_argument('-g', '--ghidra', required=True,
                        help='Ghidra installation path')
    parser.add_argument('-o', '--output', default='analysis_results',
                        help='Output base directory (default: analysis_results)')
    parser.add_argument('-w', '--workers', type=int, default=None,
                        help=f'Number of parallel workers (default: {mp.cpu_count()} = all CPU cores)')

    args = parser.parse_args()

    try:
        # Determine input source and type
        if args.json:
            driver_source = args.json
            is_directory = False
        else:
            driver_source = args.directory
            is_directory = True

        analyzer = ParallelBatchAnalyzer(
            driver_source=driver_source,
            ghidra_path=args.ghidra,
            output_base=args.output,
            max_workers=args.workers,
            is_directory=is_directory
        )

        stats = analyzer.run()

        # Exit code based on success rate
        success_rate = (stats['success'] / stats['total']) * 100 if stats['total'] > 0 else 0
        if success_rate >= 80:
            sys.exit(0)  # Great success
        elif success_rate >= 50:
            sys.exit(1)  # Partial success
        else:
            sys.exit(2)  # Mostly failed

    except Exception as e:
        print(f"\n[!] Fatal error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(3)


if __name__ == "__main__":
    main()
