// Function: FUN_000123cc
// Address: 000123cc
// Decompiled by Ghidra


undefined8 FUN_000123cc(longlong param_1,int *param_2,int param_3,longlong param_4)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  plVar5 = (longlong *)(param_1 + 0x10);
  uVar7 = 0xc0000001;
  plVar3 = (longlong *)*plVar5;
  if (plVar3 != plVar5) {
    do {
      plVar6 = plVar3 + -0x45;
      if ((int)*plVar6 == *param_2) goto LAB_00012408;
      plVar3 = (longlong *)*plVar3;
    } while (plVar3 != plVar5);
  }
  plVar6 = (longlong *)0x0;
LAB_00012408:
  if (plVar6 != (longlong *)0x0) {
    lVar4 = IoBuildAsynchronousFsdRequest
                      ((param_3 != 0x22288c) + '\x03',plVar6[0x43],*(undefined8 *)(param_2 + 6),
                       param_2[4],param_2 + 2,0);
    if (lVar4 != 0) {
      uVar7 = 0x103;
      pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      *(undefined8 *)(param_4 + 0x38) = 0x20;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = FUN_00012320;
      *(longlong *)(lVar2 + -8) = param_4;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      IofCallDriver(plVar6[0x43],lVar4);
    }
  }
  return uVar7;
}

