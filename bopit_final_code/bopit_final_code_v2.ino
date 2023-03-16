//Bop-It Project
//Final Code

//include i2c lcd library
  #include <LiquidCrystal_I2C.h>

//set up lcd screen object
  LiquidCrystal_I2C lcd(0x27, 16,2); //LCD_I2C(I2C address,# of col., # of rows)

//define input pin variables
  int greenButton = 0 ;
  int redButton = 11 ;
  int yellowButton = 2 ;
  int blueButton = 3 ;
  
  int joystickPress = 4 ;

  int tiltLeft = 12 ;
  int tiltRight = 13 ;

  int joystickX = 0 ;
  int joystickY = 1 ;

void setup()
{
  //set digital pin I/O modes
    pinMode(greenButton, INPUT_PULLUP) ;
    pinMode(redButton, INPUT_PULLUP) ;
    pinMode(yellowButton, INPUT_PULLUP) ;
    pinMode(blueButton, INPUT_PULLUP) ;
    
    pinMode(joystickPress, INPUT_PULLUP) ;

    pinMode(tiltLeft, INPUT_PULLUP) ;
    pinMode(tiltRight, INPUT_PULLUP) ;

  //initialize serial communication at 9600 bits per second
    Serial.begin(9600) ;
  
  //initialize lcd screen
    lcd.init(); 
    lcd.backlight();
    lcd.clear();
}

void loop()
{
  //define game variables
    bool hardMode = false ;
    int correctInput = -1 ;
    int score = 0 ;
    int request = -1 ;
    int inputRead = -2 ;
    long int inputDelayTime = 0;
    randomSeed(analogRead(3)) ;
    int lastRandA ;
    int lastRandB ;
  
  //prompt user for difficulty selection
    lcd.setCursor(0,0) ;
    lcd.print("Easy Mode: Green") ;
    lcd.setCursor(0,1) ;
    lcd.print("Hard Mode: Red") ;

  //read input and set hardMode boolean
    while(true)
    {
      if(readInput() == 0) //easy mode selected (default boolean value)
        break ;
      if(readInput() == 1) //hard mode selected
      {
        hardMode = true ;
        break ;
      }
    }

  //confirm difficulty selection
    lcd.clear() ;
    lcd.setCursor(0,0) ;
    if(hardMode)
    {
      lcd.print("   Hard Mode") ;
    }
    else
    {
      lcd.print("   Easy Mode") ;
    }
    lcd.setCursor(0,1) ;
    lcd.print("   Selected") ;
    delay(1500) ;
    lcd.clear() ;

  //reminder
    lcd.clear() ;
    lcd.setCursor(0,0) ;
    lcd.print("Remember To Keep") ;
    lcd.setCursor(0,1) ;
    lcd.print("The Device Level") ;
    delay(2000) ;
    lcd.clear() ;
    lcd.setCursor(0,0) ;
    lcd.print(" To Avoid Wrong") ;
    lcd.setCursor(0,1) ;
    lcd.print("   Tilt Input") ;
    delay(2000) ;
    lcd.clear() ;

  //count down start of game
    delay(1000) ;
    lcd.setCursor(0,0) ;
    lcd.print("       3") ;
    delay(1000) ;
    lcd.setCursor(0,0) ;
    lcd.print("       2") ;
    delay(1000) ;
    lcd.setCursor(0,0) ;
    lcd.print("       1") ;
    delay(1000) ;
    lcd.setCursor(0,0) ;
    lcd.print("     Begin!") ;
    delay(1000) ;

  //loop game until score of 99 is reached
    for(score ; score < 100 ; score++)
    {
      //determine random value
        request = random(0,10) ;
        
        if(!hardMode)
          if(request == 4)
            request = random(5,6) ;
            
      //prompt user for input
        lcd.clear() ;
        lcd.setCursor(0,0) ;
      
        if(hardMode)
        {          
          switch(request)
          {           
            case 0 :
              lcd.print(" Green Button") ;
            break ;
            
            case 1 :
              lcd.print("  Red Button") ;
            break ;
            
            case 2 :
              lcd.print(" Yellow Button") ;
            break ;
            
            case 3 : 
              lcd.print(" Blue Button") ;
            break ;
            
            case 4 :
              lcd.print(" Joystick Press") ;
            break ;
            
            case 5 :
              lcd.print("  Tilt Left") ;
            break ;
            
            case 6 :
              lcd.print("  Tilt Right") ;
            break ;
            
            case 7 :
              lcd.print(" Joystick Left") ;
            break ;
            
            case 8 :
              lcd.print("Joystick Right") ;
            break ;
            
            case 9 :
              lcd.print(" Joystick Down") ;
            break ;
            
            case 10 :
              lcd.print(" Joystick Up") ;
            break ;
          }
        }
        else
        {
          switch(request)
          {           
            case 0 :            
            case 1 :
            case 2 :            
            case 3 : 
            case 4 :
              lcd.print("  Button Press") ;
            break ;
            
            case 5 :
            case 6 :
              lcd.print("  Tilt Device") ;
            break ;
            
            case 7 :
            case 8 :
            case 9 :
            case 10 :
              lcd.print(" Joystick Move") ;
            break ;
          }
        }

      //read input
        inputDelayTime = millis() ;
        while(correctInput == -1)
        {
          inputRead = readInput() ;
          if(hardMode)
          {
            switch(inputRead)
            {
              case -1 :
                if(millis() - inputDelayTime >= 2000)
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("   No Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
              break ;

              case 11 :
                lcd.clear() ;
                lcd.setCursor(0,0) ;
                lcd.print("Multiple Inputs") ;
                delay(3000) ;
                correctInput = 0 ;
              break ;
              
              default:
                if(request == inputRead)
                  correctInput = 1 ;
                else
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("Incorrect Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
            }
          }
          else
          {
            switch(inputRead)
            {
              case -1 :
                if(millis() - inputDelayTime >= 2000)
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("   No Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
              break ;

              case 0 :
              case 1 :
              case 2 :
              case 3 :
              case 4 :
                if(request >= 0 && request <= 4)
                  correctInput = 1 ;
                else
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("Incorrect Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
              break ;

              case 5 :
              case 6 :
                if(request >= 5 && request <= 6)
                  correctInput = 1 ;
                else
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("Incorrect Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
              break ;

              case 7 :
              case 8 :
              case 9 :
              case 10 :
                if(request >= 7 && request <= 10)
                  correctInput = 1 ;
                else
                {
                  lcd.clear() ;
                  lcd.setCursor(0,0) ;
                  lcd.print("Incorrect Input") ;
                  delay(3000) ;
                  correctInput = 0 ;
                }
              break ;

              case 11 :
                lcd.clear() ;
                lcd.setCursor(0,0) ;
                lcd.print("Multiple Inputs") ;
                delay(3000) ;
                correctInput = 0 ;
              break ;
            }
          }
        }
      
      //validate correctness and conintue
        if(correctInput == 0)
        {
          lcd.clear() ;
          lcd.setCursor(0,0) ;
          lcd.print("   Game Lost") ;
          delay(3000) ;
          break ;
        }
        else
        {
          lcd.clear() ;
          lcd.setCursor(0,0) ;
          lcd.print("   Correct!") ;
          lcd.setCursor(0,1) ;
          lcd.print("   Score: ") ;
          lcd.print(score + 1) ;
          delay(1500) ;
        }
        
      //reset variables
        request = -1 ;
        inputRead = -2 ;
        correctInput = -1 ;
        inputDelayTime = 0 ;
    }

  //output score
    lcd.clear() ;
    lcd.setCursor(0,0) ;
    lcd.print(" Final Score: ") ;
    lcd.print(score) ;
    delay(3000) ;
  
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
