// Function: FUN_1400024d0
// Address: 1400024d0
// Decompiled by Ghidra


void FUN_1400024d0(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 *puVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  undefined1 local_58 [24];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_140005008 ^ (ulonglong)auStack_78;
  DbgPrint("Entry IoctlSMICmd");
  iVar1 = *(int *)(param_3 + 0x10);
  iVar2 = *(int *)(param_3 + 8);
  DbgPrint(&DAT_140003780);
  if ((iVar1 == 0x34) && (iVar2 == 0x34)) {
    DbgPrint("dbg1.9");
    DbgPrint(&DAT_1400037c0);
    uVar3 = *(undefined8 *)(param_1 + 0x40);
    DbgPrint("dbg2.5");
    KeAcquireInStackQueuedSpinLock(uVar3,local_58);
    DbgPrint();
    puVar4 = *(undefined2 **)(param_2 + 0x18);
    *(undefined1 *)(puVar4 + 4) = 0;
    local_40 = (ulonglong)CONCAT24(puVar4[5],(uint)*(byte *)(puVar4 + 1) | (uint)(ushort)puVar4[4]);
    uVar5 = local_40;
    puVar4[0xe] = 0;
    local_40._4_4_ = (uint)(ushort)puVar4[5];
    local_40 = CONCAT44(local_40._4_4_ | *(uint *)(puVar4 + 0xe),
                        (uint)*(byte *)(puVar4 + 1) | (uint)(ushort)puVar4[4]);
    local_38 = (ulonglong)CONCAT24(*puVar4,*(undefined4 *)(puVar4 + 0x10));
    local_30 = *(ulonglong *)(puVar4 + 0x14);
    local_28 = (ulonglong)*(uint *)(puVar4 + 0x18);
    DbgPrint("ext_ax= %x,ext_bx= %x",uVar5 & 0xffffffff);
    DbgPrint("ext_cx= %x,ext_dx= %x",local_38 & 0xffffffff,local_38._4_4_);
    DbgPrint("ext_si= %x,ext_di= %x",local_30 & 0xffffffff,local_30._4_4_);
    DbgPrint("ext_bp= %x",local_28 & 0xffffffff);
    DbgPrint(&DAT_140003860);
    FUN_140001100(&local_40);
    DbgPrint(&DAT_140003870);
    puVar4[4] = (undefined2)local_40;
    *(undefined4 *)(puVar4 + 0xc) = (undefined4)local_40;
    *(uint *)(puVar4 + 0xe) = local_40._4_4_;
    puVar4[5] = local_40._4_2_;
    *(undefined4 *)(puVar4 + 0x10) = (undefined4)local_38;
    puVar4[6] = (undefined2)local_38;
    *(undefined4 *)(puVar4 + 0x12) = local_38._4_4_;
    *(undefined4 *)(puVar4 + 0x14) = (undefined4)local_30;
    *(undefined4 *)(puVar4 + 0x16) = local_30._4_4_;
    puVar4[10] = local_28._4_2_;
    KeReleaseInStackQueuedSpinLock(local_58);
    DbgPrint("ext_bx= %x,ext_cx= %x",*(undefined4 *)(puVar4 + 0xe),*(undefined4 *)(puVar4 + 0x10));
    DbgPrint("org_ax= %x,org_cx= %x",puVar4[4],puVar4[6]);
    DbgPrint("ext_si= %x",*(undefined4 *)(puVar4 + 0x14));
    *(undefined8 *)(param_2 + 0x38) = 0x34;
  }
  else {
    DbgPrint("Buffer size not match !!");
  }
  FUN_140002e40(local_20 ^ (ulonglong)auStack_78);
  return;
}

