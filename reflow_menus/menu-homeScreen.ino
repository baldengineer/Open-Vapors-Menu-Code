void displayHomeScreen() {
      printMenuLine("Current Status");
      printMenuLine("Reflow Profile");
      printMenuLine("Settings");
      printMenuLine("Bacon (Manual)");  //    printMenuLine("Manual Control");
  if (enterButtonStatus) {
    enterButtonStatus = false;
    rememberHomeMenuSelectLine = menuSelectLine;
    switch (menuSelectLine) {
      
      case 0: //current status
      menuState = MENU_STATE_STATS;
      break;

      // reflow profile
      case 1:
        menuState = MENU_STATE_REFLOWPROFILE;
        //menuSelectLine = rememberHomeMenuSelectLine;
        menuSelectLine = 0;
      break;

      case 2: // Settings
        menuState = MENU_SETTING_LIST;
      break;
      
      case 3: // Manual Control (Bacon)
        menuState = MENU_STATE_MANUAL;
      break;
    }  
  }
}
