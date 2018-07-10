/*
  TimedWakeup

  This sketch demonstrates the usage of Internal Interrupts to wakeup a chip
  in deep sleep mode.

  In this sketch, the internal RTC will wake up the processor every second.

  This example code is in the public domain.
*/

#include "STM32LowPower.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(1000);
  Serial.println("Wakeup a chip in deep sleep mode");
  Serial.println("Please input any key begin demo.........");
  
/* Increase the startup loop  for connection jlink or stlink debugger.
 * Because in sleep mode, stlink or jlink disconnected to chip
 */
  while (!Serial.available()) {
    digitalToggle(LED_BUILTIN);
    delay(100);
  }
  Serial.println("internal RTC will wake up the processor every second now");
  // Configure low power
  LowPower.begin();
}

void loop() {
  digitalToggle(LED_BUILTIN);
  LowPower.deepSleep(1000);
}
