/////////////////////////////////////////////////////////////////

#include "Button2.h"

/////////////////////////////////////////////////////////////////

#define BUTTON_PIN_LEFT  0
#define BUTTON_PIN_RIGHT  35

/////////////////////////////////////////////////////////////////

Button2 l_button;
Button2 r_button;

/////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  delay(50);
  Serial.println("\n\nButton Demo");

  l_button.begin(BUTTON_PIN_LEFT);
  r_button.begin(BUTTON_PIN_RIGHT);
  
  // button.setLongClickTime(1000);
  // button.setDoubleClickTime(400);

  Serial.println(" Left longpress Time: " + String(l_button.getLongClickTime()) + "ms");
  Serial.println(" Left doubleClick Time: " + String(l_button.getDoubleClickTime()) + "ms");
  Serial.println(" Right longpress Time: " + String(r_button.getLongClickTime()) + "ms");
  Serial.println(" Right doubleClick Time: " + String(r_button.getDoubleClickTime()) + "ms");


  // left button
  // button.setChangedHandler(changed);
  // button.setPressedHandler(pressed);
  l_button.setReleasedHandler(released);

  // button.setTapHandler(tap);
  l_button.setClickHandler(click);
  l_button.setLongClickDetectedHandler(longClickDetected);
  l_button.setLongClickHandler(longClick);
  
  l_button.setDoubleClickHandler(doubleClick);
  l_button.setTripleClickHandler(tripleClick);


  // right button
  // button.setChangedHandler(changed);
  // button.setPressedHandler(pressed);
  r_button.setReleasedHandler(released);

  // button.setTapHandler(tap);
  r_button.setClickHandler(click);
  r_button.setLongClickDetectedHandler(longClickDetected);
  r_button.setLongClickHandler(longClick);
  
  r_button.setDoubleClickHandler(doubleClick);
  r_button.setTripleClickHandler(tripleClick);

}



/////////////////////////////////////////////////////////////////

void loop() {
  l_button.loop();
}

/////////////////////////////////////////////////////////////////

void pressed(Button2& btn) {
    Serial.println("pressed");
}
void released(Button2& btn) {
    Serial.print("released: ");
    Serial.println(btn.wasPressedFor());
}
void changed(Button2& btn) {
    Serial.println("changed");
}
void click(Button2& btn) {
    Serial.println("click\n");
}
void longClickDetected(Button2& btn) {
    Serial.println("long click detected\n");
}
void longClick(Button2& btn) {
    Serial.println("long click\n");
}
void doubleClick(Button2& btn) {
    Serial.println("double click\n");
}
void tripleClick(Button2& btn) {
    Serial.println("triple click\n");
}
void tap(Button2& btn) {
    Serial.println("tap");
}

/////////////////////////////////////////////////////////////////
