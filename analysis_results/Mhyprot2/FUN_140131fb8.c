// Function: FUN_140131fb8
// Address: 140131fb8
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_140131fb8(undefined8 param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *unaff_RDI;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  
  uVar1 = FUN_14003609e();
  if ((bool)in_ZF || in_OF != in_SF) {
    in((short)param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_RDI = uVar1;
  FUN_14009bdf8(param_1,param_2);
  FUN_140108673();
  in(0x68);
  if ((bool)in_ZF || in_OF != in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar2 = PsLookupProcessByProcessId();
  if (-1 < iVar2) {
    ObfDereferenceObject(0);
  }
  FUN_1400014d6();
  return;
}

