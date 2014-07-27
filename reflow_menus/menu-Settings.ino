void displaySettingslist() {
	menuSelectLine = 0;
	printMenuLine("Restore Defaults");
	printMenuLine("");
	printMenuLine("");
	printMenuLine("");

	if (enterButtonStatus) {
    	enterButtonStatus = false;
    	menuState = MENU_SETTING_VERIFY_DEFAULT;
    }

    if (menuButtonStatus) {
    	menuButtonStatus = false;
    	menuSelectLine = rememberHomeMenuSelectLine;
		menuState = MENU_STATE_HOME;   
    	return;
    }
}

void displaySettingsVerifyDefault() {
	printMenuLine("Are you sure?");
	printMenuLine("No");
	printMenuLine("Yes");
	printMenuLine("");

	if (enterButtonStatus) {
		enterButtonStatus = false;
		switch (menuSelectLine) {
			case 1:
				menuState = MENU_SETTING_LIST;
			break;

			case 2:
		    	menuState = MENU_SETTINGS_DEFAULT_DONE;
		    	restoreDefaults();
		    break;
		}
	}
}
void restoreDefaultsDone() {
	// MENU_SETTINGS_DEFAULT_DONE
	printMenuLine("Done");
	printMenuLine("Press Enter");
	printMenuLine("");
	printMenuLine("");

	if (enterButtonStatus) {
		enterButtonStatus = false;
		menuSelectLine = rememberHomeMenuSelectLine;
		menuState = MENU_SETTING_LIST;
	}
}