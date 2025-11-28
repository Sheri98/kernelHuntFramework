// Function: FUN_140001524
// Address: 140001524
// Decompiled by Ghidra


ulonglong FUN_140001524(longlong param_1,longlong *param_2)

{
  code *pcVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined1 *puVar9;
  undefined8 uStack_3e0;
  undefined1 auStack_3d8 [32];
  undefined1 local_3b8 [8];
  longlong local_3b0 [3];
  uint local_398 [4];
  longlong local_388 [2];
  undefined1 local_378 [16];
  undefined4 local_368 [2];
  undefined8 local_360;
  undefined1 *local_358;
  undefined4 local_350;
  undefined8 local_348;
  undefined8 uStack_340;
  longlong local_330 [99];
  
  puVar9 = auStack_3d8;
  local_388[0] = 0;
  cVar2 = MmIsAddressValid();
  if (cVar2 == '\0') {
    uVar6 = 0xc0000001;
  }
  else {
    RtlInitUnicodeString(local_378,param_1);
    local_368[0] = 0x30;
    local_360 = 0;
    local_350 = 0x40;
    local_358 = local_378;
    local_348 = 0;
    uStack_340 = 0;
    uVar6 = ZwOpenDirectoryObject(local_388,3,local_368);
    if ((int)uVar6 == 0) {
      local_398[2] = 0;
      local_398[3] = 0;
      local_388[1] = 0;
      local_398[0] = 0;
      while( true ) {
        *(undefined8 *)(puVar9 + -8) = 0x1400015ef;
        memset(puVar9 + 0xa0,0,0x104);
        *(undefined1 **)(puVar9 + 0x30) = puVar9 + 0x3f0;
        *(undefined1 **)(puVar9 + 0x28) = puVar9 + 0x3f8;
        puVar9[0x20] = 0;
        *(undefined8 *)(puVar9 + -8) = 0x140001627;
        uVar4 = ZwQueryDirectoryObject(*(undefined8 *)(puVar9 + 0x50),puVar9 + 0xa0,0x104,1);
        uVar6 = (ulonglong)uVar4;
        *(uint *)(puVar9 + 0x40) = uVar4;
        if (uVar4 != 0) break;
        *(undefined8 *)(puVar9 + -8) = 0x14000164f;
        cVar2 = MmIsAddressValid(puVar9 + 0xa0);
        if (cVar2 != '\0') {
          *(undefined8 *)(puVar9 + -8) = 0x140001665;
          cVar2 = MmIsAddressValid(*(undefined8 *)(puVar9 + 0xa8));
          if (cVar2 != '\0') {
            *(undefined8 *)(puVar9 + -8) = 0x140001682;
            memset(puVar9 + 0x1b0,0,0x208);
            *(undefined8 *)(puVar9 + -8) = 0x140001695;
            RtlStringCchCopyW((short *)(puVar9 + 0x1b0),0x104,param_1);
            *(undefined8 *)(puVar9 + -8) = 0x1400016ac;
            RtlStringCchCatW((short *)(puVar9 + 0x1b0),0x104,0x140007a60);
            *(undefined8 *)(puVar9 + -8) = 0x1400016c4;
            RtlStringCchCatW((short *)(puVar9 + 0x1b0),0x104,*(longlong *)(puVar9 + 0xa8));
            *(undefined8 *)(puVar9 + -8) = 0x1400016d7;
            RtlInitUnicodeString(puVar9 + 0x60,puVar9 + 0x1b0);
            *(undefined8 *)(puVar9 + -8) = 0x1400016eb;
            iVar5 = _wcsicmp(*(wchar_t **)(puVar9 + 0xb8),L"Directory");
            if (iVar5 == 0) {
              *(undefined8 *)(puVar9 + -8) = 0x1400016ff;
              FUN_140001524((longlong)(puVar9 + 0x1b0),param_2);
            }
            else {
              *(undefined8 *)(puVar9 + -8) = 0x140001718;
              iVar5 = _wcsicmp(*(wchar_t **)(puVar9 + 0xb8),L"Device");
              if (iVar5 == 0) {
                *(undefined8 *)(puVar9 + -8) = 0x140001734;
                iVar5 = IoGetDeviceObjectPointer(puVar9 + 0x60,1,puVar9 + 0x48,puVar9 + 0x58);
                *(int *)(puVar9 + 0x40) = iVar5;
                if (iVar5 == 0) {
                  *(undefined8 *)(puVar9 + -8) = 0x140001746;
                  bVar3 = FUN_140001aac(*(longlong *)(puVar9 + 0x58));
                  if (bVar3) {
                    lVar8 = *(longlong *)(*(longlong *)(puVar9 + 0x58) + 8);
                    *(undefined8 *)(puVar9 + -8) = 0x14000175c;
                    cVar2 = MmIsAddressValid(lVar8);
                    if (cVar2 == '\x01') {
                      *(undefined8 *)(puVar9 + -8) = 0x14000176b;
                      cVar2 = FUN_140001a4c(param_2,lVar8);
                      if (cVar2 == '\0') {
                        *(undefined8 *)(puVar9 + -8) = 0x14000177c;
                        plVar7 = (longlong *)ExAllocatePool(0,0x430);
                        *(undefined8 *)(puVar9 + -8) = 0x14000178b;
                        FUN_140001e54(lVar8,plVar7 + 2);
                        lVar8 = *param_2;
                        if (*(longlong **)(lVar8 + 8) != param_2) {
                          pcVar1 = (code *)swi(0x29);
                          lVar8 = (*pcVar1)(3);
                          puVar9 = puVar9 + 8;
                        }
                        *plVar7 = lVar8;
                        plVar7[1] = (longlong)param_2;
                        *(longlong **)(lVar8 + 8) = plVar7;
                        *param_2 = (longlong)plVar7;
                      }
                    }
                  }
                  *(undefined8 *)(puVar9 + -8) = 0x1400017b4;
                  cVar2 = MmIsAddressValid(*(undefined8 *)(puVar9 + 0x48));
                  if (cVar2 != '\0') {
                    *(undefined8 *)(puVar9 + -8) = 0x1400017c7;
                    ObfDereferenceObject(*(undefined8 *)(puVar9 + 0x48));
                    *(undefined8 *)(puVar9 + 0x48) = 0;
                  }
                }
              }
            }
          }
        }
      }
      *(undefined8 *)(puVar9 + -8) = 0x14000163c;
      ZwClose(*(undefined8 *)(puVar9 + 0x50));
    }
  }
  return uVar6;
}

