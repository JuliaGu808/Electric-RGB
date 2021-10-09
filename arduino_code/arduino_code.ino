#include "config.h"

int charIndex;
char inChar;
char inData[30];
bool has_input = false;

void setup() {
  Serial.begin(115200);

  terminal_menu();

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

  labb4_read_input();
    
  function_turnOff_All(); 

  if (buttonState_1 == HIGH || inData[0]=='1') {
    functionA_getPin_random();
    while (true) {
      labb4_read_input();
      if(function_btns_state_change()) break;
      if(has_input && (inData[0]=='1' || inData[0]=='2')){
        has_input=false;
        break;
      }
      functionA_turnOn_oneLED();     
    }    
  }

  if (buttonState_2 == HIGH || inData[0]=='2') {
    functionA_getPin_random();
    color_gap=0;
    while (true) {
      labb4_read_input();
      if(function_btns_state_change()) break;
      if(has_input && (inData[0]=='1' || inData[0]=='2')){
        has_input=false;
        break;
      }
      lastTime = millis();
      functionB_adjust_colors();
      functionB_turnOn_rainbowLED();
      functionB_color_plus();    
    }
  }

}
