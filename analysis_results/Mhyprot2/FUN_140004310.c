// Function: FUN_140004310
// Address: 140004310
// Decompiled by Ghidra


undefined8 FUN_140004310(longlong *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 local_res8 [2];
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res8[0] = 0;
  local_res20 = 0;
  local_res18 = 0;
  uVar1 = FUN_1400043c0(*param_1,local_res8);
  if ((((int)uVar1 != -0x3fffffff) &&
      (uVar1 = FUN_14000453c(param_1[2],&local_res18), (int)uVar1 != -0x3fffffff)) &&
     (uVar1 = FUN_140004250(param_1[1],&local_res20), (int)uVar1 != -0x3fffffff)) {
    ObReferenceObjectByHandle
              (param_1[3],2,*(undefined8 *)ExEventObjectType_exref,1,&DAT_14000a5f0,0);
    *param_2 = local_res8[0];
    param_2[2] = local_res18;
    param_2[1] = local_res20;
    return 0;
  }
  return 0xc0000001;
}

