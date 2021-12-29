/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h


void setup()
{
    Serial.begin(115200);

tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Note: the new fonts do not draw the background colour

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop()
{
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    tft.fillScreen(TFT_BLACK);
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
      tft.setCursor (0, 8*i);
      tft.print(i+1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setCursor (18, 8*i);
      tft.print(WiFi.SSID(i).substring(0,14)); // This uses the standard ADAFruit small font
            Serial.print(" (");
      tft.setCursor (112, 8*i);
      //tft.print("(");
            Serial.print(WiFi.RSSI(i));
      tft.print(WiFi.RSSI(i));
            Serial.print(")");
      //tft.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}
