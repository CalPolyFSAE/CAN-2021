#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "AnalogObject.h"
#include "adc.h"
#include "StateMachine.h"
#include "CanMessage.h"
#include <ctime>
/* Hardware includes. */
#include "MKE18F16.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "constants.h"



using namespace BSP;

void taskReadHunHzValuesSendCanMessages(void *){
    TickType_t xLastWakeTime;
	int end;
	int duration;
	int count = 0;


	/*
	Infinite loop below for reading from 100 HZ sensors. count used to keep track of number of current
	task cycles. end used to gather number of ticks since task started. Divide end by configTICK_RATE_HZ (stored in duration) to
	get number of seconds task has been running. Since if condition is set to count==100, duration should == 1 second
	for the function to be correctly reading at 100 HZ
	*/
	for(;;){
		xLastWakeTime = xTaskGetTickCount();
        StateMachine::readSensorsAdcValues();
    	StateMachine::readLastSensorsAdcValues();
    	StateMachine::readFirstSGaugesAdcValues();
     	StateMachine::readLastSGaugeAdcValues();
        CanMessage::sendTime();
		CanMessage::sendSensors();
		CanMessage::sendFourSGauges();
		CanMessage::sendLastSGauge();
        CANFirstSensors sensorValues1 = StateMachine::getFirstSensorsCANSensors();
		CANLastSensors sensorValues2 = StateMachine::getLastSensorsCANSensors();
		CANFourSGauges sensorValues3 = StateMachine::getFourSGaugesCANSensors();
		CANLastSGauge sensorValues4 = StateMachine::getLastSGaugeCANSensors();
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS((1/.1)));
		count++;
		if(count == 100){
			end=xTaskGetTickCount();
			duration=(end)/configTICK_RATE_HZ;
		}

    }
}


int main( void )
{

    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    adc::ADC::ConstructStatic(NULL);

	// Create a task to read 100 Hz values for sensors and strain gauges
	xTaskCreate(taskReadHunHzValuesSendCanMessages, "taskReadHunHzValuesSendCanMessages", 1000, NULL, 2, NULL);


	/* Start the scheduler. */
	vTaskStartScheduler();

	/* Infinite loop */
	//for( ;; );
}

extern "C" {

/*-----------------------------------------------------------*/
void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
}
/*-----------------------------------------------------------*/

}