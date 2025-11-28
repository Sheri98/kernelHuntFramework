// Function: FUN_000110c8
// Address: 000110c8
// Decompiled by Ghidra


int FUN_000110c8(longlong param_1,longlong param_2)

{
  char *pcVar1;
  void *_Src;
  int iVar2;
  ulonglong _Size;
  undefined8 uVar3;
  ulonglong _Size_00;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  _Src = *(void **)(param_2 + 0x18);
  _Size = (ulonglong)*(uint *)(pcVar1 + 0x10);
  _Size_00 = (ulonglong)*(uint *)(pcVar1 + 8);
  iVar2 = -0x3ffffffe;
  if ((*pcVar1 != '\0') && (*pcVar1 != '\x02')) {
    if (*pcVar1 != '\x0e') goto LAB_000112c6;
    iVar2 = *(int *)(pcVar1 + 0x18);
    if (iVar2 == -0x2927d99c) {
      memcpy(&local_28,_Src,_Size);
      local_14 = local_24;
      local_10 = local_20;
      local_18 = local_28;
      local_c = local_1c;
      FUN_00011670(&local_18);
    }
    else {
      if (iVar2 != -0x2927d998) {
        if (((iVar2 == -0x2927d994) || (iVar2 == -0x2927d990)) || (iVar2 == -0x2927d98c)) {
          uVar3 = FUN_00011338(*(undefined8 *)(param_1 + 0x40),param_2,(longlong)pcVar1,iVar2);
          iVar2 = (int)uVar3;
        }
        else if (iVar2 == -0x2927d988) {
          memcpy(&DAT_00013120,_Src,_Size);
          iVar2 = FUN_00011454(DAT_00013130,DAT_00013128,&DAT_00013138,&DAT_00013120);
          if (-1 < iVar2) {
            memcpy(_Src,&DAT_00013120,_Size_00);
            *(ulonglong *)(param_2 + 0x38) = _Size_00;
          }
        }
        else if (iVar2 == -0x2927d984) {
          memcpy(&DAT_00013120,_Src,_Size);
          iVar2 = ZwUnmapViewOfSection(0xffffffffffffffff,DAT_00013138);
          ZwClose(DAT_00013120);
        }
        else {
          iVar2 = -0x3ffffff3;
        }
        goto LAB_000112c6;
      }
      memcpy(&local_28,_Src,_Size);
      local_14 = local_24;
      local_10 = local_20;
      local_18 = local_28;
      local_c = local_1c;
      FUN_00011640(&local_18);
    }
    local_24 = local_14;
    local_20 = local_10;
    local_1c = local_c;
    local_28 = local_18;
    memcpy(_Src,&local_28,_Size_00);
    *(ulonglong *)(param_2 + 0x38) = _Size_00;
  }
  iVar2 = 0;
LAB_000112c6:
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}

