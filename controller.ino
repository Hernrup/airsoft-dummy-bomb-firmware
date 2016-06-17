void controller(){
  isMenuAllowed = 0;
  currentTime = millis();
  timer.run();
  
  switch (state) {
  
  case PRIMED:
    isMenuAllowed = 1;
    if(checkInputForValue(armCode)){
      setStateArmed();
    }
    displayPrimed();
    break;
  
  case REMOTEARMED:
    hours = 0;
    minutes = 0;
    if(seconds > 10){
      seconds = 10;
    }
    setStateArmed();
    break;
  
  case ARMED:
    if(checkInputForValue(disarmCode)){
      setStateDisarmed();
    }
    if (hours == 0 && minutes == 0 && seconds < 11){
      timer.disable(beepTimer);
      timer.enable(beepTimerFast);
      timer.enable(flashTimer);
    }else if(hours == 0 && minutes == 0 && seconds < 60 && seconds > 10){
      timer.enable(flashTimer);
      timer.enable(beepTimer);
    }else{
      flashState = true;
    }
    displayArmed();
    break;
  
  case DETONATION:
    displayDetonation();
    beepDetonation();
    break;
  
  case DETONATED:
    if(checkInputForValue(configCode)){
      setStatePrimed();
    }
    displayDetonated();
    break;
  
  case DISARMED:
    isMenuAllowed = 1;
    if(checkInputForValue(armCode)){
      setStateArmed();
    }
    displayDisarmed();
    break;
    
  /*************************
  MENU ITEMS
  *************************/
  case MENU_ENTRY:
    isMenuAllowed = 1;
    if(checkInputForValue(configCode)){
      state = MENU;
      enableDisplayUpdate();
    }
    displayMenuEntry();
    break;
  
  case MENU:
    getMenuSelection();
    displayMenu();
    saveConfig();
    break;
  
  case MENU_TIMER:
    if(VerifyInputForTime()){
      setStateMenu();
      resetCode();
      beepConfirm();
    }
    displayMenuTimer();
    break;
  
  case MENU_CONFIGCODE:
    displayMenuConfig();
    if(checkInput(8)){
      strcpy(configCode,codeInput);
      resetCode();
      setStateMenu();
      beepConfirm();
    }
    break;
  case MENU_ARMCODE:
    displayMenuArm();
    if(checkInput(8)){
      strcpy(armCode,codeInput);
      resetCode();
      setStateMenu();
      beepConfirm();
    }
    break;
  case MENU_DISARMCODE:
    displayMenuDisarm();
    if(checkInput(8)){
      strcpy(disarmCode,codeInput);
      resetCode();
      setStateMenu();
      beepConfirm();
    }
    break;
  }
  
  verifyDisableDisplayUpdate();
}
