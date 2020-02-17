#define DCSBIOS_IRQ_SERIAL
#include <DcsBios.h>

// http://www.martyncurrey.com/arduino-with-hd44780-based-lcds/

#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" // Added library*
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the default I2C bus address of the backpack-see article

void onUfcScratchpadString1DisplayChange(char* newValue) {
  lcd.setCursor(4,0);
  lcd.print(newValue);
}
DcsBios::StringBuffer<2> ufcScratchpadString1DisplayBuffer(0x744e, onUfcScratchpadString1DisplayChange);

void onUfcScratchpadString2DisplayChange(char* newValue) {
  lcd.setCursor(6,0);
  lcd.print(newValue);
}
DcsBios::StringBuffer<2> ufcScratchpadString2DisplayBuffer(0x7450, onUfcScratchpadString2DisplayChange);

void onUfcScratchpadNumberDisplayChange(char* newValue) {
  lcd.setCursor(7,0);
  lcd.print(newValue);
}
DcsBios::StringBuffer<8> ufcScratchpadNumberDisplayBuffer(0x7446, onUfcScratchpadNumberDisplayChange);

void onUfcComm1DisplayChange(char* newValue) {
  lcd.setCursor(1,3);
  lcd.print(newValue);
}
DcsBios::StringBuffer<2> ufcComm1DisplayBuffer(0x7424, onUfcComm1DisplayChange);

void onUfcComm2DisplayChange(char* newValue) {
  lcd.setCursor(17,3);
  lcd.print(newValue);
}
DcsBios::StringBuffer<2> ufcComm2DisplayBuffer(0x7426, onUfcComm2DisplayChange);

void setup()
{
   // Set off LCD module
   lcd.begin (20,4); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);   

   DcsBios::setup();
}
void loop()
{
  DcsBios::loop();
}
