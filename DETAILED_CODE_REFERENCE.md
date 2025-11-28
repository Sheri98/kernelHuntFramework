# KernelHuntFramework - Detailed Code Reference

## File Inventory

| File | Lines | Purpose |
|------|-------|---------|
| `driver_decompiler.py` | 378 | Ghidra-based driver decompilation |
| `ioctl_analyzer.py` | 227 | IOCTL pattern extraction and analysis |
| `ioctMain.cpp` | 123 | IOCTL fuzzing (C++ runtime) |
| `driverEnum.cpp` | 295 | Driver enumeration utilities |
| `kernelHuntFramework.cpp` | 36 | Main menu/entry point |
| `rundriverDecompiler.cpp` | 202 | Ghidra invocation wrapper |

---

## DETAILED CODE REFERENCE

### 1. IOCTL Counting & Extraction
**File:** `/home/user/kernelHuntFramework/ioctl_analyzer.py`

#### Entry Point
```python
# Lines 23-35: Main analyze method
def analyze(self):
    """Analyze all decompiled C files for IOCTL codes."""
    print(f"\n[*] Analyzing decompiled code in: {self.decompiled_dir}")
    print(f"[*] Searching for IOCTL patterns...\n")
    
    c_files = list(self.decompiled_dir.glob("*.c"))
    print(f"[*] Found {len(c_files)} C files to analyze")  # LINE 29 - COUNT FILES
    
    for c_file in c_files:
        self.analyze_file(c_file)
    
    self.save_results()      # LINE 34 - SAVES JSON WITH COUNTS
    self.display_results()   # LINE 35 - DISPLAYS TO CONSOLE
```

#### IOCTL Validation Logic (Critical for counting)
```python
# Lines 72-90: Validation function - filters which hex values are actual IOCTLs
def is_likely_ioctl(self, value):
    """Check if a value looks like an IOCTL code."""
    if value < 0x10000 or value > 0xFFFFFFFF:
        return False
    
    # IOCTL STRUCTURE BREAKDOWN:
    # Bits 31-16: Device Type
    # Bits 15-14: Access Type  
    # Bits 13-2: Function Code
    # Bits 1-0: Method
    
    device_type = (value >> 16) & 0xFFFF   # LINE 78 - Extract bits 31-16
    method = value & 0x3                   # LINE 79 - Extract bits 1-0
    function_code = (value >> 2) & 0xFFF   # LINE 80 - Extract bits 13-2
    
    # VALIDATION RULES:
    if device_type == 0 or device_type > 0xFFFF:  # LINE 83-84
        return False
    if method > 3:                                  # LINE 85-86
        return False
    if function_code == 0:                          # LINE 87-88
        return False
    
    return True  # LINE 90 - PASSED VALIDATION - COUNT THIS
```

#### Categorization During Save
```python
# Lines 92-123: save_results() - WHERE IOCTLS ARE CATEGORIZED
def save_results(self):
    """Save results to JSON."""
    output_file = self.decompiled_dir / "extracted_ioctls.json"
    
    results = {
        'total_ioctls': len(self.ioctls),  # LINE 97 - TOTAL COUNT
        'ioctls': []
    }
    
    for ioctl_code, locations in sorted(self.ioctls.items()):
        value = locations[0]['value']
        
        # EXTRACT CATEGORIZATION FIELDS:
        device_type = (value >> 16) & 0xFFFF        # LINE 104 - DEVICE TYPE
        access = (value >> 14) & 0x3                 # LINE 105 - ACCESS BITS
        function = (value >> 2) & 0xFFF              # LINE 106 - FUNCTION CODE
        method = value & 0x3                         # LINE 107 - METHOD (0-3)
        
        # BUILD JSON ENTRY WITH ALL CATEGORIZATION:
        results['ioctls'].append({
            'code': ioctl_hex,                           # LINE 110 - HEX CODE
            'decimal': value,                            # LINE 111 - DECIMAL
            'device_type': f"0x{device_type:04X}",      # LINE 112 - CATEGORIZED
            'function_code': f"0x{function:03X}",       # LINE 113 - CATEGORIZED
            'method': method,                            # LINE 114 - CATEGORIZED (0-3)
            'access': access,                            # LINE 115 - CATEGORIZED (0-3)
            'found_in': [loc['file'] for loc in locations],  # LINE 116
            'contexts': [loc['context'] for loc in locations[:3]]  # LINE 117
        })
    
    with open(output_file, 'w') as f:
        json.dump(results, f, indent=2)  # LINE 120-121 - SAVES TO JSON
```

#### Display/Mapping of Categories
```python
# Lines 125-155: display_results() - HOW CATEGORIES ARE NAMED
def display_results(self):
    """Display found IOCTLs."""
    print(f"\nTotal unique IOCTL codes: {len(self.ioctls)}\n")  # LINE 136 - COUNT
    
    # METHOD TYPE NAMES (indexed 0-3):
    method_names = ["METHOD_BUFFERED",       # 0 - Safe, copies data
                    "METHOD_IN_DIRECT",      # 1 - Input via DMA
                    "METHOD_OUT_DIRECT",     # 2 - Output via DMA
                    "METHOD_NEITHER"]        # 3 - DANGEROUS, direct pointer
    
    # ACCESS TYPE NAMES (indexed 0-3):
    access_names = ["FILE_ANY_ACCESS",       # 0 - No privilege required
                    "FILE_READ_ACCESS",      # 1 - Read privilege
                    "FILE_WRITE_ACCESS",     # 2 - Write privilege
                    "FILE_READ_WRITE_ACCESS"]# 3 - Full access required
    
    # DISPLAY EACH IOCTL WITH CATEGORIZATION:
    for i, (ioctl_code, locations) in enumerate(sorted(self.ioctls.items()), 1):
        value = locations[0]['value']
        
        device_type = (value >> 16) & 0xFFFF
        access = (value >> 14) & 0x3
        function = (value >> 2) & 0xFFF
        method = value & 0x3
        
        # OUTPUT CATEGORIES:
        print(f"[{i}] {ioctl_code} (decimal: {value})")
        print(f"    Device Type:   0x{device_type:04X}")      # LINE 150
        print(f"    Function Code: 0x{function:03X}")         # LINE 151
        print(f"    Method:        {method_names[method]}")   # LINE 152 - NAME LOOKUP
        print(f"    Access:        {access_names[access]}")   # LINE 153 - NAME LOOKUP
        print(f"    Found in:      {', '.join(...)}")         # LINE 154
```

---

### 2. Function Counting & Important Function Detection
**File:** `/home/user/kernelHuntFramework/driver_decompiler.py`

#### Initial Function Count (from Ghidra)
```python
# Lines 70-75: Counting total functions during decompilation script generation
print("[*] Decompiling " + str(total) + " functions...")  # LINE 75

# In the generated Ghidra script (nested Python):
# Line 73 in NESTED SCRIPT (inside create_decompiler_script):
total = func_manager.getFunctionCount()  # GET TOTAL COUNT FROM GHIDRA
```

#### Important Function Detection
```python
# Lines 137-147: Filtering for important dispatch/IOCTL functions
for func in func_manager.getFunctions(True):
    name = func.getName().lower()
    
    # CATEGORIZATION FILTER:
    if ("driverentry" in name or      # Category 1: Initialization
        "dispatch" in name or          # Category 2: IRP Handler
        "ioctl" in name or             # Category 3: IOCTL Handler
        "devicecontrol" in name or     # Category 4: Device Control
        "irp" in name):                # Category 5: IRP-related
        
        # MARK AS IMPORTANT:
        f.write("*** " + func.getName() + " @ " + func.getEntryPoint().toString() + "\\n")
        f.write("    File: " + safe_name + ".c\\n\\n")
```

#### Result Counting
```python
# Lines 291-293: Count decompiled output files
c_files = list(self.output_dir.glob("*.c"))
print(f"Total decompiled functions: {len(c_files)}")  # LINE 293
```

---

### 3. Data Output Structures

#### ANALYSIS_SUMMARY.txt Structure
**Location:** `/home/user/kernelHuntFramework/analysis_results/BdApiUtil64/ANALYSIS_SUMMARY.txt`
**Generated by:** driver_decompiler.py, Lines 120-155

```
Lines 1-2:    Header: "DRIVER ANALYSIS SUMMARY"
Lines 4-5:    "Driver: <name>" and "Total Functions: 166"
Lines 9-98:   LIST OF ALL FUNCTIONS
              Format: "<function_name> @ <address>"
Lines 101-104: IMPORTANT FUNCTIONS section (categorized functions)
              Format: "*** <function_name> @ <address>" + File reference
```

#### extracted_ioctls.json Structure
**Location:** `/home/user/kernelHuntFramework/analysis_results/BdApiUtil64/extracted_ioctls.json`
**Generated by:** ioctl_analyzer.py, Lines 92-121

```json
{
  "total_ioctls": <integer count>,
  "ioctls": [
    {
      "code": "0xHHHHHHHH",              // Hex format
      "decimal": <integer>,               // Decimal value
      "device_type": "0xXXXX",           // Upper 16 bits
      "function_code": "0xXXX",          // Bits 13-2
      "method": <0-3>,                   // Bits 1-0: {BUFFERED, IN_DIRECT, OUT_DIRECT, NEITHER}
      "access": <0-3>,                   // Bits 15-14: {ANY, READ, WRITE, READ_WRITE}
      "found_in": ["file.c", ...],       // Source files
      "contexts": ["code snippet", ...]  // Code context
    }
  ]
}
```

**Example Entry from BdApiUtil64:**
```json
{
  "code": "0x00010EC7",
  "decimal": 69319,
  "device_type": "0x0001",
  "function_code": "0x3B1",
  "method": 3,
  "access": 0,
  "found_in": ["FUN_00010eb0.c"],
  "contexts": ["ram_1) { ExGetPreviousMode();..."]
}
```

**Statistics from BdApiUtil64 example:**
- Total functions decompiled: 166
- Total IOCTLs extracted: 142
- Primary device type: 0x0001

---

### 4. Critical Counting Issues Found

#### Issue #1: Empty "Important Functions" Section
**File:** `/home/user/kernelHuntFramework/analysis_results/BdApiUtil64/ANALYSIS_SUMMARY.txt`
**Lines:** 101-104
**Problem:** Section exists but contains NO entries
```
================================================================================

IMPORTANT FUNCTIONS (Dispatch/IOCTL Related):
--------------------------------------------------------------------------------


================================================================================
```
**Root Cause:** The filter in driver_decompiler.py (Lines 139-140) searches for keywords
but the driver binary doesn't have function names matching those patterns.
This might indicate:
1. Ghidra decompiler failed to identify function names
2. Important functions were stripped from binary
3. Functions have non-standard naming conventions

#### Issue #2: Missing Dangerous Function Detection
**Status:** NOT IMPLEMENTED
**Should be:** In HTML report generator (MISSING)
**Required Data:**
- Dangerous functions list (40+ functions)
- Function categories (Memory, MSR, Port I/O, Buffer)
- Severity scoring (CRITICAL, HIGH, MEDIUM, LOW)
- CWE/CVE references

#### Issue #3: No Security Score Calculation
**Status:** NOT IMPLEMENTED
**Should compute:**
- IOCTL risk scoring based on:
  * METHOD_NEITHER (riskiest) vs METHOD_BUFFERED (safest)
  * FILE_ANY_ACCESS (highest risk) vs FILE_READ_WRITE_ACCESS
- Dangerous function risk multipliers
- Overall driver security score (0-100)

---

### 5. Data Flow Visualization

```
INPUT: Driver Binary (.sys file)
    |
    v
[1] driver_decompiler.py
    |
    +-- Ghidra Headless Analysis
    |   +-- Extract all functions
    |   |   (Line 73: total = func_manager.getFunctionCount())
    |   |
    |   +-- Decompile each function
    |   |   (Lines 79-110: iterate and save as .c files)
    |   |
    |   +-- Output: Counts decompiled functions
    |       (Line 293: c_files = list(self.output_dir.glob("*.c")))
    |
    +-- ANALYSIS_SUMMARY.txt (Lines 120-155)
    |   Contains:
    |   - Total Functions: 166
    |   - List of all functions
    |   - Important functions (if detected)
    |
    v
[2] ioctl_analyzer.py
    |
    +-- Scan decompiled .c files
    |   (Line 29: c_files = list(...))
    |
    +-- Extract hex constants
    |   (Line 45: r'(?:0x|0X)([0-9A-Fa-f]{6,8})\b')
    |
    +-- Validate IOCTL structure
    |   (Lines 77-88: device_type, method, function_code)
    |
    +-- Categorize each IOCTL
    |   (Lines 104-107: extract bits for categorization)
    |
    v
OUTPUT: extracted_ioctls.json
    Contains:
    - total_ioctls: 142
    - Each IOCTL categorized by:
      * device_type (bits 31-16)
      * method (bits 1-0): 0=BUFFERED, 1=IN_DIRECT, 2=OUT_DIRECT, 3=NEITHER
      * access (bits 15-14): 0=ANY, 1=READ, 2=WRITE, 3=READ_WRITE
      * function_code (bits 13-2)
      * found_in: source files
      * contexts: code snippets
    |
    v
[MISSING] html_report_generator.py
    Should:
    1. Load extracted_ioctls.json
    2. Detect dangerous functions in .c files
    3. Calculate security score
    4. Generate HTML dashboard with:
       - Security score card
       - IOCTL analysis by category
       - Dangerous functions list
       - Risk assessment
    |
    v
OUTPUT (MISSING): 
    - security_report.html
    - dangerous_functions.json
    - fuzzing_wordlist.txt
```

---

### 6. Specific Line References for Key Operations

#### Counting Operations:

| Operation | File | Lines | Description |
|-----------|------|-------|-------------|
| Get total functions | driver_decompiler.py | 73 | Ghidra function count |
| Count decompiled files | driver_decompiler.py | 291-293 | Count .c output files |
| Count C files to analyze | ioctl_analyzer.py | 29 | Count input .c files |
| Count valid IOCTLs | ioctl_analyzer.py | 97 | JSON total_ioctls |
| Iterate IOCTLs for display | ioctl_analyzer.py | 141 | Enumerate sorted IOCTLs |

#### Categorization Operations:

| Category | File | Lines | Bit Extraction |
|----------|------|-------|-----------------|
| Device Type | ioctl_analyzer.py | 78, 104 | (value >> 16) & 0xFFFF |
| Method | ioctl_analyzer.py | 79, 107 | value & 0x3 |
| Function Code | ioctl_analyzer.py | 80, 106 | (value >> 2) & 0xFFF |
| Access | ioctl_analyzer.py | 105 | (value >> 14) & 0x3 |
| Important Functions | driver_decompiler.py | 139-140 | Keyword matching |

---

## Summary Table: What Exists vs. What's Missing

| Component | Status | Location | Lines |
|-----------|--------|----------|-------|
| Function Decompilation | COMPLETE | driver_decompiler.py | 1-378 |
| Function Counting | COMPLETE | driver_decompiler.py | 73, 291-293 |
| IOCTL Extraction | COMPLETE | ioctl_analyzer.py | 37-70 |
| IOCTL Categorization | COMPLETE | ioctl_analyzer.py | 72-123 |
| IOCTL Display | COMPLETE | ioctl_analyzer.py | 125-155 |
| JSON Output | COMPLETE | ioctl_analyzer.py | 92-121 |
| **HTML Report Generation** | **MISSING** | **N/A** | **N/A** |
| **Dangerous Function Detection** | **MISSING** | **N/A** | **N/A** |
| **Security Scoring** | **MISSING** | **N/A** | **N/A** |

