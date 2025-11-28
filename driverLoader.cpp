#include "Header.h"

// Driver Loader - Load/Unload drivers for testing
// Requires Administrator privileges

struct LoadedDriver {
    string serviceName;
    string driverPath;
    bool loaded;
    DWORD errorCode;
};

vector<LoadedDriver> loadedDrivers;

bool IsAdministrator() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }

    return isAdmin;
}

string GetServiceNameFromPath(const string& driverPath) {
    // Extract filename without extension
    size_t lastSlash = driverPath.find_last_of("\\/");
    string filename = driverPath.substr(lastSlash + 1);
    size_t lastDot = filename.find_last_of('.');
    return filename.substr(0, lastDot);
}

bool LoadSingleDriver(const string& driverPath, string& serviceName, DWORD& errorCode) {
    SC_HANDLE scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!scManager) {
        errorCode = GetLastError();
        return false;
    }

    // Generate service name from driver path
    serviceName = GetServiceNameFromPath(driverPath);

    // Check if service already exists
    SC_HANDLE existingService = OpenServiceA(scManager, serviceName.c_str(), SERVICE_ALL_ACCESS);
    if (existingService) {
        // Service exists, try to start it
        CloseServiceHandle(existingService);

        existingService = OpenServiceA(scManager, serviceName.c_str(), SERVICE_START | SERVICE_QUERY_STATUS);
        if (existingService) {
            SERVICE_STATUS status;
            if (QueryServiceStatus(existingService, &status)) {
                if (status.dwCurrentState == SERVICE_RUNNING) {
                    CloseServiceHandle(existingService);
                    CloseServiceHandle(scManager);
                    errorCode = 0;
                    return true; // Already running
                }
            }

            if (StartService(existingService, 0, NULL)) {
                CloseServiceHandle(existingService);
                CloseServiceHandle(scManager);
                errorCode = 0;
                return true;
            } else {
                errorCode = GetLastError();
                CloseServiceHandle(existingService);
                CloseServiceHandle(scManager);
                return false;
            }
        }
    }

    // Create new service
    SC_HANDLE service = CreateServiceA(
        scManager,
        serviceName.c_str(),
        serviceName.c_str(),
        SERVICE_ALL_ACCESS,
        SERVICE_KERNEL_DRIVER,
        SERVICE_DEMAND_START,
        SERVICE_ERROR_IGNORE,
        driverPath.c_str(),
        NULL, NULL, NULL, NULL, NULL
    );

    if (!service) {
        errorCode = GetLastError();
        CloseServiceHandle(scManager);
        return false;
    }

    // Start the driver
    bool success = StartService(service, 0, NULL);
    errorCode = success ? 0 : GetLastError();

    CloseServiceHandle(service);
    CloseServiceHandle(scManager);

    return success;
}

bool UnloadSingleDriver(const string& serviceName, DWORD& errorCode) {
    SC_HANDLE scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!scManager) {
        errorCode = GetLastError();
        return false;
    }

    SC_HANDLE service = OpenServiceA(scManager, serviceName.c_str(), SERVICE_STOP | SERVICE_QUERY_STATUS | DELETE);
    if (!service) {
        errorCode = GetLastError();
        CloseServiceHandle(scManager);
        return false;
    }

    // Stop the service
    SERVICE_STATUS status;
    bool stopped = ControlService(service, SERVICE_CONTROL_STOP, &status);

    // Wait for it to stop
    if (stopped) {
        Sleep(1000);
        QueryServiceStatus(service, &status);
        while (status.dwCurrentState != SERVICE_STOPPED) {
            Sleep(500);
            if (!QueryServiceStatus(service, &status)) {
                break;
            }
        }
    }

    // Delete the service
    bool deleted = DeleteService(service);
    errorCode = deleted ? 0 : GetLastError();

    CloseServiceHandle(service);
    CloseServiceHandle(scManager);

    return deleted;
}

void LoadDriversFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "\033[91m[✗]\033[0m Could not open file: " << filePath << endl;
        return;
    }

    vector<string> driverPaths;
    string line;
    while (getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }
        driverPaths.push_back(line);
    }
    file.close();

    if (driverPaths.empty()) {
        cout << "\033[93m[⚠]\033[0m No driver paths found in file" << endl;
        return;
    }

    cout << "\n\033[94m[ℹ]\033[0m Found " << driverPaths.size() << " drivers to load\n" << endl;

    int successCount = 0;
    int failCount = 0;

    for (size_t i = 0; i < driverPaths.size(); i++) {
        string driverPath = driverPaths[i];
        string serviceName;
        DWORD errorCode;

        cout << "\033[96m[" << (i + 1) << "/" << driverPaths.size() << "]\033[0m Loading: " << driverPath << " ... ";

        if (LoadSingleDriver(driverPath, serviceName, errorCode)) {
            cout << "\033[92m✓ SUCCESS\033[0m" << endl;
            loadedDrivers.push_back({serviceName, driverPath, true, 0});
            successCount++;
        } else {
            cout << "\033[91m✗ FAILED\033[0m (Error: " << errorCode << ")" << endl;
            loadedDrivers.push_back({serviceName, driverPath, false, errorCode});
            failCount++;
        }
    }

    cout << "\n\033[96m================================================================\033[0m" << endl;
    cout << "\033[97mLOADING SUMMARY\033[0m" << endl;
    cout << "\033[96m================================================================\033[0m\n" << endl;
    cout << "\033[92m✓ Loaded Successfully:\033[0m  " << successCount << endl;
    cout << "\033[91m✗ Failed to Load:\033[0m      " << failCount << endl;
    cout << "\033[97mTotal Drivers:\033[0m         " << driverPaths.size() << endl;
}

void LoadDriversFromDirectory(const string& dirPath) {
    vector<string> driverFiles;

    WIN32_FIND_DATAA findData;
    string searchPath = dirPath + "\\*.sys";
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "\033[91m[✗]\033[0m Could not access directory: " << dirPath << endl;
        return;
    }

    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            string fullPath = dirPath + "\\" + findData.cFileName;
            driverFiles.push_back(fullPath);
        }
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);

    if (driverFiles.empty()) {
        cout << "\033[93m[⚠]\033[0m No .sys files found in directory" << endl;
        return;
    }

    cout << "\n\033[94m[ℹ]\033[0m Found " << driverFiles.size() << " .sys files\n" << endl;

    int successCount = 0;
    int failCount = 0;

    for (size_t i = 0; i < driverFiles.size(); i++) {
        string driverPath = driverFiles[i];
        string serviceName;
        DWORD errorCode;

        cout << "\033[96m[" << (i + 1) << "/" << driverFiles.size() << "]\033[0m Loading: " << driverPath << " ... ";

        if (LoadSingleDriver(driverPath, serviceName, errorCode)) {
            cout << "\033[92m✓ SUCCESS\033[0m" << endl;
            loadedDrivers.push_back({serviceName, driverPath, true, 0});
            successCount++;
        } else {
            cout << "\033[91m✗ FAILED\033[0m (Error: " << errorCode << ")" << endl;
            loadedDrivers.push_back({serviceName, driverPath, false, errorCode});
            failCount++;
        }
    }

    cout << "\n\033[96m================================================================\033[0m" << endl;
    cout << "\033[97mLOADING SUMMARY\033[0m" << endl;
    cout << "\033[96m================================================================\033[0m\n" << endl;
    cout << "\033[92m✓ Loaded Successfully:\033[0m  " << successCount << endl;
    cout << "\033[91m✗ Failed to Load:\033[0m      " << failCount << endl;
    cout << "\033[97mTotal Drivers:\033[0m         " << driverFiles.size() << endl;
}

void UnloadAllLoadedDrivers() {
    if (loadedDrivers.empty()) {
        cout << "\033[93m[⚠]\033[0m No drivers have been loaded by this session" << endl;
        return;
    }

    cout << "\n\033[94m[ℹ]\033[0m Unloading " << loadedDrivers.size() << " drivers...\n" << endl;

    int successCount = 0;
    int failCount = 0;

    for (size_t i = 0; i < loadedDrivers.size(); i++) {
        LoadedDriver& driver = loadedDrivers[i];

        if (!driver.loaded) {
            continue; // Skip drivers that weren't successfully loaded
        }

        cout << "\033[96m[" << (i + 1) << "/" << loadedDrivers.size() << "]\033[0m Unloading: " << driver.serviceName << " ... ";

        DWORD errorCode;
        if (UnloadSingleDriver(driver.serviceName, errorCode)) {
            cout << "\033[92m✓ SUCCESS\033[0m" << endl;
            driver.loaded = false;
            successCount++;
        } else {
            cout << "\033[91m✗ FAILED\033[0m (Error: " << errorCode << ")" << endl;
            failCount++;
        }
    }

    cout << "\n\033[96m================================================================\033[0m" << endl;
    cout << "\033[97mUNLOADING SUMMARY\033[0m" << endl;
    cout << "\033[96m================================================================\033[0m\n" << endl;
    cout << "\033[92m✓ Unloaded Successfully:\033[0m " << successCount << endl;
    cout << "\033[91m✗ Failed to Unload:\033[0m     " << failCount << endl;

    loadedDrivers.clear();
}

void ListLoadedDrivers() {
    if (loadedDrivers.empty()) {
        cout << "\033[93m[⚠]\033[0m No drivers have been loaded by this session" << endl;
        return;
    }

    cout << "\n\033[96m================================================================\033[0m" << endl;
    cout << "\033[97mLOADED DRIVERS\033[0m" << endl;
    cout << "\033[96m================================================================\033[0m\n" << endl;

    for (size_t i = 0; i < loadedDrivers.size(); i++) {
        const LoadedDriver& driver = loadedDrivers[i];

        if (driver.loaded) {
            cout << "\033[92m[✓]\033[0m ";
        } else {
            cout << "\033[91m[✗]\033[0m ";
        }

        cout << driver.serviceName << endl;
        cout << "    Path: " << driver.path << endl;
        if (!driver.loaded && driver.errorCode != 0) {
            cout << "    \033[91mError Code: " << driver.errorCode << "\033[0m" << endl;
        }
        cout << endl;
    }
}

void runDriverLoader() {
    system("cls");
    printBanner();

    cout << "\n\033[96m================================================================\033[0m" << endl;
    cout << "\033[97m                    DRIVER LOADER / UNLOADER\033[0m" << endl;
    cout << "\033[96m================================================================\033[0m\n" << endl;

    // Check admin privileges
    if (!IsAdministrator()) {
        cout << "\033[91m[✗]\033[0m This feature requires Administrator privileges!" << endl;
        cout << "\033[93m[⚠]\033[0m Please restart the program as Administrator\033[0m\n" << endl;
        cout << "\033[2mPress Enter to continue...\033[0m";
        cin.get();
        cin.get();
        return;
    }

    cout << "\033[92m[✓]\033[0m Running with Administrator privileges\n" << endl;

    cout << "\033[97mSelect operation:\033[0m" << endl;
    cout << "  \033[93m[1]\033[0m Load drivers from text file" << endl;
    cout << "  \033[93m[2]\033[0m Load all drivers from directory" << endl;
    cout << "  \033[93m[3]\033[0m List loaded drivers (this session)" << endl;
    cout << "  \033[93m[4]\033[0m Unload all drivers (this session)" << endl;
    cout << "  \033[91m[0]\033[0m Back to main menu\n" << endl;

    cout << "\033[93mChoice:\033[0m ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        string filePath;
        cout << "\n\033[97mText file path (one driver path per line):\033[0m ";
        cin.ignore();
        getline(cin, filePath);
        LoadDriversFromFile(filePath);
        break;
    }

    case 2: {
        string dirPath;
        cout << "\n\033[97mDirectory path (will load all .sys files):\033[0m ";
        cin.ignore();
        getline(cin, dirPath);
        LoadDriversFromDirectory(dirPath);
        break;
    }

    case 3:
        ListLoadedDrivers();
        break;

    case 4:
        UnloadAllLoadedDrivers();
        break;

    case 0:
        return;

    default:
        cout << "\033[91m[✗]\033[0m Invalid choice" << endl;
        break;
    }

    cout << "\n\033[2mPress Enter to continue...\033[0m";
    cin.get();
    cin.get();
}
