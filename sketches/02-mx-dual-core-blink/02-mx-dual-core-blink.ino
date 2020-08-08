/*
 * Portenta Example Two: Dual Core Blink Sketch
 *
 * lyonk - 08/08/2020
 *
 * Board: Portenta H7
 * Core:  M7 / M4
 *
 * Example of booting M4 core, and running two programs simultaneously.
 *
 * Thanks to Jeremy Ellis for the idea of using the defines to identify the target core.
 * https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/blob/master/my02a-dual-core.ino
 * 
 */

int blinkLED;

void setup() {
  #ifdef CORE_CM7
    LL_RCC_ForceCM4Boot();
    blinkLED = LEDB;
  #endif
  #ifdef CORE_CM4
    blinkLED = LEDR;
  #endif  
}

void loop() {
   #ifdef CORE_CM4
     delay(200);
   #endif
  
   digitalWrite(blinkLED, LOW);
   delay(200);
   digitalWrite(blinkLED, HIGH);
   delay(200);
}
