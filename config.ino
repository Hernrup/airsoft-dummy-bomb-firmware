/*******************
CONFIG
*******************/
void readConfig() {
 
  EEPROM_readAnything(0, configuration);
 
  ltoa(configuration.armCode, armCode, 10);
  ltoa(configuration.disarmCode,disarmCode,10);
  ltoa(configuration.configCode,configCode,10);
  hours = configuration.hours;
  minutes = configuration.minutes;
  seconds = configuration.seconds;
  isRemoteDetonationAllowed = configuration.isRemoteDetonationAllowed;
  //useSiren = configuration.useSiren;
  isMuted = configuration.isMuted;
}
void saveConfig() {
  
  configuration.armCode = atol(armCode);
  configuration.disarmCode = atol(disarmCode);
  configuration.configCode = atol(configCode);
  configuration.hours = hours;
  configuration.minutes = minutes;
  configuration.seconds = seconds;
  configuration.isRemoteDetonationAllowed = isRemoteDetonationAllowed;
  //configuration.useSiren = useSiren;
  configuration.isMuted = isMuted;
  
  EEPROM_writeAnything(0, configuration);
  
}
