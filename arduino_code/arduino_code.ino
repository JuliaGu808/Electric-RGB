#include "config.h"

void setup() {
  Serial.begin(115200);

  // put your setup code here, to run once:
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);

}

void loop() {
    
  function_btns_state_change();
    
  function_turnOff_All();

  if (buttonState_1 == HIGH ) {
    functionA_getPin_random();
    while (true) {
      if(function_btns_state_change()) break;
      functionA_turnOn_oneLED();     
    }
  }

  if (buttonState_2 == HIGH ) {
    while (true) {
      if(function_btns_state_change()) break;
      lastTime = millis();
      functionB_adjust_colors();
      functionB_turnOn_rainbowLED();
//      Serial.println();
//      Serial.print(init_color_red);
//      Serial.print(init_color_blue);
//      Serial.print(init_color_green);
//      Serial.println();
      functionB_color_plus();    
    }
  }

}
