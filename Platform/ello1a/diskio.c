/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various existing       */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/
/* modified by KnivD, (C) 2020                                           */
/*-----------------------------------------------------------------------*/

#include <time.h>
#include <string.h>		/* memcpy() */
#include <stdio.h>		/* printf() */
#include "../../FatFs/source/diskio.h"
#include "../../xmem.h"
#include "platform.h"

byte *drvIFS = (byte *) ifs_data;   /* internal flash disk data entry point for the IFS: drive */
byte *drvRAM = NULL;                /* internal RAM disk data entry point for the RAM: drive */


DWORD get_fattime (void) {
	struct tm *t = localtime((const time_t *) &ss_time);
	return ((DWORD) (t->tm_year - 80) << 25)
         | ((DWORD) (t->tm_mon + 1) << 21)
         | ((DWORD) t->tm_mday << 16)
         | ((DWORD) t->tm_hour << 11)
         | ((DWORD) t->tm_min << 5)
         | ((DWORD) t->tm_sec >> 1);
}


/* helper function for getting current sector size */
unsigned int get_ssize(FATFS *fs) {
#if FF_MIN_SS != FF_MAX_SS
    return fs->ssize;
#else
    return FF_MAX_SS;
#endif
}


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive number to identify the drive */
) {
	DSTATUS stat = 0;

	switch (pdrv) {

		case DEV_NUL:
			return stat;

		case DEV_IFS:
            /* nothing is needed here */
			return stat;

		case DEV_RAM:
			if(!drvRAM) stat |= STA_NODISK;
			return stat;

		case DEV_SD1:
        case DEV_SD2:
			currentSD = pdrv - DEV_SD1;
			stat = sd_status(0);
			return stat;

        default: break;
    }
	return STA_NOINIT;
}


/*-----------------------------------------------------------------------*/
/* Initialise a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive number to identify the drive */
) {
	DSTATUS stat = 0;

	switch (pdrv) {

		case DEV_NUL:
			return stat;

		case DEV_IFS:
			#if IFS_DRV_KB > 0
				drvIFS = (byte *) ifs_data;
			#endif
			return stat;

		case DEV_RAM:
			if(!drvRAM) {
				x_malloc((byte **) &drvRAM, (RAM_DRV_KB * 1024ul));	/* allocate RAM disk memory */
				if(!drvRAM) stat |= STA_NODISK;
			}
			return stat;

		case DEV_SD1:
        case DEV_SD2:
            currentSD = pdrv - DEV_SD1;
			if(SYSTEM_SPI < 0 || openSPI(SYSTEM_SPI, 0, 8, SD_CARD_CLK)) break;
            stat = sd_init(0);
			return stat;

        default: break;

    }
	return STA_NOINIT;
}


/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive number to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
) {
	DRESULT res = FR_OK;

	switch (pdrv) {

		case DEV_NUL:
			return res;

		case DEV_IFS:
			#if IFS_DRV_KB > 0
                if(sector < ((IFS_DRV_KB * 1024ul) / BYTE_ROW_SIZE))
                    memcpy(buff, (drvIFS + (sector * BYTE_ROW_SIZE)), (count * BYTE_ROW_SIZE));
                else res = RES_PARERR;
            #else
                res = RES_PARERR;
			#endif
			return res;

		case DEV_RAM:
			if(drvRAM) {
				if(sector < ((RAM_DRV_KB * 1024ul) / get_ssize(&FatFs)))
					memcpy(buff, (drvRAM + (sector * get_ssize(&FatFs))), (count * get_ssize(&FatFs)));
				else res = RES_PARERR;
			}
			else res = RES_NOTRDY;
			return res;

		case DEV_SD1:
        case DEV_SD2:
			currentSD = pdrv - DEV_SD1;
            if(SYSTEM_SPI < 0 || openSPI(SYSTEM_SPI, 0, 8, SD_CARD_CLK)) break;
			res = sd_read(0, buff, sector, count);
			return res;

        default: break;

    }
	return RES_PARERR;
}


/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive number to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
) {
	DRESULT res = FR_OK;

	switch (pdrv) {

		case DEV_NUL:
			return res;

		case DEV_IFS:
            #if IFS_DRV_KB > 0
                if(sector < ((IFS_DRV_KB * 1024ul) / BYTE_ROW_SIZE)) {
                    byte *pagebuff = NULL;
                    x_malloc((byte **) &pagebuff, BYTE_PAGE_SIZE);
                    if(pagebuff) {
                        #if FF_MIN_SS != FF_MAX_SS
                            WORD ss = FatFs.ssize;
                        #else
                            WORD ss = FF_MAX_SS;
                        #endif
                        NVMProgramMX1((byte *) (drvIFS + (sector * ss)), (byte *) buff, (count * ss), pagebuff);
                        x_free((byte **) &pagebuff);
                    }
                    else res = RES_ERROR;
                }
                else res = RES_PARERR;
            #else
                res = RES_PARERR;
            #endif
			return res;

		case DEV_RAM:
			if(drvRAM) {
				if(sector < ((RAM_DRV_KB * 1024ul) / get_ssize(&FatFs)))
					memcpy((drvRAM + (sector * get_ssize(&FatFs))), buff, (count * get_ssize(&FatFs)));
				else res = RES_PARERR;
			}
			else res = RES_NOTRDY;
			return res;

		case DEV_SD1:
        case DEV_SD2:
			currentSD = pdrv - DEV_SD1;
            if(SYSTEM_SPI < 0 || openSPI(SYSTEM_SPI, 0, 8, SD_CARD_CLK)) break;
			res = sd_write(0, buff, sector, count);
			return res;

        default: break;

    }
	return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive number (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
) {
	DRESULT res = FR_OK;
    DWORD v;

	switch (pdrv) {

		case DEV_NUL:
			switch(cmd) {
				case GET_SECTOR_COUNT:
					v = 0;
					memcpy(buff, &v, sizeof(DWORD));
					break;

				case GET_SECTOR_SIZE:
					v = get_ssize(&FatFs);
					memcpy(buff, &v, sizeof(WORD));
					break;

				case GET_BLOCK_SIZE:
					v = 1; /* not flash memory */
					memcpy(buff, &v, sizeof(DWORD));
					break;

                default: break;
			}
			return res;

		case DEV_IFS:
			switch(cmd) {
                case GET_SECTOR_COUNT:
                    v = (IFS_DRV_KB * 1024ul) / BYTE_ROW_SIZE;
                    memcpy(buff, &v, sizeof(DWORD));
                    break;

                case GET_SECTOR_SIZE:
                    #if IFS_DRV_KB > 0
                        v = BYTE_ROW_SIZE;
                    #else
                        v = 0;
                    #endif
                    memcpy(buff, &v, sizeof(WORD));
                    break;

                case GET_BLOCK_SIZE:
                    #if IFS_DRV_KB > 0
                        v = NUM_ROWS_PAGE;
                    #else
                        v = 0;
                    #endif
                    memcpy(buff, &v, sizeof(DWORD));
                    break;

            }
			return res;

		case DEV_RAM:
			switch(cmd) {
				case GET_SECTOR_COUNT:
					v = (RAM_DRV_KB * 1024ul) / FF_MIN_SS;
					memcpy(buff, &v, sizeof(DWORD));
					break;

				case GET_SECTOR_SIZE:
					v = FF_MIN_SS;
					memcpy(buff, &v, sizeof(WORD));
					break;

				case GET_BLOCK_SIZE:
					v = 1;	/* not flash memory */
					memcpy(buff, &v, sizeof(DWORD));
					break;

                default: break;
			}
			return res;

		case DEV_SD1:
        case DEV_SD2:
			currentSD = pdrv - DEV_SD1;
            if(SYSTEM_SPI < 0 || openSPI(SYSTEM_SPI, 0, 8, SD_CARD_CLK)) break;
			res = sd_ioctl(0, cmd, buff);
			return res;

        default: break;
	}
	return RES_PARERR;
}
