#include "Arduino.h"
#include "Wire.h"
//#include <LiquidCrystal.h>
#include <LiquidTWI.h>

#define UP 0
#define RIGHT 4
#define DOWN 2
#define LEFT 3
#define ENTER 1
#define buttonBounceInterval 200
#define ACTIVE LOW
#define NOT_ACTIVE HIGH

#define DEGREE 0xdf
#define ARROW 0x7e

#define EEPROM_VER 0x01
//#define USE_SERIAL

const byte preheat = 0;
const byte soak = 1;
const byte reflow = 2;
const byte cool = 3;

// LCD backlight pins
const byte lcdRGB[] = {11,10,9};

// Pins used by front panel 
const byte buttonPins[] = {A5,A1,A4,A2,A3};

unsigned long currentMillis;
unsigned long buttonPreviousMillis;

typedef enum MENU_STATE {
  MENU_STATE_HOME,
  MENU_STATE_STATS,
  MENU_STATE_REFLOWPROFILE,
  MENU_STATE_EDIT_REFLOW,
  MENU_STATE_SETTINGS,
  MENU_STATE_MANUAL,
  MENU_STATE_EDIT_NUMBER,
  MENU_STATE_EDIT_NUMBER_DONE,
  MENU_SETTING_LIST,
  MENU_SETTINGS_DEFAULT_DONE,
  MENU_SETTING_VERIFY_DEFAULT
}
menuState_t;

struct temperatureSettings {
  byte tempMin;
  int tempMax;
  byte timeMin;
  int timeMax;
};

// variable used when editing a number value
struct numberEditor {
  unsigned int min;
  unsigned int max;
  unsigned int current;
  byte leftpos;
  byte length;
  byte currentpos;
};

// hold overs from control code
const char* lcdMessagesMenuStates[] = {
  "Status",
  "Reflow",
  "Settings",
  "Manual",
};

const char* tempStateNames[] = {
  "Preheat",
  "Soak",
  "Reflow",
  "Cool",
};

//byte reflowStageTemps[4];
//byte reflowStageTimes[4];
// hold overs from control code