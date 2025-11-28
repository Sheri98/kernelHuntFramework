// Function: FUN_140001a20
// Address: 140001a20
// Decompiled by Ghidra


uint FUN_140001a20(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  longlong lVar5;
  ulonglong *puVar6;
  longlong *plVar7;
  char cVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  char *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  pbVar4 = *(byte **)(param_2 + 0xb8);
  lVar5 = *(longlong *)(param_1 + 0x40);
  uVar9 = 0xc0000002;
  puVar6 = *(ulonglong **)(param_2 + 0x18);
  uVar1 = *(uint *)(pbVar4 + 0x10);
  if ((*pbVar4 & 0xfd) == 0) {
LAB_140001d8e:
    uVar9 = 0;
    goto LAB_140001d90;
  }
  if (*pbVar4 != 0xe) goto LAB_140001d90;
  uVar2 = *(uint *)(pbVar4 + 0x18);
  if (uVar2 < 0xc3502801) {
    if (uVar2 == 0xc3502800) {
      DbgPrint("In Alloc function!!");
      uVar10 = FUN_140001788(lVar5,param_2);
      uVar9 = (uint)uVar10;
      pcVar15 = "Exit Alloc function!!";
    }
    else {
      if (uVar2 < 0xc3500e69) {
        if (uVar2 == 0xc3500e68) {
          uVar9 = FUN_140002a14(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e50) {
          uVar9 = FUN_1400024d0(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e54) {
          uVar9 = FUN_1400015ac(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e58) {
          uVar9 = FUN_14000140c(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e5c) {
          uVar9 = FUN_14000189c(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e60) {
          uVar9 = FUN_140001250(param_1,param_2,(longlong)pbVar4);
        }
        else if (uVar2 == 0xc3500e64) {
          uVar9 = FUN_140001338(param_1,param_2,(longlong)pbVar4);
        }
        goto LAB_140001d90;
      }
      if (uVar2 == 0xc3500e6c) {
        uVar9 = FUN_140002b4c(param_1,param_2,(longlong)pbVar4);
        goto LAB_140001d90;
      }
      if (uVar2 == 0xc3500e70) {
        DbgPrint("In SMBUS Control");
        uVar10 = FUN_1400023e0(param_1,param_2,(longlong)pbVar4);
        uVar9 = (uint)uVar10;
        pcVar15 = "Exit SMBUS Control";
      }
      else {
        if (uVar2 == 0xc3502000) {
          uVar10 = FUN_140001f1c(lVar5,param_2,(longlong)pbVar4);
          uVar9 = (uint)uVar10;
          goto LAB_140001d90;
        }
        if (uVar2 == 0xc3502004) {
          uVar9 = FUN_1400026f0(param_1,puVar6);
          if ((int)uVar9 < 0) {
            uVar9 = 0xc000000d;
            pcVar15 = "MAPMEM.SYS: memory map failed :(\n";
          }
          else {
            DbgPrint("Sizeof(PVOID)=%d",8);
            pcVar15 = "MAPMEM.SYS: memory successfully mapped\n";
            *(undefined8 *)(param_2 + 0x38) = 8;
          }
        }
        else {
          if (uVar2 != 0xc3502008) {
            if (uVar2 == 0xc3502580) {
              uVar10 = FUN_14000234c(lVar5,param_2,(longlong)pbVar4);
              uVar9 = (uint)uVar10;
            }
            goto LAB_140001d90;
          }
          DbgPrint("InputBufferLength=%d,szieof(PVOID)=%d",uVar1,8);
          if (uVar1 < 8) {
            uVar9 = 0xc000009a;
            pcVar15 = "MAPMEM.SYS: ZwUnmapViewOfSection failed\n";
          }
          else {
            uVar9 = ZwUnmapViewOfSection(0xffffffffffffffff,*puVar6);
            pcVar15 = "MAPMEM.SYS: memory successfully unmapped\n";
          }
        }
      }
    }
    DbgPrint(pcVar15);
    goto LAB_140001d90;
  }
  if (uVar2 < 0xc3506405) {
    if (uVar2 != 0xc3506404) {
      if (uVar2 == 0xc3502804) {
        uVar9 = FUN_1400017dc(lVar5,param_2,(longlong)pbVar4);
        goto LAB_140001d90;
      }
      if (uVar2 == 0xc3502808) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        cVar8 = FUN_1400029b4(puVar6);
        uVar9 = ~-(uint)(cVar8 != '\0') & 0xc000000d;
        goto LAB_140001d90;
      }
      if (uVar2 == 0xc350280c) {
        uVar10 = FUN_140001820(lVar5,param_2);
        uVar9 = (uint)uVar10;
        goto LAB_140001d90;
      }
      if (uVar2 == 0xc3502840) {
        if ((uVar1 == 0x10) && (*(int *)(pbVar4 + 8) == 0x10)) {
          uVar3 = (undefined4)puVar6[1];
          lVar11 = MmMapIoSpace((int)*puVar6,uVar3,0);
          if (lVar11 != 0) {
            lVar12 = IoAllocateMdl(lVar11,uVar3,0,0,0);
            if (lVar12 != 0) {
              MmBuildMdlForNonPagedPool(lVar12);
              uVar13 = MmMapLockedPages(lVar12,1);
              puVar14 = (undefined8 *)ExAllocatePool(0,0x28);
              puVar14[1] = lVar12;
              puVar14[2] = lVar11;
              puVar14[3] = uVar13;
              *(undefined4 *)(puVar14 + 4) = uVar3;
              *puVar14 = *(undefined8 *)(lVar5 + 0x18);
              *(undefined8 **)(lVar5 + 0x18) = puVar14;
              *puVar6 = uVar13;
              *(undefined8 *)(param_2 + 0x38) = 0x10;
              goto LAB_140001d8e;
            }
            MmUnmapIoSpace(lVar11,uVar3);
          }
          uVar9 = 0xc000009a;
          goto LAB_140001d90;
        }
      }
      else {
        if (uVar2 != 0xc3502844) {
          if (uVar2 != 0xc3506400) goto LAB_140001d90;
          goto LAB_140001d02;
        }
        if (uVar1 == 0x10) {
          *(undefined4 *)((longlong)puVar6 + 4) = 0;
          plVar16 = *(longlong **)(lVar5 + 0x18);
          if (plVar16 != (longlong *)0x0) {
            plVar17 = plVar16;
            do {
              if (plVar17[3] == *puVar6) {
                if ((int)plVar17[4] != (int)puVar6[1]) goto LAB_140001dbf;
                MmUnmapLockedPages(plVar17[3],plVar17[1]);
                IoFreeMdl(plVar17[1]);
                MmUnmapIoSpace(plVar17[2],(int)plVar17[4]);
                if (plVar17 == *(longlong **)(lVar5 + 0x18)) {
                  *(longlong *)(lVar5 + 0x18) = *plVar17;
                }
                else {
                  *plVar16 = *plVar17;
                }
                ExFreePoolWithTag(plVar17,0);
                goto LAB_140001d8e;
              }
              plVar7 = (longlong *)*plVar17;
              plVar16 = plVar17;
              plVar17 = plVar7;
            } while (plVar7 != (longlong *)0x0);
          }
          goto LAB_140001d90;
        }
      }
LAB_140001dbf:
      uVar9 = 0xc000000d;
      goto LAB_140001d90;
    }
  }
  else if (uVar2 != 0xc3506408) {
    if (((uVar2 + 0x3caf5bc0 & 0xfffffff3) == 0) && (uVar2 != 0xc350a44c)) {
      uVar10 = FUN_1400021c8(param_2,(longlong)pbVar4,uVar2);
      uVar9 = (uint)uVar10;
    }
    else if (uVar2 == 0xc350e44c) {
      uVar10 = FUN_14000204c(param_2,(longlong)pbVar4);
      uVar9 = (uint)uVar10;
    }
    else if (uVar2 == 0xc350e454) {
      uVar10 = FUN_1400020f8(param_1,param_2);
      uVar9 = (uint)uVar10;
    }
    goto LAB_140001d90;
  }
LAB_140001d02:
  uVar10 = FUN_140001f88(param_2,(longlong)pbVar4,uVar2);
  uVar9 = (uint)uVar10;
LAB_140001d90:
  *(uint *)(param_2 + 0x30) = uVar9;
  IofCompleteRequest(param_2,0);
  return uVar9;
}

