// Function: FUN_1400029b4
// Address: 1400029b4
// Decompiled by Ghidra


undefined1 FUN_1400029b4(undefined8 *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  longlong lVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar2 = 0;
  }
  else {
    puVar4 = (undefined1 *)*param_1;
    lVar5 = param_1[1];
    uVar1 = *(uint *)(param_1 + 2);
    DbgPrint("Dest=%x,Src=%x,size=%d",puVar4,lVar5,uVar1);
    if (uVar1 != 0) {
      lVar5 = lVar5 - (longlong)puVar4;
      uVar3 = (ulonglong)uVar1;
      do {
        *puVar4 = puVar4[lVar5];
        puVar4 = puVar4 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar2 = 1;
  }
  return uVar2;
}

