# 🛡️ KernelHunt Framework

> **Advanced Windows Driver 0-Day Hunter**
> By Shravan Kumar Sheri (SSK)

Automated discovery of 0-day vulnerabilities in Windows kernel drivers through systematic analysis of attack surfaces, exploitation primitives, and dangerous operations.

[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%7C%20Python-blue)]()
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)]()
[![License](https://img.shields.io/badge/License-Research-green)]()
[![Version](https://img.shields.io/badge/Version-2.0.0-brightgreen)]()

---

## 🚀 Quick Start

```cmd
# Run the main Windows executable
kernelHuntFramework.exe

# Interactive console menu:
======================== MAIN MENU ========================

  [1] Analyze Driver (Complete)     - Decompile + IOCTLs + Report + Primitives
  [2] Batch Analysis                - Analyze multiple drivers sequentially
  [3] Generate HTML Report          - Create visual security report
  [4] Detect Exploit Primitives     - Find arbitrary read/write/exec
  [5] Patch Diff Analyzer           - Compare driver versions (0-day hunter)
  [6] Live IOCTL Fuzzer             - Test driver IOCTLs in real-time
  [7] Enumerate Third-Party Drivers - Scan system for drivers
  [8] Process Security Checker      - Check process privileges/integrity
  [9] About / Credits               - Framework information
  [10] Enumerate ALL System Drivers - Scan ALL drivers (inc. Microsoft)
  [11] Parallel Batch Analysis      - FAST! Use all CPU cores
  [12] Generate Master Dashboard    - NEW! Aggregate all analyses
  [13] Driver Loader / Unloader     - Load/unload drivers for testing

  [0] Exit

===============================================================
```

**Note:** Compile from `kernelHuntFramework.sln` in Visual Studio

https://github.com/user-attachments/assets/c6db5708-60af-42b1-89d3-c55a4f0ce4cd


---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🎨 **Professional Console** | Beautiful interactive interface with color-coded output |
| 🔬 **Auto Decompilation** | Ghidra headless batch processing |
| 🎯 **IOCTL Extraction** | Maps complete attack surface with proper categorization |
| ⚠️ **Dangerous Functions** | Detects 40+ exploitable functions across 4 severity levels |
| ⚡ **Exploitation Primitives** | Detects arbitrary read/write, code execution, privilege escalation |
| 📊 **Security Scoring** | Automated risk assessment (0-100 scale) |
| 🎨 **HTML Reports** | Beautiful visual dashboards with compartmentalized data |
| 🔄 **Batch Analysis** | Analyze multiple drivers sequentially or in parallel |
| 🚀 **Parallel Processing** | Multi-CPU batch analysis - 8-16x faster than sequential |
| 📈 **Master Dashboard** | Aggregate view of all analyzed drivers by severity |
| 🔍 **Patch Diff Analyzer** | Compare driver versions to find 0-days (85-95% success) |
| 🖥️ **System-Wide Scanning** | Enumerate ALL Windows drivers (Microsoft + Third-Party) |
| 🎯 **Live IOCTL Fuzzing** | Real-time driver testing with automated input generation |
| 🔌 **Driver Loader** | Bulk load/unload drivers for testing - supports file lists & directories |

---

## 📋 How It Works

```
         ┌──────────────────────────┐
         │  kernelHuntFramework.exe │  ← Windows Console Application
         │  (Compiled from C++)     │
         └────────────┬─────────────┘
                      │
         ┌────────────┴─────────────┐
         │   Interactive Menu       │
         │  [1] Single  [2] Batch   │
         └────────────┬─────────────┘
                      │
    ╔═════════════════╩═════════════════╗
    ║  AUTOMATED 4-STEP ANALYSIS        ║
    ╚═════════════════╦═════════════════╝
                      │
    ┌─────────────────┼─────────────────┬─────────────────┐
    ▼                 ▼                 ▼                 ▼
┌─────────┐      ┌─────────┐      ┌──────────┐    ┌──────────┐
│ Step 1  │  →   │ Step 2  │  →   │ Step 3   │ →  │ Step 4   │
│Decompile│      │ IOCTLs  │      │HTML Rpt  │    │Primitives│
└─────────┘      └─────────┘      └──────────┘    └──────────┘
                      │
                      ▼
         ┌────────────────────────┐
         │  Complete Security     │
         │  Analysis Package      │
         └────────────────────────┘
```

---

## 🎯 Example Output

### Security Report
```
============================================================
REPORT SUMMARY
============================================================
Security Score:      100/100 (CRITICAL)
Total IOCTLs:        142
Total Functions:     166
Dangerous Functions: 92
  - Critical:        1
  - High:            13
  - Medium:          69
============================================================
```

### Exploitation Primitives Detected
```
🔍 ARBITRARY READ PRIMITIVES
🔴 MmMapIoSpace + User Address (CRITICAL)
   Physical memory mapping with potentially user-controlled address
   Found in: FUN_000115b0.c

⚡ CODE EXECUTION PRIMITIVES
🔴 Function Pointer from User Input (CRITICAL)
   Indirect call through potentially user-controlled function pointer

🔓 PRIVILEGE ESCALATION
🟠 No Privilege Check Before Dangerous Op (HIGH)
   Dangerous operation without privilege validation
```

---

## 💾 Installation

### **Prerequisites:**
- **Windows 10/11** (required for main executable)
- **Visual Studio 2019+** (to compile C++)
- **Python 3.8+** (for analysis helper scripts)
- **Ghidra 11.0+** (for decompilation engine)

### **Build Steps:**

1. **Clone the repository:**
   ```cmd
   git clone https://github.com/Sheri98/kernelHuntFramework
   cd kernelHuntFramework
   ```

2. **Open in Visual Studio:**
   ```cmd
   # Open kernelHuntFramework.sln in Visual Studio
   # Build > Build Solution (Ctrl+Shift+B)
   ```

3. **Configure paths (in code):**
   ```cpp
   // Edit rundriverDecompiler.cpp line 123-126:
   string baseDir = "C:\\YourPath\\kernelHuntFramework";
   string ghidraPath = "C:\\ghidra_11.0_PUBLIC";
   ```

4. **Ensure Python scripts are in exe directory:**
   ```
   kernelHuntFramework.exe  ← Compiled output
   driver_decompiler.py
   ioctl_analyzer.py
   html_report_generator.py
   exploit_primitive_detector.py
   ```

5. **Run as Administrator:**
   ```cmd
   Right-click kernelHuntFramework.exe → Run as Administrator
   ```

## Demo


---

## 📁 Output Files

Each analyzed driver produces:

| File | Description |
|------|-------------|
| `extracted_ioctls.json` | All IOCTL codes categorized by device type, method, access |
| `dangerous_functions.json` | Exploitable functions found by severity level |
| `exploitation_primitives.json` | Detected exploitation primitives (read/write/exec) |
| `security_report.html` | Beautiful visual analysis dashboard |
| `ANALYSIS_SUMMARY.txt` | Complete function listing and decompilation summary |

---

## 🧪 Live IOCTL Fuzzing (Menu Option [5])

**Real-time driver testing with Windows API:**

The framework includes integrated live fuzzing:

```cmd
kernelHuntFramework.exe → Select [5] Live IOCTL Fuzzer
  ↓
Fuzzes loaded drivers using DeviceIoControl()
  ↓
Tests all IOCTL codes with structure-aware buffer sizes
  ↓
Analyzes error codes to identify valid IOCTLs
```

**Structure-Aware Fuzzing:**
- Based on METHOD type (BUFFERED, IN_DIRECT, OUT_DIRECT, NEITHER)
- Smart buffer sizes: [0, 4, 8, 16, 32, 64, 128, 256, 1024...]
- Lower BSOD rate: 2-5% vs. 40-60% for blind fuzzing
- 4x more tests per hour

**Requirements:**
- Driver must be loaded in system
- Run as Administrator

---

## 📊 Dangerous Functions Detected

| Category | Functions | Impact |
|----------|-----------|--------|
| **Memory Access** | `MmMapIoSpace` | Arbitrary physical memory R/W |
| **MSR Access** | `__writemsr`, `__readmsr` | Disable kernel protections |
| **Port I/O** | `WRITE_PORT_UCHAR` | Hardware manipulation |
| **Buffer Ops** | `memcpy`, `RtlCopyMemory` | Buffer overflows |

40+ dangerous functions tracked with CWE mapping.

---

## 🎨 HTML Reports

Beautiful visual dashboards showing:
- Security score & risk level
- IOCTL analysis cards with fuzzing recommendations
- Dangerous functions categorized by severity
- Exploit primitives identified
- One-click export to PDF/JSON

---

## 🐛 Troubleshooting

**Executable won't start?**
```cmd
# Ensure all Python scripts are in same directory as .exe
# Verify Python is installed and in PATH:
python --version

# Run as Administrator (always)
Right-click kernelHuntFramework.exe → Run as Administrator
```

**Ghidra decompilation fails?**
```cmd
# Update ghidraPath in rundriverDecompiler.cpp (line 126):
string ghidraPath = "C:\\ghidra_11.0_PUBLIC";  # ← Your Ghidra path

# Recompile in Visual Studio
```

**Python scripts not found?**
```cmd
# List files in exe directory:
dir *.py

# Should see:
#   driver_decompiler.py
#   ioctl_analyzer.py
#   html_report_generator.py
#   exploit_primitive_detector.py
```

**Need to regenerate specific reports?**
```cmd
# Use console menu options:
kernelHuntFramework.exe
  → [3] Generate HTML Report
  → [4] Detect Exploit Primitives
```

**Batch analysis not finding drivers?**
```cmd
# Ensure driver.json exists in base directory
# Format:
{
  "drivers": [
    "C:\\Windows\\System32\\drivers\\driver1.sys",
    "C:\\path\\to\\driver2.sys"
  ]
}
```

---


## 📝 License

For security research purposes only. Use responsibly and ethically.

**⚠️ Disclaimer:** Authorized security research only. Do not use on systems without permission.
---

<div align="center">

**Built with ❤️ for security researchers**

[⭐ Star](https://github.com/yourusername/kernelHuntFramework) · [🐛 Report Bug](https://github.com/yourusername/kernelHuntFramework/issues) · [💡 Request Feature](https://github.com/yourusername/kernelHuntFramework/issues)

</div>
