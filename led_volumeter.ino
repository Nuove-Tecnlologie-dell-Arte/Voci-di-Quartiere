int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int sensorPin = A0; // select the input pin for the sensor
int sensorval = 0; // variable to store the value coming from the sensor

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  Serial.begin(9600); // initialize serial communication with computer

}

// the loop routine runs over and over again forever:
void loop() {
  sensorval = analogRead(sensorPin); // read the value from the sensor
  sensorval = sensorval / 8;
  //Serial.println(sensorval); // send it to the computer (as ASCII digits)
  if (sensorval< 19){Serial.println("Led 0");}
  if (sensorval > 30) {digitalWrite(led1, HIGH); Serial.println("Led 1");}
  else {digitalWrite(led1, LOW);}

  if (sensorval > 40) {digitalWrite(led2, HIGH); Serial.println("Led 2");}
  else {digitalWrite(led2, LOW);}

  if (sensorval > 50) {digitalWrite(led3, HIGH); Serial.println("Led 3");}
  else {digitalWrite(led3, LOW);}

  if (sensorval > 60) {digitalWrite(led4, HIGH); Serial.println("Led 4");}
  else {digitalWrite(led4, LOW);}

  if (sensorval > 70) {digitalWrite(led5, HIGH); Serial.println("Led 5");}
  else {digitalWrite(led5, LOW);}
  
  if (sensorval > 80) {digitalWrite(led6, HIGH); Serial.println("Led 6");}
  else {digitalWrite(led6, LOW);}

  delay(10);
}