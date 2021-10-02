enum RGB {
  PIN_GREEN=9, PIN_RED, PIN_BLUE
};

int RANDOM_PIN = PIN_GREEN;

int init_color_red = 20, init_color_green = 100, init_color_blue = 200;

const int buttonPin_1 = 8;
const int buttonPin_2 = 13;
int buttonState_1 = 0;
int buttonState_2 = 0;
int speedPin = 2;
int speedPinValue = 0;

unsigned long lastTime = 0;
