#include "Header.h"

// Clean Windows NT path format (remove \??\ prefix)
string CleanDriverPath(const string& path) {
    string cleaned = path;

    // Remove \??\ prefix if present
    if (cleaned.find("\\??\\") == 0) {
        cleaned = cleaned.substr(4);
    }

    return cleaned;
}

// Read driver paths from your JSON file
vector<string> ReadDriverPathsFromJSON(const string& jsonFile) {
    vector<string> driverPaths;

    ifstream file(jsonFile);
    if (!file.is_open()) {
        cerr << "[!] Failed to open: " << jsonFile << endl;
        return driverPaths;
    }

    string line;
    bool inDriversArray = false;

    while (getline(file, line)) {
        // Look for the "drivers" array
        if (line.find("\"drivers\"") != string::npos) {
            inDriversArray = true;
            continue;
        }

        // Extract paths from array
        if (inDriversArray) {
            // Look for strings - handles both \??\ and regular paths
            size_t start = line.find("\"\\??\\");
            if (start == string::npos) {
                start = line.find("\"C:\\");
            }
            if (start == string::npos) {
                start = line.find("\"D:\\");
            }

            if (start != string::npos) {
                start++; // Skip opening quote
                size_t end = line.find("\"", start);

                if (end != string::npos) {
                    string path = line.substr(start, end - start);
                    driverPaths.push_back(path);

                    cout << "[*] Found: " << path << endl;
                }
            }

            // Check if we've reached end of array
            if (line.find("]") != string::npos) {
                break;
            }
        }
    }

    file.close();

    cout << "\n[+] Total drivers found: " << driverPaths.size() << endl;

    return driverPaths;
}

// Export cleaned paths to new JSON format for Python
void ExportDriversForPython(const vector<string>& drivers,
    const string& outputFile) {
    ofstream file(outputFile);

    if (!file.is_open()) {
        cerr << "[!] Failed to create: " << outputFile << endl;
        return;
    }

    file << "{\n";
    file << "  \"drivers\": [\n";

    for (size_t i = 0; i < drivers.size(); i++) {
        // Clean the path
        string cleaned = CleanDriverPath(drivers[i]);

        // Escape backslashes for JSON
        string escaped;
        for (char ch : cleaned) {
            if (ch == '\\') {
                escaped += "\\\\";
            }
            else {
                escaped += ch;
            }
        }

        file << "    {\"path\": \"" << escaped << "\"}";

        if (i < drivers.size() - 1) {
            file << ",";
        }
        file << "\n";
    }

    file << "  ]\n";
    file << "}\n";

    file.close();

    cout << "[+] Exported to: " << outputFile << endl;
}


void runDriverDecompile() {
    cout << "\n\033[96m════════════════════════════════════════════════════════════════\033[0m" << endl;
    cout << "\033[97m              BATCH DRIVER ANALYSIS - COMPLETE WORKFLOW\033[0m" << endl;
    cout << "\033[96m════════════════════════════════════════════════════════════════\033[0m\n" << endl;

    // Configuration - use current working directory
    char currentDir[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDir);
    string baseDir = string(currentDir);
    string driverJsonFile = baseDir + "\\driver.json";
    string scriptDir = baseDir;
    string ghidraPath = GHIDRA_PATH;

    // Read drivers
    vector<string> drivers = ReadDriverPathsFromJSON(driverJsonFile);

    if (drivers.empty()) {
        cout << "\033[91m[✗]\033[0m No drivers found in driver.json!" << endl;
        return;
    }

    cout << "\033[94m[ℹ]\033[0m Found " << drivers.size() << " drivers to analyze" << endl;
    cout << "\033[94m[ℹ]\033[0m Full workflow: Decompile → IOCTLs → HTML Report → Primitives\n" << endl;

    int successful = 0;
    int failed = 0;
    int partialSuccess = 0;

    // Loop through each driver
    for (size_t i = 0; i < drivers.size(); i++) {
        string driverPath = drivers[i];

        // EXTRACT DRIVER NAME for unique output directory
        size_t lastSlash = driverPath.find_last_of("\\/");
        string driverFileName = driverPath.substr(lastSlash + 1);

        // Remove .sys extension
        string driverName = driverFileName.substr(0, driverFileName.find_last_of('.'));

        // CREATE UNIQUE OUTPUT DIRECTORY
        string analysisBase = baseDir + "\\analysis_results";
        CreateDirectoryA(analysisBase.c_str(), NULL); // Create base directory
        string outputDir = analysisBase + "\\" + driverName;
        CreateDirectoryA(outputDir.c_str(), NULL); // Create driver-specific directory

        cout << "\n\033[96m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m" << endl;
        cout << "\033[97m[" << (i + 1) << "/" << drivers.size() << "] " << driverFileName << "\033[0m" << endl;
        cout << "\033[96m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m" << endl;
        cout << "\033[94m[ℹ]\033[0m Source: " << driverPath << endl;
        cout << "\033[94m[ℹ]\033[0m Output: " << outputDir << "\n" << endl;

        bool driverSuccess = true;
        int completedSteps = 0;

        // Step 1: Decompile to unique directory
        cout << "\033[96m[▶]\033[0m \033[93mStep 1/4:\033[0m Decompiling driver with Ghidra..." << endl;
        string cmd1 = "python \"" + scriptDir + "\\driver_decompiler.py\" "
            + "-g \"" + ghidraPath + "\" "
            + "-d \"" + driverPath + "\" "
            + "-o \"" + outputDir + "\"";

        int result1 = system(cmd1.c_str());

        if (result1 != 0) {
            cout << "\033[91m[✗]\033[0m Decompilation failed, skipping driver...\n" << endl;
            failed++;
            continue;
        }
        cout << "\033[92m[✓]\033[0m Decompilation complete\n" << endl;
        completedSteps++;

        // Step 2: Extract IOCTLs from unique directory
        cout << "\033[96m[▶]\033[0m \033[93mStep 2/4:\033[0m Extracting IOCTL codes..." << endl;
        string cmd2 = "python \"" + scriptDir + "\\ioctl_analyzer.py\" "
            + "-d \"" + outputDir + "\"";

        int result2 = system(cmd2.c_str());

        if (result2 == 0) {
            cout << "\033[92m[✓]\033[0m IOCTL extraction complete\n" << endl;
            completedSteps++;
        }
        else {
            cout << "\033[93m[⚠]\033[0m IOCTL extraction had issues (may be normal)\n" << endl;
            driverSuccess = false;
        }

        // Step 3: Generate HTML Report
        cout << "\033[96m[▶]\033[0m \033[93mStep 3/4:\033[0m Generating HTML security report..." << endl;
        string cmd3 = "python \"" + scriptDir + "\\html_report_generator.py\" "
            + "-d \"" + outputDir + "\"";

        int result3 = system(cmd3.c_str());

        if (result3 == 0) {
            cout << "\033[92m[✓]\033[0m HTML report generated\n" << endl;
            completedSteps++;
        }
        else {
            cout << "\033[91m[✗]\033[0m HTML report generation failed\n" << endl;
            driverSuccess = false;
        }

        // Step 4: Detect Exploitation Primitives
        cout << "\033[96m[▶]\033[0m \033[93mStep 4/4:\033[0m Detecting exploitation primitives..." << endl;
        string cmd4 = "python \"" + scriptDir + "\\exploit_primitive_detector.py\" "
            + "-d \"" + outputDir + "\"";

        int result4 = system(cmd4.c_str());

        if (result4 == 0) {
            cout << "\033[92m[✓]\033[0m Primitive detection complete\n" << endl;
            completedSteps++;
        }
        else {
            cout << "\033[93m[⚠]\033[0m Primitive detection had issues\n" << endl;
            driverSuccess = false;
        }

        // Summary for this driver
        if (completedSteps == 4) {
            cout << "\n\033[92m════════════════════════════════════════════════════════════════\033[0m" << endl;
            cout << "\033[92m✓ DRIVER ANALYSIS COMPLETE - ALL STEPS SUCCESSFUL!\033[0m" << endl;
            cout << "\033[92m════════════════════════════════════════════════════════════════\033[0m" << endl;
            cout << "\033[92m[✓]\033[0m HTML Report: " << outputDir << "\\security_report.html" << endl;
            cout << "\033[92m[✓]\033[0m IOCTLs: " << outputDir << "\\extracted_ioctls.json" << endl;
            cout << "\033[92m[✓]\033[0m Dangerous Functions: " << outputDir << "\\dangerous_functions.json" << endl;
            cout << "\033[92m[✓]\033[0m Primitives: " << outputDir << "\\exploitation_primitives.json" << endl;
            successful++;
        }
        else if (completedSteps >= 2) {
            cout << "\n\033[93m════════════════════════════════════════════════════════════════\033[0m" << endl;
            cout << "\033[93m⚠ DRIVER ANALYSIS PARTIAL - " << completedSteps << "/4 STEPS COMPLETED\033[0m" << endl;
            cout << "\033[93m════════════════════════════════════════════════════════════════\033[0m" << endl;
            partialSuccess++;
        }
        else {
            cout << "\n\033[91m════════════════════════════════════════════════════════════════\033[0m" << endl;
            cout << "\033[91m✗ DRIVER ANALYSIS FAILED\033[0m" << endl;
            cout << "\033[91m════════════════════════════════════════════════════════════════\033[0m" << endl;
            failed++;
        }
    }

    // Final Summary
    cout << "\n\n\033[96m╔══════════════════════════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[96m║\033[0m              \033[97mBATCH ANALYSIS COMPLETE - FINAL SUMMARY\033[0m              \033[96m║\033[0m" << endl;
    cout << "\033[96m╚══════════════════════════════════════════════════════════════╝\033[0m\n" << endl;

    cout << "\033[97mTotal Drivers:\033[0m       " << drivers.size() << endl;
    cout << "\033[92mFully Successful:\033[0m   " << successful << " (all 4 steps completed)" << endl;
    cout << "\033[93mPartial Success:\033[0m    " << partialSuccess << " (some steps completed)" << endl;
    cout << "\033[91mFailed:\033[0m             " << failed << " (decompilation failed)" << endl;

    cout << "\n\033[94m[ℹ]\033[0m Results directory: " << baseDir << "\\analysis_results\\" << endl;
    cout << "\033[94m[ℹ]\033[0m Open security_report.html in browser for visual analysis" << endl;

    // Generate master dashboard if we have any successful or partial analyses
    if (successful > 0 || partialSuccess > 0) {
        cout << "\n\033[96m════════════════════════════════════════════════════════════════\033[0m" << endl;
        cout << "\033[97m              GENERATING MASTER DASHBOARD\033[0m" << endl;
        cout << "\033[96m════════════════════════════════════════════════════════════════\033[0m\n" << endl;

        string dashboardCmd = "python \"" + scriptDir + "\\master_dashboard_generator.py\" -d analysis_results -o master_dashboard.html";
        int dashboardResult = system(dashboardCmd.c_str());

        if (dashboardResult == 0) {
            cout << "\n\033[92m[✓]\033[0m Master dashboard created: master_dashboard.html" << endl;
            cout << "\033[94m[ℹ]\033[0m Open master_dashboard.html in browser to see all drivers organized by severity!" << endl;
        } else {
            cout << "\n\033[93m[⚠]\033[0m Could not generate master dashboard" << endl;
        }
    }

    cout << "\n\033[96m════════════════════════════════════════════════════════════════\033[0m\n" << endl;
}
