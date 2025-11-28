// Function: FUN_14005a2bc
// Address: 14005a2bc
// Decompiled by Ghidra


void FUN_14005a2bc(void)

{
  int iVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uStack_88;
  ulonglong uStack_80;
  
  uStack_80 = (ulonglong)(in_NT & 1) * 0x4000 | (ulonglong)(in_OF & 1) * 0x800 |
              (ulonglong)(in_IF & 1) * 0x200 | (ulonglong)(in_TF & 1) * 0x100 |
              (ulonglong)(in_SF & 1) * 0x80 | (ulonglong)(in_ZF & 1) * 0x40 |
              (ulonglong)(in_AF & 1) * 0x10 | (ulonglong)(in_PF & 1) * 4 | (ulonglong)(in_CF & 1) |
              (ulonglong)(in_ID & 1) * 0x200000 | (ulonglong)(in_VIP & 1) * 0x100000 |
              (ulonglong)(in_VIF & 1) * 0x80000 | (ulonglong)(in_AC & 1) * 0x40000;
  uStack_88 = 0;
  iVar1 = 0;
  if ((uint)&uStack_88 != 0) {
    for (; ((uint)&uStack_88 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  FUN_140043dc3();
  return;
}

