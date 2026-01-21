
// base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code
// enable or disable GxEPD2_GFX base class
#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_3C.h>
#include "display.h"

void helloWorld();
void helloFullScreenPartialMode();
void showPartialUpdate();
void showHiGrace();

void setup() {
  Serial.begin(115200);
  displayInit();
}

void loop() {
  // put your main code here, to run repeatedly:
}