# LCD
Working code for direct driving LCD via Arduino


LCD_original.ino is from http://www.atmel.com/Images/doc8103.pdf. Coded in C to direct drive a bare LCD via IO pins on an ATmega48. 

LCD_compileIDE.ino has some edits to enable it to compile in the Arduino IDE. 
Assitance via Arduino forum: http://forum.arduino.cc/index.php?topic=495043.new#new


Device001_v1.ino is working code that LCD code will be intergrated with. 
It requires the DS1307RTC library: https://github.com/PaulStoffregen/DS1307RTC
