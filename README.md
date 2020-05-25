# EZ-FLASH OMEGA Kernel

[Source code at GitHub](https://github.com/Rarder44/omega-kernel)

## Patched by Rarder44 (v5)
###Based on veikkos (v5) work:

* Updated to [Goomba GB/GBC emulator](http://www.dwedit.org/gba/goombacolor.php) version 2019-05-04 
    * Applied [source patch](https://github.com/veikkos/omega-kernel/blob/master/goomba-patch/goomba_ezflash_omega.patch) to Goomba to make it Omega compatible
    * Removed binary patching by kernel which is no longer needed
* Goomba changes [(issue link)](https://github.com/veikkos/omega-kernel/issues/2) [(patch link)](https://github.com/veikkos/omega-kernel/blob/master/goomba-patch/goomba_gbc_mode.patch)
    * No SGB borders by default
        * New "Prefer GBC over GB" default mode instead of "Prefer GBC over SGB"
    * Original GB games use black and white "Grayscale" palette instead of colorized "Wario Blast"
* Quick start
    * Keep L pressed when booting to start last game in NOR
    * Keep L+A pressed when booting to start last played SD-card game
* Start emulated games directly without single-item game menu [(link)](https://github.com/veikkos/omega-kernel/issues/4)
* Automated backup of game saves
    * Save file is backed up automatically when starting a game
    * Backups are stored in `/SAVER-BACKUP` directory
    * 5 last save files are stored
        * `.sav0` is most recent, `.sav4` is oldest
		
##What's new? 
    * Restore is AUTOMATIC process
		* you can restore a backup by going, from the game boy, on saving and selecting "RESTORE" (there is a menu that displays the date and time of the backup creation)
	* Backups can be deleted from the console ( if "holes" remain in the numbering, these are moved so that the numbering is chronological (0 = most recent)) 
	* Changed how languages are handled ( removed the Chinese language; it is now easier to enter a second language )
    * Implemented red theme (by veikkos and Nona_Elexis) by default
	* Changed how themes are handled
	* Created tool (c#) for the AUTOMATIC creation of all the files (.h / .c) necessary for the theme.
		* edit the images in the "_images_template" folder as described in the README file (DO NOT CHANGE THE NAME, SIZE AND EXTENSIONS OF THE FILES)
		* Launch the "Template Util" program (the vs project is located in the "_utils / Template Util" folder (to compile it you need the [ExtendCSharp](https://github.com/Rarder44/ExtendCSharp) library
		* will create a "theme" folder that can be cut and pasted directly into the "source" folder
		* recompile
	* vs code can be used to speed up the editing process:
		* install mingw-w64 -> i686-8.1.0-posix-dwarf-rt_v6-rev0
		* edit includePath and compilerPath in .vscode/c_cpp_properties.json
		* optional: change default build keybind on "F5"
		

And as always...
Use with your own risk!

## How to build

    1.Install [DevkitPro Updater v3.0.3](https://github.com/devkitPro/installer/releases) (install it on  C:\devkitPro\ to have all the correct setups)
    2.Check/Set the following environment variables in build_vscode.bat, based on your installation path
        PATH,DEVKITARM,DEVKITPRO,LIBGBA

    3.Double click on build_vscode.bat under Windows. If it goes well, you will get ezkernel.bin which is the omega kernel upgrade file
	4.I recommend using the vscode task to build it
