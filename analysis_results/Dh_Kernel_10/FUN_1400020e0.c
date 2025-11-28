// Function: FUN_1400020e0
// Address: 1400020e0
// Decompiled by Ghidra


/* WARNING: Switch with 1 destination removed at 0x0001400020e3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400020e0(void)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 unaff_retaddr;
  
  puVar3 = (undefined8 *)0x0;
  do {
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)(0x2c,unaff_retaddr);
    puVar3 = (undefined8 *)((ulonglong)puVar3 ^ uVar2);
    unaff_retaddr = *puVar3;
  } while( true );
}

