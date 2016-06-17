void log(char* msg){
  char line[34];
  sprintf(line,"Log: %-30s",msg);
  Serial.println(line);
}

void logInt(int msg){
  char line[34];
  sprintf(line,"Log: %-30d",msg);
  Serial.println(line);
}

void RefreshFormatedTime(){    
    sprintf(formatedTime,"%02d:%02d:%02d",hours,minutes,seconds);
    enableDisplayUpdate();
}

void countdown(){ 
  if (seconds > 0) {
      seconds--;
  }
  if (minutes > 0) {
      if (seconds <= 0) {
          minutes--;
          seconds = 60;
      }
  }
  if (hours > 0) {
      if (minutes <= 0) {
          hours--;
          minutes = 60;
      }
  }
  if (seconds == 0 && minutes == 0 && hours == 0) {
    setStateDetonation();
  }
  
  RefreshFormatedTime();
  enableDisplayUpdate();
}

void resetCode(){
  codeCount = 0;
  strcpy(codeInput,"________"); 
  enableDisplayUpdate();
}

void resetTime(){
  hours = 0;
  minutes = 0;
  seconds = 0; 
  RefreshFormatedTime();
  enableDisplayUpdate();
}


