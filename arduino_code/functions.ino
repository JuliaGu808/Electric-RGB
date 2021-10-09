void function_turnOff_All() {
  for (int EACH_PIN = PIN_GREEN; EACH_PIN <= PIN_BLUE; EACH_PIN++) {
    digitalWrite(EACH_PIN, LOW);
  }
}

bool function_btns_state_change() {
  buttonState_1 = digitalRead(buttonPin_1);
  buttonState_2 = digitalRead(buttonPin_2);
  if (buttonState_1 == HIGH || buttonState_2 == HIGH) return true;
  return false;
}

void functionA_getPin_random() {
  RANDOM_PIN = random(PIN_GREEN, PIN_GREEN + 3);
}

void functionA_turnOn_oneLED() {
  digitalWrite(RANDOM_PIN, HIGH);
}

void functionB_turnOn_rainbowLED() {
  functionC_read_speed_value();

  while ((millis() - lastTime) < speedPinValue) {
    if (function_btns_state_change()) break;
    functionC_read_speed_value();
    functionC_choose_one_rainbow();
  }
}

void functionC_choose_one_rainbow(){
  switch(RANDOM_PIN){
    case 9: // green up
      analogWrite(PIN_RED, 0); // do nothing
      analogWrite(PIN_GREEN, color_gap); // fade up
      analogWrite(PIN_BLUE, 255 - color_gap); // fade down
      break;
    case 10: // red up
      analogWrite(PIN_RED, color_gap); // fade up
      analogWrite(PIN_GREEN, 255 - color_gap); // fade down
      analogWrite(PIN_BLUE, 0); // do nothing
      break;
    case 11: // blue up
      analogWrite(PIN_RED, 255 - color_gap); // fade down
      analogWrite(PIN_GREEN, 0); // do nothing
      analogWrite(PIN_BLUE, color_gap); // fade up  
      break;
    default:
      break;         
  }
}

void functionB_adjust_colors() {
  if (color_gap==256){
    color_gap = 0;
    RANDOM_PIN = RANDOM_PIN==11 ? 8 : RANDOM_PIN+1;
  }
}

void functionB_color_plus() {
  color_gap = color_gap + 1;
}

void functionC_read_speed_value() {
  speedPinValue = analogRead(speedPin);
  speedPinValue = map(speedPinValue, 275, 725, 10, 100);
}
