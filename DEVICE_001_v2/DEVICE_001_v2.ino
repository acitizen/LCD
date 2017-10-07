#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h> 
//_____________________________________________ ARDUINO PINS
const int BUTTON = 16;
const int DIP_SWITCH = 15;
const int LCD_COM [] = {11,12,10};
const int LCD_SEGMENTS []  = {14,9,8,7,6,5,4,3,2};
// RTC is connected to SDA(A4) and SCL(A5)
//_____________________________________________ CONST VARIABLES
const long INTERVAL = 1000;
const int RATE = 2;
const long debounceDelay = 50; 
//_____________________________________________ OTHER VARIABLES
int digits [] = {0};
boolean segments[3][9] = {0};
long previousMillis = 0;
long userMinute = 0;
long userHour = 0;
long previousDebounceTime = 0; 

float userTimeChunk = 60;
int buttonState = HIGH;
int previousButtonState = HIGH;
boolean setTimeMode = false;
boolean debug = false;


void setup()  {
//________________________________________________ SETUP RTC
  setSyncProvider(RTC.get);  // Real time clock
   
  if(debug){
    Serial.begin(9600);
      if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
     else
     Serial.println("RTC has set the system time"); 
  }
//________________________________________________  PINMODES

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(DIP_SWITCH, INPUT_PULLUP); 
  for (int i=0; i < 9; ++i) pinMode(LCD_SEGMENTS[i], OUTPUT);
}

//__________________________________________________ MAIN LOOP
void loop()
{
    refreshLCD();
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= INTERVAL) {
       previousMillis = currentMillis;
       setUserTime();
    }
      boolean hasSwitched = getButton();
      if (hasSwitched) UserTimeMode();
}

//__________________________________________________ READ BUTTON

boolean getButton() {
 int reading = digitalRead(BUTTON);
 boolean hasSwitched = false;
   
     if (reading != previousButtonState) {
        previousDebounceTime = millis();
     }
          if ((millis() - previousDebounceTime) > debounceDelay) {
              if (reading != buttonState) {
                  buttonState = reading;
                  if (reading == 0) {
                     hasSwitched = true;
                    if(debug) Serial.println("Switched"); 
                   }
               }
          }
      
      previousButtonState = reading;
      
  if(debug){
    Serial.print("Button State: ");
    Serial.println(buttonState); 
  }
  return(hasSwitched);
}

//_________________________________________________________________________

