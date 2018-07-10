/*
  ExternalWakeup

  This sketch demonstrates the usage of External Interrupts (on pins) to wakeup
  a chip in sleep mode. Sleep modes allow a significant drop in the power usage
  of a board while it does nothing waiting for an event to happen.
  Battery powered application can take advantage of these modes to enhance
  battery life significantly.

  In this sketch, pressing a pushbutton attached to wkpin will wake up the board.

  This example code is in the public domain.
*/

#include "STM32LowPower.h"

// Blink sequence number
// Declare it volatile since it's incremented inside an interrupt
volatile int repetitions = 1;

// wkpin used to trigger a wakeup
#define wkpin BUTTON        /*default USER BUTTON*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Set wkpin as INPUT_PULLUP to avoid spurious wakeup
  pinMode(wkpin, INPUT_PULLUP);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("Button interrupt Wakeup a chip in deep sleep mode");
  Serial.println("Please input any key begin demo.........");
  
/* Increase the startup loop  for connection jlink or stlink debugger.
 * Because in sleep mode, stlink or jlink disconnected to chip
 */
  while (!Serial.available()) {
    digitalToggle(LED_BUILTIN);
    delay(100);
  }

  // Configure low power
  LowPower.begin();
  // Attach a wakeup interrupt on wkpin, calling repetitionsIncrease when the device is woken up
  LowPower.attachInterruptWakeup(wkpin, repetitionsIncrease, RISING);
}

void loop() {
  for (int i = 0; i < repetitions; i++) {
    digitalToggle(LED_BUILTIN);
    delay(200);
  }
  // Triggers an infinite sleep (the device will be woken up only by the registered wakeup sources)
  // The power consumption of the chip will drop consistently
  LowPower.deepSleep();
}

void repetitionsIncrease() {
  // This function will be called once on device wakeup
  // You can do some little operations here (like changing variables which will be used in the loop)
  // Remember to avoid calling delay() and long running functions since this functions executes in interrupt context
  repetitions ++;
}
