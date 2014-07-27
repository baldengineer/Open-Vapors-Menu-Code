void displayStatus() {
  menuSelectLine = -1;

  currentTemperature=random(25,260);
  printMenuLine("Ready...");
  sprintf(messageBuffer, "Temp: %d%cC", currentTemperature, DEGREE);
  printMenuLine(messageBuffer);
  sprintf(messageBuffer, "Target: %d%cC", targetTemperature, DEGREE);
  printMenuLine(messageBuffer);
  sprintf(messageBuffer,"Time: %ds", (millis()/1000));
  printMenuLine(messageBuffer);
  if (menuButtonStatus) {
    menuButtonStatus = false;
    menuSelectLine = rememberHomeMenuSelectLine;
    menuState = MENU_STATE_HOME;

  }
  if (enterButtonStatus) {
    enterButtonStatus = false;
    flashLCDWarning();
  }
}