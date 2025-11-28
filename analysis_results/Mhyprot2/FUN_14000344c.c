// Function: FUN_14000344c
// Address: 14000344c
// Decompiled by Ghidra


int FUN_14000344c(void)

{
  longlong lVar1;
  
  lVar1 = PsGetProcessWow64Process();
  return (-(uint)(lVar1 != 0) & 0xffffffe0) + 0x40;
}

