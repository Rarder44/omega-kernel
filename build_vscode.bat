set PATH=C:\devkitPro\msys2\bin;C:\devkitPro\devkitARM\bin;%PATH%
set DEVKITARM=/c/devkitPro/devkitARM
set DEVKITPRO=/c/devkitPro
set LIBGBA=/c/devkitPro/libgba

del *.bin
make  
rem >error.txt 2>&1

del *.elf
ren ezkernel.gba ezkernel.bin 