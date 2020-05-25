#ifndef BACKUP_HEADER
#define BACKUP_HEADER

#include "Common.h"
#include "GUI.h"

void DeleteBakup(const char *filename);
u8 RestoreBackup(const char *filename);
void Backup_savefile(const char *filename);

#endif