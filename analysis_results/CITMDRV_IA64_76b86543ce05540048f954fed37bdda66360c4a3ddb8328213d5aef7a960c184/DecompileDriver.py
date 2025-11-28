#Simple decompilation using built-in Ghidra decompiler
#@category Analysis
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os

# Output directory
output_dir = "C:/Users/MalwareDevelopment/Desktop/kernelHuntFramework/kernelHuntFramework-master/analysis_results/CITMDRV_IA64_76b86543ce05540048f954fed37bdda66360c4a3ddb8328213d5aef7a960c184"

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
            for ch in ['/', '\\', ':', '*', '?', '"', '<', '>', '|']:
                safe_name = safe_name.replace(ch, '_')
            
            # Save to file
            filepath = os.path.join(output_dir, safe_name + ".c")
            with open(filepath, 'w') as f:
                f.write("// Function: " + func_name + "\n")
                f.write("// Address: " + address + "\n")
                f.write("// Decompiled by Ghidra\n")
                f.write("\n")
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
    f.write("DRIVER ANALYSIS SUMMARY\n")
    f.write("="*80 + "\n\n")
    f.write("Driver: " + currentProgram.getName() + "\n")
    f.write("Total Functions: " + str(total) + "\n\n")
    f.write("="*80 + "\n\n")
    
    f.write("ALL FUNCTIONS:\n")
    f.write("-"*80 + "\n\n")
    
    for func in func_manager.getFunctions(True):
        f.write(func.getName() + " @ " + func.getEntryPoint().toString() + "\n")
    
    f.write("\n" + "="*80 + "\n\n")
    
    f.write("IMPORTANT FUNCTIONS (Dispatch/IOCTL Related):\n")
    f.write("-"*80 + "\n\n")
    
    for func in func_manager.getFunctions(True):
        name = func.getName().lower()
        if ("driverentry" in name or "dispatch" in name or 
            "ioctl" in name or "devicecontrol" in name or "irp" in name):
            
            safe_name = func.getName()
            for ch in ['/', '\\', ':', '*', '?', '"', '<', '>', '|']:
                safe_name = safe_name.replace(ch, '_')
            
            f.write("*** " + func.getName() + " @ " + func.getEntryPoint().toString() + "\n")
            f.write("    File: " + safe_name + ".c\n\n")
    
    f.write("\n" + "="*80 + "\n\n")
    f.write("NEXT STEPS:\n")
    f.write("-"*80 + "\n\n")
    f.write("1. Review the functions marked with *** above\n")
    f.write("2. Look for IOCTL handling patterns\n")
    f.write("3. Search for hex constants (0x...)\n")
    f.write("4. Use AI to analyze the C code\n\n")

print("    Summary saved!")

decompiler.dispose()

print("")
print("="*80)
print("DECOMPILATION COMPLETE")
print("="*80)
