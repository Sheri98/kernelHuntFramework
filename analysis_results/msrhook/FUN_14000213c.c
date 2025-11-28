// Function: FUN_14000213c
// Address: 14000213c
// Decompiled by Ghidra


undefined8 FUN_14000213c(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  if (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38) == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    return 0xc0000010;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000217f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = IofCallDriver();
  return uVar1;
}

