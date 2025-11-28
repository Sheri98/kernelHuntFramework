#!/usr/bin/env python3
"""
Driver Decompiler using Ghidra Headless Mode
Decompiles a driver to C source code for analysis
"""

import os
import sys
import subprocess
import argparse
import tempfile
import shutil
from pathlib import Path

class DriverDecompiler:
    def __init__(self, ghidra_path, driver_path, output_dir=None):
        self.ghidra_path = Path(ghidra_path)
        self.driver_path = Path(driver_path).absolute()
        self.output_dir = Path(output_dir).absolute() if output_dir else Path.cwd() / "decompiled_output"
        self.output_dir.mkdir(parents=True, exist_ok=True)
        
        self.validate_paths()
        self.temp_dir = Path(tempfile.mkdtemp(prefix="ghidra_decompile_"))
        self.project_name = "decompile_project"
        
    def validate_paths(self):
        if not self.ghidra_path.exists():
            raise FileNotFoundError(f"Ghidra path not found: {self.ghidra_path}")
        
        if not self.driver_path.exists():
            raise FileNotFoundError(f"Driver file not found: {self.driver_path}")
        
        if os.name == 'nt':
            self.analyze_headless = self.ghidra_path / "support" / "analyzeHeadless.bat"
        else:
            self.analyze_headless = self.ghidra_path / "support" / "analyzeHeadless"
            
        if not self.analyze_headless.exists():
            raise FileNotFoundError(f"analyzeHeadless not found: {self.analyze_headless}")
    
    def create_decompiler_script(self):
        """Create Ghidra Python script to decompile all functions to C code."""
        
        output_dir_python = str(self.output_dir).replace('\\', '/')
        
        script_content = f'''#Simple decompilation using built-in Ghidra decompiler
#@category Analysis
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os

# Output directory
output_dir = "{output_dir_python}"

# Create output directory
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

print("="*80)
print("DRIVER DECOMPILER (Python)")
print("="*80)
print("Driver: " + currentProgram.getName())
print("Output: " + output_dir)
print("")

# Initialize decompiler
decompiler = DecompInterface()
decompiler.openProgram(currentProgram)

# Get all functions
func_manager = currentProgram.getFunctionManager()
functions = func_manager.getFunctions(True)
total = func_manager.getFunctionCount()

print("[*] Decompiling " + str(total) + " functions...")

count = 0
for func in functions:
    count += 1
    
    if count % 50 == 0:
        print("    Progress: " + str(count) + "/" + str(total))
    
    try:
        func_name = func.getName()
        address = func.getEntryPoint().toString()
        
        # Decompile
        results = decompiler.decompileFunction(func, 30, ConsoleTaskMonitor())
        
        if results and results.decompileCompleted():
            c_code = results.getDecompiledFunction().getC()
            
            # Clean filename
            safe_name = func_name
            for ch in ['/', '\\\\', ':', '*', '?', '"', '<', '>', '|']:
                safe_name = safe_name.replace(ch, '_')
            
            # Save to file
            filepath = os.path.join(output_dir, safe_name + ".c")
            with open(filepath, 'w') as f:
                f.write("// Function: " + func_name + "\\n")
                f.write("// Address: " + address + "\\n")
                f.write("// Decompiled by Ghidra\\n")
                f.write("\\n")
                f.write(c_code)
    
    except Exception as e:
        # Continue on error
        pass

print("    Decompiled " + str(count) + " functions")

# Create summary
print("")
print("[*] Creating summary...")

summary_path = os.path.join(output_dir, "ANALYSIS_SUMMARY.txt")
with open(summary_path, 'w') as f:
    f.write("DRIVER ANALYSIS SUMMARY\\n")
    f.write("="*80 + "\\n\\n")
    f.write("Driver: " + currentProgram.getName() + "\\n")
    f.write("Total Functions: " + str(total) + "\\n\\n")
    f.write("="*80 + "\\n\\n")
    
    f.write("ALL FUNCTIONS:\\n")
    f.write("-"*80 + "\\n\\n")
    
    for func in func_manager.getFunctions(True):
        f.write(func.getName() + " @ " + func.getEntryPoint().toString() + "\\n")
    
    f.write("\\n" + "="*80 + "\\n\\n")
    
    f.write("IMPORTANT FUNCTIONS (Dispatch/IOCTL Related):\\n")
    f.write("-"*80 + "\\n\\n")
    
    for func in func_manager.getFunctions(True):
        name = func.getName().lower()
        if ("driverentry" in name or "dispatch" in name or 
            "ioctl" in name or "devicecontrol" in name or "irp" in name):
            
            safe_name = func.getName()
            for ch in ['/', '\\\\', ':', '*', '?', '"', '<', '>', '|']:
                safe_name = safe_name.replace(ch, '_')
            
            f.write("*** " + func.getName() + " @ " + func.getEntryPoint().toString() + "\\n")
            f.write("    File: " + safe_name + ".c\\n\\n")
    
    f.write("\\n" + "="*80 + "\\n\\n")
    f.write("NEXT STEPS:\\n")
    f.write("-"*80 + "\\n\\n")
    f.write("1. Review the functions marked with *** above\\n")
    f.write("2. Look for IOCTL handling patterns\\n")
    f.write("3. Search for hex constants (0x...)\\n")
    f.write("4. Use AI to analyze the C code\\n\\n")

print("    Summary saved!")

decompiler.dispose()

print("")
print("="*80)
print("DECOMPILATION COMPLETE")
print("="*80)
'''
        
        # Save as Python script (.py extension for Jython)
        script_path = self.temp_dir / "DecompileDriver.py"
        with open(script_path, 'w', encoding='utf-8') as f:
            f.write(script_content)
        
        # Also save copy in output for reference
        output_script = self.output_dir / "DecompileDriver.py"
        with open(output_script, 'w', encoding='utf-8') as f:
            f.write(script_content)
        
        return script_path
    
    def run_decompilation(self, script_path):
        """Run Ghidra decompilation."""
        print(f"\n[*] Running Ghidra decompilation...")
        print(f"    Driver: {self.driver_path}")
        print(f"    Output: {self.output_dir}")
        print(f"\n[*] This may take several minutes for large drivers...\n")
        
        cmd = [
            str(self.analyze_headless),
            str(self.temp_dir),
            self.project_name,
            "-import", str(self.driver_path),
            "-scriptPath", str(self.temp_dir),  # Tell Ghidra where to find scripts
            "-postScript", script_path.name,     # Use just the filename, not full path
            "-deleteProject"
        ]
        
        try:
            use_shell = (os.name == 'nt')
            
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=1800,  # 30 minute timeout for large drivers
                shell=use_shell
            )
            
            # Show progress
            for line in result.stdout.split('\n'):
                if any(keyword in line for keyword in ['DRIVER', 'Decompil', 'Progress', 'functions', 'Summary', 'COMPLETE']):
                    print(f"    {line}")
            
            # Save full log
            log_file = self.output_dir / "decompilation_log.txt"
            with open(log_file, 'w', encoding='utf-8') as f:
                f.write(result.stdout)
                f.write("\n\n=== STDERR ===\n")
                f.write(result.stderr)
            
            if result.returncode != 0:
                print(f"\n[!] Warning: Ghidra returned code {result.returncode}")
                print(f"[!] Check log: {log_file}")
            else:
                print(f"\n[+] Decompilation completed!")
            
            return result.returncode == 0
            
        except subprocess.TimeoutExpired:
            print("\n[!] Decompilation timed out (30 minutes)")
            return False
        except Exception as e:
            print(f"\n[!] Error: {e}")
            return False
    
    def create_ai_prompt(self):
        """Create a ready-to-use prompt for AI analysis."""
        
        summary_file = self.output_dir / "ANALYSIS_SUMMARY.txt"
        if not summary_file.exists():
            return
        
        prompt_file = self.output_dir / "AI_ANALYSIS_PROMPT.txt"
        
        with open(prompt_file, 'w') as f:
            f.write("=" * 80 + "\n")
            f.write("PROMPT FOR AI ANALYSIS\n")
            f.write("=" * 80 + "\n\n")
            
            f.write("Copy this prompt and the relevant C files to Claude/ChatGPT:\n\n")
            f.write("-" * 80 + "\n\n")
            
            f.write("""I have decompiled a Windows kernel driver and need help analyzing it to find IOCTL codes.

Please analyze the following decompiled C code and:
1. Identify all IOCTL codes (hex values like 0x9C402084)
2. Explain what each IOCTL does
3. Identify the dispatch function that handles IOCTLs
4. Show the control flow for IOCTL handling

Look for:
- Comparisons with hex constants (likely IOCTL codes)
- Switch/case statements with hex values
- IRP_MJ_DEVICE_CONTROL dispatch handlers
- CTL_CODE macro usage

Here are the important files to analyze:

""")
            
            # List important function files
            with open(summary_file, 'r') as sf:
                lines = sf.readlines()
                in_important = False
                for line in lines:
                    if "IMPORTANT FUNCTIONS" in line:
                        in_important = True
                    elif in_important and line.strip().startswith("***"):
                        f.write(line)
            
            f.write("\n")
            f.write("-" * 80 + "\n\n")
            f.write("After reviewing the summary, attach the C files mentioned above.\n")
        
        print(f"[+] AI prompt template created: {prompt_file}")
    
    def show_results(self):
        """Display results summary."""
        print(f"\n{'='*80}")
        print("DECOMPILATION RESULTS")
        print(f"{'='*80}\n")
        
        # Count C files
        c_files = list(self.output_dir.glob("*.c"))
        print(f"Total decompiled functions: {len(c_files)}")
        
        # Show summary if exists
        summary_file = self.output_dir / "ANALYSIS_SUMMARY.txt"
        if summary_file.exists():
            print(f"\n[+] Analysis summary: {summary_file}")
            print(f"[+] Review this file first to identify key functions\n")
            
            # Show important functions
            with open(summary_file, 'r') as f:
                lines = f.readlines()
                in_important = False
                print("Key functions to analyze:")
                print("-" * 80)
                for line in lines:
                    if "IMPORTANT FUNCTIONS" in line:
                        in_important = True
                    elif in_important and "===========" in line:
                        break
                    elif in_important and line.strip().startswith("***"):
                        print(line.strip())
        
        print(f"\n{'='*80}")
        print("NEXT STEPS:")
        print(f"{'='*80}")
        print(f"1. Review: {self.output_dir / 'ANALYSIS_SUMMARY.txt'}")
        print(f"2. Open the important .c files mentioned in the summary")
        print(f"3. Use AI to analyze them (see: {self.output_dir / 'AI_ANALYSIS_PROMPT.txt'})")
        print(f"4. Or manually search for hex constants in dispatch functions")
        print(f"\n[+] All files saved to: {self.output_dir}\n")
    
    def cleanup(self):
        try:
            if self.temp_dir.exists():
                shutil.rmtree(self.temp_dir)
        except:
            pass
    
    def decompile(self):
        """Main decompilation workflow."""
        try:
            print(f"[+] Driver Decompiler Starting...")
            print(f"[+] Target: {self.driver_path.name}")
            
            script_path = self.create_decompiler_script()
            print(f"[+] Created decompilation script")
            
            success = self.run_decompilation(script_path)
            
            if success:
                self.create_ai_prompt()
                self.show_results()
                return True
            else:
                print("\n[!] Decompilation failed")
                return False
                
        finally:
            self.cleanup()


def main():
    parser = argparse.ArgumentParser(
        description='Decompile Windows drivers to C source using Ghidra',
        epilog='Example: python decompiler.py -g C:\\ghidra_11.0_PUBLIC -d driver.sys'
    )
    
    parser.add_argument('-g', '--ghidra', required=True, help='Ghidra installation path')
    parser.add_argument('-d', '--driver', required=True, help='Driver file to decompile')
    parser.add_argument('-o', '--output', default=None, help='Output directory (default: ./decompiled_output)')
    
    args = parser.parse_args()
    
    try:
        decompiler = DriverDecompiler(args.ghidra, args.driver, args.output)
        success = decompiler.decompile()
        sys.exit(0 if success else 1)
    except Exception as e:
        print(f"\n[!] Fatal error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()
