void setStatePrimed(){
  state = PRIMED;
  resetCode();
  RefreshFormatedTime();
  enableDisplayUpdate();
}
void setStateMenu(){
  state = MENU;
  enableDisplayUpdate();
}
void setStateMenuEntry(){
  state = MENU_ENTRY;
  enableDisplayUpdate();
}
void setStateDetonation(){
  resetCode();
  state = DETONATION;
  beepDetonation();
  timer.disable(countdownTimer);
  timer.disable(flashTimer);
  timer.disable(beepTimer);
  timer.disable(beepTimerFast);
  timer.setTimeout(5000, setStateDetonated);
  enableSiren();
  enableDisplayUpdate();
}
void setStateDetonated(){
  state = DETONATED;
  disableSiren();
  enableDisplayUpdate();
}
void setStateDisarmed(){
  state = DISARMED;
  timer.disable(countdownTimer);
  timer.disable(flashTimer);
  timer.disable(beepTimer);
  timer.disable(beepTimerFast);
  beepDisarm();
  enableDisplayUpdate();
}
void setStateArmed(){
  state = ARMED;
  timer.enable(countdownTimer);
  beepArm();
  setFlashState(true);
  enableDisplayUpdate();
}
void setStateRemoteArmed(){
  state = REMOTEARMED;
  enableDisplayUpdate();
}
void toggleFlashState(){
  flashState = !flashState;
  enableDisplayUpdate();
}
void setFlashState(boolean state){
  flashState = state;
  enableDisplayUpdate();
}
void toggleBeepState(){
  beepState = !beepState;
  enableDisplayUpdate();
}
void enableDisplayUpdate(){
  updateDisplay = true;
  updateDisplaySecondary = true;
}
void disableDisplayUpdate(){
  updateDisplay = false;
  updateDisplaySecondary = false;
}
void verifyDisableDisplayUpdate(){
  updateDisplay = (updateDisplaySecondary && updateDisplay);
  updateDisplaySecondary = false;
}
void toggleSound(){
  isMuted = !isMuted;
  beep();
  enableDisplayUpdate();
}
void toggleSiren(){
  useSiren = !useSiren;
  beep();
  enableDisplayUpdate();
}
void toggleRemote(){
  isRemoteDetonationAllowed = !isRemoteDetonationAllowed;
  beep();
  enableDisplayUpdate();
}
void enableSiren(){
  if(useSiren){
    digitalWrite(PIN_ALARM,HIGH);
  }
}
void disableSiren(){
  digitalWrite(PIN_ALARM,LOW);
}
void newAtempt(){
  nbrOfAtempts = nbrOfAtempts +1;
}

