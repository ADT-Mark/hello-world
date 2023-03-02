//Include the library for LCD with I2C 
#include <LiquidCrystal_I2C.h> // Having issues with accessing the library

//Create an object of the LCDI2C with overloaded constructor.
LiquidCrystal_I2C lcd(0x3F, 16,2) //LCD_I2C(I2C address,# of col., # of rows)


void setup() {
  lcd.init(); 

  // Make sure backlight is on
  lcd.backlight();

  // Clear the Screen
  lcd.clear();

  // Initial Start Message
  lcd.print("Game Start");
}

void loop() {
  // Any output print message will be
  // lcd.print("message");
}
