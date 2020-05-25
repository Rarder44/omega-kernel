#ifndef EZKERNEL_HEADER
#define EZKERNEL_HEADER

#include "ff.h"
#include "Common.h"

//----------------------------
extern DWORD Get_NextCluster(FFOBJID *obj, DWORD clst);
extern DWORD ClustToSect(FATFS *fs, DWORD clst);

extern FM_NOR_FS pNorFS[MAX_NOR] EWRAM_BSS;
extern u8 pReadCache[MAX_pReadCache_size] EWRAM_BSS;
extern u8 __attribute__((aligned(4))) GAMECODE[4];

extern u16 gl_reset_on;
extern u16 gl_rts_on;
extern u16 gl_sleep_on;
extern u16 gl_cheat_on;

u32 Setting_window(void);
u32 LoadRTSfile(TCHAR *filename);
void ShowTime(u32 page_num, u32 page_mode);

#endif