// Function: FUN_140002d4c
// Address: 140002d4c
// Decompiled by Ghidra


ulonglong FUN_140002d4c(longlong param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  undefined1 local_38 [48];
  
  if (param_1 == 0) {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  else {
    lVar3 = PsGetProcessWow64Process();
    KeStackAttachProcess(param_1,local_38);
    if (lVar3 == 0) {
      lVar3 = PsGetProcessPeb(param_1);
      if ((lVar3 != 0) && (*(longlong *)(lVar3 + 0x18) != 0)) {
        for (puVar6 = *(undefined8 **)(*(longlong *)(lVar3 + 0x18) + 0x10);
            puVar6 != (undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x10);
            puVar6 = (undefined8 *)*puVar6) {
          FUN_14000260c(param_2,(longlong)puVar6);
        }
      }
    }
    else {
      lVar3 = PsGetProcessWow64Process();
      if ((lVar3 != 0) && (*(uint *)(lVar3 + 0xc) != 0)) {
        uVar1 = *(uint *)((ulonglong)*(uint *)(lVar3 + 0xc) + 0xc);
        while (puVar5 = (uint *)(ulonglong)uVar1,
              puVar5 != (uint *)((ulonglong)*(uint *)(lVar3 + 0xc) + 0xc)) {
          FUN_14000252c(param_2,(longlong)puVar5);
          uVar1 = *puVar5;
        }
      }
    }
    uVar4 = KeUnstackDetachProcess(local_38);
    uVar2 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  return uVar2;
}

