void printCodeLine(char* msg, char* code,int lcdRow){
  lcd.setCursor(0,lcdRow);
  char line[20];
  sprintf(line,"%-11s %-8s",msg,code);
  lcd.print(line);
}
void printHeaderLine(char* msg,int lcdRow){
  lcd.setCursor(0,lcdRow);
  char line[20];
  sprintf(line,"%-11s %-8s",msg,formatedTime);
  lcd.print(line);
}
void printEmptyLine(int lcdRow){
  lcd.setCursor(0,lcdRow);
  char line[20];
  sprintf(line,"%-20s","");
  lcd.print(line);
}
void printLine(char* msg, int lcdRow){
  lcd.setCursor(0,lcdRow);
  char line[20];
  sprintf(line,"%-20s",msg);
  lcd.print(line);
}

void printTimeCodeLine(char* msg, int lcdRow){
  lcd.setCursor(0,lcdRow);
  char line[20];
  sprintf(line,"%-11s %-8s",msg,formatedTime);
  lcd.print(line);
}
void clearLCD(){
  lcd.clear();
}
