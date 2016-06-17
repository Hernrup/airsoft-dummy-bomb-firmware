/****************************************
BEEPS
****************************************/
void beep(){
  if(isMuted){return;}
  beepProcess(PIN_SPEAKER,'D',20);
}
void beepLow(){
  if(isMuted){return;}
  beepProcess(PIN_SPEAKER,'C',50);
}
void beepTimesTree(){
  if(isMuted){return;}
  timer.setTimer(50,beep,3);
}
void beepConfirm(){
  timer.setTimeout(100,beepTimesTree);
}
void beepLong(){
  if(isMuted){return;}
  beepProcess(PIN_SPEAKER,'D',200);
}
void beepDetonation(){
  if(isMuted){return;}
  if(!useSiren){
    beepProcess(PIN_SPEAKER,'C',50);
  }
}
void beepError(){
  if(isMuted){return;}
  timer.setTimeout(50,beepLow);
}
void beepArm(){
  if(isMuted){return;}
  //beepProcess(PIN_SPEAKER,'D',100);
} 
void beepDisarm(){
  if(isMuted){return;}
  //beepProcess(PIN_SPEAKER,'D',100);
} 
 	 
void beepProcess (unsigned char speakerPin, char toneVal, long timeInMilliseconds)     // the sound producing function
{	 
  int x;
  int toneFreq = getToneFreq(toneVal);
  long delayAmount = (long)(1000000/toneFreq);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++)	 
  {	 
      digitalWrite(speakerPin,HIGH);
      delayMicroseconds(delayAmount);
      digitalWrite(speakerPin,LOW);
      delayMicroseconds(delayAmount);
  }	 
}	 
 	 
int getToneFreq (char c)
{	 
    switch(c){
      case 'C':
        return 2093;
        break;
       case 'D':
        return 2349;
        break;
       case 'E':
        return 2637;
        break;
       case 'F':
        return 2793;
        break;
       case 'G':
        return 3136;
        break;
       case 'A':
        return 3520;
        break;
       case 'B':
        return 3951;
        break;
    }
}	 
