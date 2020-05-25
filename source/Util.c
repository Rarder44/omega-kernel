#include "Util.h"

//---------------------------------------------------------------------------------
u32 Copy_file(const char *src, const char *dst)
{
    //pFile
    //pReadCache
    u32 ret = 0;
    UINT read_ret;
    UINT write_ret;
    u32 filesize;
    u32 res;
    u32 blocknum;
    FIL dst_file;

    res = f_open(&gfile, src, FA_READ);
    if (res == FR_OK)
    {
        res = f_open(&dst_file, dst, FA_WRITE | FA_CREATE_ALWAYS);
        if (res == FR_OK)
        {
            filesize = f_size(&gfile);
            f_lseek(&gfile, 0x0000);

            for (blocknum = 0x0000; blocknum < filesize; blocknum += 0x20000)
            {
                f_read(&gfile, pReadCache, 0x20000, &read_ret);
                f_write(&gfile, pReadCache, read_ret, &write_ret);
                if (write_ret != read_ret)
                {
                    ret = 0;
                    break;
                }
                else
                {
                    ret = 1;
                }
            }

            f_close(&dst_file);

            if (!ret)
                f_unlink(dst);
        }
        f_close(&gfile);
    }

    return ret;
}
//---------------------------------------------------------------------------------

void fdateParser(WORD date, u8 *year, u8 *month, u8 *day)
{
    /* date
		0000000 			0000 		00000
		year(from 1980)		month(1-12)	day(1-31)

		0101000 			0101		10001
		40=2020				5			17

		0101000010110001	= 20657 = 0x50B1
	*/

    //year selector		1111111000000000 = 65024
    //month selector	0000000111100000 = 480
    //day selector		0000000000011111 = 31

    *year = (u8)((date & 65024) >> 9);
    *month = (u8)((date & 480) >> 5);
    *day = (u8)((date & 31));
}
void ftimeParser(WORD time, u8 *hour, u8 *minute, u8 *second)
{
    /* date
		00000 			000000 			00000
		hour(0-23)		minute(0-59)	second/2(0-29)

		01100 			010100		11001
		12				20			50 ( 25 )

		0110001010011001	= 25241 = 0x6299
	*/

    //hour selector		1111100000000000 = 63488
    //minute selector	0000011111100000 = 2016
    //second selector	0000000000011111 = 31

    *hour = (u8)((time & 63488) >> 11);
    *minute = (u8)((time & 2016) >> 5);
    *second = (u8)((time & 31));
}
void fdateToString(char *str, WORD date)
{
    u8 year, month, day;
    fdateParser(date, &year, &month, &day);
    sprintf(str, "%d/%d/%d", year + 1980, month, day);
}
void ftimeToString(char *str, WORD time)
{
    u8 hour, minute, second;
    ftimeParser(time, &hour, &minute, &second);
    sprintf(str, "%d:%d:%d", hour, minute, second * 2);
}
//Concat 2 string
void StrConcat(u8 *ReturnString, u32 RetrurnStringLeght, const char *pt1, const char *pt2)
{
    //strncpy(destination, source, max_number_of_char_to_copy);
    strncpy(ReturnString, pt1, RetrurnStringLeght - 1);                           //copy the first string
    u32 tmp_lenght = strlen(ReturnString);                                        //get the current lenght
    strncpy(ReturnString + tmp_lenght, pt2, RetrurnStringLeght - tmp_lenght - 1); //copy the second string after the first
}