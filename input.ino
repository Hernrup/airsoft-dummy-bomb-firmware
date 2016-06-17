/*******************************
CODE
*******************************/
int checkInputForValue(char* wantedCode){
    if(checkInput(8)){
      if(strcmp(wantedCode,codeInput) == 0){
        resetCode();
        beepConfirm();
        return 1;
      }
      
      if(codeCount == 8){
        resetCode();
        newAtempt();
        beepError();
        return 0;
      }
    }
    return 0;
}

int checkInput(int length){
    char key;
    
    key = keypad.getKey(); 
  
    if(codeCount == length){
      enableDisplayUpdate();
      return 1;
    }
 
    if(key){    
        if(key == '#' && isMenuAllowed == 1) {
            resetCode();
            setStateMenuEntry();
            enableDisplayUpdate();
            beep();
            return 0;
        }
        if(key == '*' && isMenuAllowed == 1) {
            resetCode();
            setStatePrimed();
            enableDisplayUpdate();
            beep();
            return 0;
        }
       else if(codeCount < length) {
            codeCount++;
            codeInput[codeCount-1] = key;
            beep();
            enableDisplayUpdate();
            return 0;
       }else{
             return 0;
       }
    }
    return 0;
}
/*******************************
TIME
*******************************/
int VerifyInputForTime(){
    char key;
    int validation = 0;
    
    key = keypad.getKey(); 
  
    if(codeCount == 6){
      return 1;
    }
    
    if(key){    
        if(key == '#') {
            return 0;
        }
        if(key == '*') {
            return 0;
        }
       else{
         int nbr = atoi(&key);
          validation = setTimeChar(nbr);
          if(validation){
            codeCount++;
            codeInput[codeCount-1] = key;
            beep();
            enableDisplayUpdate();
            return 0;
          }
       }
    }
    return 0;
}

boolean setTimeChar(int nbr){ 
  int retval = 0;
  
  switch(codeCount){
    case 0:
      retval = nbr <= 2;
      if(retval){
        hours = nbr*10;
      }
      break;
    case 1:
      retval = nbr <= 4;
      if(retval){
        hours = hours + nbr;
      }
      break;
    case 2:
      retval = nbr <= 5;
      if(retval){
        minutes = nbr*10;
      }
      break;
    case 3:
      retval = nbr <= 9;
      if(retval){
        minutes = minutes + nbr;
      }
      break;
    case 4:
      retval = nbr <= 5;
      if(retval){
       seconds = nbr*10;
      }
      break;
    case 5:
      retval = nbr <= 9;
      if(retval){
        seconds = seconds + nbr;
      }
      break;
  }
  RefreshFormatedTime();
  
  return retval;
}
/*******************************
MENU
*******************************/
void getMenuSelection(){
    int menuPage;
    menuPage = keypad.getKey();  
    
    switch(menuPage) {
      case '1': //Timer
           resetTime();
           state = MENU_TIMER;
           enableDisplayUpdate();
           break;
      case '5': // toggle sound
           toggleSound();
          break;
      case '6': // toggle remote
           toggleRemote();
          break;
      case '4': // Edit admin code
         state = MENU_CONFIGCODE;
         enableDisplayUpdate();
          break;
      case '2': //Arm code
          state = MENU_ARMCODE;
          enableDisplayUpdate();
          break;
      case '3': //disarm code
          state = MENU_DISARMCODE;
          enableDisplayUpdate();
        break; 
      case '*': //disarm code
        state = PRIMED;
        enableDisplayUpdate();
        break;   
    }
}
/*******************************
RF DETONATION
*******************************/
void remoteDetonation(unsigned long receivedCode, unsigned int period){
  
  Serial.print("Code: ");
  Serial.print(receivedCode);
  Serial.print(", period duration: ");
  Serial.print(period);
  Serial.println("us.");
  
   if(isRemoteDetonationAllowed && receivedCode == DETONATION_CODE && (state == PRIMED || state == DISARMED)){
     setStateRemoteArmed();
   } 
}
