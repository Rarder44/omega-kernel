#ifndef COMMON_HEADER
#define COMMON_HEADER

#include <gba_base.h>
#include "ff.h"
#include "IMAGES.h"
#include "lang.h"
#include "Util.h"

#define MAX_pReadCache_size 0x20000
#define MAX_files 0x200
#define MAX_folder 0x100
#define MAX_NOR 0x40

#define MAX_path_len 0x100

#define FAT_table_size 0x400
#define FAT_table_SAV_offset 0x200
#define FAT_table_RTS_offset 0x300

#define DEBUG

#define VideoBuffer (u16 *)0x6000000
#define Vcache (u16 *)pReadCache
#define RGB(r, g, b) ((r) + (g << 5) + (b << 10))

#define PSRAMBase_S98 (u32)0x08800000
#define FlashBase_S98 (u32)0x09000000
#define FlashBase_S98_end (u32)0x09800000

#define SAVE_sram_base (u32)0x0E000000
#define SRAMSaver (u32)0x0E000000

#define UNBCD(x) (((x)&0xF) + (((x) >> 4) * 10))
#define _BCD(x) ((((x) / 10) << 4) + ((x) % 10))
#define _YEAR 0
#define _MONTH 1
#define _DAY 2
#define _WKD 3
#define _HOUR 4
#define _MIN 5
#define _SEC 6

typedef struct FM_NOR_FILE_SECT
{ ////save to nor
    unsigned char filename[100];
    u16 rompage;
    u16 have_patch;
    u16 have_RTS;
    u16 reserved;
    u32 filesize;
    u32 reserved2;
    char gamename[0x10];
} FM_NOR_FS;

typedef struct FM_Folder_SECT
{
    unsigned char filename[100];
} FM_Folder_FS;

typedef struct FM_FILE_SECT
{
    unsigned char filename[100];
    u32 filesize;
} FM_FILE_FS;

typedef enum
{
    SD_list = 0,
    NOR_list = 1,
    SET_win = 2,
    HELP = 3,
} PAGE_NUM;

extern FIL gfile;
extern u8 pReadCache[MAX_pReadCache_size] EWRAM_BSS;
extern FILINFO fileinfo;
extern const char *backup_dir; // = "/SAVER-BACKUP";

#endif