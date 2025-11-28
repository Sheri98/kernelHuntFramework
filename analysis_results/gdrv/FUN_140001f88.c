// Function: FUN_140001f88
// Address: 140001f88
// Decompiled by Ghidra


undefined8 FUN_140001f88(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined2 local_resc;
  undefined2 local_res18;
  
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  iVar1 = *(int *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 8);
  DbgPrint("In IO Read");
  if (param_3 == -0x3caf9bfc) {
    uVar8 = 2;
  }
  else {
    if (param_3 != -0x3caf9bf8) {
      local_res18 = *(undefined2 *)puVar3;
      uVar8 = 1;
      goto LAB_140001fed;
    }
    uVar8 = 4;
  }
  local_resc = *(undefined2 *)puVar3;
LAB_140001fed:
  if ((iVar1 == 4) && (uVar8 <= uVar2)) {
    if (param_3 == -0x3caf9c00) {
      uVar4 = in(local_res18);
      *(undefined1 *)puVar3 = uVar4;
      DbgPrint("Exit IO Read %d ");
    }
    else if (param_3 == -0x3caf9bfc) {
      uVar5 = in(local_resc);
      *(undefined2 *)puVar3 = uVar5;
    }
    else if (param_3 == -0x3caf9bf8) {
      uVar6 = in(local_resc);
      *puVar3 = uVar6;
    }
    *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar8;
    uVar7 = 0;
  }
  else {
    uVar7 = 0xc000000d;
  }
  return uVar7;
}

