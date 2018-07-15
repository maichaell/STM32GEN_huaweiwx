/* Test to determine context switch time with a semaphore
  使用信号量确定上下文切换时间
  Connect a scope to pin LED_PIN /请使用示波器看 LED_PIN 波形
  Measure difference in time between first pulse with no context switch
  and second pulse started in ledControl and ended in ledOffTask.
  This is the time for the semaphore and a context switch.
*/

#include <FreeRTOS.h>

// The LED is attached to pin 13 on Arduino.
#ifdef  LED_BUILTIN
# define LED_PIN    LED_BUILTIN
#	define LED_ON bitRead(LED_BUILTIN_MASK,0)
#else
#	define LED_PIN  13    //fixd me
#	define LED_ON 1   //fixd me
#endif

// Semaphore to trigger context switch
SemaphoreHandle_t xSemaphore;
//------------------------------------------------------------------------------
// high priority thread to set pin low
static void ledOffTask(void *pvParameters) {
  for (;;) {
    xSemaphoreTake(xSemaphore, portMAX_DELAY);
    digitalWrite(LED_PIN, HIGH);
  }
}
//------------------------------------------------------------------------------
// lower priority thread to toggle LED and trigger thread 1
static void ledControl(void *pvParameters) {
  for (;;) {
    // first pulse to get time with no context switch
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

    // start second pulse
    digitalWrite(LED_PIN, LOW);

    // trigger context switch for task that ends pulse
    xSemaphoreGive(xSemaphore);

    // sleep until next tick
    vTaskDelay(1);
  }
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // create high priority thread
  xTaskCreate(ledOffTask,
              "Task1",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 2,
              NULL);

  // create lower priority thread
  xTaskCreate(ledControl,
              "Task2",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY + 1,
              NULL);

  // create semaphore
  vSemaphoreCreateBinary(xSemaphore);

  // start FreeRTOS
  vTaskStartScheduler();

  // should never return
  Serial.println("Die");
  while (1);
}

/*  ----------------------------------- idle hook  attention --------------------------
    1  loop() function is a idle hook. (set configUSE_IDLE_HOOK to 1 enable it)
    2  idle loop has a very small stack.(check or set configMINIMAL_STACK_SIZE)
    3  loop must never block.
---------------------------------------------------------------------------------------*/
void loop() {
  while (1) {
    // idel hook code begin;
	
	
    // idel hook code end;
  }
}
