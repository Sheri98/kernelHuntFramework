#include "Header.h"

int main() {
    println("\t\t\t=====KERNEL HUNTING FRAMEWORK by SSK=====\n");
    println("1. Kernel DRIVER IOCTL Fuzzer\n");
    println("2. Check Driver Has EDR killing Capacity\n");
    println("3. Process checker\n");
    DWORD input;
    cin>>input;
    switch (input) {
    case 1:
    {
        println("Switch to IOCTL FUZZER");
        break;
    };
    case 2:
    {
        println("Switch to ntoskrnl.exe checker\n");
        break;
    };
    case 3:
    {
        println("Enter PID to check for Information on Particualar PID or scan same process\n");
        DWORD pID;
        cin >> pID;
        pidSDChecker(pID);
        break;
    };
    default:
        break;
    }
    return 0;

}