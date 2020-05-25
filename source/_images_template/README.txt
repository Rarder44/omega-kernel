Questa cartella contiene un template di immagini per creare tutto lo stile.
Utilizzare l'utility "Template Util" per generare i .c/.h


I file devono chiamarsi esattamente in questo modo:

asc126.bmp				-> bitmap 96x132 contenente i caratteri ( ogni carattere è 8*12 pixel ) ordinate da sx a dx, dall'alto al basso secondo il codice ASCII
Chinese_manual.png
Color map.png
English_manual.png
HELP.png
icons.png
icon_FC.png
icon_GB.png
icon_GBC.png
MENU.png
NOR.png
nor_icon.png
NOTFOUND.png
RECENTLY.png
SD.png
SET.png
splash.png


Il file _text_palette.png dovrà essere una png di 1x10 px contenente, "riga per riga" i seguenti colori;
u16 gl_color_selected
u16 gl_color_text
u16 gl_color_selectBG_sd
u16 gl_color_selectBG_nor 
u16 gl_color_MENU_btn 
u16 gl_color_cheat_count 
u16 gl_color_cheat_black 
u16 gl_color_NORFULL 
u16 gl_color_btn_clean
u16 gl_color_patch_note 




Can be converted to .c/.h with grit (https://www.coranac.com/projects/grit/)

grit SD.png -gB16 -gu8 -gb -ftc
