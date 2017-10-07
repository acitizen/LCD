
//__________________________________________________________

void refreshLCD(){
 
 for (int j=0; j < 3; ++j){
      //------------------------------------------- FLOAT COMS
      floatComs();
      //------------------------------------------- SET SEGMENTS 
      // Segments to be ON are set to low 
      // Segments to be OFF are set to HIGH
      for (int i=0; i < 9; ++i) 
          digitalWrite(LCD_SEGMENTS[i], !segments[j][i]);  
    
      //------------------------------------------- COM HIGH
      pinMode(LCD_COM[j], OUTPUT);
      digitalWrite(LCD_COM[j], HIGH);
         
      delay(RATE); 
      //------------------------------------------- SET OPPOSITE SEGMENTS 
      // Segments to be ON are set to HIGH 
      // Segments to be OFF are set to LOW 
      for (int i=0; i < 9; ++i) 
          digitalWrite(LCD_SEGMENTS[i], segments[j][i]); 
           
      //------------------------------------------- COM LOW 
      pinMode(LCD_COM[j], OUTPUT);
      digitalWrite(LCD_COM[j], LOW);
      
      delay(RATE); 
  }
}

//_______________________________________________________ FLOAT COMS
// Set COM pins as input. 
// The network resistors will pull volatage to half.

void floatComs(){
  
  for (int j=0; j < 3; ++j){
      pinMode(LCD_COM[j], INPUT);
      digitalWrite(LCD_COM[j], LOW);
  }
}
//_________________________________________________________________________






