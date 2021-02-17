/*        Standard includes.                */
#include "stm32f10x.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*        freertos           */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "portmacro.h"
#include "projdefs.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"
#include "semphr.h"

/*        FatFS             */
//#include "ff.h"

/*        Project            */
#include "maindef.h"
//#include "sd.h"
#include "apiLib.h"
//#include "TK_SDCardController.h"


/*  系统变量相关控制库                                              */
void api_InitParamsAtPowerOn(void);

/*  时间相关控制库                                                  */
u32 api_GetSystemTimePeriod(u32 StartTime);
u32 api_GetCurrentSystemTime(void);




/*--------------------------------------------------------------------------

        系统变量相关控制库

---------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* SD card power-on initialization variables              		   			   */
/*-----------------------------------------------------------------------*/


void api_InitParamsAtPowerOn(void)
{
	u16 iCont;
	/*    系统滴答计数器        */
	mMaininf.mSystem.mSystemTick = 0;
	
	/*    其它时间              */
	mMaininf.mSystem.mPowerOnStartTime = 0;
	
	
}



/*--------------------------------------------------------------------------

        时间相关库函数

---------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* Get system time period         	      														   */
/*-----------------------------------------------------------------------*/


u32 api_GetSystemTimePeriod(u32 StartTime)
{
	u32 res;
	
	if(mMaininf.mSystem.mSystemTick >= StartTime)
	{
		res = mMaininf.mSystem.mSystemTick - StartTime;
	}
	else
	{
		res = SYSTEMTIMEMAX - StartTime + mMaininf.mSystem.mSystemTick;
	}
	
	return res;
}



/*-----------------------------------------------------------------------*/
/* Get the current system time          															   */
/*-----------------------------------------------------------------------*/


u32 api_GetCurrentSystemTime(void)
{
	return mMaininf.mSystem.mSystemTick;
}


