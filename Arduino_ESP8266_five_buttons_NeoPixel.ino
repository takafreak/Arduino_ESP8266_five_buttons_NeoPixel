#include <Adafruit_NeoPixel.h>

#define PIN_BUTTONS       A0  // Analog 0
#define PIN_BLUE          2   // On board blue LED
#define PIN_NEOPIXEL      15  // GPIO 15
#define COUNT_NEOPIXEL    1   // Number of NeoPixel RGB x 1

// Button
int buttonRead = 0;

// NeoPixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(COUNT_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

//#####################################
//# Main SETUP
//#####################################
void setup() { 
  // Serial
  Serial.begin(115200);

  // NeoPixel
  strip.begin();
  strip.setBrightness(32);
  strip.show();
}

//#####################################
//# Main LOOP
//#####################################
void loop() {
  buttonRead = analogRead(PIN_BUTTONS);

  Serial.println(buttonRead);
  
  if (buttonRead >= 860) {
    // White
    pushWhite();
  } else if (buttonRead >= 710) {
    // Green
    pushGreen();
  } else if (buttonRead >= 590) {
    // Yellow
    pushYellow();
  } else if (buttonRead >= 520) {
    // Blue
    pushBlue();
  } else if (buttonRead >= 450) {
    // Red
    pushRed();
  } else {
    // None
    showNeoPixel(0,0,0,0);
  }
}

//#####################################
//# Show NeoPixel LED
//#####################################
void showNeoPixel(int num,int r,int g,int b) {
  strip.setPixelColor(num,r,g,b);
  strip.show();
}

//#####################################
//# Function for RED button
//#####################################
void pushRed() {
  showNeoPixel(0,255,0,0);
}

//#####################################
//# Function for BLUE button
//#####################################
void pushBlue() {
  showNeoPixel(0,0,0,255);
}

//#####################################
//# Function for YELLOW button
//#####################################
void pushYellow() {
  showNeoPixel(0,255,255,0);
}

//#####################################
//# Function for GREEN button
//#####################################
void pushGreen() {
  showNeoPixel(0,0,255,0);
}

//#####################################
//# Function for WHITE button
//#####################################
void pushWhite() {
  showNeoPixel(0,255,255,255);  
}
