// Function: FUN_00013430
// Address: 00013430
// Decompiled by Ghidra


void FUN_00013430(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 auStack_148 [32];
  undefined4 local_128;
  undefined4 uStack_124;
  char local_118 [4];
  uint local_114;
  ulonglong local_18;
  
  local_18 = DAT_00016100 ^ (ulonglong)auStack_148;
  DbgPrint("misc 350");
  uVar6 = 0;
  uStack_124 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    lVar5 = 0;
    do {
      local_128 = *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x28));
      uVar4 = CONCAT44(uStack_124,local_128);
      uVar2 = FUN_00012eb0(uVar4,local_118,0x24);
      if (((int)uVar2 == 0) && (pcVar3 = strstr(local_118,"FACP"), pcVar3 == local_118)) {
        uVar1 = local_114;
        if (0x100 < local_114) {
          uVar1 = 0x100;
        }
        uVar4 = FUN_00012eb0(uVar4,local_118,(ulonglong)uVar1);
        if ((int)uVar4 == 0) break;
      }
      uVar6 = uVar6 + 1;
      lVar5 = lVar5 + 4;
    } while (uVar6 < *(uint *)(param_1 + 0x30));
  }
  FUN_00013640(local_18 ^ (ulonglong)auStack_148);
  return;
}

