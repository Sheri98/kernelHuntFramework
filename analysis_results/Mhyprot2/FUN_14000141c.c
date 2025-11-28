// Function: FUN_14000141c
// Address: 14000141c
// Decompiled by Ghidra


undefined1 FUN_14000141c(void)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = 1;
  lVar2 = FUN_140002314();
  ExAcquireFastMutex(&DAT_14000a0a0);
  iVar1 = DAT_14000a0d8._4_4_;
  if ((int)DAT_14000a0d8 != 0) {
    iVar4 = (int)lVar2;
    if ((uint)(iVar4 - (int)DAT_14000a0d8) < 8000) {
      DAT_14000a0d8._4_4_ = 0;
      iVar1 = DAT_14000a0d8._4_4_;
    }
    else {
      iVar1 = iVar4;
      if ((DAT_14000a0d8._4_4_ != 0) &&
         (iVar1 = DAT_14000a0d8._4_4_, 7999 < (uint)(iVar4 - DAT_14000a0d8._4_4_))) {
        uVar3 = 0;
      }
    }
  }
  DAT_14000a0d8._4_4_ = iVar1;
  ExReleaseFastMutex(&DAT_14000a0a0);
  return uVar3;
}

