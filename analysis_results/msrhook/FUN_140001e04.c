// Function: FUN_140001e04
// Address: 140001e04
// Decompiled by Ghidra


ulonglong FUN_140001e04(undefined8 param_1)

{
  longlong *plVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong local_res18;
  longlong local_res20;
  undefined4 uVar8;
  undefined8 uVar7;
  undefined1 local_38 [16];
  
  local_res18 = 0;
  local_res20 = 0;
  RtlInitUnicodeString(local_38,L"\\Driver\\Kbdclass");
  uVar7 = *(undefined8 *)IoDriverObjectType_exref;
  uVar4 = ObReferenceObjectByName(local_38,0x40,0,0,uVar7,0,0,&local_res20);
  if (-1 < (int)uVar4) {
    ObfDereferenceObject(param_1);
    DbgPrint("KbdDriverObject:0x%x\n",local_res20);
    lVar6 = *(longlong *)(local_res20 + 8);
    uVar4 = uVar4 & 0xffffffff;
    while (uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20), lVar6 != 0) {
      DbgPrint("pTargetDeviceObject:0x%x\n",lVar6);
      plVar1 = (longlong *)(lVar6 + 0x10);
      DbgPrint("pTargetDeviceObject->NextDevice:0x%x\n",*plVar1);
      DbgPrint("pTargetDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar6 + 0x18));
      uVar7 = CONCAT44(uVar8,*(undefined4 *)(lVar6 + 0x34));
      uVar3 = IoCreateDevice(param_1,0x40,0,*(undefined4 *)(lVar6 + 0x48),uVar7,0,&local_res18);
      uVar4 = (ulonglong)uVar3;
      DbgPrint("carete pFilterDeviceObject:0x%x\n",local_res18);
      if ((int)uVar3 < 0) {
        return uVar4;
      }
      lVar5 = IoAttachDeviceToDeviceStack(local_res18,lVar6);
      if (lVar5 == 0) {
        IoDeleteDevice(local_res18);
        return uVar4;
      }
      DbgPrint("pLowerDeviceObject:0x%x\n",lVar5);
      DbgPrint("pLowerDeviceObject->NextDevice:0x%x\n",*(undefined8 *)(lVar5 + 0x10));
      DbgPrint("pLowerDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar5 + 0x18));
      DbgPrint("pFilterDeviceObject->NextDevice:0x%x\n",*(undefined8 *)(local_res18 + 0x10));
      DbgPrint("pFilterDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(local_res18 + 0x18));
      DbgPrint("pTargetDeviceObject->NextDevice:0x%x\n",*plVar1);
      DbgPrint("pTargetDeviceObject->AttachedDevice:0x%x\n",*(undefined8 *)(lVar6 + 0x18));
      puVar2 = *(undefined4 **)(local_res18 + 0x40);
      FUN_1400020cc(puVar2,local_res18,lVar6,lVar5);
      *(undefined4 *)(local_res18 + 0x48) = *(undefined4 *)(lVar5 + 0x48);
      *(undefined4 *)(local_res18 + 0x34) = *(undefined4 *)(lVar5 + 0x34);
      *(char *)(local_res18 + 0x4c) = *(char *)(lVar5 + 0x4c) + '\x01';
      *(uint *)(local_res18 + 0x30) =
           *(uint *)(local_res18 + 0x30) | *(uint *)(lVar5 + 0x30) & 0x2014;
      DbgPrint("devExt->LowerDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xe));
      DbgPrint("devExt->TargetDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xc));
      DbgPrint("devExt->LowerDeviceObject:0x%x\n",*(undefined8 *)(puVar2 + 0xe));
      FUN_140001860(local_res18);
      FUN_1400028f4(lVar6);
      lVar6 = *plVar1;
    }
  }
  return uVar4;
}

