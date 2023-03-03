//Bop-It Project
//Rough Test Code

/***********************************************
General Comments
*******
"Meara's SLides" on the M11: Lecture Module on Canvas was incredibly helpful. Used that to make pin assignments.
    https://canvas.pitt.edu/courses/188460/pages/m11-lecture?module_item_id=3661982
*******
for analog input:
    https://startingelectronics.org/beginners/arduino-tutorial-for-beginners/read-an-analog-input-with-arduino/#:~:text=Open%20the%20serial%20monitor%20window%20in%20the%20Arduino%20IDE%20to,values%20between%200%20and%201023.
pinMode reference:
    https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
tilt switch data sheet:
    https://www.digikey.com/en/products/detail/e-switch/TM1000Q/2541277
what I think we should order for joystick:
    https://www.adafruit.com/product/3246
      or
    https://www.adafruit.com/product/512
    
*****************************************/
//vvvvv CODE vvvvv

//Include the library for LCD with I2C 
#include <LiquidCrystal_I2C.h>

//Create an object of the LCDI2C with overloaded constructor.
LiquidCrystal_I2C lcd(0x27, 16,2); //LCD_I2C(I2C address,# of col., # of rows)

//define pin variables

  int greenButton = 0 ;
  int redButton = 11 ;
  int yellowButton = 2 ;
  int blueButton = 3 ;
  
  int joystickPress = 4 ;

/* TO DO:
  int screenA = 5 ;
  int screenB = 6 ;
  int screenC = 7 ;
  int screenD = 8 ; 
  int screenE = 9 ;
  int screenF = 10 ; */
  
  int tiltLeft = 12 ;
  int tiltRight = 13 ;

  int joystickX = 0 ;
  int joystickY = 1 ;

//define game variables

  bool hardMode = false ;
  int score = 0 ;

void setup()
{
  //set digital pin I/O modes
  
    pinMode(greenButton, INPUT_PULLUP) ;
    pinMode(redButton, INPUT_PULLUP) ;
    pinMode(yellowButton, INPUT_PULLUP) ;
    pinMode(blueButton, INPUT_PULLUP) ;
    
    pinMode(joystickPress, INPUT_PULLUP) ;

/*  TO DO:
    pinMode(screenOutPinA, OUTPUT) ;
    pinMode(screenOutPinB, OUTPUT) ;
    pinMode(screenOutPinC, OUTPUT) ;
    pinMode(screenOutPinD, OUTPUT) ;
    pinMode(screenOutPinE, OUTPUT) ;
    pinMode(screenOutPinF, OUTPUT) ; */

    pinMode(tiltLeft, INPUT_PULLUP) ;
    pinMode(tiltRight, INPUT_PULLUP) ;

//initialize serial communication at 9600 bits per second

  Serial.begin(9600) ;

  lcd.init(); 

  lcd.backlight();
    lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Game Start");
}

void loop()
{
  //prompt user for difficulty selection
    //TO DO: out -> "Start Easy - Green, Start Hard - Red"

  //read input and set hardMode boolean
    while(true)
    {
      if(digitalRead(greenButton == HIGH)) //easy mode selected (default boolean value)
        break ;
      if(digitalRead(redButton == HIGH)) //hard mode selected
      {
        hardMode = true ;
        break ;
      }
    }

  //confirm difficulty selection
    if(hardMode)
    {
      //TO DO: out -> "hard mode selected"
    }
    else
    {
      //TO DO: out -> "easy mode selected"
    }

  //count down start of game
    delay(1000) ;
    //TO DO: out -> "3"
   // lcd.print("Game Start");
    //lcd.print("Game Start");
   // Serial.print("2");
    //lcd.print("Game Start");
   // Serial.print("1");
    //lcd.print("Game Start");
   // Serial.print("Begin");
    //lcd.print("Game Start");

  //loop game until score of 99 is reached
    for(score ; score < 100 ; score++)
    {
      //TO DO: determine random value
      //TO DO: prompt user for input
      //TO DO: read input
      //TO DO: validate input
      //TO DO: add to score or exit loop
      //TO DO: reset variables (if needed) and repeat

      
int displayValue = readInput();
  lcd.clear();
    lcd.setCursor(2,0);
  lcd.print(displayValue);
  
          
    Serial.print(displayValue);

    delay(2000) ;
    }

  //TO DO: check to see if winning score
  //TO DO: tell user if they won
  //TO DO: tell user their score
  
  //reset variables and repeat to first menu
    hardMode = false ;
    score = 0 ;

    

}

/*
 * function for determining user input
 *  return values:
 *    no input -> -1
 *    green button -> 0, red button -> 1, yellow button -> 2, blue button -> 3
 *    joystick press -> 4
 *    tilt left -> 5, tilt right -> 6
 *    joystick left -> 7, joystick right -> 8, joystick down -> 9, joystick up -> 10
 *    multiple inputs read -> 11  
 */

 
int readInput()
{
  //declare variables
    bool doubleInput = false;
    int inputPin = -1 ;

  //check each digital pin for user input
    if(digitalRead(greenButton) == LOW && !doubleInput) //green button -> 0
    {
      Serial.print("greenbutton");
      if(inputPin == -1)
        inputPin = 0 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(redButton) == LOW && !doubleInput) //red button -> 1
    {
      Serial.print("redbutton") ;
      if(inputPin == -1)
        inputPin = 1 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(yellowButton) == LOW && !doubleInput) //yellow button -> 2
    {
      Serial.print("yellowbutton") ;
      if(inputPin == -1)
        inputPin = 2 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(blueButton) == LOW && !doubleInput) //blue button -> 3
    {
      Serial.print("bluebutton") ;
      if(inputPin == -1)
        inputPin = 3 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(joystickPress) == LOW && !doubleInput) //joystick press ->4
    {
      Serial.print("joystickpress") ;
      if(inputPin == -1)
        inputPin = 4 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(tiltLeft) == LOW && !doubleInput) //tilt left -> 5
    {
      Serial.print("tiltleft") ;
      if(inputPin == -1)
        inputPin = 5 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(digitalRead(tiltRight) == LOW && !doubleInput) //tilt right -> 6
    {
      Serial.print("tiltright") ;
      if(inputPin == -1)
        inputPin = 6 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }

  //check analog joystick pins for user input
  //joystick values range from 0-1024
  //if the joystick is pushed halfway to the max value it will be considered as "active"
    if(analogRead(joystickX) < 100 && !doubleInput) //joystick left -> 7
    {
      Serial.print("leftx_") ;
      Serial.print(analogRead(joystickX)) ;
      if(inputPin == -1)
        inputPin = 7 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(analogRead(joystickX) > 900 && !doubleInput) //joystick right -> 8
    {
      Serial.print("rightx_") ;
      Serial.print(analogRead(joystickX)) ;
      if(inputPin == -1)
        inputPin = 8 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(analogRead(joystickY) < 100 && !doubleInput) //joystick down -> 9
    {
      Serial.print("downy_") ;
      Serial.print(analogRead(joystickY)) ;
      if(inputPin == -1)
        inputPin = 9 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }
    if(analogRead(joystickY) > 900 && !doubleInput) //joystick up -> 10
    {
      Serial.print("upy_") ;
      Serial.print(analogRead(joystickY)) ;
      if(inputPin == -1)
        inputPin = 10 ;
      else //multiple inputs read
      {
        inputPin = 11 ;
        doubleInput = true ;
      }
    }

  //return input read
    return inputPin ;
}
