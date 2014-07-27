void displayManualList() {
	printMenuLine("Bacon");
	printMenuLine("Bacon");
	printMenuLine("Bacon");
	printMenuLine("Bacon");
	
	if (menuButtonStatus) {
		menuButtonStatus = false;
		menuState = MENU_STATE_HOME;
	}

	if (enterButtonStatus) {
		enterButtonStatus = false;
		menuState = MENU_STATE_HOME;
	}
}
