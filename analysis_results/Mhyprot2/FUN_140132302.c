// Function: FUN_140132302
// Address: 140132302
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001401323ed) overlaps instruction at (ram,0x0001401323e9)
    */

void FUN_140132302(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  longlong lVar4;
  byte bVar6;
  undefined8 uVar5;
  uint uVar7;
  byte in_CF;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  lVar4 = FUN_1400e6084();
  pbVar1 = (byte *)(lVar4 + -1);
  bVar6 = (byte)((ulonglong)param_1 >> 8);
  bVar2 = *pbVar1 - bVar6;
  uVar8 = *pbVar1 < bVar6 || bVar2 < in_CF;
  uVar10 = SBORROW1(*pbVar1,bVar6) != SBORROW1(bVar2,in_CF);
  *pbVar1 = bVar2 - in_CF;
  uVar9 = *pbVar1 == 0;
  uVar5 = CONCAT62((int6)((ulonglong)param_1 >> 0x10),CONCAT11(0xd0,(char)param_1));
  FUN_14009dd98();
  FUN_1400896ed(uVar5,param_2,param_3);
  uVar7 = (uint)param_2;
  lVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),0xbd);
  pcVar3 = (code *)swi(0xe8);
  (*pcVar3)();
  if ((bool)uVar10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_14009bdf8(lVar4,uVar7);
  FUN_14003609e();
  FUN_140062be5();
  if ((bool)uVar8 || (bool)uVar9) {
    if (lVar4 == 1) {
      FUN_14003609e();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    FUN_1400bf4a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

