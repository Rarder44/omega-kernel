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





Can be converted to .c/.h with grit (https://www.coranac.com/projects/grit/)

grit SD.png -gB16 -gu8 -gb -ftc
