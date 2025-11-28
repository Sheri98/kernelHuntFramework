// Function: entry
// Address: 1000:0000
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00010042) overlaps instruction at (ram,0x00010040)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0001007a) */
/* WARNING: Removing unreachable block (ram,0x0001009c) */

void entry(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  code *pcVar4;
  byte in_CH;
  undefined2 uVar5;
  int in_BX;
  undefined1 *puVar6;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined4 uVar7;
  
  uRam000100b6 = 0x1000;
  puVar6 = (undefined1 *)0xb8;
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x21);
  uVar7 = (*pcVar4)();
  uVar5 = (undefined2)((ulong)uVar7 >> 0x10);
  *(undefined1 **)(puVar6 + -2) = puVar6;
  *(undefined2 *)(puVar6 + -4) = 0x7369;
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x72);
  *pbVar1 = *pbVar1 & (byte)((ulong)uVar7 >> 0x18);
  out(*unaff_SI,uVar5);
  uVar3 = in(uVar5);
  *unaff_DI = uVar3;
  pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 99);
  *pbVar1 = *pbVar1 & (byte)((ulong)uVar7 >> 8);
  out(*(undefined1 *)(unaff_SI + 1),uVar5);
  out(*(undefined1 *)((int)unaff_SI + 3),uVar5);
  out(unaff_SI[2],uVar5);
  if (*pbVar1 != 0) {
    out(*(undefined1 *)(unaff_SI + 3),uVar5);
    pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x70);
    *pbVar1 = *pbVar1 & in_CH;
    *(byte *)(unaff_SI + 0x2b) = *(byte *)(unaff_SI + 0x2b) & (byte)uVar7;
    *(int *)(puVar6 + -6) = in_BX;
    *(byte *)((int)unaff_DI + 0x71) = *(byte *)((int)unaff_DI + 0x71) & in_CH;
    puVar2 = (undefined1 *)((int)unaff_SI + in_BX + 7);
    *puVar2 = *puVar2;
    puVar2 = (undefined1 *)((int)unaff_SI + in_BX + 7);
    *puVar2 = *puVar2;
    puVar2 = (undefined1 *)((int)unaff_SI + in_BX + 7);
    *puVar2 = *puVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(0xc3);
  pcVar4 = (code *)swi(1);
  (*pcVar4)();
  return;
}

