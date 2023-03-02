//Bop-It Project
//pinMode reference:
    //https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
//tilt switch data sheet:
    //https://www.digikey.com/en/products/detail/e-switch/TM1000Q/2541277

const int ledPin = 13;// we will turn the Pin 13 light on
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
}
/******************************************/
void loop()
{
  int digitalVal = digitalRead(2);
  if(HIGH == digitalVal)
  {
    digitalWrite(ledPin,LOW);//turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH);//turn the led on
  }
}
