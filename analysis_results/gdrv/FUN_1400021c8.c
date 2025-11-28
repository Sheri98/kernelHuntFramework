// Function: FUN_1400021c8
// Address: 1400021c8
// Decompiled by Ghidra


undefined8 FUN_1400021c8(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ushort local_resc;
  ushort local_res18;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  *(undefined8 *)(param_1 + 0x38) = 0;
  puVar2 = *(ushort **)(param_1 + 0x18);
  DbgPrint("In IO Write func");
  uVar4 = 0xc350a448;
  if (param_3 == -0x3caf5bbc) {
    uVar3 = 6;
LAB_140002225:
    local_resc = *puVar2;
  }
  else {
    if (param_3 == -0x3caf5bb8) {
      uVar3 = 8;
      goto LAB_140002225;
    }
    local_res18 = *puVar2;
    uVar3 = 5;
  }
  if (uVar1 < uVar3) {
    return 0xc000000d;
  }
  if (param_3 == -0x3caf5bc0) {
    DbgPrint("write %d to %d",local_res18,(char)puVar2[2]);
    uVar4 = (ulonglong)local_res18;
    out(local_res18,(char)puVar2[2]);
  }
  else {
    if (param_3 == -0x3caf5bbc) {
      DbgPrint("write %d to %d",local_resc,puVar2[2]);
      out(local_resc,puVar2[2]);
    }
    else {
      if (param_3 != -0x3caf5bb8) goto LAB_1400022a0;
      DbgPrint("write %d to %d",local_resc,*(undefined4 *)(puVar2 + 2));
      out(local_resc,*(undefined4 *)(puVar2 + 2));
    }
    uVar4 = (ulonglong)local_resc;
  }
LAB_1400022a0:
  DbgPrint("Exit IO Write func",uVar4);
  return 0;
}

