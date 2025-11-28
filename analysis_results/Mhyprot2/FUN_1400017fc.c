// Function: FUN_1400017fc
// Address: 1400017fc
// Decompiled by Ghidra


int FUN_1400017fc(longlong *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong local_res20;
  undefined8 uStack_3d0;
  undefined1 auStack_3c8 [32];
  undefined8 local_3a8;
  longlong local_3a0 [3];
  int local_388 [2];
  undefined8 local_380;
  undefined1 local_378 [16];
  undefined4 local_368 [2];
  undefined8 local_360;
  undefined1 *local_358;
  undefined4 local_350;
  undefined8 local_348;
  undefined8 uStack_340;
  longlong local_330 [99];
  
  puVar6 = auStack_3c8;
  local_380 = 0;
  RtlInitUnicodeString(local_378,L"\\Driver");
  local_368[0] = 0x30;
  local_360 = 0;
  local_350 = 0x40;
  local_358 = local_378;
  local_348 = 0;
  uStack_340 = 0;
  iVar3 = ZwOpenDirectoryObject(&local_380,3,local_368);
  if (iVar3 == 0) {
    local_388[0] = 0;
    while( true ) {
      *(undefined8 *)(puVar6 + -8) = 0x140001898;
      memset(puVar6 + 0x90,0,0x104);
      *(undefined1 **)(puVar6 + 0x30) = puVar6 + 0x3d8;
      *(undefined1 **)(puVar6 + 0x28) = puVar6 + 0x3e0;
      puVar6[0x20] = 0;
      *(undefined8 *)(puVar6 + -8) = 0x1400018d0;
      iVar3 = ZwQueryDirectoryObject(*(undefined8 *)(puVar6 + 0x48),puVar6 + 0x90,0x104);
      *(int *)(puVar6 + 0x40) = iVar3;
      if (iVar3 != 0) break;
      *(undefined8 *)(puVar6 + -8) = 0x1400018f8;
      cVar2 = MmIsAddressValid(puVar6 + 0x90);
      if (cVar2 != '\0') {
        *(undefined8 *)(puVar6 + -8) = 0x14000190e;
        cVar2 = MmIsAddressValid(*(undefined8 *)(puVar6 + 0x98));
        if (cVar2 != '\0') {
          *(undefined8 *)(puVar6 + -8) = 0x14000192b;
          memset(puVar6 + 0x1a0,0,0x208);
          *(undefined8 *)(puVar6 + -8) = 0x140001942;
          RtlStringCchCopyW((short *)(puVar6 + 0x1a0),0x104,0x140007ab0);
          *(undefined8 *)(puVar6 + -8) = 0x14000195a;
          RtlStringCchCatW((short *)(puVar6 + 0x1a0),0x104,*(longlong *)(puVar6 + 0x98));
          *(undefined8 *)(puVar6 + -8) = 0x14000196d;
          RtlInitUnicodeString(puVar6 + 0x50,puVar6 + 0x1a0);
          *(undefined8 *)(puVar6 + 1000) = 0;
          *(undefined1 **)(puVar6 + 0x38) = puVar6 + 1000;
          *(undefined8 *)(puVar6 + 0x30) = 0;
          puVar6[0x28] = 0;
          *(undefined8 *)(puVar6 + 0x20) = *(undefined8 *)IoDriverObjectType_exref;
          *(undefined8 *)(puVar6 + -8) = 0x1400019b2;
          iVar3 = ObReferenceObjectByName(puVar6 + 0x50,0x40,0);
          *(int *)(puVar6 + 0x40) = iVar3;
          if (iVar3 == 0) {
            *(undefined8 *)(puVar6 + -8) = 0x1400019c8;
            cVar2 = MmIsAddressValid(*(undefined8 *)(puVar6 + 1000));
            if (cVar2 == '\x01') {
              *(undefined8 *)(puVar6 + -8) = 0x1400019dc;
              cVar2 = FUN_140001a4c(param_1,*(longlong *)(puVar6 + 1000));
              if (cVar2 == '\0') {
                *(undefined8 *)(puVar6 + -8) = 0x1400019ed;
                plVar4 = (longlong *)ExAllocatePool(0,0x430);
                *(undefined8 *)(puVar6 + -8) = 0x140001a01;
                FUN_140001e54(*(longlong *)(puVar6 + 1000),plVar4 + 2);
                lVar5 = *param_1;
                if (*(longlong **)(lVar5 + 8) != param_1) {
                  pcVar1 = (code *)swi(0x29);
                  lVar5 = (*pcVar1)(3);
                  puVar6 = puVar6 + 8;
                }
                *plVar4 = lVar5;
                plVar4[1] = (longlong)param_1;
                *(longlong **)(lVar5 + 8) = plVar4;
                *param_1 = (longlong)plVar4;
              }
            }
            *(undefined8 *)(puVar6 + -8) = 0x140001a2d;
            ObfDereferenceObject(*(undefined8 *)(puVar6 + 1000));
          }
        }
      }
    }
    *(undefined8 *)(puVar6 + -8) = 0x1400018e5;
    ZwClose(*(undefined8 *)(puVar6 + 0x48));
  }
  else {
    iVar3 = -0x3fffffff;
  }
  return iVar3;
}

