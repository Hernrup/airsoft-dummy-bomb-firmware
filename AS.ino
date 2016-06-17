/*************************
INCLUDES
*************************/
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <EEPROMAnything.h>
#include <Keypad.h>
#include <string>
#include <SimpleTimer.h>
#include <RemoteReceiver.h>

/*************************
RF
*************************/
const unsigned long DETONATION_CODE = 371816;
const int PIN_RF = A2;

/**************************
KEYPAD
**************************/
const byte ROWS = 4;
const byte COLS = 3;
byte rowPins[ROWS] = {11, 6, 7, 9};
byte colPins[COLS] = {10, 12, 8};  
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

/**************************
LCD 
**************************/   
LiquidCrystal lcd(A4, A5, A3, 3, 4, 5);

/**************************
BEEP
**************************/
const int PIN_SPEAKER = A0;
const int PIN_ALARM = A1;

enum BEEP_TYPE
    {
    BEEP_CONFIRM,
    BEEP_DETONATION,
    BEEP_SINGLE,
    BEEP_SINGLE_LONG
    };
    
/**************************
PROGRAM STATES
**************************/     
enum STATE{
  MENU_ENTRY,
  MENU,
  MENU_TIMER,
  MENU_CONFIGCODE,
  MENU_ARMCODE,
  MENU_DISARMCODE,
  PRIMED,
  REMOTEARMED,
  ARMED,
  DISARMED,
  DETONATION,
  DETONATED
};

/**************************
STATE VARS
**************************/
unsigned long currentTime = 0;
unsigned long startupTime = 0;
int state = 0;
char codeInput[9] = "________";
int codeCount = 0;
char armCode[9] = "11111111";
char disarmCode[9] = "22222222";
char configCode[9] = "33333333";
char formatedTime[] = "00:00:00";
int seconds=0;
int minutes=0;
int hours=0;
int isRemoteDetonationAllowed = 1;
boolean useSiren = true;
boolean isMuted = false;
boolean updateDisplay = true;
boolean updateDisplaySecondary = true;
boolean flashState = true;
boolean beepState = false;
int isMenuAllowed = 0;
boolean punishWrongDisarmCode = true;
int nbrOfAtempts = 0;
int nbrOfDisarmAtemptsLimit = 3;
/**************************
CONFIG
**************************/
struct config_t
{
    long armCode; 
    long disarmCode;
    long configCode;
    int hours;
    int minutes;
    int seconds;
    int isRemoteDetonationAllowed;
    boolean useSiren;
    boolean isMuted;
} configuration;

/**************************
TIMERS (GLOBALS)
**************************/
SimpleTimer timer;
int displayTimer;
int countdownTimer;
int flashTimer;
int beepTimer;
int beepTimerFast;

/**************************
MAIN PROGRAM
**************************/
void setup(){
    //system
    Serial.begin(115200);
    log("Startup");
    
    //sound	 
    pinMode(PIN_SPEAKER, OUTPUT);
    pinMode(PIN_ALARM, OUTPUT);
    
    //LCD
    lcd.begin(20, 4);
    
    //config
    readConfig();
   
    //remote detonation
    RemoteReceiver::init(0, 3, remoteDetonation);
    
    //timers
    displayTimer = timer.setInterval(250, enableDisplayUpdate);
    timer.disable(displayTimer);
    countdownTimer = timer.setInterval(1000, countdown);
    timer.disable(countdownTimer);
    flashTimer = timer.setInterval(500, toggleFlashState);
    timer.disable(flashTimer);
    beepTimer = timer.setInterval(1000, beep);
    timer.disable(beepTimer);
    beepTimerFast = timer.setInterval(500, beep);
    timer.disable(beepTimerFast);
    
    //set init states
    startupTime = millis();
    setStatePrimed();
    displaySplashScreen();
    beep();
}	
void loop(){	 
  controller();
}

