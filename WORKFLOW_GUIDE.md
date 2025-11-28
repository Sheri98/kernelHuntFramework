# KernelHunt Framework - Complete Workflow Guide

**By Shravan Kumar Sheri (SSK)**

This guide explains the integrated workflow and how all components work together.

---

## 🎯 **Complete Analysis Workflow**

### **Unified 4-Step Pipeline:**

```
Driver.sys
    ↓
┌─────────────────────────────────────────────────────────────┐
│  STEP 1: Decompilation (driver_decompiler.py)              │
│  • Ghidra headless analysis                                │
│  • Extract all functions to .c files                       │
│  • Generate ANALYSIS_SUMMARY.txt                           │
└─────────────────────────────────────────────────────────────┘
    ↓
┌─────────────────────────────────────────────────────────────┐
│  STEP 2: IOCTL Extraction (ioctl_analyzer.py)              │
│  • Scan decompiled code for IOCTL patterns                 │
│  • Categorize by device type, method, access                │
│  • Output: extracted_ioctls.json                           │
└─────────────────────────────────────────────────────────────┘
    ↓
┌─────────────────────────────────────────────────────────────┐
│  STEP 3: HTML Report (html_report_generator.py)            │
│  • Count dangerous functions (40+ tracked)                  │
│  • Calculate security risk score                           │
│  • Generate visual dashboard                               │
│  • Output: security_report.html                            │
│            dangerous_functions.json                         │
└─────────────────────────────────────────────────────────────┘
    ↓
┌─────────────────────────────────────────────────────────────┐
│  STEP 4: Exploitation Primitives (exploit_primitive_detector.py) │
│  • Detect arbitrary read/write primitives                  │
│  • Find code execution vectors                             │
│  • Identify privilege escalation paths                     │
│  • Output: exploitation_primitives.json                    │
└─────────────────────────────────────────────────────────────┘
    ↓
COMPLETE ANALYSIS PACKAGE
```

---

## 📂 **Output Structure**

After analysis, each driver gets its own directory:

```
analysis_results/
└── driver_name/
    ├── *.c                              ← Decompiled functions (100-1000+ files)
    ├── ANALYSIS_SUMMARY.txt             ← Function listing
    ├── extracted_ioctls.json            ← IOCTL codes categorized
    ├── dangerous_functions.json         ← Vulnerable function calls
    ├── exploitation_primitives.json     ← Detected primitives
    └── security_report.html             ← Visual dashboard (OPEN THIS!)
```

---

## 🚀 **Usage Modes**

### **Mode 1: Single Driver Analysis (Recommended for Learning)**

```
kernelHuntFramework.exe
  ↓
Select [1] Analyze Driver (Complete)
  ↓
Enter driver path: C:\path\to\driver.sys
  ↓
Wait for 4-step analysis
  ↓
Open: analysis_results\driver\security_report.html
```

**Best for:**
- Learning how the framework works
- Deep analysis of specific drivers
- Testing new features

---

### **Mode 2: Batch Analysis (Recommended for Scale)**

**Step 1: Prepare driver.json**
```json
{
  "drivers": [
    "C:\\Windows\\System32\\drivers\\driver1.sys",
    "C:\\Windows\\System32\\drivers\\driver2.sys",
    "C:\\path\\to\\driver3.sys"
  ]
}
```

**Step 2: Run batch analysis**
```
kernelHuntFramework.exe
  ↓
Select [2] Batch Analysis
  ↓
Framework processes ALL drivers automatically
  ↓
View results in: analysis_results\*\security_report.html
```

**Best for:**
- Analyzing 10-100+ drivers
- Systematic vulnerability research
- Finding 0-days at scale

---

### **Mode 3: Individual Tool Usage (Advanced)**

You can also run each Python tool independently:

```bash
# Step 1: Decompile only
python driver_decompiler.py -g C:\ghidra_11.0_PUBLIC -d driver.sys -o output_dir

# Step 2: Extract IOCTLs only
python ioctl_analyzer.py -d output_dir

# Step 3: Generate report only
python html_report_generator.py -d output_dir

# Step 4: Detect primitives only
python exploit_primitive_detector.py -d output_dir
```

**Best for:**
- Re-running specific analysis steps
- Custom automation scripts
- Integration with other tools

---

## 🎨 **Menu Options Explained**

### **[1] Analyze Driver (Complete)**
- Runs all 4 steps on a single driver
- Interactive: asks for driver path
- Shows progress for each step
- Displays final results summary

### **[2] Batch Analysis**
- Reads drivers from `driver.json`
- Runs all 4 steps on each driver
- Tracks: Successful / Partial / Failed
- Final summary with statistics

### **[3] Generate HTML Report**
- Standalone report generation
- Use on existing analysis directories
- Good for re-generating after updates

### **[4] Detect Exploit Primitives**
- Standalone primitive detection
- Scans decompiled code for vulnerabilities
- Can run multiple times on same driver

### **[5] Live IOCTL Fuzzer**
- **Windows only** - requires driver loaded
- Real-time testing with DeviceIoControl()
- Fuzzes all IOCTL codes with various buffer sizes
- Analyzes error codes for valid IOCTLs

### **[6] Enumerate Third-Party Drivers**
- Scans system for loaded drivers
- Identifies third-party (non-Microsoft) drivers
- Exports to JSON for batch analysis

### **[7] Process Security Checker**
- Checks process privileges
- Views security descriptors
- Integrity level analysis
- Useful for understanding process context

### **[8] About / Credits**
- Framework information
- Feature overview
- Research focus areas

---

## 📊 **Understanding the HTML Report**

### **Dashboard Sections:**

1. **Security Score Card**
   - 0-100 risk score (lower = safer)
   - Color-coded: GREEN, YELLOW, ORANGE, RED
   - Based on: IOCTLs + dangerous functions + METHOD_NEITHER

2. **IOCTLs by Transfer Method**
   - METHOD_BUFFERED (safest)
   - METHOD_IN_DIRECT, METHOD_OUT_DIRECT (safer)
   - METHOD_NEITHER (most dangerous!)

3. **IOCTLs by Device Type**
   - Groups by device type (0x0001, 0x9C, etc.)
   - Shows distribution

4. **Dangerous Functions**
   - **CRITICAL**: MmMapIoSpace, __writemsr, etc.
   - **HIGH**: memcpy, strcpy, ProbeForWrite
   - **MEDIUM**: ExAllocatePool, etc.

5. **Complete IOCTL Table**
   - All IOCTLs with full details
   - Sortable reference

---

## 🎯 **Workflow Best Practices**

### **For Systematic Research:**

1. **Collect Drivers**
   ```
   • Download from hardware vendors
   • Extract from installers
   • Use Windows driver store
   • Check loldrivers.io for known-vulnerable
   ```

2. **Batch Analyze**
   ```
   • Add all to driver.json
   • Run batch analysis overnight
   • Sort results by security score
   ```

3. **Prioritize High-Risk Drivers**
   ```
   • Score 70+: CRITICAL
   • Look for exploitation primitives
   • Focus manual analysis here
   ```

4. **Deep Dive**
   ```
   • Review HTML report
   • Check exploitation_primitives.json
   • Examine decompiled .c files
   • Look for vulnerable IOCTL handlers
   ```

5. **Develop Exploits**
   ```
   • Use live fuzzer to test IOCTLs
   • Confirm primitives (read/write/exec)
   • Write PoC exploit
   • Responsible disclosure
   ```

---

## 🔧 **Configuration**

### **Update Paths in rundriverDecompiler.cpp:**

```cpp
// Line 123-126
string baseDir = "C:\\Your\\Path\\Here";  // UPDATE THIS!
string ghidraPath = "C:\\ghidra_11.0_PUBLIC";  // UPDATE THIS!
```

### **Update Paths in kernelHuntFramework.cpp:**

```cpp
// Line 84 (analyzeSingleDriver function)
string cmd1 = "python driver_decompiler.py -g C:\\ghidra_11.0_PUBLIC ...";
                                              ^^^^^^^^^^^^^^^^^^^^ UPDATE THIS!
```

---

## ⚡ **Performance Tips**

### **Speed Up Analysis:**

1. **Use SSD storage** for analysis_results directory
2. **Close unnecessary programs** during Ghidra analysis
3. **Batch analyze overnight** for large datasets
4. **Skip Step 4** if not hunting primitives (comment out in rundriverDecompiler.cpp)

### **Reduce False Positives:**

1. **Review IOCTL context** - many are jump addresses (known issue)
2. **Focus on METHOD_NEITHER** IOCTLs (most dangerous)
3. **Cross-reference dangerous functions** with IOCTL handlers
4. **Manual code review** is still required for confirmation

---

## 🐛 **Troubleshooting**

### **"Decompilation failed"**
- Check Ghidra path is correct
- Ensure driver file exists
- Run as Administrator
- Check disk space

### **"No IOCTLs found"**
- Normal for some drivers (no IOCTLs)
- May be false negatives (regex limitations)
- Check decompiled code manually

### **"HTML report shows 0 vulnerabilities"**
- Driver may be secure
- Or decompilation incomplete
- Check dangerous_functions.json directly

### **"Python script not found"**
- Ensure all .py files in same directory as .exe
- Use absolute paths in C++ code
- Check Python is in PATH

---

## 📈 **Next Steps**

After mastering the workflow:

1. **Implement advanced features** from ADVANCED_FEATURES_ROADMAP.md
2. **Fix IOCTL false positives** (context-based validation)
3. **Add control flow analysis** (track user input → dangerous sinks)
4. **Integrate fuzzing** with automated crash analysis
5. **Build vulnerability database** from your findings

---

## 🎓 **Example Analysis Session**

```
1. Download vulnerable driver (e.g., cpuz141.sys)
2. Run: kernelHuntFramework.exe → [1] Analyze Driver
3. Enter path: C:\drivers\cpuz141.sys
4. Wait ~5-10 minutes for analysis
5. Open: analysis_results\cpuz141\security_report.html

FINDINGS:
✓ Security Score: 100/100 (CRITICAL!)
✓ 59 IOCTLs found
✓ 54 dangerous functions
✓ 2 CRITICAL exploitation primitives:
  - MmMapIoSpace with user-controlled address
  - No privilege checks before dangerous ops

6. Review exploitation_primitives.json
7. Examine decompiled IOCTL handlers
8. Test with live fuzzer: [5] Live IOCTL Fuzzer
9. Develop exploit PoC
10. Responsible disclosure to vendor
```

---

## 🏆 **Success Criteria**

You're using the framework effectively when:

✅ You can analyze 10+ drivers per hour (batch mode)
✅ You understand the security score calculation
✅ You can identify exploitation primitives from reports
✅ You prioritize manual analysis on high-risk drivers
✅ You've found at least one real vulnerability

---

**Happy hunting! - Shravan Kumar Sheri (SSK)**

*For issues: https://github.com/Sheri98/kernelHuntFramework/issues*
