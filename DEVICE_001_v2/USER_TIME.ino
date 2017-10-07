
//_________________________________________________________________________
void UserTimeMode (){
    setTimeMode = true;
    //Serial.println("Setting User time");
    long startTime = millis();

    setSegmentsBlank(); //turn off digits
  
    while(setTimeMode){  
        refreshLCD();
        boolean hasSwitched = getButton();
              if (hasSwitched) setTimeMode = false;
            }
     userTimeChunk = (millis() - startTime) / 1000;

     if (userTimeChunk < 10) userTimeChunk = 10;  // MINIMUM
     if (userTimeChunk > 240) userTimeChunk = 240; // MAXIMUM

     setUserTime();
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

    if(userHour < 10){
    digits[0] = 0; //empty
    digits[1] = userHour;
  }else {
    digits[0] = userHour/10; 
    digits[1] = userHour%10;
  }
  
  if(userMinute < 10){
    digits[2] = 0; //add a leading zero
    digits[3] = userMinute;
  } else {
    digits[2] = userMinute/10; 
    digits[3] = userMinute%10;
  }
  setSegments();
  
  if(debug){
     Serial.print("Digits: ");
     Serial.print(digits[0]);
     Serial.print(digits[1]);
     Serial.print(":");
     Serial.print(digits[2]);
     Serial.println(digits[3]);
  }
}




