#define joyXValue A0 //Horizontal values will be from A0
#define joyYValue A1 //Vertical values will be from A1

void setup() {
  Serial.begin(9600);
  
}

void loop() {

  int VRx = analogRead(joyXValue);
  int VRy = analogRead(joyYValue);
  //SW = digitalRead(SWPin);

  //Joystick values range from 0-1024
  //If the joystick is pushed halfway to the max value it will be considered as "active"

  if (VRx > 768)
  {
    Serial.print("Right");
  }
  else if (VRx < 256)
  {
    Serial.print("Left");
  } 
  else if (VRy > 768)
  {
    Serial.print("Up");
  }
  else if (VRx < 256)
  {
    Serial.print("Down");
  }

  delay(200);
}
