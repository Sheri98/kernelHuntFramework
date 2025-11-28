// Function: FUN_00011000
// Address: 00011000
// Decompiled by Ghidra


undefined8 FUN_00011000(undefined2 param_1,undefined4 param_2,char param_3)

{
  if (param_3 == '\x01') {
    out(param_1,(char)param_2);
  }
  else if (param_3 == '\x02') {
    out(param_1,(short)param_2);
  }
  else if (param_3 == '\x04') {
    out(param_1,param_2);
  }
  return 1;
}

