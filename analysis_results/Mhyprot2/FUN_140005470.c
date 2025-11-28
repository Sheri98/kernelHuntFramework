// Function: FUN_140005470
// Address: 140005470
// Decompiled by Ghidra


ulonglong FUN_140005470(longlong param_1,ulonglong *param_2,uint param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = FUN_140005320(param_2,param_3,param_4);
  LOCK();
  uVar1 = *param_2;
  *param_2 = *param_2 + 1;
  UNLOCK();
  uVar3 = ExfUnblockPushLock(param_1 + 0x30,0,uVar1);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),(char)uVar2);
}

