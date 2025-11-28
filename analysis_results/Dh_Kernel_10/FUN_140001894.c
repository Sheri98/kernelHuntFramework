// Function: FUN_140001894
// Address: 140001894
// Decompiled by Ghidra


ulonglong FUN_140001894(longlong param_1)

{
  byte *pbVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int *piVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  ulonglong local_18;
  
  puVar11 = (undefined8 *)auStack_48;
  local_18 = DAT_140004010 ^ (ulonglong)auStack_48;
  lVar10 = 0;
  DbgPrintEx(0,0,"Unload");
  puVar12 = &DAT_1400040c8;
  while( true ) {
    if ((undefined8 **)DAT_1400040c8 == &DAT_1400040c8) {
      puVar12 = &DAT_1400040b8;
      while( true ) {
        if (DAT_1400040b8 == puVar12) {
          *(undefined8 *)((longlong)puVar11 + -8) = 0x14000194c;
          RtlInitUnicodeString
                    ((undefined1 *)((longlong)puVar11 + 0x20),L"\\DosDevices\\DianHuRing0");
          *(undefined8 *)((longlong)puVar11 + -8) = 0x140001957;
          IoDeleteSymbolicLink((undefined1 *)((longlong)puVar11 + 0x20));
          uVar3 = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)((longlong)puVar11 + -8) = 0x140001961;
          IoDeleteDevice(uVar3);
          *(undefined8 *)((longlong)puVar11 + -8) = 0x14000196e;
          uVar7 = FUN_140001c10(*(ulonglong *)((longlong)puVar11 + 0x30) ^ (ulonglong)puVar11);
          return uVar7;
        }
LAB_14000190a:
        puVar2 = (undefined8 *)DAT_1400040c0[1];
        if (((undefined8 *)*DAT_1400040c0 != puVar12) || ((undefined8 *)*puVar2 != DAT_1400040c0))
        break;
        lVar10 = 0;
        DAT_1400040c0 = puVar2;
        *puVar2 = puVar12;
        puVar11[-1] = 0x140001931;
        ExFreePoolWithTag();
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)();
      puVar11[2] = param_1;
      *puVar11 = puVar12;
      uVar7 = 0;
      if ((*(longlong *)(lVar10 + 0xb8) != 0) &&
         (((piVar4 = *(int **)(lVar10 + 0x18), piVar4 != (int *)0x0 &&
           (*(longlong *)(piVar4 + 5) != 0)) && (uVar7 = 0, *piVar4 == -0x77885545)))) {
        uVar9 = 0x811c9dc5;
        lVar8 = 0;
        do {
          pbVar1 = (byte *)(lVar8 + (longlong)piVar4);
          lVar8 = lVar8 + 1;
          uVar6 = *pbVar1 ^ uVar9;
          uVar9 = uVar6 * 0x1000193;
        } while (lVar8 < 0x2c);
        uVar6 = uVar6 * 0x1326193;
        uVar9 = (uVar6 >> 7 ^ uVar6) * 9;
        uVar9 = (uVar9 >> 0x11 ^ uVar9) * 0x21;
        if ((uint)((ulonglong)uVar9 * 0x780ed4c7 >> 0x3e) * 0x77885545 + uVar9 == piVar4[0xb]) {
          puVar11[-5] = 0x140001a0a;
          uVar9 = FUN_1400013dc((undefined8 *)piVar4);
          uVar7 = (ulonglong)uVar9;
        }
      }
      *(undefined8 *)(lVar10 + 0x38) = 0;
      *(int *)(lVar10 + 0x30) = (int)uVar7;
      puVar11[-5] = 0x140001a1f;
      IofCompleteRequest(lVar10,0);
      return uVar7;
    }
    puVar2 = (undefined8 *)DAT_1400040d0[1];
    if (((undefined8 **)*DAT_1400040d0 != &DAT_1400040c8) ||
       ((undefined8 *)*puVar2 != DAT_1400040d0)) break;
    lVar10 = 0;
    DAT_1400040d0 = puVar2;
    *puVar2 = &DAT_1400040c8;
    ExFreePoolWithTag();
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar11 = (undefined8 *)auStack_40;
  goto LAB_14000190a;
}

