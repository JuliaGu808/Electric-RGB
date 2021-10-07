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
    if(function_btns_state_change()) break;
    functionC_read_speed_value();
    analogWrite(PIN_GREEN, init_color_green);
    analogWrite(PIN_RED, init_color_red);
    analogWrite(PIN_BLUE, init_color_blue);
  }
}

void functionB_adjust_colors() {
  if (init_color_red > 255) init_color_red = 0;
  if (init_color_green > 255) init_color_green = 0;
  if (init_color_blue > 255) init_color_blue = 0;
}

void functionB_color_plus() {
  init_color_red = init_color_red + 10;
  init_color_green = init_color_green + 50;
  init_color_blue = init_color_blue + 100;
}

void functionC_read_speed_value(){
  speedPinValue = analogRead(speedPin);
  speedPinValue = map(speedPinValue, 275, 725, 50, 800);
}
