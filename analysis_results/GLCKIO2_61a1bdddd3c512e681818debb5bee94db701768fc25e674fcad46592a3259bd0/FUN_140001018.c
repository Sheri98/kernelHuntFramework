// Function: FUN_140001018
// Address: 140001018
// Decompiled by Ghidra


void FUN_140001018(byte param_1,byte *param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar1 = 0;
  do {
    bVar2 = 0;
    do {
      bVar3 = bVar2 + 1;
      *param_2 = *param_2 ^
                 *(byte *)((ulonglong)((uint)bVar2 + ((uint)bVar1 + (uint)param_1 * 4) * 4) +
                          param_3);
      param_2 = param_2 + 1;
      bVar2 = bVar3;
    } while (bVar3 < 4);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}

