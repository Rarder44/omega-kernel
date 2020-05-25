
#ifndef GUI_HEADER
#define GUI_HEADER

#include <gba_base.h>
#include <gba_input.h>
#include <gba_systemcalls.h>
#include "ff.h"
#include "Common.h"

u8 show_MENU_confirm();
u8 show_MENU_backup_details(const char *filename);
u8 Show_menu_override_restore_save();

#endif