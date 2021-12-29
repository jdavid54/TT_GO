/////////////////////////////////////////////////////////////////

#include "Button2.h"
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h


/////////////////////////////////////////////////////////////////

#define BUTTON_PIN_LEFT  0
#define BUTTON_PIN_RIGHT  35

/////////////////////////////////////////////////////////////////

Button2 l_button;
Button2 r_button;

/////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("\n\nButton Demo");

tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK); 
  
  l_button.begin(BUTTON_PIN_LEFT);
  r_button.begin(BUTTON_PIN_RIGHT);
  
  // button.setLongClickTime(1000);
  // button.setDoubleClickTime(400);

  Serial.println(" Longpress Time: " + String(l_button.getLongClickTime()) + "ms");
  Serial.println(" DoubleClick Time: " + String(l_button.getDoubleClickTime()) + "ms");
  
  
  //Serial.println(" Right longpress Time: " + String(r_button.getLongClickTime()) + "ms");
  //Serial.println(" Right doubleClick Time: " + String(r_button.getDoubleClickTime()) + "ms");


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
  r_button.loop();
}

/////////////////////////////////////////////////////////////////

void pressed(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button pressed");
//    tft.fillScreen(TFT_BLACK);
//    tft.setCursor (0, 8);
//      tft.print((btn == l_button) ? "Left" : "Right");
//    tft.setCursor (0, 16);
//      tft.print("button pressed");
}
void released(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.print(" button released: ");
    Serial.println(btn.wasPressedFor());
//    tft.fillScreen(TFT_BLACK);
//    tft.setCursor (0, 8);
//      tft.print("button pressed");
}
void changed(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println("  button changed");
}
void click(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button click\n");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor (0, 8);
    tft.print((btn == l_button) ? "Left" : "Right");
    tft.setCursor (0, 16);
    tft.print("Click detected"); 
}
void longClickDetected(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button long click detected\n");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor (0, 8);
      tft.print((btn == l_button) ? "Left" : "Right");
    tft.setCursor (0, 16);
      tft.print("Long click detected");  
}
void longClick(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button long click\n");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor (0, 8);
      tft.print((btn == l_button) ? "Left" : "Right");
    tft.setCursor (0, 16);
      tft.print("Long click");
}
void doubleClick(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button double click\n");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor (0, 8);
      tft.print((btn == l_button) ? "Left" : "Right");
    tft.setCursor (0, 16);
      tft.print("Double click");
}
void tripleClick(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" button triple click\n");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor (0, 8);
      tft.print((btn == l_button) ? "Left" : "Right");
    tft.setCursor (0, 16);
      tft.print("Triple click");
}
void tap(Button2& btn) {
    Serial.print((btn == l_button) ? "Left" : "Right");
    Serial.println(" buttontap");
}

/////////////////////////////////////////////////////////////////
