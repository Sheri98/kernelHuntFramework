// Function: FUN_140131fe4
// Address: 140131fe4
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_140131fe4(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  byte bVar5;
  undefined1 *unaff_RDI;
  undefined8 in_stack_00000030;
  char *pcVar4;
  
  uVar1 = in((short)param_2);
  *unaff_RDI = uVar1;
  uVar2 = in((short)param_2);
  pcVar4 = (char *)(ulonglong)uVar2;
  bVar5 = (byte)param_2 & pcVar4[0x3cfa8149];
  if ((char)bVar5 < '\0') {
    if ((int)DAT_14000a710 != 0) {
      in_stack_00000030 = 0;
      iVar3 = PsLookupProcessByProcessId(DAT_14000a688,&stack0x00000030);
      if (-1 < iVar3) {
        ObfDereferenceObject(in_stack_00000030);
      }
    }
    FUN_1400014d6();
    return;
  }
  *pcVar4 = *pcVar4 + (char)uVar2;
  in((short)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar5));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

