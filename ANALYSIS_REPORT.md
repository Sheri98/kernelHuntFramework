# KernelHuntFramework - HTML Report Generation Analysis

## Executive Summary

The KernelHuntFramework codebase currently **lacks a complete HTML report generator**, despite it being prominently featured in the README. The analysis pipeline collects data through decompilation and IOCTL extraction, but the final HTML report component referenced in troubleshooting section (`html_report_generator.py`) does not exist in the repository.

## Current Architecture

### 1. Data Flow
```
Driver File (.sys)
    ↓
driver_decompiler.py (Decompilation via Ghidra)
    ↓
Decompiled C Functions (*.c files)
    ↓
ioctl_analyzer.py (IOCTL Pattern Extraction)
    ↓
extracted_ioctls.json (Structured IOCTL Data)
    ↓
[MISSING] HTML Report Generator
    ↓
security_report.html (Mentioned but doesn't exist)
```

---

## Key Source Files

### 1. driver_decompiler.py (378 lines)
**Location:** `/home/user/kernelHuntFramework/driver_decompiler.py`

#### Key Functions:
- **`DriverDecompiler.__init__()` (Lines 15-24)**
  - Initializes paths and validates Ghidra installation
  
- **`create_decompiler_script()` (Lines 41-177)**
  - Generates Ghidra Python script for decompilation
  - Saves to `/output_dir/DecompileDriver.py`
  - **Analysis Note:** Counts functions at line 73: `total = func_manager.getFunctionCount()`

- **`run_decompilation()` (Lines 179-232)**
  - Executes Ghidra headless analysis
  - **Line 209:** Filters output by keywords like "DRIVER", "Decompil", "Progress", "functions"

- **`show_results()` (Lines 285-322)**
  - Displays decompilation summary
  - **Line 291-293:** Counts C files (decompiled functions)

#### Important Counting Logic:
```python
# Line 73 - Total function count from Ghidra
total = func_manager.getFunctionCount()

# Line 291-293 - Count of successfully decompiled functions
c_files = list(self.output_dir.glob("*.c"))
print(f"Total decompiled functions: {len(c_files)}")
```

#### Output Files Generated:
1. `ANALYSIS_SUMMARY.txt` - Text summary (Lines 120-155)
2. `AI_ANALYSIS_PROMPT.txt` - AI analysis template (Lines 243-281)
3. `decompilation_log.txt` - Full Ghidra output
4. Individual `*.c` files - Decompiled C source

---

### 2. ioctl_analyzer.py (227 lines)
**Location:** `/home/user/kernelHuntFramework/ioctl_analyzer.py`

#### Key Functions:

##### A. IOCTLAnalyzer Class
- **`__init__()` (Lines 15-21)** - Initialize with decompiled directory
- **`analyze()` (Lines 23-35)** - Main analysis entry point
  - Counts C files: Line 29
  - Calls `analyze_file()` for each

- **`analyze_file()` (Lines 37-70)** 
  - Regex pattern at line 45: `r'(?:0x|0X)([0-9A-Fa-f]{6,8})\b'`
  - Validates IOCTL structure with `is_likely_ioctl()`

- **`is_likely_ioctl()` (Lines 72-90)** - **IOCTL Validation Logic**
  ```
  IOCTL Structure Breakdown (Lines 77-88):
  - Device Type: (value >> 16) & 0xFFFF
  - Method: value & 0x3 (values 0-3)
  - Function Code: (value >> 2) & 0xFFF
  
  Validation Rules:
  - Device Type: must be 1-0xFFFF (not 0)
  - Method: must be 0-3
  - Function Code: must be non-zero
  ```

##### B. Data Extraction & Saving (Lines 92-123)
**`save_results()` - JSON Output Structure**

Saves to `extracted_ioctls.json` with:
```json
{
  "total_ioctls": <COUNT>,
  "ioctls": [
    {
      "code": "0xHHHHHHHH",
      "decimal": <DEC_VALUE>,
      "device_type": "0xXXXX",
      "function_code": "0xXXX",
      "method": 0-3,
      "access": 0-3,
      "found_in": ["file1.c", "file2.c"],
      "contexts": ["surrounding code snippet"]
    }
  ]
}
```

##### C. Display & Analysis (Lines 125-201)
- **`display_results()` (Lines 125-155)** - Console output
  - Line 136: Total unique IOCTL count
  - Lines 138-139: Method/Access name mappings
  
  **Method Types:**
  ```
  0 = METHOD_BUFFERED
  1 = METHOD_IN_DIRECT
  2 = METHOD_OUT_DIRECT
  3 = METHOD_NEITHER
  ```
  
  **Access Types:**
  ```
  0 = FILE_ANY_ACCESS
  1 = FILE_READ_ACCESS
  2 = FILE_WRITE_ACCESS
  3 = FILE_READ_WRITE_ACCESS
  ```

- **`create_ai_analysis_file()` (Lines 157-200)**
  - Creates `FOR_AI_ANALYSIS.txt` for AI processing
  - Filters files by dispatch/IOCTL keywords (Line 167)

---

## Data Analysis Examples

### Sample IOCTL Structure (from extracted_ioctls.json)

**File:** `/home/user/kernelHuntFramework/analysis_results/BdApiUtil64/extracted_ioctls.json`

Example IOCTL entry:
```json
{
  "code": "0x00010EC7",
  "decimal": 69319,
  "device_type": "0x0001",
  "function_code": "0x3B1",
  "method": 3,              // METHOD_NEITHER
  "access": 0,              // FILE_ANY_ACCESS
  "found_in": ["FUN_00010eb0.c"],
  "contexts": ["ram_1) { ExGetPreviousMode()..."]
}
```

**Statistics:**
- **Total IOCTLs Found:** 142 (in BdApiUtil64.sys example)
- **Device Types:** Primarily 0x0001
- **Method Distribution:** Spread across METHOD_NEITHER (3), METHOD_OUT_DIRECT (2), METHOD_IN_DIRECT (1)

---

## Missing Components

### 1. HTML Report Generator (MISSING - Branch Purpose)

**Referenced in README (Line 153-155):**
```bash
# Use updated html_report_generator.py
python html_report_generator.py -d analysis_results/driver_name
```

**Expected Output Files (README Lines 98-103):**
- `security_report.html` - Main visual dashboard
- `dangerous_functions.json` - Exploitable functions found
- `fuzzing_wordlist.txt` - Structure-aware test inputs

### 2. Dangerous Function Detection (MISSING)

**Referenced in README (Lines 125-134):**
- Should detect 40+ dangerous functions
- Categories: Memory Access, MSR Access, Port I/O, Buffer Operations
- Examples: `MmMapIoSpace`, `__writemsr`, `WRITE_PORT_UCHAR`, `memcpy`

**No Code Found For:**
- Function dangerous-ness scoring
- CWE mapping
- Severity categorization

### 3. Security Scoring (MISSING)

**Referenced in README (Line 33):**
- Security Score (0-100)
- Risk level assessment
- Critical issues counting

---

## Categorization & Compartmentalization

### Current Implementation

#### 1. IOCTL Categorization (ioctl_analyzer.py)

**Extraction Points:**

1. **By Device Type** (Line 104)
   ```python
   device_type = (value >> 16) & 0xFFFF
   ```
   - Groups IOCTLs by device (e.g., 0x0001, 0x0002, etc.)

2. **By Method Type** (Line 107)
   ```python
   method = value & 0x3
   # 0: METHOD_BUFFERED (copies data to/from kernel buffer)
   # 1: METHOD_IN_DIRECT (input via DMA)
   # 2: METHOD_OUT_DIRECT (output via DMA)
   # 3: METHOD_NEITHER (direct pointer passing - most dangerous)
   ```

3. **By Access Requirements** (Line 105)
   ```python
   access = (value >> 14) & 0x3
   # 0: FILE_ANY_ACCESS (no privilege check)
   # 1: FILE_READ_ACCESS
   # 2: FILE_WRITE_ACCESS
   # 3: FILE_READ_WRITE_ACCESS
   ```

4. **By Function Code** (Line 106)
   ```python
   function = (value >> 2) & 0xFFF
   # Unique operation identifier within device
   ```

#### 2. Function Categorization (driver_decompiler.py)

**Important Function Detection (Lines 137-147):**
```python
name = func.getName().lower()
if ("driverentry" in name or "dispatch" in name or 
    "ioctl" in name or "devicecontrol" in name or "irp" in name):
    # Mark as important for analysis
    f.write("*** " + func.getName() + ...)
```

**Categories Detected:**
- DriverEntry (driver initialization)
- Dispatch (IRP handler)
- IOCTL (control code handler)
- DeviceControl (device operations)
- IRP (I/O Request Packet)

---

## Analysis Results Structure

### Analysis Results Directory
```
analysis_results/
├── BdApiUtil64/
│   ├── ANALYSIS_SUMMARY.txt
│   │   ├── Total Functions: 166
│   │   ├── All Functions List
│   │   └── Important Functions: (empty for BdApiUtil64)
│   ├── extracted_ioctls.json
│   │   └── 142 unique IOCTLs
│   ├── FOR_AI_ANALYSIS.txt
│   ├── FUN_*.c (decompiled functions)
│   └── decompilation_log.txt
│
└── cpuz141/
    ├── ANALYSIS_SUMMARY.txt
    │   └── Total Functions: ~25
    ├── extracted_ioctls.json
    └── [similar structure]
```

---

## Critical Issues & Gaps

### Issue 1: Missing HTML Report Generator
**Severity:** HIGH
- Branch name indicates this is the primary fix needed
- README references non-existent `html_report_generator.py`
- Counters showing 0 issue (README Line 149-151) requires this tool

### Issue 2: No Dangerous Function Detection
**Severity:** HIGH
- README promises 40+ dangerous function detection
- No code implements this analysis
- Would require:
  - Function name matching against known dangerous functions
  - CWE/CVSS scoring
  - Risk assessment

### Issue 3: Data Counting Issues
**Severity:** MEDIUM
- IOCTL counting: ✓ Implemented (total_ioctls in JSON)
- Function counting: ✓ Implemented (via Ghidra)
- Dangerous function counting: ✗ Missing
- Risk scoring: ✗ Missing

### Issue 4: Important Functions Not Being Detected
**Severity:** MEDIUM
- ANALYSIS_SUMMARY.txt shows "IMPORTANT FUNCTIONS" section empty for BdApiUtil64
- Decompiler filters for keywords but no "dispatch" functions found
- May indicate:
  1. No such functions in binary
  2. Functions have different naming
  3. Decompiler didn't extract them properly

---

## Data Flow for HTML Report Generation

### What Exists (Ready for Report Generation):

1. **extracted_ioctls.json**
   - 142 IOCTLs in BdApiUtil64 example
   - All categorized by: method, access, device_type, function_code
   - File locations and code context included

2. **ANALYSIS_SUMMARY.txt**
   - Function count: 166 total functions
   - Important functions list (if identified)

3. **Decompiled C Files**
   - Source code for detailed analysis
   - Risk indicators in code (e.g., memcpy, MmMapIoSpace mentions)

### What's Needed for HTML Report:

1. **HTML Template Generation**
   - Dashboard with security score card
   - IOCTL cards showing: code, method, access, file location
   - Dangerous function summary
   - Risk heat map

2. **Vulnerable Function Detection**
   - Regex/keyword matching in decompiled C files
   - Classification by severity
   - CVSS/CWE tagging

3. **Risk Aggregation**
   - Method type risk weighting (METHOD_NEITHER > METHOD_BUFFERED)
   - Access type weighting (FILE_ANY_ACCESS = higher risk)
   - Function risk multiplier
   - Overall driver security score calculation

---

## Code Quality Observations

### Strengths:
1. Clean separation of concerns (decompile vs. analyze)
2. Structured JSON output for easy parsing
3. Good error handling in IOCTL validation
4. Support for multiple analysis drivers

### Weaknesses:
1. No logging framework (print statements only)
2. Hardcoded paths and values
3. No unit tests for IOCTL parsing logic
4. Missing configuration file for detection rules
5. No persistent caching of analysis results

---

## Recommendations for HTML Report Generator

### Structure:

```python
class HTMLReportGenerator:
    def __init__(self, analysis_dir):
        self.ioctls = load_ioctls_json()
        self.functions = load_analysis_summary()
        
    def calculate_security_score(self):
        # Aggregate risk from IOCTLs and functions
        
    def generate_ioctl_cards(self):
        # Create visual cards for each IOCTL
        # Color code by method/access risk
        
    def detect_dangerous_functions(self):
        # Search decompiled C files for known-bad functions
        
    def generate_html(self):
        # Create final report
```

### Risk Calculation Formula (Suggested):
```
Risk = (IOCTL_Count * 0.3) + 
        (Dangerous_Functions * 0.5) +
        (METHOD_NEITHER_Count * 0.2)
Security_Score = 100 - Risk
```

