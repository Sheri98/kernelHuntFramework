// Function: FUN_00011090
// Address: 00011090
// Decompiled by Ghidra


int FUN_00011090(ulonglong param_1,longlong param_2,longlong *param_3,undefined8 *param_4,
                undefined8 *param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  longlong local_res10 [2];
  undefined4 local_res20 [2];
  longlong local_98;
  longlong local_90;
  ulonglong local_88;
  ulonglong local_80;
  undefined1 local_78 [16];
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined1 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_98 = 0;
  local_res10[0] = param_2;
  DbgPrint("Entering MapPhysicalMemoryToLinearSpace");
  RtlInitUnicodeString(local_78,L"\\Device\\PhysicalMemory");
  local_58 = local_78;
  *param_4 = 0;
  *param_5 = 0;
  local_68[0] = 0x30;
  local_60 = 0;
  local_50 = 0x40;
  local_48 = 0;
  local_40 = 0;
  iVar3 = ZwOpenSection(param_4,0xf001f,local_68);
  if (iVar3 < 0) {
    DbgPrint("ERROR: ZwOpenSection failed");
  }
  else {
    iVar3 = ObReferenceObjectByHandle(*param_4,0xf001f,0,0,param_5,0);
    if (iVar3 < 0) {
      DbgPrint("ERROR: ObReferenceObjectByHandle failed");
    }
    else {
      local_88 = param_1 & 0xffffffff;
      local_90 = local_88 + local_res10[0];
      local_res20[0] = 0;
      cVar1 = HalTranslateBusAddress(1,0,local_88,local_res20,&local_88);
      local_res20[0] = 0;
      cVar2 = HalTranslateBusAddress(1,0,local_90,local_res20,&local_90);
      if ((cVar1 == '\0') || (cVar2 == '\0')) {
        DbgPrint("ERROR: HalTranslateBusAddress failed");
      }
      else {
        local_res10[0] = local_90 - local_88;
        local_80 = local_88;
        iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_98,0,local_res10[0],&local_80,
                                   local_res10,1,0,0x204);
        if (iVar3 == -0x3fffffe8) {
          iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_98,0,local_res10[0],
                                     &local_80,local_res10,1,0,4);
        }
        if (iVar3 < 0) {
          DbgPrint("ERROR: ZwMapViewOfSection failed");
        }
        else {
          local_98 = local_98 + (local_88 - local_80);
          *param_3 = local_98;
        }
      }
    }
  }
  if (iVar3 < 0) {
    ZwClose(*param_4);
  }
  DbgPrint("Leaving MapPhysicalMemoryToLinearSpace");
  return iVar3;
}

