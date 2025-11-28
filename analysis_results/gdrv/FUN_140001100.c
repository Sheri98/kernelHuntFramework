// Function: FUN_140001100
// Address: 140001100
// Decompiled by Ghidra


undefined8 FUN_140001100(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined8 in_RAX;
  ulonglong uVar7;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  
  uVar1 = *param_1;
  uVar2 = *(undefined8 *)((longlong)param_1 + 4);
  uVar3 = param_1[1];
  uVar4 = *(undefined8 *)((longlong)param_1 + 0xc);
  uVar7 = param_1[2];
  uVar6 = (undefined1)uVar1;
  out((short)uVar4,uVar6);
  out(0xeb,uVar6);
  out(0xeb,uVar6);
  out(0xeb,uVar6);
  out(0xeb,uVar6);
  DAT_140005000 = (undefined4)uVar7;
  *(byte *)((longlong)param_1 + 0x1c) =
       ((longlong)uVar7 < 0) * -0x80 | (uVar7 == 0) * '@' | (in_AF & 1) * '\x10' |
       ((POPCOUNT(uVar7 & 0xff) & 1U) == 0) * '\x04';
  *(byte *)((longlong)param_1 + 0x1d) =
       (byte)((ulonglong)(in_NT & 1) * 0x4000 >> 8) | (byte)((ulonglong)(in_IF & 1) * 0x200 >> 8) |
       (byte)((ulonglong)(in_TF & 1) * 0x100 >> 8);
  *(byte *)((longlong)param_1 + 0x1e) =
       (byte)((ulonglong)(in_ID & 1) * 0x200000 >> 0x10) |
       (byte)((ulonglong)(in_VIP & 1) * 0x100000 >> 0x10) |
       (byte)((ulonglong)(in_VIF & 1) * 0x80000 >> 0x10) |
       (byte)((ulonglong)(in_AC & 1) * 0x40000 >> 0x10);
  *(undefined1 *)((longlong)param_1 + 0x1f) = 0;
  *(undefined1 *)param_1 = uVar6;
  *(char *)((longlong)param_1 + 1) = (char)((ulonglong)uVar1 >> 8);
  *(char *)((longlong)param_1 + 2) = (char)((ulonglong)uVar1 >> 0x10);
  *(char *)((longlong)param_1 + 3) = (char)((ulonglong)uVar1 >> 0x18);
  *(char *)((longlong)param_1 + 4) = (char)uVar2;
  *(char *)((longlong)param_1 + 5) = (char)((ulonglong)uVar2 >> 8);
  *(char *)((longlong)param_1 + 6) = (char)((ulonglong)uVar2 >> 0x10);
  *(char *)((longlong)param_1 + 7) = (char)((ulonglong)uVar2 >> 0x18);
  *(char *)(param_1 + 1) = (char)uVar3;
  *(char *)((longlong)param_1 + 9) = (char)((ulonglong)uVar3 >> 8);
  *(char *)((longlong)param_1 + 10) = (char)((ulonglong)uVar3 >> 0x10);
  *(char *)((longlong)param_1 + 0xb) = (char)((ulonglong)uVar3 >> 0x18);
  *(char *)((longlong)param_1 + 0xc) = (char)uVar4;
  *(char *)((longlong)param_1 + 0xd) = (char)((ulonglong)uVar4 >> 8);
  *(char *)((longlong)param_1 + 0xe) = (char)((ulonglong)uVar4 >> 0x10);
  *(char *)((longlong)param_1 + 0xf) = (char)((ulonglong)uVar4 >> 0x18);
  uVar5 = DAT_140005000;
  *(char *)(param_1 + 2) = (char)DAT_140005000;
  *(char *)((longlong)param_1 + 0x11) = (char)((uint)uVar5 >> 8);
  *(char *)((longlong)param_1 + 0x12) = (char)((uint)uVar5 >> 0x10);
  *(char *)((longlong)param_1 + 0x13) = (char)((uint)uVar5 >> 0x18);
  uVar7 = *(ulonglong *)((longlong)param_1 + 0x14) & 0xffffffff;
  *(char *)((longlong)param_1 + 0x14) = (char)uVar7;
  *(char *)((longlong)param_1 + 0x15) = (char)(uVar7 >> 8);
  *(char *)((longlong)param_1 + 0x16) = (char)(uVar7 >> 0x10);
  *(char *)((longlong)param_1 + 0x17) = (char)(uVar7 >> 0x18);
  return in_RAX;
}

