// Code to be intergrated with LCD code

#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t


const int BUTTON_LED = 17;
const int BUTTON = 16;
const int DIP_SWITCH = 15;
//const int CLOCK_LED = 14;
const int LCD [] = { 2,3,4,5,6,7,8,9,10,11,12,13};

unsigned long previousMillis = 0;
const long interval = 1000;

int DIGITS [] ={ 0,0,0,0 };
float userTimeChunk = 70;
long userMinute = 0;
long userHour = 0;

int buttonState = HIGH;
int previousButtonState = HIGH;
long previousDebounceTime = 0; 
long debounceDelay = 50;  
 
boolean setTimeMode = false;

void setup()  {
  Serial.begin(9600);
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time"); 
   
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUTTON_LED, OUTPUT);
  pinMode(DIP_SWITCH, INPUT_PULLUP);
  //pinMode(CLOCK_LED, OUTPUT);
  for (int i=0; i < 12; i++) pinMode(LCD[i], OUTPUT);
    
}

//_________________________________________________________________________

void loop()
{
    digitalWrite(BUTTON_LED, LOW); 
    // digitalWrite(CLOCK_LED, HIGH);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    setUserTime();
    displayTime();
    }
    
    getButton();
    if (buttonState == LOW) setTimeMode = true;   
    delay(10);
    // if (setTimeMode) UserTimeMode();
}

//_________________________________________________________________________

void UserTimeMode (){
  
    Serial.println("Setting User time");
    unsigned long startTime = millis();
    
    while(setTimeMode){ 
        digitalWrite(BUTTON_LED, LOW); 
        //turn off clock light
        getButton();
        if (buttonState == LOW) setTimeMode = false; 
    }
     unsigned long endTime = millis();
     userTimeChunk = (endTime - startTime) / 1000;
     
}

//_________________________________________________________________________
 
void displayTime(){
  

  if(userHour < 10){
    DIGITS[0] = 0; //empty
    DIGITS[1] = userHour;
  }else {
    DIGITS[0] = userHour/10; 
    DIGITS[1] = userHour%10;
  }
  
  if(userMinute < 10){
    DIGITS[2] = 0; //add a leading zero
    DIGITS[3] = userMinute;
  } else {
    DIGITS[2] = userMinute/10; 
    DIGITS[3] = userMinute%10;
  }
  
  Serial.print(DIGITS[0]);
  Serial.print(DIGITS[1]);
  Serial.print( ":" ); 
  Serial.print( DIGITS[2]);
  Serial.println(DIGITS[3]);
}

//_________________________________________________________________________

void getButton() {
  int reading = digitalRead(BUTTON);
   
     if (reading != previousButtonState) {
        previousDebounceTime = millis();
          if ((millis() - previousDebounceTime) > debounceDelay) {
              if (reading != buttonState) {
                buttonState = reading;
               }
          }
      }
      previousButtonState = reading;
}

//_________________________________________________________________________

void setUserTime (){

long s = 0;
long h = hour();
long m = minute();
s = ((h*60) +  m) * 60; 
float userTimeSecs = s * (userTimeChunk/60); // user time in seconds
userMinute = ((long)userTimeSecs/ 60) % 60;
userHour = ((long)userTimeSecs / (60 * 60)) % 24;
}




