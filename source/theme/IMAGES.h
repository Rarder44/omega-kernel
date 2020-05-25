#ifndef IMAGES_HEADER
#define IMAGES_HEADER
#include "../Common.h"

extern const unsigned char ASC_DATA[] ;
extern const unsigned char gImage_Chinese_manual[9800] __attribute__((aligned(4)));
extern const unsigned char gImage_English_manual[9800] __attribute__((aligned(4)));
extern const unsigned char gImage_HELP[76800] __attribute__((aligned(4)));
extern const unsigned char gImage_icons[1344] __attribute__((aligned(4)));
extern const unsigned char gImage_icon_FC[448] __attribute__((aligned(4)));
extern const unsigned char gImage_icon_GB[448] __attribute__((aligned(4)));
extern const unsigned char gImage_icon_GBC[448] __attribute__((aligned(4)));
extern const unsigned char gImage_MENU[28160] __attribute__((aligned(4)));
extern const unsigned char gImage_NOR[76800] __attribute__((aligned(4)));
extern const unsigned char gImage_nor_icon[448] __attribute__((aligned(4)));
extern const unsigned char gImage_NOTFOUND[19200] __attribute__((aligned(4)));
extern const unsigned char gImage_RECENTLY[76800] __attribute__((aligned(4)));
extern const unsigned char gImage_SD[76800] __attribute__((aligned(4)));
extern const unsigned char gImage_SET[76800] __attribute__((aligned(4)));
extern const unsigned char gImage_splash[76800] __attribute__((aligned(4)));
extern u16 gl_color_selected;
extern u16 gl_color_text;
extern u16 gl_color_selectBG_sd;
extern u16 gl_color_selectBG_nor;
extern u16 gl_color_MENU_btn;
extern u16 gl_color_cheat_count;
extern u16 gl_color_cheat_black;
extern u16 gl_color_NORFULL;
extern u16 gl_color_btn_clean;
extern u16 gl_color_patch_note;
#endif