/*
* This example sets timerx software interrupt
* TIM6/7 baseTimer  by huaweiwx@sina.com
* note: if  used freeRtos, Timer7 is undefined
*/

#include "HardwareBaseTimer.h"

#define Timerx Timer6

void interrupt() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setup() {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);

    Timerx.setPeriod(1000000); // in microseconds = 1 second

    Timerx.attachInterrupt(interrupt);
    Timerx.resume();
}

void loop() {
    delay(5000);

    Serial.println("----");
    
    Serial.print("PCLK1Freq: ");
    Serial.println(HAL_RCC_GetPCLK1Freq());
    
    Serial.print("Timer base frequency:");
    Serial.println(Timerx.getBaseFrequency());

    Serial.print("Timer prescaler:");
    Serial.println(Timerx.getPrescaleFactor());

    Serial.print("Timer period:");
    Serial.println(Timerx.getOverflow());
}
