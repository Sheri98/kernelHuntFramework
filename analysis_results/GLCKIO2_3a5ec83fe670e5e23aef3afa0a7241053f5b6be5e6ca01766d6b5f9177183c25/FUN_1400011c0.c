// Function: FUN_1400011c0
// Address: 1400011c0
// Decompiled by Ghidra


void FUN_1400011c0(longlong param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte *pbVar25;
  longlong local_48;
  
  pbVar25 = (byte *)(param_1 + 2);
  local_48 = 4;
  do {
    bVar1 = pbVar25[-2];
    bVar2 = *pbVar25;
    bVar3 = pbVar25[-1];
    bVar5 = ((char)bVar1 >> 7) * -0x1b;
    bVar4 = pbVar25[1];
    bVar10 = bVar1 * '\x02' ^ bVar5;
    bVar6 = ((char)bVar10 >> 7) * -0x1b;
    bVar12 = bVar10 * '\x02' ^ bVar6;
    bVar14 = ((char)bVar3 >> 7) * -0x1b;
    bVar17 = bVar3 * '\x02' ^ bVar14;
    bVar7 = ((char)bVar17 >> 7) * -0x1b;
    bVar21 = bVar17 * '\x02' ^ bVar7;
    bVar8 = ((char)bVar2 >> 7) * -0x1b;
    bVar16 = bVar2 * '\x02' ^ bVar8;
    bVar24 = ((char)bVar16 >> 7) * -0x1b;
    bVar9 = ((char)bVar4 >> 7) * -0x1b;
    bVar19 = bVar16 * '\x02' ^ bVar24;
    bVar11 = bVar4 * '\x02' ^ bVar9;
    bVar22 = ((char)bVar11 >> 7) * -0x1b;
    bVar15 = bVar11 * '\x02' ^ bVar22;
    bVar23 = ((char)bVar15 >> 7) * -0x1b;
    bVar13 = ((char)bVar19 >> 7) * -0x1b;
    bVar20 = ((char)bVar21 >> 7) * -0x1b;
    bVar18 = ((char)bVar12 >> 7) * -0x1b;
    pbVar25[-2] = (bVar10 ^ bVar16 ^ bVar15 ^ bVar19 ^ bVar21 ^ bVar12 ^ bVar3 ^ bVar1) * '\x02' ^
                  bVar18 ^ bVar20 ^ bVar13 ^ bVar23 ^ bVar24 ^ bVar6 ^ bVar14 ^ bVar5 ^ bVar4 ^
                  bVar2 ^ bVar3;
    bVar11 = bVar15 ^ bVar19 ^ bVar21 ^ bVar12 ^ bVar17 ^ bVar11;
    pbVar25[-1] = (bVar11 ^ bVar2 ^ bVar3) * '\x02' ^ bVar18 ^ bVar20 ^ bVar13 ^ bVar23 ^ bVar22 ^
                  bVar7 ^ bVar14 ^ bVar8 ^ bVar4 ^ bVar2 ^ bVar1;
    *pbVar25 = (bVar15 ^ bVar19 ^ bVar16 ^ bVar21 ^ bVar12 ^ bVar10 ^ bVar4 ^ bVar2) * '\x02' ^
               bVar18 ^ bVar13 ^ bVar23 ^ bVar20 ^ bVar24 ^ bVar6 ^ bVar9 ^ bVar8 ^ bVar4 ^ bVar3 ^
               bVar1;
    pbVar25[1] = (bVar11 ^ bVar4 ^ bVar1) * '\x02' ^ bVar18 ^ bVar13 ^ bVar23 ^ bVar20 ^ bVar22 ^
                 bVar7 ^ bVar5 ^ bVar9 ^ bVar2 ^ bVar3 ^ bVar1;
    pbVar25 = pbVar25 + 4;
    local_48 = local_48 + -1;
  } while (local_48 != 0);
  return;
}

