// Function: FUN_1400019e4
// Address: 1400019e4
// Decompiled by Ghidra


ulonglong FUN_1400019e4(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  if (param_1 != DAT_1400075c0) {
    lVar1 = *(longlong *)(param_1 + 0x40);
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    uVar4 = IofCallDriver(*(undefined8 *)(lVar1 + 0x38));
    return uVar4;
  }
  uVar4 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar2 = *(char **)(param_2 + 0xb8);
  if (*pcVar2 == '\x02') {
LAB_140001b6a:
    DAT_1400050f0 = 0;
    uVar6 = uVar4;
    goto LAB_140001b71;
  }
  uVar6 = 0;
  if (*pcVar2 != '\x0e') goto LAB_140001b71;
  uVar3 = *(uint *)(pcVar2 + 0x18);
  if (uVar3 < 0x22201d) {
    if (uVar3 == 0x22201c) {
      uVar5 = FUN_1400016c4(param_2,(longlong)pcVar2);
      uVar3 = (uint)uVar5;
    }
    else {
      if (uVar3 == 0x222000) {
        DAT_1400050f4 = 0;
        DAT_1400050e4 = 0;
        DAT_1400050f0 = 1;
        uVar6 = uVar4;
        goto LAB_140001b71;
      }
      if (uVar3 == 0x222004) goto LAB_140001b6a;
      if (uVar3 == 0x222008) {
        uVar5 = FUN_140001514(param_2,(longlong)pcVar2);
        uVar3 = (uint)uVar5;
      }
      else if (uVar3 == 0x22200c) {
        uVar5 = FUN_1400013f4(param_2,(longlong)pcVar2);
        uVar3 = (uint)uVar5;
      }
      else {
        if (uVar3 != 0x222010) {
          if (uVar3 == 0x222014) {
            if (*(int *)(pcVar2 + 0x10) != 0) {
              DAT_1400050e6 = **(undefined1 **)(param_2 + 0x18);
              goto LAB_140001b71;
            }
          }
          else if (uVar3 == 0x222018) {
            uVar5 = FUN_14000161c(param_2,(longlong)pcVar2);
            uVar3 = (uint)uVar5;
            goto LAB_140001b66;
          }
LAB_140001b1f:
          uVar6 = 0xc000000d;
          goto LAB_140001b71;
        }
        uVar5 = FUN_140001468(param_2,(longlong)pcVar2);
        uVar3 = (uint)uVar5;
      }
    }
  }
  else {
    if (uVar3 != 0x222020) {
      if (uVar3 == 0x222024) {
        uVar6 = FUN_140001088();
        uVar6 = uVar6 & 0xffff;
      }
      else {
        if (uVar3 != 0x222040) {
          if (uVar3 == 0x222044) {
            uVar4 = FUN_140001188(param_1);
            uVar3 = (uint)uVar4;
          }
          else {
            uVar6 = uVar4;
            if (uVar3 == 0x222048) goto LAB_140001b71;
            if (uVar3 == 0x22204c) {
              uVar3 = FUN_140001540(param_2);
            }
            else {
              if (uVar3 != 0x222050) goto LAB_140001b1f;
              uVar3 = FUN_14000168c(param_2);
            }
          }
          goto LAB_140001b66;
        }
        FUN_140001128();
        uVar6 = 1;
      }
      *(ulonglong *)(param_2 + 0x38) = uVar6;
      uVar6 = uVar4;
      goto LAB_140001b71;
    }
    uVar5 = FUN_140001578(param_2,(longlong)pcVar2);
    uVar3 = (uint)uVar5;
  }
LAB_140001b66:
  uVar6 = (ulonglong)uVar3;
LAB_140001b71:
  *(int *)(param_2 + 0x30) = (int)uVar6;
  IofCompleteRequest(param_2,0);
  return uVar6;
}

