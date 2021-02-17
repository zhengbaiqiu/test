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


/*  ϵͳ������ؿ��ƿ�                                              */
void api_InitParamsAtPowerOn(void);

/*  ʱ����ؿ��ƿ�                                                  */
u32 api_GetSystemTimePeriod(u32 StartTime);
u32 api_GetCurrentSystemTime(void);




/*--------------------------------------------------------------------------

        ϵͳ������ؿ��ƿ�

---------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* SD card power-on initialization variables              		   			   */
/*-----------------------------------------------------------------------*/


void api_InitParamsAtPowerOn(void)
{
	u16 iCont;
	/*    ϵͳ�δ������        */
	mMaininf.mSystem.mSystemTick = 0;
	
	/*    ����ʱ��              */
	mMaininf.mSystem.mPowerOnStartTime = 0;
	
	
}



/*--------------------------------------------------------------------------

        ʱ����ؿ⺯��

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


