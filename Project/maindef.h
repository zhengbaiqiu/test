/****************************************************************************************************/
/*			@FileName		:	MAINDEF.h																																	  	*/
/*			@Author			:	zhengbaiqiu																																		*/
/*			@Version		:	v1.0																																					*/
/*			@Date				:	2019.11.12  																																	*/
/****************************************************************************************************/

#ifndef	__MAINDEF_H__
#define	__MAINDEF_H__

#include <stdlib.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stm32f10x.h"


/*		struct congig		*/



#ifdef __cplusplus
extern "C" {
#endif
	
	
#define m_Ok 1                         //真
#define m_NoOk 0                       //假
	
#define BURN_TIMEOUT 300               //烧录步骤500ms超时	
	
#define mePRINT_QUEUE_SIZE	(5)
#define meBURN_QUEUE_SIZE	(5)
#define mDELAY100msTick		( pdMS_TO_TICKS( ( TickType_t ) 100 ) )	
#define mDELAY200msTick		( pdMS_TO_TICKS( ( TickType_t ) 200 ) )	
#define mDELAY500msTick		( pdMS_TO_TICKS( ( TickType_t ) 500 ) )
	
	
/* Task priorities. */
//#define mainQUEUE_POLL_PRIORITY				( tskIDLE_PRIORITY + 2 )
//#define mainCHECK_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
//#define mainSEM_TEST_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainBLOCK_Q_PRIORITY				( tskIDLE_PRIORITY + 2 )
//#define mainCREATOR_TASK_PRIORITY           ( tskIDLE_PRIORITY + 3 )
//#define mainFLASH_TASK_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainCOM_TEST_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainINTEGER_TASK_PRIORITY           ( tskIDLE_PRIORITY )
#define mainTIMER_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainCHECKKEY_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainCHECKSD_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainPRINT_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainBURN_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainVERSIONCHECK_TASK_PRIORITY				( tskIDLE_PRIORITY + 2 )


/* Task Stack. */
#define mainTIMER_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKKEY_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKSD_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainVERSIONCHECK_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainPRINT_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainBURN_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 128 )



/*--------------------------------------------------------------------------

        自定义结构体

---------------------------------------------------------------------------*/	


/*   	 自定义			*/
#define SYSTEMTIMEMAX                86400000               /*   System timing maximum 24 hours  */

/* timeout time define */

#define TIMEOUT_0ms           (0)               /*   0ms超时      */
#define TIMEOUT_5ms           (5)               /*   5ms超时      */
#define TIMEOUT_10ms          (10)              /*   10ms超时     */
#define TIMEOUT_50ms          (50)              /*   50ms超时     */
#define TIMEOUT_100ms         (100)             /*   100ms超时    */
#define TIMEOUT_300ms         (300)             /*   300ms超时    */
#define TIMEOUT_500ms         (500)             /*   500ms超时    */
#define TIMEOUT_1000ms        (1000)            /*   1000ms超时   */
#define TIMEOUT_3500ms        (3500)            /*   3500ms超时   */
#define TIMEOUT_5000ms        (5000)            /*   5000ms超时   */

/*   	 结构体声明			*/

typedef struct _ST_SYSTEM_MANAGER{
	u32 mSystemTick ;                /*  1ms 模拟滴答计数器   */
	u32 mPowerOnStartTime ;
}_ST_SYSTEM_MANAGER;


typedef struct _ST_MAINMANAGER{
	/*        文件内定义        */
	_ST_SYSTEM_MANAGER         mSystem;

}_ST_MAINMANAGER;
		
extern _ST_MAINMANAGER mMaininf;
	
void prvSetupHardware(void);
void vCreateQueueAndSemphr(void);



	
	
#ifdef _cplusplus
extern }
#endif

#endif /*__MAINDEF_H__*/	

