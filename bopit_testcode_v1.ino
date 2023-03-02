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




//define pin variables

  int greenButton = 0 ;
  int redButton = 1 ;
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

  int joystickPinX = 0 ;
  int joystickPinY = 1 ;

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
    delay(1000) ;
    //TO DO: out -> "2"
    delay(1000) ;
    //TO DO: out -> "1"
    delay(1000) ;
    //TO DO: out -> "begin"
    delay(1000) ;

  //loop game until score of 99 is reached
    for(score ; score < 100 ; score++)
    {
      //TO DO: determine random value
      //TO DO: prompt user for input
      //TO DO: read input
      //TO DO: validate input
      //TO DO: add to score or exit loop
      //TO DO: reset variables (if needed) and repeat
    }

  //TO DO: check to see if winning score
  //TO DO: tell user if they won
  //TO DO: tell user their score
  
  //reset variables and repeat to first menu
    hardMode = false ;
    score = 0 ;
}
