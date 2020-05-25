#include "GUI.h"

//1 = false
//0 = true
u8 show_MENU_confirm()
{
    DrawPic((u16 *)gImage_MENU, 56, 25, 128, 110, 0, 0, 1); //draw background
    const char *en_confirm[] = {                            //define text TODO: move to lang
                                "",
                                "ARE YOU SURE?"};

    u32 y_offset = 30;                  //offset of text start
    for (s8 line = 0; line < 2; line++) //4 = number of line of en_restore_override
    {
        DrawHZText12(en_confirm[line], 32, 60, y_offset + line * 14, gl_color_text, 1); //draw/write all lines
    }
    Show_MENU_btn(); //show cancel/ok

    while (1)
    {
        //ShowTime(SD_list, 0);
        ShowTime(0, 0);
        VBlankIntrWait(); //???

        scanKeys();
        u16 keysdown = keysDown();
        if (keysdown & KEY_A)
            return 1;
        else if (keysdown & KEY_B)
            return 0;
    }

    return 0;
}

//show a backup info ( creation date / time)
//then ask for restore or delete selected backup
//return
// 0 = cancel
// 1 = restore backup
// 2 = delete backup

u8 show_MENU_backup_details(const char *filename)
{

    s8 Selected_Item = 0;
    u8 LastItem = 1;
    u8 backup_fullpath[MAX_path_len] = {0};

    //get file path
    StrConcat(backup_fullpath, MAX_path_len, backup_dir, "/");
    StrConcat(backup_fullpath, MAX_path_len, backup_fullpath, filename);

    //get file info
    FRESULT res = f_stat(backup_fullpath, &fileinfo);
    if (res != FR_OK)
    {
        //Error?? file not found...
        return 0;
    }

    char strDate[11] = {0}; //get date -> convert into string
    fdateToString(strDate, fileinfo.fdate);

    char strTime[11] = {0}; //get time -> convert into string
    ftimeToString(strTime, fileinfo.ftime);

    const char *en_menu_backup[] = {
        //define text TODO: move to lang
        "RESTORE",
        "DELETE",
    };

    u8 RepaintMenu = 1;

    Show_MENU_btn(); //show cancel/ok

    while (1)
    {
        if (RepaintMenu == 1)
        {
            RepaintMenu = 0;

            u32 y_offset = 30; //offset of text start
            s8 line = 0;

            DrawPic((u16 *)gImage_MENU, 56, 25, 128, 110, 0, 0, 1);                //draw background
            DrawHZText12(strDate, 32, 60, y_offset + line * 14, gl_color_text, 1); //print date
            line++;
            DrawHZText12(strTime, 32, 60, y_offset + line * 14, gl_color_text, 1); //print time
            line++;

            //give space for separate text from menu
            line++;

            for (s8 i = 0; i < 2; i++) //2 = number of line of en_menu_backup
            {
                u16 color = gl_color_text;
                if (Selected_Item == i)
                    color = gl_color_selected;
                DrawHZText12(en_menu_backup[i], 32, 60, y_offset + (line + i) * 14, color, 1); //draw/write all lines
            }
        }

        ShowTime(SD_list, 0);
        VBlankIntrWait(); //???

        scanKeys();
        u16 keysdown = keysDown();
        //u16 keysup = keysUp();

        if (keysdown & KEY_A)
        {
            if (Selected_Item == 0)
                return 1; //restore backup
            else if (Selected_Item == 1)
                return 2; //delete backup
        }
        else if (keysdown & KEY_B)
        {
            return 0; //cancel
        }
        else if (keysdown & KEY_UP)
        {
            RepaintMenu = 1;
            Selected_Item--;
            if (Selected_Item < 0)
                Selected_Item = 0;
        }
        else if (keysdown & KEY_DOWN)
        {
            RepaintMenu = 1;
            Selected_Item++;
            if (Selected_Item > LastItem)
                Selected_Item = LastItem;
        }
    }

    return 0;
}
//show a menu for ask user to confirm overwrite a save file
//return 1 = true -> overwrite | 0 = false -> not overwrite
u8 Show_menu_override_restore_save()
{
    DrawPic((u16 *)gImage_MENU, 56, 25, 128, 110, 0, 0, 1); //draw background
    const char *en_restore_override[] = {
        //define text TODO: move to lang
        "SAVE FILE ALREADY",
        "EXIST,",
        "DO YOU WANT TO",
        "OVERWRITE?",
    };

    u32 y_offset = 30;                  //offset of text start
    for (s8 line = 0; line < 4; line++) //4 = number of line of en_restore_override
    {
        DrawHZText12(en_restore_override[line], 32, 60, y_offset + line * 14, gl_color_text, 1); //draw/write all lines
    }
    Show_MENU_btn(); //show cancel/ok

    u8 to_override = 0;
    while (1)
    {
        ShowTime(SD_list, 0);
        VBlankIntrWait(); //???

        scanKeys();
        u16 keysdown = keysDown();
        //u16 keysup = keysUp();

        if (keysdown & KEY_A)
        {
            to_override = 1;
            break;
        }
        else if (keysdown & KEY_B)
        {
            to_override = 0;
            break;
        }
    }

    return to_override;
}