/*
 * main.c
 *
 *  Created on: 2018/8/21
 *      Author: John
 */

#include "main.h"

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	GPIO_Init();
	Main_Task_Function();

    for( ;; );

}

/*
 * In this projector just to create a task to blink LED
 */
void Main_Task_Function(){
    /* Create the queue. */
    xQueue = xQueueCreate( mainQUEUE_LENGTH, sizeof( uint32_t ) );

    if( xQueue != NULL )
    {
        /* Start the two tasks as described in the comments at the top of this
        file. */
        xTaskCreate( testQueueTask,                     /* The function that implements the task. */
                    "TEST",                             /* The text name assigned to the task - for debug only as it is not used by the kernel. */
                    configMINIMAL_STACK_SIZE,           /* The size of the stack to allocate to the task. */
                    NULL,                               /* The parameter passed to the task - not used in this case. */
                    mainQUEUE_RECEIVE_TASK_PRIORITY,    /* The priority assigned to the task. */
                    NULL );                             /* The task handle is not required, so NULL is passed. */


        /* Start the tasks and timer running. */
        vTaskStartScheduler();
    }
}

/*
 * Task
 */
static void testQueueTask( void *pvParameters )
{
    TickType_t xNextWakeTime;
    /* Remove compiler warning about unused parameter. */
    ( void ) pvParameters;

    /* Initialise xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ;; )
    {
        /* Place this task in the blocked state until it is time to run again. */
        vTaskDelayUntil( &xNextWakeTime, testQUEUE_SEND_FREQUENCY_MS );
        /* Toggle the LED. */
        TestToggleLED(1);
    }
}

/*
 *  PIN GPIO or feature initial
 */
void GPIO_Init(){
    P6DIR |= BIT6 +BIT7;
    P6OUT |= BIT6 +BIT7;
}

/*
 *  Toggle LED for test
 */
void TestToggleLED(){
    P6OUT ^= (BIT6+BIT7);
}
















