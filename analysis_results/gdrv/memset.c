// Function: memset
// Address: 140003340
// Decompiled by Ghidra


/* Library Function - Single Match
    memset
   
   Library: Visual Studio 2019 Release */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_140003400;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1400033fd_caseD_2;
      case 3:
        goto switchD_1400033fd_caseD_3;
      case 4:
        goto switchD_1400033fd_caseD_4;
      case 5:
        goto switchD_1400033fd_caseD_5;
      case 6:
        goto switchD_1400033fd_caseD_6;
      case 7:
        goto switchD_1400033fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_140003400:
        *puVar3 = uVar4;
switchD_1400033fd_caseD_7:
        puVar3[1] = uVar4;
switchD_1400033fd_caseD_6:
        puVar3[2] = uVar4;
switchD_1400033fd_caseD_5:
        puVar3[3] = uVar4;
switchD_1400033fd_caseD_4:
        puVar3[4] = uVar4;
switchD_1400033fd_caseD_3:
        puVar3[5] = uVar4;
switchD_1400033fd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}

