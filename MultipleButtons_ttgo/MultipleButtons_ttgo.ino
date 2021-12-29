/////////////////////////////////////////////////////////////////

#include "Button2.h"

/////////////////////////////////////////////////////////////////

#define BUTTON_A_PIN  0
#define BUTTON_B_PIN  35

/////////////////////////////////////////////////////////////////

Button2 buttonA, buttonB;

/////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("\n\nMultiple Buttons Demo");
  
  buttonA.begin(BUTTON_A_PIN);
  buttonA.setClickHandler(click);

  buttonB.begin(BUTTON_B_PIN);
  buttonB.setClickHandler(click);
}

/////////////////////////////////////////////////////////////////

void loop() {
  buttonA.loop();
  buttonB.loop();
}

/////////////////////////////////////////////////////////////////

void click(Button2& btn) {
    if (btn == buttonA) {
      Serial.println("Left button clicked");
    } else if (btn == buttonB) {
      Serial.println("Right button clicked");
    }
}

/////////////////////////////////////////////////////////////////
