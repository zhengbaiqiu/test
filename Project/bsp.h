/****************************************************************************************************/
/*			@FileName		:	BSP.h																																		    	*/
/*			@Author			:	zhengbaiqiu																																		*/
/*			@Version		:	v1.0																																					*/
/*			@Date				:	2019.11.12  																																	*/
/****************************************************************************************************/

#ifndef	__BSP_H__
#define	__BSP_H__
#include "stm32f10x.h"

#ifdef __cplusplus
extern "C" {
#endif

static volatile ErrorStatus HSEStartUpStatus = SUCCESS;	

void BSP_Init(void);
	
void NVIC_Configure(void);
u8 HSI_SystemClock(void);
void HSE_SystemClock(void);
void IWDG_Configure(void);
//void Systick_Config_Init(void);
void TIM2_Configure(void);
void TIM3_Configure(void);
void UART3_Configure(void);
void GpioConfigInit(void);
void GpioPeriphClockConfig(void);
void SDCard_HardwareConfig(void);
void Key_HardwareConfig(void);
void Led_HardwareConfig(void);
void DigitalTubew_HardwareConfig(void);

	
	
#ifdef _cplusplus
extern }
#endif

#endif /*__BSP_H__*/	

