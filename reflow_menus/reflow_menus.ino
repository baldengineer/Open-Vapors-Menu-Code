#include "Arduino.h"
#include "Wire.h"
#include <EEPROM.h>
//#include <LiquidCrystal.h>
#include <LiquidTWI.h>
#include "ReflowMenu.h"

LiquidTWI lcd(0);
const byte LCD_WIDTH = 20;
const byte LCD_HEIGHT = 4;
char messageBuffer[21];

byte buttonStates[5];  // updated in processButtons()

numberEditor numberEditorState = {0,0,0,0,0,0};

temperatureSettings currentReflowSettings[4];
boolean menuButtonStatus = false;
boolean enterButtonStatus = false;

menuState_t menuState;
byte menuStatus = 0;
byte menuSelectLine = 0;
byte rememberHomeMenuSelectLine = 0;

byte menuPrintLine = 0;
byte reflowEditIndex = 0;

// used by Status (may be removed later?)
int currentTemperature=0;
int targetTemperature=150;

void setup() {
  #ifdef USE_SERIAL
    Serial.begin(9600);
  #endif // USE_SERIAL
  lcd.begin(LCD_WIDTH,LCD_HEIGHT);
  setLCDColor(0,255,0);
  menuState = MENU_STATE_HOME;

  for (int x=0; x<5; x++)
  pinMode(buttonPins[x], INPUT_PULLUP);

  readReflowProfile();
 // initReflowSettings();
}

void loop() {
  #ifdef USE_SERIAL
    processSerial();
  #endif // USE_SERIAL

  currentMillis = millis();
  if ((unsigned long)(currentMillis - buttonPreviousMillis) >= buttonBounceInterval) {
    processButtons();
    buttonPreviousMillis = currentMillis;
  }
  
  processMenu();
}


void setLCDColor(byte R, byte G, byte B) {
  analogWrite(lcdRGB[0], (255-R));
  analogWrite(lcdRGB[1], (255-G));
  analogWrite(lcdRGB[2], (255-B));
}



#ifdef USE_SERIAL
void processSerial() {
  if (Serial.available() <1) return;

  char incomingChar = Serial.read();
  switch (incomingChar) {
    case 'I': // Enter
    case 'i':
    enterButtonStatus = true;
    break;

    case 'M':  // Menu
    case 'm':
    menuButtonStatus = true;
    break;

    case 'J':  // Move Up
    case 'j':
    if (menuSelectLine > 0) {
      menuSelectLine--;
      } else {
        flashLCDWarning();
      }
      break;

    case 'K': // move Down
    case 'k':
    if (menuSelectLine < 3) {
      menuSelectLine++;
      } else {
        flashLCDWarning();
      }
      break;
    }
  }
  #endif USE_SERIAL








