#include "lang.h"
#include "lang_en.h"
#include "lang_it.h"

char *gl_init_error;
char *gl_power_off;
char *gl_init_ok;
char *gl_Loading;
char *gl_file_overflow;

char *gl_menu_btn;
char *gl_lastest_game;

char *gl_writing;

char *gl_time;
char *gl_Mon;
char *gl_Tues;
char *gl_Wed;
char *gl_Thur;
char *gl_Fri;
char *gl_Sat;
char *gl_Sun;

char *gl_addon;
char *gl_reset;
char *gl_rts;
char *gl_sleep;
char *gl_cheat;

char *gl_hot_key;
char *gl_hot_key2;

char *gl_language;
char *gl_second_lang;
char *gl_first_lang;
char *gl_set_btn;
char *gl_ok_btn;

char *gl_formatnor_info;

char *gl_check_sav;
char *gl_make_sav;

char *gl_check_RTS;
char *gl_make_RTS;

char *gl_check_pat;
char *gl_make_pat;

char *gl_loading_game;

char *gl_engine;
char *gl_use_engine;

char *gl_recently_play;

char *gl_START_help;
char *gl_SELECT_help;
char *gl_L_A_help;
char *gl_LSTART_help;
char *gl_online_manual;

char *gl_no_game_played;

char *gl_ingameRTC;
//char* gl_offRTC_powersave;
char *gl_ingameRTC_open;
char *gl_ingameRTC_close;

char *gl_error_0;
char *gl_error_1;
char *gl_error_2;
char *gl_error_3;
char *gl_error_4;
char *gl_error_5;
char *gl_error_6;
//--
char **gl_rom_menu;
char **gl_nor_op;

char *gl_rotating_backups;
char *gl_saving_backup;
char *gl_backup_done;

//---------------------------------------------------------------------------------
void LoadFirstLanguage(void)
{
	gl_init_error = (char *)first_init_error;
	gl_power_off = (char *)first_power_off;
	gl_init_ok = (char *)first_init_ok;
	gl_Loading = (char *)first_Loading;
	gl_file_overflow = (char *)first_file_overflow;

	gl_menu_btn = (char *)first_menu_btn;
	gl_writing = (char *)first_writing;
	gl_lastest_game = (char *)first_lastest_game;

	gl_time = (char *)first_time;
	gl_Mon = (char *)first_Mon;
	gl_Tues = (char *)first_Tues;
	gl_Wed = (char *)first_Wed;
	gl_Thur = (char *)first_Thur;
	gl_Fri = (char *)first_Fri;
	gl_Sat = (char *)first_Sat;
	gl_Sun = (char *)first_Sun;

	gl_addon = (char *)first_addon;
	gl_reset = (char *)first_reset;
	gl_rts = (char *)first_rts;
	gl_sleep = (char *)first_sleep;
	gl_cheat = (char *)first_cheat;

	gl_hot_key = (char *)first_hot_key;
	gl_hot_key2 = (char *)first_hot_key2;

	gl_language = (char *)first_language;
	gl_second_lang = (char *)second_lang;
	gl_first_lang = (char *)first_lang;
	;
	gl_set_btn = (char *)first_set_btn;
	gl_ok_btn = (char *)first_ok_btn;
	gl_formatnor_info = (char *)first_formatnor_info;

	gl_check_sav = (char *)first_check_sav;
	gl_make_sav = (char *)first_make_sav;

	gl_check_RTS = (char *)first_check_RTS;
	gl_make_RTS = (char *)first_make_RTS;

	gl_check_pat = (char *)first_check_pat;
	gl_make_pat = (char *)first_make_pat;

	gl_loading_game = (char *)first_loading_game;
	gl_engine = (char *)first_engine;
	gl_use_engine = (char *)first_use_engine;

	gl_recently_play = (char *)first_recently_play;

	gl_START_help = (char *)first_START_help;
	gl_SELECT_help = (char *)first_SELECT_help;
	gl_L_A_help = (char *)first_L_A_help;
	gl_LSTART_help = (char *)first_LSTART_help;
	gl_online_manual = (char *)first_online_manual;

	gl_no_game_played = (char *)first_no_game_played;

	gl_ingameRTC = (char *)first_ingameRTC;
	//gl_offRTC_powersave = (char*)first_offRTC_powersave;
	gl_ingameRTC_open = (char *)first_ingameRTC_open;
	gl_ingameRTC_close = (char *)first_ingameRTC_close;

	gl_error_0 = (char *)first_error_0;
	gl_error_1 = (char *)first_error_1;
	gl_error_2 = (char *)first_error_2;
	gl_error_3 = (char *)first_error_3;
	gl_error_4 = (char *)first_error_4;
	gl_error_5 = (char *)first_error_5;
	gl_error_6 = (char *)first_error_6;

	//
	gl_rom_menu = (char **)first_rom_menu;
	gl_nor_op = (char **)first_nor_op;

	gl_rotating_backups = (char *)first_rotating_backups;
	gl_saving_backup = (char *)first_saving_backup;
	gl_backup_done = (char *)first_backup_done;
}
//---------------------------------------------------------------------------------
void LoadSecondLanguage(void)
{
	gl_init_error = (char *)second_init_error;
	gl_power_off = (char *)second_power_off;
	gl_init_ok = (char *)second_init_ok;
	gl_Loading = (char *)second_Loading;
	gl_file_overflow = (char *)second_file_overflow;

	gl_menu_btn = (char *)second_menu_btn;
	gl_writing = (char *)second_writing;
	gl_lastest_game = (char *)second_lastest_game;

	gl_time = (char *)second_time;
	gl_Mon = (char *)second_Mon;
	gl_Tues = (char *)second_Tues;
	gl_Wed = (char *)second_Wed;
	gl_Thur = (char *)second_Thur;
	gl_Fri = (char *)second_Fri;
	gl_Sat = (char *)second_Sat;
	gl_Sun = (char *)second_Sun;
	gl_addon = (char *)second_addon;
	gl_reset = (char *)second_reset;
	gl_rts = (char *)second_rts;
	gl_sleep = (char *)second_sleep;
	gl_cheat = (char *)second_cheat;

	gl_hot_key = (char *)second_hot_key;
	gl_hot_key2 = (char *)second_hot_key2;

	gl_language = (char *)second_language;
	gl_second_lang = (char *)second_lang;
	gl_first_lang = (char *)first_lang;

	gl_set_btn = (char *)second_set_btn;
	gl_ok_btn = (char *)second_ok_btn;
	gl_formatnor_info = (char *)second_formatnor_info;

	gl_check_sav = (char *)second_check_sav;
	gl_make_sav = (char *)second_make_sav;

	gl_check_RTS = (char *)second_check_RTS;
	gl_make_RTS = (char *)second_make_RTS;

	gl_check_pat = (char *)second_check_pat;
	gl_make_pat = (char *)second_make_pat;

	gl_loading_game = (char *)second_loading_game;

	gl_engine = (char *)second_engine;
	gl_use_engine = (char *)second_use_engine;

	gl_recently_play = (char *)second_recently_play;

	gl_START_help = (char *)second_START_help;
	gl_SELECT_help = (char *)second_SELECT_help;
	gl_L_A_help = (char *)second_L_A_help;
	gl_LSTART_help = (char *)second_LSTART_help;
	gl_online_manual = (char *)second_online_manual;

	gl_no_game_played = (char *)second_no_game_played;

	gl_ingameRTC = (char *)second_ingameRTC;
	//gl_offRTC_powersave = (char*)second_offRTC_powersave;
	gl_ingameRTC_open = (char *)second_ingameRTC_open;
	gl_ingameRTC_close = (char *)second_ingameRTC_close;

	gl_error_0 = (char *)second_error_0;
	gl_error_1 = (char *)second_error_1;
	gl_error_2 = (char *)second_error_2;
	gl_error_3 = (char *)second_error_3;
	gl_error_4 = (char *)second_error_4;
	gl_error_5 = (char *)second_error_5;
	gl_error_6 = (char *)second_error_6;
	//
	gl_rom_menu = (char **)second_rom_menu;
	gl_nor_op = (char **)second_nor_op;

	gl_rotating_backups = (char *)second_rotating_backups;
	gl_saving_backup = (char *)second_saving_backup;
	gl_backup_done = (char *)second_backup_done;
}
