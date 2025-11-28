// Function: FUN_140002110
// Address: 140002110
// Decompiled by Ghidra


void FUN_140002110(void)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 *in_R11;
  undefined8 unaff_retaddr;
  
  uVar2 = (ulonglong)in_R11 & 7;
  if ((int)uVar2 != 0) goto LAB_14000212b;
  do {
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)(0x2c,unaff_retaddr);
LAB_14000212b:
    in_R11 = (undefined8 *)((ulonglong)in_R11 ^ uVar2);
    unaff_retaddr = *in_R11;
  } while( true );
}

