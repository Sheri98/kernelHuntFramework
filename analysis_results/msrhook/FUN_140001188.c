// Function: FUN_140001188
// Address: 140001188
// Decompiled by Ghidra


ulonglong FUN_140001188(longlong param_1)

{
  longlong *plVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong local_res10;
  longlong local_res18;
  undefined1 local_38 [16];
  
  local_res10 = 0;
  local_res18 = 0;
  RtlInitUnicodeString(local_38,L"\\Driver\\Kbdclass");
  uVar3 = ObReferenceObjectByName
                    (local_38,0x40,0,0,*(undefined8 *)IoDriverObjectType_exref,0,0,&local_res18);
  if (-1 < (int)uVar3) {
    DbgPrint("KbdDriverObject:0x%x\n",&local_res18);
    DbgPrint("KbdDriverObject:0x%x\n",*(undefined8 *)(param_1 + 8));
    lVar7 = *(longlong *)(local_res18 + 8);
    uVar3 = uVar3 & 0xffffffff;
    while (lVar7 != 0) {
      DbgPrint("pTargetDeviceObject:0x%x\n",lVar7);
      plVar1 = (longlong *)(lVar7 + 0x10);
      DbgPrint("pTargetDeviceObject->NextDevice:0x%x\n",*plVar1);
      DbgPrint("pTargetDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar7 + 0x18));
      uVar4 = FUN_140001b8c(lVar7);
      if ((char)uVar4 == '\0') {
        uVar5 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0x40,0,*(undefined4 *)(lVar7 + 0x48),
                               *(undefined4 *)(lVar7 + 0x34),0,&local_res10);
        uVar3 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        DbgPrint("carete pFilterDeviceObject:0x%x\n",local_res10);
        lVar6 = IoAttachDeviceToDeviceStack(local_res10,lVar7);
        if (lVar6 == 0) {
          IoDeleteDevice(local_res10);
          return uVar3;
        }
        DbgPrint("pLowerDeviceObject:0x%x\n",lVar6);
        DbgPrint("pLowerDeviceObject->NextDevice:0x%x\n",*(undefined8 *)(lVar6 + 0x10));
        DbgPrint("pLowerDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar6 + 0x18));
        DbgPrint("pFilterDeviceObject->NextDevice:0x%x\n",*(undefined8 *)(local_res10 + 0x10));
        DbgPrint("pFilterDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(local_res10 + 0x18));
        DbgPrint("pTargetDeviceObject->NextDevice:0x%x\n",*plVar1);
        DbgPrint("pTargetDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar7 + 0x18));
        puVar2 = *(undefined4 **)(local_res10 + 0x40);
        FUN_1400020cc(puVar2,local_res10,lVar7,lVar6);
        *(undefined4 *)(local_res10 + 0x48) = *(undefined4 *)(lVar6 + 0x48);
        *(undefined4 *)(local_res10 + 0x34) = *(undefined4 *)(lVar6 + 0x34);
        *(char *)(local_res10 + 0x4c) = *(char *)(lVar6 + 0x4c) + '\x01';
        *(uint *)(local_res10 + 0x30) =
             *(uint *)(local_res10 + 0x30) | *(uint *)(lVar6 + 0x30) & 0x2014;
        DbgPrint("devExt->LowerDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xe));
        DbgPrint("devExt->TargetDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xc));
        DbgPrint("devExt->LowerDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xe));
        FUN_1400028f4(lVar7);
      }
      lVar7 = *plVar1;
    }
  }
  return uVar3;
}

