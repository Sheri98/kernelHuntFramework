#include "Header.h"

int main() {
    println("\t\t\t\t\t=====KERNEL DRIVER HUNTING FRAMEWORK by SSK=====\n");
    println("1. Kernel DRIVER IOCTL Fuzzer\n");
    println("2. Check Driver Has EDR killing Capacity\n");
    println("3. Process checker\n");
    println("4. Enumerate Thrid Party Drivers\n");
    DWORD input;
    cin>>input;
    switch (input) {
    case 1:
    {
        ioctMain();
        break;
    };
    case 2:
    {
        break;
    };
    case 3:
    {
        println("[X] Enter PID to check for Information on Particualar PID or scan same process\n");
        DWORD pID;
        cin >> pID;
        pidSDChecker(pID);
        break;
    };
    case 4:
        driverEnum();
    default:
        break;
    }
    return 0;

}