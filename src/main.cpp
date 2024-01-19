#include <Arduino.h>
#include "settings.h"
#include "drive.h"
#include "mouse.h"
#include "odometry.h"
#include "utils.h"

void setup()
{
  attachServos();

  Serial.begin(250000);

  while (!Serial)
  {
    ; // Wait for Serial to initialize
  }

  /*
  calculateDeltas();
  calculatePosition();

  debug();
  */

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  initializeMice();
}

void loop()
{
  while (digitalRead(BUTTON_PIN) == HIGH)
  {
    ; // Wait for button to be pressed
  }

  delay(1000);

  driveStraight(500);

  delay(1000);
}