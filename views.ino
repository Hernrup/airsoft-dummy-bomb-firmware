
void displaySplashScreen(){
  if (!updateDisplay){return;}
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("--------------------");
  lcd.setCursor(0,3);
  lcd.print("(C) Mikael Hernrup");
  
  lcd.setCursor(0,0);
  lcd.print("SYSTEM BOOT  ");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("SYSTEM BOOT     [OK]");
}

void displayPrimed(){
  if (!updateDisplay){return;}
  printHeaderLine("PRIMED",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("ARM",codeInput,3);
}

void displayArmed(){
  if (!updateDisplay){return;}
  if (flashState){
    printHeaderLine("ARMED",0);
  }else{
    printEmptyLine(0);
  }
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("DISARM",codeInput,3);
}

void displayDisarmed(){
  if (!updateDisplay){return;}
  printHeaderLine("DISARMED",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("RE-ARM",codeInput,3);
}

void displayDetonation(){
  if (!updateDisplay){return;}
  printEmptyLine(0);
  lcd.setCursor(0,1);
  lcd.print("   HAVE A NICE DAY   ");
  printEmptyLine(2);
  printEmptyLine(3);
}

void displayDetonated(){
  if (!updateDisplay){return;}
  printHeaderLine("DETONATED",0);
  lcd.setCursor(0,1);
  lcd.print("   YOU ARE DEAD!   ");
  printEmptyLine(2);
  printCodeLine("RESET",codeInput,3);
}

void displayMenuEntry(){
  if (!updateDisplay){return;}
  printLine("MENU",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("CONFIG CODE",codeInput,3);
}

void displayMenu(){
 if (!updateDisplay){return;}
 
 printLine("1.Timer     2.Arm   ",0);
 printLine("3.Disarm    4.Config",1);
 
 if(isMuted){
     printLine("5.Sound        [OFF]",2);
 }else{
     printLine("5.Sound        [ON ]",2);
 }
 if(isRemoteDetonationAllowed){
     printLine("6.Remote       [ON ]",3);
 }else{
     printLine("6.Remote       [OFF]",3);
 }

}

void displayMenuConfig(){
  if (!updateDisplay){return;}
  printLine("Config code",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("New Code",codeInput,3);
}

void displayMenuArm(){
  if (!updateDisplay){return;}
  printLine("Arm code",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("New Code",codeInput,3);
}

void displayMenuDisarm(){
  if (!updateDisplay){return;}
  printLine("Disarm code",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printCodeLine("New Code",codeInput,3);
}

void displayMenuTimer(){
  if (!updateDisplay){return;}
  printLine("Timer",0);
  printEmptyLine(1);
  printEmptyLine(2);
  printTimeCodeLine("Time",3);
}



