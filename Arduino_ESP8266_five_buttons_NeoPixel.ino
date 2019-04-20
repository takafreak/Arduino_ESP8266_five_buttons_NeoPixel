#include <Adafruit_NeoPixel.h>

#define PIN_BUTTONS       A0  // Analog 0
#define PIN_BLUE          2   // On board blue LED
#define PIN_NEOPIXEL      15  // GPIO 15
#define COUNT_NEOPIXEL    1   // Number of NeoPixel RGB x 1

// Button
int buttonRead = 0;

// NeoPixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(COUNT_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void setup() { 
  // Serial
  Serial.begin(115200);

  // NeoPixel
  strip.begin();
  strip.setBrightness(32);
  strip.show();
}

void loop() {
  buttonRead = analogRead(PIN_BUTTONS);

  Serial.println(buttonRead);
  
  if (buttonRead >= 860) {
    // White
    strip.setPixelColor(0, 255, 255, 255);
    strip.show();
  } else if (buttonRead >= 710) {
    // Green
    strip.setPixelColor(0, 0, 255, 0);
    strip.show();
  } else if (buttonRead >= 590) {
    // Yellow
    strip.setPixelColor(0, 255, 255, 0);
    strip.show();
  } else if (buttonRead >= 520) {
    // Blue
    strip.setPixelColor(0, 0, 0, 255);
    strip.show();
  } else if (buttonRead >= 450) {
    // Red
    strip.setPixelColor(0, 255, 0, 0);
    strip.show();    
  } else {
    // None
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();    
  }


}
