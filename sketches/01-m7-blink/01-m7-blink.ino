/*
 * Portenta Example One: Basic Arduino Blink
 *
 * lyonk - 08/08/2020
 *
 * Board: Portenta H7
 * Core:  M7
 *
 * Standard Arduino Hello World - Blink
 * 
 */


void setup() {
  pinMode( LED_BUILTIN, OUTPUT );
}

void loop() {
  digitalWrite( LED_BUILTIN, HIGH );
  delay(1000);
  digitalWrite( LED_BUILTIN, LOW );
  delay(1000); 
}
