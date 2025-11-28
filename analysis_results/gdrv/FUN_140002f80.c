// Function: FUN_140002f80
// Address: 140002f80
// Decompiled by Ghidra


void FUN_140002f80(void)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 *in_R11;
  undefined8 unaff_retaddr;
  
  uVar2 = (ulonglong)in_R11 & 7;
  if ((int)uVar2 != 0) goto LAB_140002f9b;
  do {
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)(0x2c,unaff_retaddr);
LAB_140002f9b:
    in_R11 = (undefined8 *)((ulonglong)in_R11 ^ uVar2);
    unaff_retaddr = *in_R11;
  } while( true );
}

