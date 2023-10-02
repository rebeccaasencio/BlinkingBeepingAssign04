//tilt switch is connected to digital pin 2
int tiltPin=2;
//defining tilt switch
int tiltVal;
//red LED is connected to digital pin 7
int redPin=7;
//green LED is connected to digital pin 6
int greenPin=6;
//microlimit switch is connected to digital pin 4
int limitPin = 4;
//defining mircolimit switch
int lSwitch;

void setup() {
  //inputs
  //tilt switch input
  pinMode(tiltPin,INPUT);
  //microlimit switch input
  pinMode(limitPin, INPUT_PULLUP);
  //outputs
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}
 
void loop() {
  //microlimit switch 
  lSwitch = digitalRead(limitPin);
  //tilt switch 
  tiltVal=digitalRead(tiltPin);
  //prints out 0 or 1 based on tilt switch orientation
  Serial.println(tiltVal);

  if (tiltVal==0){
    //if the box is closed, the green LED is turned on and the red LED is turned off
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }

  if (tiltVal==1){
    //if the box is open, the green LED is turned off and the red LED is turned on and blinking
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,HIGH);
    delay(1500);
    digitalWrite(redPin, LOW);
    delay(1500);
  }

  //turns off LED's
  if (lSwitch == LOW){
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    delay(1000);
  }

}

