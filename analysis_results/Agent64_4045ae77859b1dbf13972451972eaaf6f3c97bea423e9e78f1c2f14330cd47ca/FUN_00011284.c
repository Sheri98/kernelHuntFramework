// Function: FUN_00011284
// Address: 00011284
// Decompiled by Ghidra


uint FUN_00011284(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  byte bVar10;
  undefined1 uVar11;
  ushort uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined8 uVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  uint uVar22;
  ulonglong *puVar23;
  ulonglong *puVar24;
  longlong local_res8;
  undefined8 local_58 [5];
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  puVar24 = *(ulonglong **)(param_2 + 0x18);
  uVar15 = 0;
  uVar13 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  puVar5 = *(undefined8 **)(param_1 + 0x40);
  if (*pcVar4 == '\0') {
    uVar13 = FUN_00012178(puVar24,(longlong)puVar5,param_2);
    goto LAB_0001197c;
  }
  if (*pcVar4 != '\x02') {
    if (*pcVar4 == '\x0e') {
      uVar18 = *(uint *)(pcVar4 + 0x18);
      if (0x8000204c < uVar18) {
        if (uVar18 < 0x80002085) {
          if (uVar18 == 0x80002084) {
            FUN_00012960(local_58,puVar24,0x20);
            uVar14 = 0xffffff;
LAB_00011948:
            FUN_00012700((undefined4 *)local_58,uVar14);
            FUN_00012960(puVar24,local_58,0x20);
            *(undefined8 *)(param_2 + 0x38) = 0x20;
            goto LAB_0001197c;
          }
          if (uVar18 == 0x80002050) {
            uVar21 = (ulonglong)*(uint *)((longlong)puVar24 + 4);
            puVar23 = puVar24 + 1;
            while (uVar21 != 0) {
              uVar21 = uVar21 - 1;
              out((short)*puVar23,(short)*puVar24);
              puVar23 = (ulonglong *)((longlong)puVar23 + 2);
            }
          }
          else if (uVar18 == 0x80002054) {
            uVar21 = (ulonglong)*(uint *)((longlong)puVar24 + 4);
            puVar23 = puVar24 + 1;
            while (uVar21 != 0) {
              uVar21 = uVar21 - 1;
              out((int)*puVar23,(short)*puVar24);
              puVar23 = (ulonglong *)((longlong)puVar23 + 4);
            }
          }
          else {
            if (uVar18 == 0x80002064) {
              uVar15 = FUN_000119a0((uint)*(ushort *)((longlong)puVar24 + 2),
                                    (uint)*(ushort *)((longlong)puVar24 + 4),
                                    (uint)*(ushort *)((longlong)puVar24 + 6),
                                    (ulonglong)*(uint *)(pcVar4 + 8),(int *)puVar24);
              *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar15;
              goto LAB_0001197c;
            }
            if (uVar18 == 0x80002068) {
              uVar16 = FUN_00011e48(puVar24,puVar5,param_2);
              uVar13 = (uint)uVar16;
              goto LAB_0001197c;
            }
            uVar17 = uVar15;
            uVar22 = uVar15;
            if (uVar18 == 0x8000206c) {
LAB_000116b4:
              do {
                bVar10 = in(100);
                uVar18 = uVar15;
                if ((bVar10 & 1) == 0) {
LAB_000116c6:
                  do {
                    bVar10 = in(100);
                    if ((bVar10 & 2) == 0) goto LAB_000116d8;
                    uVar18 = uVar18 + 1;
                  } while (uVar18 < 0xffdc);
                  if ((bVar10 & 2) == 0) {
LAB_000116d8:
                    out(100,0xd2);
                    uVar18 = uVar15;
                    do {
                      bVar10 = in(100);
                      if ((bVar10 & 2) == 0) goto LAB_00011701;
                      uVar18 = uVar18 + 1;
                    } while (uVar18 < 0xffdc);
                    if ((bVar10 & 2) == 0) {
LAB_00011701:
                      out(0x60,(char)*puVar24);
                      in(0x60);
                      uVar11 = 1;
                      goto LAB_0001170e;
                    }
                  }
                }
                else {
                  uVar17 = uVar17 + 1;
                  if (uVar17 < 0xffdc) goto LAB_000116b4;
                  if ((bVar10 & 1) == 0) goto LAB_000116c6;
                }
                uVar22 = uVar22 + 1;
                in(0x60);
                uVar17 = uVar15;
              } while (uVar22 < 6);
              uVar11 = 0;
LAB_0001170e:
              *(undefined1 *)puVar24 = uVar11;
              *(undefined8 *)(param_2 + 0x38) = 1;
              goto LAB_0001197c;
            }
            if ((uVar18 == 0x80002070) || (uVar18 == 0x80002074)) goto LAB_000112dc;
            if (uVar18 != 0x8000207c) {
LAB_000117fc:
              uVar13 = 0xc000000d;
              goto LAB_0001197c;
            }
            lVar19 = puVar5[0x13];
            if (lVar19 != 0) {
LAB_0001137c:
              KeSetEvent(lVar19,0,0);
            }
          }
        }
        else {
          if (uVar18 == 0x80002088) {
            FUN_00012960(local_58,puVar24,0x20);
            uVar14 = 0xffffffff;
            goto LAB_00011948;
          }
          if (uVar18 == 0x8000208c) {
            if ((int)puVar24[2] != 0) {
              uVar21 = puVar24[2];
              uVar20 = puVar24[3];
              MmUnmapLockedPages(*(undefined4 *)((longlong)puVar24 + 0xc),uVar21);
              IoFreeMdl(uVar21);
              MmFreeContiguousMemory(uVar20);
            }
          }
          else {
            if (uVar18 == 0x800020a0) {
              uVar13 = FUN_00011f54((short *)puVar24,puVar5,param_2,
                                    (ulonglong)*(uint *)(pcVar4 + 0x10),*(uint *)(pcVar4 + 8));
              goto LAB_0001197c;
            }
            if (uVar18 == 0x800020a4) {
              uVar13 = FUN_0001204c((short *)puVar24,puVar5,param_2);
              goto LAB_0001197c;
            }
            if (uVar18 == 0x800020e8) {
              *(undefined4 *)puVar24 = 0x7fffdf17;
LAB_000113fc:
              *(undefined8 *)(param_2 + 0x38) = 4;
              goto LAB_0001197c;
            }
            if (uVar18 == 0x800020ec) {
              uVar16 = rdmsr((int)puVar24[1]);
              *(int *)puVar24 = (int)uVar16;
              *(int *)((longlong)puVar24 + 4) = (int)((ulonglong)uVar16 >> 0x20);
              *(undefined8 *)(param_2 + 0x38) = 0xc;
              goto LAB_0001197c;
            }
            if (uVar18 == 0x800020f0) {
              wrmsr(0x8b,0);
              iVar3 = (int)*puVar24;
              if (iVar3 == 0) {
                puVar6 = (undefined4 *)cpuid_basic_info(0);
              }
              else if (iVar3 == 1) {
                puVar6 = (undefined4 *)cpuid_Version_info(1);
              }
              else if (iVar3 == 2) {
                puVar6 = (undefined4 *)cpuid_cache_tlb_info(2);
              }
              else if (iVar3 == 3) {
                puVar6 = (undefined4 *)cpuid_serial_info(3);
              }
              else if (iVar3 == 4) {
                puVar6 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
              }
              else if (iVar3 == 5) {
                puVar6 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
              }
              else if (iVar3 == 6) {
                puVar6 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
              }
              else if (iVar3 == 7) {
                puVar6 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
              }
              else if (iVar3 == 9) {
                puVar6 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
              }
              else if (iVar3 == 10) {
                puVar6 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
              }
              else if (iVar3 == 0xb) {
                puVar6 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
              }
              else if (iVar3 == 0xd) {
                puVar6 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
              }
              else if (iVar3 == 0xf) {
                puVar6 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
              }
              else if (iVar3 == -0x7ffffffe) {
                puVar6 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
              }
              else if (iVar3 == -0x7ffffffd) {
                puVar6 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
              }
              else if (iVar3 == -0x7ffffffc) {
                puVar6 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
              }
              else {
                puVar6 = (undefined4 *)cpuid(iVar3);
              }
              uVar14 = *puVar6;
              uVar7 = puVar6[1];
              uVar8 = puVar6[2];
              *(undefined4 *)((longlong)puVar24 + 0x14) = puVar6[3];
              *(undefined4 *)(puVar24 + 3) = uVar14;
              *(undefined4 *)((longlong)puVar24 + 0xc) = uVar7;
              *(undefined4 *)(puVar24 + 2) = uVar8;
              uVar16 = rdmsr(0x8b);
              *(int *)((longlong)puVar24 + 4) = (int)uVar16;
              *(int *)(puVar24 + 1) = (int)((ulonglong)uVar16 >> 0x20);
              *(undefined8 *)(param_2 + 0x38) = 0x1c;
              goto LAB_0001197c;
            }
            if (uVar18 != 0x800020f4) goto LAB_000117fc;
            wrmsr((int)puVar24[1],CONCAT44(*(undefined4 *)((longlong)puVar24 + 4),(int)puVar24[1]));
          }
        }
LAB_00011457:
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar13 = uVar15;
        goto LAB_0001197c;
      }
      if (uVar18 == 0x8000204c) {
        uVar21 = (ulonglong)*(uint *)((longlong)puVar24 + 4);
        puVar23 = puVar24 + 1;
        while (uVar21 != 0) {
          uVar21 = uVar21 - 1;
          out((char)*puVar23,(short)*puVar24);
          puVar23 = (ulonglong *)((longlong)puVar23 + 1);
        }
        goto LAB_00011457;
      }
      if (uVar18 < 0x80002029) {
        if (uVar18 != 0x80002028) {
          if (uVar18 == 0x80002008) {
            uVar13 = FUN_00011b34(puVar24,(longlong)puVar5,param_2);
            goto LAB_0001197c;
          }
          if (uVar18 == 0x8000200c) {
            lVar19 = puVar5[0x15];
            while (lVar9 = lVar19, lVar9 != 0) {
              if (*(ulonglong *)(lVar9 + 0x18) == *puVar24) {
                piVar1 = (int *)(puVar5 + 0x14);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                  puVar5[0x15] = 0;
                }
                else if (lVar9 == puVar5[0x15]) {
                  puVar5[0x15] = *(undefined8 *)(lVar9 + 0x20);
                }
                else {
                  *(undefined8 *)(local_res8 + 0x20) = *(undefined8 *)(lVar9 + 0x20);
                }
                if (lVar9 != 0) {
                  ZwUnmapViewOfSection(0xffffffffffffffff);
                  ExFreePoolWithTag(lVar9,0);
                }
                break;
              }
              local_res8 = lVar9;
              lVar19 = *(longlong *)(lVar9 + 0x20);
            }
            goto LAB_0001197c;
          }
          if (uVar18 == 0x80002010) {
            uVar16 = FUN_00011c0c((int *)puVar24,(longlong)puVar5,param_2);
            uVar13 = (uint)uVar16;
            goto LAB_0001197c;
          }
          if (uVar18 == 0x80002014) {
            if (puVar5[0x16] != 0) {
              MmUnmapLockedPages(puVar5[0x18],puVar5[0x17]);
              IoFreeMdl(puVar5[0x17]);
              ExFreePoolWithTag(puVar5[0x16],0);
            }
            puVar5[0x16] = 0;
            puVar5[0x17] = 0;
            puVar5[0x18] = 0;
          }
          else {
            if (uVar18 == 0x80002018) {
              *(undefined4 *)puVar24 = *(undefined4 *)((longlong)puVar5 + 0x5c);
              goto LAB_000113fc;
            }
            if (uVar18 == 0x8000201c) {
              *(undefined4 *)puVar24 = *(undefined4 *)((longlong)puVar5 + 0x5c);
              if ((*(char *)(puVar5 + 0xb) != '\0') && (puVar5[2] != 0)) {
                IoDisconnectInterrupt();
                if (puVar5[0x10] != 0) {
                  MmUnmapIoSpace(puVar5[0x10],*(undefined4 *)(puVar5 + 0x12));
                  IoFreeMdl(puVar5[0x11]);
                }
              }
              *(undefined1 *)(puVar5 + 0xb) = 0;
              goto LAB_000113e8;
            }
            if (uVar18 == 0x80002020) {
              uVar16 = FUN_00011d2c((int *)puVar24,puVar5,param_2);
              uVar13 = (uint)uVar16;
              goto LAB_0001197c;
            }
            if (uVar18 != 0x80002024) goto LAB_000117fc;
            if (*(char *)(puVar5 + 0xb) != '\0') {
              piVar1 = (int *)(puVar5[0x16] + (ulonglong)*(uint *)(puVar5 + 0xd) * 4);
              *piVar1 = *piVar1 + 1;
              *(int *)((longlong)puVar5 + 0x5c) = *(int *)((longlong)puVar5 + 0x5c) + 1;
              lVar19 = puVar5[0xc];
              goto LAB_0001137c;
            }
          }
          goto LAB_00011457;
        }
        bVar10 = in((short)*puVar24);
        uVar15 = (uint)bVar10;
LAB_0001151c:
        *(uint *)puVar24 = uVar15;
      }
      else {
        if (uVar18 == 0x8000202c) {
          uVar12 = in((short)*puVar24);
          uVar15 = (uint)uVar12;
          goto LAB_0001151c;
        }
        if (uVar18 != 0x80002030) {
          if (uVar18 == 0x80002034) {
            out((short)*puVar24,*(undefined1 *)((longlong)puVar24 + 4));
          }
          else if (uVar18 == 0x80002038) {
            out((short)*puVar24,*(undefined2 *)((longlong)puVar24 + 4));
          }
          else {
            if (uVar18 != 0x8000203c) {
              if (uVar18 == 0x80002040) {
                uVar15 = *(uint *)((longlong)puVar24 + 4);
                uVar20 = (ulonglong)uVar15;
                uVar21 = *puVar24;
                puVar24 = puVar24 + 1;
                while (uVar20 != 0) {
                  uVar20 = uVar20 - 1;
                  uVar11 = in((short)uVar21);
                  *(undefined1 *)puVar24 = uVar11;
                  puVar24 = (ulonglong *)((longlong)puVar24 + 1);
                }
                uVar21 = (ulonglong)(uVar15 + 8);
              }
              else if (uVar18 == 0x80002044) {
                uVar15 = *(uint *)((longlong)puVar24 + 4);
                uVar20 = (ulonglong)uVar15;
                uVar21 = *puVar24;
                puVar24 = puVar24 + 1;
                while (uVar20 != 0) {
                  uVar20 = uVar20 - 1;
                  uVar2 = in((short)uVar21);
                  *(undefined2 *)puVar24 = uVar2;
                  puVar24 = (ulonglong *)((longlong)puVar24 + 2);
                }
                uVar21 = (ulonglong)(uVar15 * 2 + 8);
              }
              else {
                if (uVar18 != 0x80002048) goto LAB_000117fc;
                uVar15 = *(uint *)((longlong)puVar24 + 4);
                uVar20 = (ulonglong)uVar15;
                uVar21 = *puVar24;
                puVar24 = puVar24 + 1;
                while (uVar20 != 0) {
                  uVar20 = uVar20 - 1;
                  uVar14 = in((short)uVar21);
                  *(undefined4 *)puVar24 = uVar14;
                  puVar24 = (ulonglong *)((longlong)puVar24 + 4);
                }
                uVar21 = (ulonglong)(uVar15 * 4 + 8);
              }
              *(ulonglong *)(param_2 + 0x38) = uVar21;
              goto LAB_0001197c;
            }
            out((short)*puVar24,*(undefined4 *)((longlong)puVar24 + 4));
          }
          goto LAB_00011457;
        }
        uVar14 = in((short)*puVar24);
        *(undefined4 *)puVar24 = uVar14;
      }
LAB_000113e8:
      *(undefined8 *)(param_2 + 0x38) = 4;
      goto LAB_0001197c;
    }
    uVar13 = uVar15;
    if (*pcVar4 != '\x12') goto LAB_0001197c;
    *(undefined4 *)(puVar5 + 0x14) = 0;
    puVar5[0x15] = 0;
  }
LAB_000112dc:
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar13 = uVar15;
LAB_0001197c:
  *(uint *)(param_2 + 0x30) = uVar13;
  IofCompleteRequest(param_2,0);
  return uVar13;
}

