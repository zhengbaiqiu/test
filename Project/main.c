/* Standard includes. */
#include <stdio.h>
#include "string.h"
//#include "startup_stm32f10x_hd.s"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "FreeRTOSConfig.h"
//#include "death.h"
#include "semphr.h"

/* Include includes. */
#include "projdefs.h"

/* Library includes. */
#include "stm32f10x.h"
#include "stm32f10x_it.h"

/*  Project includes. */
#include "maindef.h"
#include "bsp.h"
#include "gpioredef.h"

/*  TaskManager includes. */
#include "TK_TimerController.h"


/*        Global variable.            */
_ST_MAINMANAGER mMaininf;

//ST_MAINMANAGER mMainManager;
//SemaphoreHandle_t InitSD_Semaphore;
TaskHandle_t xTaskTimer;

/*      config function.      */
void prvSetupHardware(void);
void vCreateQueueAndSemphr(void);
void vCreateTaskManager(void);



int main(void)
{
	/*     Setup Hardware            */
	prvSetupHardware();
	
  /*     Create QueueAndSemphr.    */
	vCreateQueueAndSemphr();
	
  /*     Create Task.              */
	vCreateTaskManager();

  /*     Start the scheduler.      */
	vTaskStartScheduler();
  
	return 0;
}



void prvSetupHardware(void)
{
	BSP_Init();
}

void vCreateQueueAndSemphr(void)
{	
// 	Burn_Semaphore=xSemaphoreCreateBinary();
// 	Version_Semaphore = xSemaphoreCreateBinary();
// 	if(Burn_Semaphore == NULL)
// 	{
// 		/*��ջ�ڴ治�㣬������Ӧ��Ӧ����*/
// //		iossf = 0;
// 	}
// 	{
// 		/*�ź��������ɹ���ǰΪ�ź�����������������API����xSemaphoreTake()����ȡ�ź�����Ȼʧ�ܣ���Ϊ�������ź����ĳ�ʼֵΪ��*/
// //		iossf = 1;
// 	}
}

void vCreateTaskManager(void)
{
	xTaskCreate( TK_TimerController, "TimerTask", mainTIMER_TASK_STACK_SIZE, NULL, mainTIMER_TASK_PRIORITY, &xTaskTimer );
//	xTaskCreate( TK_CheckKeyTask, "CheckKeyTask", mainCHECKKEY_TASK_STACK_SIZE, NULL, mainCHECKKEY_TASK_PRIORITY, &xTaskKeyCheck );
	
//	vTaskSuspend(xTaskPrint);
}

void vApplicationTickHook(void)
{
	
}

































