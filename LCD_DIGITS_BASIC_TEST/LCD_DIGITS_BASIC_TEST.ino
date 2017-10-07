
const int LCD_COM []    = {10,12,12};
const int LCD_SEGMENTS []  = {14,9,8,7,6,5,4,3,2};
const int RATE = 2;

boolean segments[3][9] = {0};

int digits [] = {1,8,3,9}; // numbers to be displayed

void setup()  
{
  for (int i=0; i < 9; ++i) 
    pinMode(LCD_SEGMENTS[i], OUTPUT);
    Serial.begin(9600);
    setSegments();
}


void loop()
{
  refreshLCD();

}

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





