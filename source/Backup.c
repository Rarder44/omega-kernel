#include "Backup.h"

void DeleteBakup(const char *filename)
{
    u8 backup_fullpath[MAX_path_len] = {0};
    StrConcat(backup_fullpath, MAX_path_len, backup_dir, "/");
    StrConcat(backup_fullpath, MAX_path_len, backup_fullpath, filename);
    f_unlink(backup_fullpath); //delete backup
}

//restore a backup into SAVER path
u8 RestoreBackup(const char *filename)
{
    u32 res;
    u8 LastChar;
    u8 backup_fullpath[MAX_path_len] = {0};
    u8 restore_fullpath[MAX_path_len] = {0};

    //get full path of backup file

    StrConcat(backup_fullpath, MAX_path_len, backup_dir, "/");
    StrConcat(backup_fullpath, MAX_path_len, backup_fullpath, filename);

    //check if backup folder exist ( recreate if not exist... )
    f_mkdir(backup_dir);

    //check if file exist in backup_dir
    res = f_stat(backup_fullpath, &fileinfo);
    /*res = f_open(&gfile, backup_fullpath, FA_READ);				//deprecate: use f_stat ( http://elm-chan.org/fsw/ff/doc/stat.html )
	f_close(&gfile);*/
    if (res != FR_OK)
    {
        //Error?? file not found...
        return false;
    }

    //?? check if backup has digit on last 1/2 letter
    LastChar = backup_fullpath[strlen(backup_fullpath) - 1];
    if (!(LastChar >= '0' && LastChar <= '9'))
    {
        return false;
    }

    //get the full path of restored file
    StrConcat(restore_fullpath, MAX_path_len, "/SAVER/", filename);
    restore_fullpath[strlen(restore_fullpath) - 1] = 0; //remove last digit ( put \0 over the number of backup )

    //check if save file exist
    res = f_stat(backup_fullpath, &fileinfo);
    /*res = f_open(&gfile, restore_fullpath, FA_READ);		//deprecate: use f_stat ( http://elm-chan.org/fsw/ff/doc/stat.html )
	f_close(&gfile);*/
    if (res == FR_OK)
    {
        //save file exist, ask for override
        res = Show_menu_override_restore_save();
        if (res == 0) //not override!!! ABORT! ABORT!!!
        {
            return false;
        }

        f_unlink(restore_fullpath); //delete save
    }

    //copy the backup file into SAVER folder ( rename )
    Copy_file(backup_fullpath, restore_fullpath);
    return 1;
}

u8 numberOfSave = 5; //MAX 9!!!!
void Backup_savefile(const char *filename)
{
    u8 temp_filename[MAX_path_len] = {0};
    u8 temp_filename_dst[MAX_path_len] = {0};
    u32 temp_filename_length;

    strncpy(temp_filename, backup_dir, sizeof(temp_filename) - 2);
    temp_filename_length = strlen(temp_filename);
    temp_filename[temp_filename_length++] = '/';

    strncpy(temp_filename + temp_filename_length, filename, sizeof(temp_filename) - temp_filename_length - 2);
    temp_filename_length = strlen(temp_filename);

    f_mkdir(backup_dir);
    strncpy(temp_filename_dst, temp_filename, sizeof(temp_filename_dst));

    ShowbootProgress(gl_rotating_backups);

    //get first empy space
    s8 FirstEmpySpace = numberOfSave;
    for (s8 i = 0; i < numberOfSave; i++)
    {
        temp_filename[temp_filename_length] = '0' + i;
        if (f_stat(temp_filename, &fileinfo) != FR_OK)
        {
            FirstEmpySpace = i;
            break;
        }
    }

    //shift save to First Empty Space
    if (FirstEmpySpace > 0)
    {
        for (s8 i = FirstEmpySpace - 1; i >= 0; --i)
        {
            if (i + 1 != numberOfSave) //excluded copy from 4 to 5
            {
                temp_filename[temp_filename_length] = '0' + i;
                temp_filename_dst[temp_filename_length] = '0' + i + 1;

                f_unlink(temp_filename_dst);
                f_rename(temp_filename, temp_filename_dst);
            }
        }
    }

    ShowbootProgress(gl_saving_backup);

    //Save the backup as 0
    temp_filename[temp_filename_length] = '0';

    if (Copy_file(filename, temp_filename))
    {
        ShowbootProgress(gl_backup_done);
    }
}
