/*
 * main.h
 *
 *  Created on: 2018/8/21
 *      Author: John
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <msp430.h>

/*
 * Scheduler include files.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "RTOS_Init.h"

//=======================================================================================================================

/*
 * Priorities at which the tasks are created.
 */
#define mainQUEUE_RECEIVE_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2 )
#define mainQUEUE_SEND_TASK_PRIORITY        ( tskIDLE_PRIORITY + 1 )

/*
 * The rate at which data is sent to the queue.  The 200ms value is converted
 * to ticks using the portTICK_PERIOD_MS constant.
 */
#define mainQUEUE_SEND_FREQUENCY_MS         ( pdMS_TO_TICKS( 1000 ) )
#define testQUEUE_SEND_FREQUENCY_MS         ( pdMS_TO_TICKS( 600 ) )

/*
 * The number of items the queue can hold.  This is 1 as the receive task
 * will remove items as they are added, meaning the send task should always find
 * the queue empty.
 */
#define mainQUEUE_LENGTH                    ( 1 )

/*
 * The queue used by both tasks.
 */
static QueueHandle_t xQueue = NULL;

/*
 * The heap is allocated here so the "persistent" qualifier can be used.  This
 * requires configAPPLICATION_ALLOCATED_HEAP to be set to 1 in FreeRTOSConfig.h.
 * See http://www.freertos.org/a00111.html for more information.
 */
#ifdef __ICC430__
    __persistent                    /* IAR version. */
#else
    #pragma PERSISTENT( ucHeap )    /* CCS version. */
#endif
uint8_t ucHeap[ configTOTAL_HEAP_SIZE ] = { 0 };

/*
 * Used for maintaining a 32-bit run time stats counter from a 16-bit timer.
 */
volatile uint32_t ulRunTimeCounterOverflows = 0;


/*
 * Set mainCREATE_SIMPLE_BLINKY_DEMO_ONLY to one to run the simple blinky demo,
 * or 0 to run the more comprehensive test and demo application.
 */
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY  1

//=======================================================================================================================

/*
 * The tasks as described in the comments at the top of this file.
 */
static void testQueueTask( void *pvParameters );

//=======================================================================================================================
void Main_Task_Function();
void GPIO_Init();
void TestToggleLED();

#endif /* MAIN_H_ */






















