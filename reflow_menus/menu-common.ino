void processMenu() {
    switch (menuState) {
      case MENU_STATE_HOME:
        displayHomeScreen();
      break;

      case MENU_STATE_MANUAL:
        displayManualList();
      break; 

      case MENU_STATE_REFLOWPROFILE:
        displayReflowProfile();
      break;

      case  MENU_STATE_EDIT_REFLOW:
       // Called from MENU_STATE_REFLOWPROFILE
        editReflowProfile();
      break;

      case MENU_STATE_STATS: 
       displayStatus();
      break;

      case MENU_STATE_EDIT_NUMBER:
        editNumber();
      break;

      case MENU_STATE_EDIT_NUMBER_DONE:
        doneEditingReflowNumbers();
      break;

      case MENU_SETTING_LIST:
        displaySettingslist();
      break;

      case MENU_SETTINGS_DEFAULT_DONE: 
        restoreDefaultsDone();
      break;

      case MENU_SETTING_VERIFY_DEFAULT:
        displaySettingsVerifyDefault();
      break;
    }
  }

void printMenuLine(char *c) {
  int lineWidth = LCD_WIDTH-1;
  lcd.setCursor(0,menuPrintLine);
  if (menuPrintLine == menuSelectLine) {
    lcd.print((char)ARROW);
    lineWidth = lineWidth - 1; 
    } else {
      lcd.print(" ");
      lineWidth = lineWidth - 1; 
    }
    lcd.print(c);
    for (int x=0; x < (lineWidth-strlen(c)); x++) {
      lcd.print(" ");
    }
    menuPrintLine++;
    if (menuPrintLine > 3) menuPrintLine = 0;
}

void processButtons() {
  for (int x=0; x<5; x++) 
    buttonStates[x] = digitalRead(buttonPins[x]);
      
  if (buttonStates[ENTER] == LOW)
    enterButtonStatus = true;

  if (buttonStates[LEFT] == LOW)
    menuButtonStatus = true;

  if (menuState != MENU_STATE_EDIT_NUMBER) {
    if (buttonStates[DOWN] == LOW)
      if (menuSelectLine < 3)
        menuSelectLine++;
      else
        flashLCDWarning();


    if (buttonStates[UP] == LOW) {
      if (menuSelectLine > 0) {
        menuSelectLine--;
      }      
      else {
        flashLCDWarning();
      }
    }
  }
}


void flashLCDWarning() {
  setLCDColor(255,255,0);
  delay(250);
  setLCDColor(0,255,0); 
}