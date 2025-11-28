// Function: FUN_00015294
// Address: 00015294
// Decompiled by Ghidra


undefined8 FUN_00015294(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *_Dst;
  longlong *plVar6;
  
  if (*(uint *)(param_1 + 1) < 0x18) {
    uVar4 = 0xc000000d;
  }
  else {
    plVar6 = (longlong *)*param_1;
    lVar1 = *plVar6;
    lVar2 = plVar6[1];
    uVar3 = plVar6[2];
    if ((param_1[2] == 0) || (param_1[2] == lVar1)) {
      plVar5 = (longlong *)((uVar3 & 0xffffffff) + lVar2);
      if (param_2 == '\0') {
        plVar6 = plVar6 + 3;
        _Dst = plVar5;
      }
      else {
        _Dst = plVar6 + 3;
        plVar6 = plVar5;
      }
      memcpy(_Dst,plVar6,(ulonglong)(*(uint *)(param_1 + 1) - 0x18));
      plVar6 = (longlong *)*param_1;
      *plVar6 = lVar1;
      plVar6[1] = lVar2;
      plVar6[2] = uVar3;
      uVar4 = 0;
    }
    else {
      uVar4 = 0xc0000005;
    }
  }
  return uVar4;
}

