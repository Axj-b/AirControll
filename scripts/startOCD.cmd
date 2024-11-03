set ocdPath=G:\40_Software\10_Development\10_ARM\OpenOCD\OpenOCD-20240916-0.12.0
set exePath=%ocdPath%\bin\

%exePath%\openocd.exe -f %ocdPath%\share\openocd\scripts\interface\stlink-v2.cfg -f %ocdPath%\share\openocd\scripts\target\stm32f1x.cfg
