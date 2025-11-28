// Function: FUN_00013550
// Address: 00013550
// Decompiled by Ghidra


void FUN_00013550(longlong param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_138 [32];
  char local_118 [4];
  uint local_114;
  ulonglong local_18;
  
  local_18 = DAT_00016100 ^ (ulonglong)auStack_138;
  DbgPrint("misc 377");
  uVar4 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    do {
      uVar1 = FUN_00012eb0(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + uVar4 * 8),local_118,0x24
                          );
      if (((int)uVar1 == 0) && (pcVar2 = strstr(local_118,"FACP"), pcVar2 == local_118)) {
        uVar3 = local_114;
        if (0x100 < local_114) {
          uVar3 = 0x100;
        }
        uVar1 = FUN_00012eb0(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + uVar4 * 8),local_118,
                             (ulonglong)uVar3);
        if ((int)uVar1 == 0) break;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(param_1 + 0x30));
  }
  FUN_00013640(local_18 ^ (ulonglong)auStack_138);
  return;
}

