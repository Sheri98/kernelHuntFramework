// Function: FUN_00011344
// Address: 00011344
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_00011344(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int local_res10 [2];
  undefined4 local_res18 [4];
  int local_98;
  undefined4 uStack_94;
  ulonglong local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulonglong local_78;
  longlong local_70 [2];
  undefined4 local_60 [2];
  undefined8 local_58;
  undefined1 *local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined1 local_30 [24];
  
  uVar8 = *(uint *)(param_3 + 0x10);
  uVar1 = *(uint *)(param_3 + 8);
  puVar2 = *(ulonglong **)(param_2 + 0x18);
  local_80 = 0;
  local_70[1] = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((uVar8 < 0x18) || (uVar1 < 0x18)) {
    DbgPrint("(MAPMEM) Buffer size error\n");
    return 0xc000009a;
  }
  local_90 = *puVar2;
  local_res18[0] = 0;
  local_res10[0] = 0;
  uVar3 = puVar2[2];
  RtlInitUnicodeString(local_30,L"\\Device\\PhysicalMemory");
  local_50 = local_30;
  local_60[0] = 0x30;
  local_58 = 0;
  local_48 = 0x40;
  local_40 = 0;
  local_38 = 0;
  ZwOpenSection(&local_80,0xf001f,local_60);
  iVar6 = ObReferenceObjectByHandle(local_80,0xf001f,0,0,local_70 + 1,0);
  if (iVar6 < 0) {
    pcVar7 = "(MAPMEM) ObReferenceObjectByHandle failed\n";
  }
  else {
    local_88 = local_90 + (uint)uVar3;
    cVar4 = HalTranslateBusAddress(1,0,local_90,local_res10,&local_98);
    cVar5 = HalTranslateBusAddress(1,0,local_88,local_res18,&local_88);
    if ((cVar4 == '\0') || (cVar5 == '\0')) {
      pcVar7 = "(MAPMEM) HalTranslatephysicalAddress failed\n";
    }
    else {
      DbgPrint("(MAPMEM) physicalAddressbase=%8.8x %8.8x\n",uStack_94,local_98);
      DbgPrint("(MAPMEM) physicalAddressend=%8.8x %8.8x\n",local_88._4_4_,local_88 & 0xffffffff);
      local_70[0] = CONCAT44(uStack_94,local_98);
      uVar8 = (int)local_88 - local_98;
      if (uVar8 != 0) {
        if (local_res10[0] == 0) {
          local_90 = (ulonglong)uVar8;
          local_78 = 0;
          DbgPrint("viewBase:%x %x\n",uStack_94,local_98);
          iVar6 = ZwMapViewOfSection(local_80,0xffffffffffffffff,&local_78,0,local_90,local_70,
                                     &local_90,1,0,0x204);
          if (iVar6 < 0) {
            DbgPrint("(MAPMEM) ZwMapViewOfSection failed:%x\n",iVar6);
            goto LAB_00011604;
          }
          DbgPrint("(MAPMEM) physicalMemoryHandle=%x\n",local_80);
          local_78 = local_78 + (CONCAT44(uStack_94,local_98) - local_70[0]);
          uVar3 = puVar2[1];
          puVar2[1] = local_78;
          DbgPrint("(MAPMEM) virtualAddress=%x %x\n",(longlong)local_78 >> 0x20 & 0xffffffff,
                   (int)uVar3);
        }
        else {
          DbgPrint("inIoSpace = 1\n");
          *(int *)(puVar2 + 1) = local_98;
          *(undefined4 *)((longlong)puVar2 + 0xc) = uStack_94;
        }
        DbgPrint("(MAPMEM) memory successfully mapped\n");
        *(undefined8 *)(param_2 + 0x38) = 0x18;
        goto LAB_00011604;
      }
      pcVar7 = "(MAPMEM) mappedLength.LowPart == 0\n";
    }
  }
  DbgPrint(pcVar7);
LAB_00011604:
  ZwClose(local_80);
  return 0;
}

