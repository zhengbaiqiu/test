/*        Standard includes.                */
#include "stm32f10x.h"

/*        freertos           */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "portmacro.h"
#include "projdefs.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/*        Project            */
#include "maindef.h"
//#include "sd.h"
#include "apiLib.h"
#include "TK_TimerController.h"
#include "timer.h"
//#include "TK_SDCardController.h"


u8 smgduan[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
             0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
void TK_TimerController( void *pvParameters );
void TimerDetection(void);



/*-----------------------------------------------------------------------*/
/* Timer task                                   						             */
/*-----------------------------------------------------------------------*/


void TK_TimerController( void *pvParameters )
{
	u8 mDelay;
	u32 mTickTime;
	
	for(;;)
	{
		/*    ��ȡ��ǰʱ��     */
		mTickTime = api_GetCurrentSystemTime();
		
		/*    ��ʱ��λ���Ź�   */
		IWDG_ReloadCounter();
		
		/*    ��ʱ�������     */
		TimerDetection();
		
		/*    ��ȡ����ʱ��     */
		if(api_GetSystemTimePeriod(mTickTime) < TIMEOUT_50ms) mDelay = 50 - api_GetSystemTimePeriod(mTickTime);
		else mDelay = TIMEOUT_0ms;
		
		/*    ����������ʱ     */
		vTaskDelay(mDelay);
	}
}



/*-----------------------------------------------------------------------*/
/* Timing Detection Peripheral                                           */
/*-----------------------------------------------------------------------*/


void TimerDetection(void)
{
	u8 i;
	/*    SD����⴦��      */
	
	for(i=1;i<16;i++)
	{
	//	GPIO_Write(GPIOC,(u16)(~smgduan[i]));
	//	GPIO_Write(GPIOC,0x12);
		GPIO_SetBits(GPIOC,GPIO_Pin_0);
		GPIO_ResetBits(GPIOC,GPIO_Pin_1);
		delay_ms(10);	
	}
}








