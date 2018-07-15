
#include <Arduino.h>
#include "FreeRTOS_STM.h"

//------------------------------------------------------------------------------
/** vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. 
*/
	
void  __attribute__((weak)) vApplicationIdleHook( void ) {
  void loop();
  loop();
}

//------------------------------------------------------------------------------
/** calibration factor for delayMS */
#define CAL_FACTOR (F_CPU/7000)
/** delay between led error flashes
 * \param[in] millis milliseconds to delay
 */
static void delayMS(uint32_t millis) {
  uint32_t iterations = millis * CAL_FACTOR;
  uint32_t i;
  for(i = 0; i < iterations; ++i) {
    asm volatile("nop\n\t");
  }
}
//------------------------------------------------------------------------------
/** Blink error pattern
 *
 * \param[in] n  number of short pulses
 */
static void errorBlink(int n) {
  noInterrupts();
  pinMode(LED_BUILTIN, OUTPUT);
  for (;;) {
    int i;
    for (i = 0; i < 2*n; i++) {
      digitalToggle(LED_BUILTIN);
      delayMS(300);
    }
    delayMS(2000);
  }
}
//------------------------------------------------------------------------------
/** assertBlink
 * Blink one short pulse every two seconds if configASSERT fails.
*/
void assertBlink() {
  errorBlink(1);
}

void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.*/
    //taskDISABLE_INTERRUPTS();
#ifdef USE_FULL_ASSERT
  errorBlink(5);
#else
	for(;;);
#endif
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    //taskDISABLE_INTERRUPTS();
#ifdef USE_FULL_ASSERT
	errorBlink(6);
#else
	for(;;);
#endif
}

