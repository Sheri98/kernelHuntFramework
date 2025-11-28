// Function: FUN_000121e3
// Address: 000121e3
// Decompiled by Ghidra


undefined8 FUN_000121e3(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 in_RAX;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  
  iVar1 = *(int *)(longlong)param_1;
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (iVar1 == 1) {
    puVar2 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (iVar1 == 2) {
    puVar2 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (iVar1 == 3) {
    puVar2 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (iVar1 == 4) {
    puVar2 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (iVar1 == 5) {
    puVar2 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (iVar1 == 6) {
    puVar2 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (iVar1 == 7) {
    puVar2 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (iVar1 == 9) {
    puVar2 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (iVar1 == 10) {
    puVar2 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (iVar1 == 0xb) {
    puVar2 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (iVar1 == 0xd) {
    puVar2 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (iVar1 == 0xf) {
    puVar2 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (iVar1 == -0x7ffffffe) {
    puVar2 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (iVar1 == -0x7ffffffd) {
    puVar2 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (iVar1 == -0x7ffffffc) {
    puVar2 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar2 = (undefined4 *)cpuid(iVar1);
  }
  uVar3 = puVar2[1];
  uVar4 = puVar2[2];
  uVar5 = puVar2[3];
  *(undefined4 *)(longlong)param_1 = *puVar2;
  *(undefined4 *)(longlong)(param_1 + 4) = uVar3;
  *(undefined4 *)(longlong)(param_1 + 8) = uVar5;
  *(undefined4 *)(longlong)(param_1 + 0xc) = uVar4;
  *(uint *)(longlong)(param_1 + 0x10) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  return in_RAX;
}

