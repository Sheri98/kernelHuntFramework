// Function: FUN_00011a20
// Address: 00011a20
// Decompiled by Ghidra


undefined8
FUN_00011a20(undefined8 param_1,uint *param_2,undefined8 param_3,uint *param_4,undefined8 param_5,
            undefined4 *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar1 = *param_2;
  uVar3 = 0;
  uVar2 = (uint)(999999999 / (ulonglong)uVar1);
  if (uVar2 != 0) {
    uVar4 = FUN_000129c0(0,uVar1);
    uVar3 = (uint)uVar4;
    if (uVar2 < uVar3) {
      uVar4 = FUN_000129c0(0,uVar1);
      uVar3 = (uint)uVar4;
      if (uVar2 < uVar3) {
        uVar3 = 0;
        goto LAB_00011ab5;
      }
    }
    if (uVar3 < 3) {
      if (uVar3 == 1) {
        uVar3 = 0;
        if (DAT_0001511c != 0) {
          DbgPrint("CalcBaseClk - PM Timer was not detected.\n");
          DAT_0001511c = 0;
        }
      }
      else if ((uVar3 == 2) && (uVar3 = 0, DAT_00015120 != 0)) {
        DbgPrint("CalcBaseClk - APIC could not be located.\n");
        DAT_00015120 = 0;
      }
    }
  }
LAB_00011ab5:
  *param_4 = uVar3;
  *param_6 = 4;
  return 0;
}

