/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ianp/Documents/iot2021/labs/lab-19/src/lab-19.ino"
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "/home/ianp/Documents/iot2021/labs/lab-19/src/lab-19.ino"
SYSTEM_MODE(MANUAL);
//SYSTEM_THREAD(ENABLED);

WatchDog wd;
OledWingAdafruit display;

void setup()
{
  pinMode(D5, INPUT);

  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    display.println("Watchdog timer ran out!");
  }
  else
  {
    display.println("Reset normally");
  }
  display.display();

  wd.initialize(5000);
  wd.pet();
}

void loop()
{
  if (digitalRead(D5) == HIGH)
  {
    wd.pet();
    delay(100);
  }
}