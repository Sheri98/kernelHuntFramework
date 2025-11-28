// Function: FUN_000122a4
// Address: 000122a4
// Decompiled by Ghidra


ulonglong FUN_000122a4(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  char cVar2;
  longlong lVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong in_RAX;
  uint *puVar7;
  short sVar8;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  if (*(char *)(lVar3 + 0x58) == '\0') goto LAB_000123c6;
  *(int *)(lVar3 + 0x5c) = *(int *)(lVar3 + 0x5c) + 1;
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xb0) + (ulonglong)*(uint *)(lVar3 + 0x68) * 4);
  *piVar1 = *piVar1 + 1;
  if (*(char *)(lVar3 + 0x6c) == '\0') goto LAB_000123b2;
  if (*(char *)(lVar3 + 0x6d) == '\0') {
    puVar7 = *(uint **)(lVar3 + 0x80);
    if (*(int *)(lVar3 + 0x74) != 0) {
      puVar7 = (uint *)((longlong)puVar7 + (ulonglong)*(uint *)(lVar3 + 0x74));
    }
    cVar2 = *(char *)(lVar3 + 0x6e);
    if (*(char *)(lVar3 + 0x6f) != '\0') {
      if (cVar2 == '\x01') {
LAB_0001237f:
        *(byte *)puVar7 = *(byte *)(lVar3 + 0x78);
      }
      else if (cVar2 == '\x02') {
        *(ushort *)puVar7 = *(ushort *)(lVar3 + 0x78);
      }
      else {
        if (cVar2 != '\x04') goto LAB_0001237f;
        *puVar7 = *(uint *)(lVar3 + 0x78);
      }
      goto LAB_000123b2;
    }
    if (cVar2 == '\x01') {
LAB_0001239d:
      uVar6 = (uint)(byte)*puVar7;
    }
    else if (cVar2 == '\x02') {
      uVar6 = (uint)(ushort)*puVar7;
    }
    else {
      if (cVar2 != '\x04') goto LAB_0001239d;
      uVar6 = *puVar7;
    }
LAB_000123a0:
    *(uint *)(lVar3 + 0x78) = uVar6;
LAB_000123a4:
    *(undefined4 *)(*(longlong *)(lVar3 + 0xb0) + 0x40) = *(undefined4 *)(lVar3 + 0x78);
  }
  else {
    cVar2 = *(char *)(lVar3 + 0x6e);
    sVar8 = (short)*(undefined4 *)(lVar3 + 0x74) + (short)*(undefined4 *)(lVar3 + 0x70);
    if (*(char *)(lVar3 + 0x6f) == '\0') {
      if (cVar2 == '\x01') {
LAB_00012337:
        bVar4 = in(sVar8);
        uVar6 = (uint)bVar4;
      }
      else {
        if (cVar2 != '\x02') {
          if (cVar2 == '\x04') {
            uVar6 = in(sVar8);
            goto LAB_000123a0;
          }
          goto LAB_00012337;
        }
        uVar5 = in(sVar8);
        uVar6 = (uint)uVar5;
      }
      *(uint *)(lVar3 + 0x78) = uVar6;
      goto LAB_000123a4;
    }
    if (cVar2 == '\x01') {
LAB_00012316:
      out(sVar8,*(undefined1 *)(lVar3 + 0x78));
    }
    else if (cVar2 == '\x02') {
      out(sVar8,*(undefined2 *)(lVar3 + 0x78));
    }
    else {
      if (cVar2 != '\x04') goto LAB_00012316;
      out(sVar8,*(undefined4 *)(lVar3 + 0x78));
    }
  }
LAB_000123b2:
  in_RAX = KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),0);
LAB_000123c6:
  return in_RAX & 0xffffffffffffff00;
}

