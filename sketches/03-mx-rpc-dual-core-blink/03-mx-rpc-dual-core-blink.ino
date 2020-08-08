/*
 * Portenta Sample 03: Dual Core Blink Sketch (using RPC) 
 *
 * lyonk - 08/08/2020
 *
 * Board: Portenta H7
 * Core:  M7 / M4
 *
 * Example of using a variable to synchronize actions across cores.  There is probably a better way to do this, 
 * please let me know.
 *
 * Note: The M4 core will not compile unless -fexceptions is added 
 * to the bottom of the files: 
 * cflags.txt
 * cxxflags.txt 
 * at
 * C:\Users\<USER>\AppData\Local\Arduino15\packages\arduino-beta\hardware\mbed\1.2.2\variants\PORTENTA_H7_M4
 * 
 */

#include "RPC_internal.h" 
#define BLINK_DELAY       400
#define BLINK_CHECK_DELAY 20
int blinkLED;

#ifdef CORE_CM4
  unsigned int m4Blink = 0;
  
  unsigned int setM4Blink( unsigned int blinkEnable ){
    m4Blink = blinkEnable;
    return blinkEnable;
  }
#endif


void setup()   {
  RPC1.begin();
  #ifdef CORE_CM7
    LL_RCC_ForceCM4Boot();
    blinkLED = LEDB;
  #endif
  #ifdef CORE_CM4
    blinkLED = LEDR;
    RPC1.bind("m4Blink", setM4Blink ); // RPC binds don't need to be named the same as their target fn.
  #endif  
  pinMode(blinkLED, OUTPUT);
}

void loop() {
   #ifdef CORE_CM7
      digitalWrite(blinkLED, LOW);
      RPC1.call("m4Blink", 1 );
      delay(BLINK_DELAY);
      digitalWrite(blinkLED, HIGH);
      RPC1.call("m4Blink", 0 );
      delay(BLINK_DELAY);
   #endif

   #ifdef CORE_CM4
      if( m4Blink == 1 ) {
        digitalWrite(blinkLED, HIGH);  
      }else{
        digitalWrite(blinkLED, LOW);
      }
      delay(BLINK_CHECK_DELAY);
   #endif   
   
}
