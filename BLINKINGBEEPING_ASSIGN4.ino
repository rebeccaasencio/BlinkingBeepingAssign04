int tiltPin=2;
int tiltVal;
int redPin=7;
int greenPin=6;
int limitPin = 4;
int lSwitch;


void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  //Serial.begin(9600);
  pinMode(limitPin, INPUT_PULLUP);
  digitalWrite(tiltPin,HIGH);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  //tiltVal = 0;
  lSwitch = digitalRead(limitPin);
  tiltVal=digitalRead(tiltPin);
  Serial.println(tiltVal);

  if (tiltVal==0){
    digitalWrite(greenPin,HIGH);
    //delay(1000);
    digitalWrite(redPin,LOW);
  
  }

  if (tiltVal==1){
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

