// Function: memset
// Address: 140007900
// Decompiled by Ghidra


/* Library Function - Single Match
    memset
   
   Library: Visual Studio 2019 Release */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (0x4e < _Size) {
    *(longlong *)_Dst = lVar3;
    *(longlong *)((longlong)_Dst + 8) = lVar3;
    plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
    uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
    uVar5 = uVar4 >> 7;
    plVar2 = plVar1;
    if (uVar5 != 0) {
      do {
        *plVar2 = lVar3;
        plVar2[1] = lVar3;
        plVar2[2] = lVar3;
        plVar2[3] = lVar3;
        plVar1 = plVar2 + 0x10;
        plVar2[4] = lVar3;
        plVar2[5] = lVar3;
        plVar2[6] = lVar3;
        plVar2[7] = lVar3;
        uVar5 = uVar5 - 1;
        plVar2[8] = lVar3;
        plVar2[9] = lVar3;
        plVar2[10] = lVar3;
        plVar2[0xb] = lVar3;
        plVar2[0xc] = lVar3;
        plVar2[0xd] = lVar3;
        plVar2[0xe] = lVar3;
        plVar2[0xf] = lVar3;
        plVar2 = plVar1;
      } while (uVar5 != 0);
      uVar4 = uVar4 & 0x7f;
    }
    for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
      *plVar1 = lVar3;
      plVar1[1] = lVar3;
      plVar1 = plVar1 + 2;
    }
    if ((uVar4 & 0xf) != 0) {
      plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
      *plVar1 = lVar3;
      plVar1[1] = lVar3;
    }
    return _Dst;
  }
  uVar4 = _Size & 0xfffffffffffffff8;
  do {
    *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
    uVar4 = uVar4 - 8;
  } while (uVar4 != 0);
  if ((_Size & 7) != 0) {
    *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
  }
  return _Dst;
}

