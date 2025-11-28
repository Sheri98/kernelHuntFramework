// Function: FUN_140005be0
// Address: 140005be0
// Decompiled by Ghidra


void FUN_140005be0(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  vsprintf_s(param_1,0x200,param_2,(va_list)&local_res18);
  return;
}

