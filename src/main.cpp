// *****************************************************
//  SD-poswerOff
//                           2024-06-04  by NoRi
// *****************************************************
#include <Arduino.h>
#include <SD.h>
#include <M5Unified.h>
#include <ESP32-targz.h>
#include <M5StackUpdater.h>
#define TFCARD_CS_PIN 4

#define APP_NAME "Power OFF"   // app Name
#define APP_BIN  "/00_powerOff.bin" // app bin file-name
#define TIMEOUT00 10000       // lobby countdouwn timeout : msec
#define TIMEOUT01 20000       // lobby countdouwn timeout : msec
void setupSDUpdater();
void POWER_OFF();

void setup(void)
{
  auto cfg = M5.config();
  M5.begin(cfg);
  setupSDUpdater();

  POWER_OFF();
  Serial.println("setup done");
}

void loop(void)
{
  delay(1);
}

void POWER_OFF()
{
  Serial.println(" *** POWER OFF ***");
  SD.end();
  delay(1000);
  M5.Power.powerOff();
  delay(1000);
}

void setupSDUpdater()
{
  SDUCfg.setLabelMenu("< Menu"); // load menu.bin
  SDUCfg.setLabelSkip("Skip");   // skip the lobby countdown and run the app
  SDUCfg.setAppName(APP_NAME);   // lobby screen label: application name
  checkSDUpdater(
      SD,           // filesystem (default=SD)
      MENU_BIN,     // path to binary (default=/menu.bin, empty string=rollback only)
      TIMEOUT01,    // wait delay, (default=0, will be forced to 2000 upon ESP.restart() )
      TFCARD_CS_PIN // usually default=4 but your mileage may vary
  );
}

