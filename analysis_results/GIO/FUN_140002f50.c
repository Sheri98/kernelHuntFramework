// Function: FUN_140002f50
// Address: 140002f50
// Decompiled by Ghidra


/* WARNING: Switch with 1 destination removed at 0x000140002f53 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002f50(void)

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

