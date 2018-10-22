/*
 * RTOS_Init.h
 *
 *  Created on: 2018/8/21
 *      Author: John
 */

#ifndef RTOS_INIT_H_
#define RTOS_INIT_H_

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include <msp430.h>

//=======================================================================================================================

/*
 * Prototypes for the standard FreeRTOS callback/hook functions implemented
 * within this file.
 */
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );

#endif /* RTOS_INIT_H_ */
