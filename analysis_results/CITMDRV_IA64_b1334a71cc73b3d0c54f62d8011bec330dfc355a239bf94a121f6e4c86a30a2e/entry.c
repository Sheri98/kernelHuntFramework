// Function: entry
// Address: 1000:0000
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000102f0) overlaps instruction at (ram,0x000102ef)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0001007a) */
/* WARNING: Removing unreachable block (ram,0x0001009c) */
/* WARNING: Removing unreachable block (ram,0x0001013e) */
/* WARNING: Removing unreachable block (ram,0x00010153) */
/* WARNING: Removing unreachable block (ram,0x00010211) */
/* WARNING: Removing unreachable block (ram,0x0001019d) */
/* WARNING: Removing unreachable block (ram,0x000101c3) */
/* WARNING: Removing unreachable block (ram,0x00010227) */
/* WARNING: Removing unreachable block (ram,0x000101c6) */
/* WARNING: Removing unreachable block (ram,0x000101eb) */
/* WARNING: Removing unreachable block (ram,0x000101ee) */
/* WARNING: Removing unreachable block (ram,0x00010285) */
/* WARNING: Removing unreachable block (ram,0x00010289) */
/* WARNING: Removing unreachable block (ram,0x00010213) */
/* WARNING: Removing unreachable block (ram,0x00010217) */
/* WARNING: Removing unreachable block (ram,0x0001023b) */
/* WARNING: Removing unreachable block (ram,0x0001023e) */
/* WARNING: Removing unreachable block (ram,0x0001025f) */
/* WARNING: Removing unreachable block (ram,0x0001024f) */
/* WARNING: Removing unreachable block (ram,0x00010278) */
/* WARNING: Removing unreachable block (ram,0x000102f0) */
/* WARNING: Removing unreachable block (ram,0x0001028b) */
/* WARNING: Removing unreachable block (ram,0x0001029f) */
/* WARNING: Removing unreachable block (ram,0x000102b7) */
/* WARNING: Removing unreachable block (ram,0x000103c3) */
/* WARNING: Removing unreachable block (ram,0x000103d3) */
/* WARNING: Removing unreachable block (ram,0x00010414) */

void entry(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  code *pcVar4;
  undefined2 in_CX;
  byte bVar5;
  undefined2 uVar6;
  int in_BX;
  undefined1 *puVar7;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined4 uVar8;
  
  bVar5 = (byte)((uint)in_CX >> 8);
  uRam000100b6 = 0x1000;
  puVar7 = (undefined1 *)0xb8;
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x21);
  uVar8 = (*pcVar4)();
  uVar6 = (undefined2)((ulong)uVar8 >> 0x10);
  *(undefined1 **)(puVar7 + -2) = puVar7;
  *(undefined2 *)(puVar7 + -4) = 0x7369;
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x72);
  *pbVar1 = *pbVar1 & (byte)((ulong)uVar8 >> 0x18);
  out(*unaff_SI,uVar6);
  uVar3 = in(uVar6);
  *unaff_DI = uVar3;
  pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 99);
  *pbVar1 = *pbVar1 & (byte)((ulong)uVar8 >> 8);
  out(*(undefined1 *)(unaff_SI + 1),uVar6);
  out(*(undefined1 *)((int)unaff_SI + 3),uVar6);
  out(unaff_SI[2],uVar6);
  if (*pbVar1 != 0) {
    out(*(undefined1 *)(unaff_SI + 3),uVar6);
    pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x70);
    *pbVar1 = *pbVar1 & bVar5;
    *(byte *)(unaff_SI + 0x2b) = *(byte *)(unaff_SI + 0x2b) & (byte)uVar8;
    *(int *)(puVar7 + -6) = in_BX;
    *(byte *)((int)unaff_DI + 0x71) = *(byte *)((int)unaff_DI + 0x71) & bVar5;
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

