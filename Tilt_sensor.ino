//Bop-It Project
//pinMode reference:
    //https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
//tilt switch data sheet:
    //https://www.digikey.com/en/products/detail/e-switch/TM1000Q/2541277

//Only 50% sure will be able to tell if the sensor is tilting left or right
//alternative is that the sensor just knows that it is tilting.

const int tiltLeft = 12;
const int tiltRight = 13;
int tiltValue1;
int tiltValue2;

void setup()
{
  pinMode(tiltLeft,INPUT);
  pinMode(tiltRight,INPUT);
    
  digitalWrite(TiltLeft, HIGH);
  digitalWrite(TiltRight, HIGH);
    
  Serial.begin(9600);
}
/******************************************/
void loop()
{
  tiltValue1 = digitalRead(tiltLeft);
  tiltValue2 = digitalRead(tiltRight);
  
/*  if(HIGH == digitalVal)
  {
    digitalWrite(TiltLeft,LOW);
  }
  else
  {
    digitalWrite(TiltLeft,HIGH);//turn the led on
  }*/
}
