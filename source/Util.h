
#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <gba_base.h>
#include "ff.h"
#include "Common.h"

u32 Copy_file(const char *src, const char *dst);

void fdateParser(WORD date, u8 *year, u8 *month, u8 *day);
void ftimeParser(WORD time, u8 *hour, u8 *minute, u8 *second);
void fdateToString(char *str, WORD date);
void ftimeToString(char *str, WORD time);
void StrConcat(u8 *ReturnString, u32 RetrurnStringLeght, const char *pt1, const char *pt2);

#endif