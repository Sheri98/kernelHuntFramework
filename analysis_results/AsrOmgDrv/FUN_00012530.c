// Function: FUN_00012530
// Address: 00012530
// Decompiled by Ghidra


void FUN_00012530(void)

{
  undefined4 *puVar1;
  
  if (DAT_00014100 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (DAT_00014100 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (DAT_00014100 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (DAT_00014100 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (DAT_00014100 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (DAT_00014100 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (DAT_00014100 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (DAT_00014100 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (DAT_00014100 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (DAT_00014100 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (DAT_00014100 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (DAT_00014100 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (DAT_00014100 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (DAT_00014100 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (DAT_00014100 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (DAT_00014100 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(DAT_00014100);
  }
  DAT_00014100 = *puVar1;
  DAT_00014104 = puVar1[1];
  DAT_0001410c = puVar1[2];
  DAT_00014108 = puVar1[3];
  return;
}

