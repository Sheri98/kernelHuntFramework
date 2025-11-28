// Function: FUN_00015100
// Address: 00015100
// Decompiled by Ghidra


undefined8 FUN_00015100(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  
  if (*(uint *)(param_1 + 1) < 0x10) {
    uVar3 = 0xc000000d;
  }
  else {
    plVar8 = (longlong *)*param_1;
    lVar1 = *plVar8;
    lVar2 = plVar8[1];
    if ((param_1[2] == 0) || (param_1[2] == lVar1)) {
      uVar6 = (ulonglong)(*(uint *)(param_1 + 1) - 0x10);
      plVar8 = plVar8 + 2;
      uVar3 = FUN_0001155c(lVar2);
      puVar4 = (undefined1 *)MmMapIoSpace(uVar3,uVar6,0);
      if (puVar4 == (undefined1 *)0x0) {
        uVar3 = 0xc00000a0;
      }
      else {
        uVar5 = uVar6;
        puVar7 = puVar4;
        if (param_2 == '\0') {
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = (char)*plVar8;
            plVar8 = (longlong *)((longlong)plVar8 + 1);
            puVar7 = puVar7 + 1;
          }
          LOCK();
          UNLOCK();
        }
        else {
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)plVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            plVar8 = (longlong *)((longlong)plVar8 + 1);
          }
        }
        MmUnmapIoSpace(puVar4,uVar6);
        plVar8 = (longlong *)*param_1;
        uVar3 = 0;
        *plVar8 = lVar1;
        plVar8[1] = lVar2;
      }
    }
    else {
      uVar3 = 0xc0000005;
    }
  }
  return uVar3;
}

