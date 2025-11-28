// Function: FUN_00011c0c
// Address: 00011c0c
// Decompiled by Ghidra


undefined8 FUN_00011c0c(int *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 local_res8 [4];
  
  uVar4 = *param_1 + 0xfffU >> 0xc;
  param_1[1] = uVar4;
  if (*(longlong *)(param_2 + 0xb0) == 0) {
    lVar1 = ExAllocatePool(0);
    if (lVar1 != 0) {
      lVar2 = IoAllocateMdl(lVar1,uVar4 << 0xc,0,0,0);
      if (lVar2 != 0) {
        uVar3 = FUN_00012654(1,(longlong *)(param_2 + 0xc0),(undefined8 *)(param_2 + 0xb0),
                             (longlong *)(param_2 + 0xb8),local_res8,lVar2);
        if ((char)uVar3 != '\0') goto LAB_00011cc2;
      }
      *(undefined8 *)(param_2 + 0xb0) = 0;
      ExFreePoolWithTag(lVar1);
    }
  }
LAB_00011cc2:
  if (*(ulonglong **)(param_2 + 0xb0) != (ulonglong *)0x0) {
    FUN_00012860(*(ulonglong **)(param_2 + 0xb0),0,(ulonglong)(uVar4 << 0xc));
    **(undefined4 **)(param_2 + 0xb0) = 0;
    *(undefined4 *)(*(longlong *)(param_2 + 0xb0) + 0x40) = 0x58;
    *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 0xc0);
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 0xb0);
  }
  *(undefined8 *)(param_3 + 0x38) = 0x18;
  return 0;
}

