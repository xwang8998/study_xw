SET PATH=F:\Keil_v5\ARM\ARMCC\Bin;d:\MentorGraphics\9.5PADS\SDD_HOME\common\win32\bin;d:\MentorGraphics\9.5PADS\SDD_HOME\common\win32\lib;d:\MentorGraphics\9.5PADS\MGC_HOME.ixn\bin;d:\MentorGraphics\9.5PADS\MGC_HOME.ixn\lib;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;E:\DXP\System;d:\Program Files\Git\cmd;C:\Cadence\SPB_16.5\OpenAccess\bin\win32\opt;C:\Cadence\SPB_16.5\tools\Capture;C:\Cadence\SPB_16.5\tools\PSpice\Library;C:\Cadence\SPB_16.5\tools\PSpice;C:\Cadence\SPB_16.5\tools\specctra\bin;C:\Cadence\SPB_16.5\tools\fet\bin;C:\Cadence\SPB_16.5\tools\libutil\bin;C:\Cadence\SPB_16.5\tools\bin;C:\Cadence\SPB_16.5\tools\pcb\bin;;d:\MentorGraphics\9.5PADS\SDD_HOME\common\win32\lib
SET CPU_TYPE=STM32F407ZG
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=LED
SET CPU_CLOCK=0x007A1200
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\main.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f4xx_it.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\system_stm32f4xx.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\led.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\delay.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\sys.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "..\obj\startup_stm32f40_41xxx._ia"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\misc.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f4xx_gpio.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f4xx_rcc.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f4xx_syscfg.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\hmac_sha3.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\sha3.__i"
"F:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "..\OBJ\LED.lnp"
"F:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" "..\OBJ\LED.axf" --i32combined --output "..\OBJ\LED.hex"
