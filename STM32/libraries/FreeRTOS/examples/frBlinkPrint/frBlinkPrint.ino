// Simple demo of three threads/ 三个线程的简单演示
// LED blink thread, print thread, and idle loop

/*
    Attention(注意):
	  To use idle hook, Must set  configUSE_IDLE_HOOK to 1 in file HAL_Conf.h or FreeRTOSConfig.h
	  该例程使用 idle, 因此在文件HAL_Conf.h 或 FreeRTOSConfig.h 中需要设置 宏定义 configUSE_IDLE_HOOK 为 1
*/
#include <FreeRTOS.h>

// The LED is attached to pin 13 on Arduino.
# define LED_PIN    LED_BUILTIN

volatile uint32_t count = 0;

// handle for blink task
TaskHandle_t blink;

//------------------------------------------------------------------------------
// high priority for blinking LED
static void vLEDFlashTask(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);

  // Flash led every 200 ms.
  for (;;) {
    // Turn LED on.
    digitalWrite(LED_PIN, LOW);

    // Sleep for 20 milliseconds.
    vTaskDelay((20L * configTICK_RATE_HZ) / 1000L);

    // Turn LED off.
    digitalWrite(LED_PIN, HIGH);

    // Sleep for 230 milliseconds.
    vTaskDelay((230L * configTICK_RATE_HZ) / 1000L);
  }
}

//------------------------------------------------------------------------------
static void vPrintTask(void *pvParameters) {
  while (1) {
    // Sleep for one second.
    vTaskDelay(configTICK_RATE_HZ);

    // Print count for previous second.
    Serial.print(F("Count per second: "));
    Serial.println(count);

    // Zero count.
    count = 0;
  }
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  // wait for Leonardo
  while (!Serial) {}

  // create blink task
  xTaskCreate(vLEDFlashTask,
              "Task1",
              configMINIMAL_STACK_SIZE + 50,
              NULL,
              tskIDLE_PRIORITY + 2,
              &blink);

  // create print task
  xTaskCreate(vPrintTask,
              "Task2",
              configMINIMAL_STACK_SIZE + 100,
              NULL,
              tskIDLE_PRIORITY + 1,
              NULL);

  // start FreeRTOS
  vTaskStartScheduler();

  // should never return
  Serial.println(F("Die"));
  while (1);
}

/*  ----------------------------------- idle hook  attention --------------------------
    1  loop() function is a idle hook. (set configUSE_IDLE_HOOK to 1 enable it)
    2  idle loop has a very small stack.(check or set configMINIMAL_STACK_SIZE)
    3  loop must never block.
---------------------------------------------------------------------------------------*/
void loop() {
  while (1) {
    // must insure increment is atomic
    // in case of context switch for print
    noInterrupts();
    count++;
    interrupts();
  }
}
