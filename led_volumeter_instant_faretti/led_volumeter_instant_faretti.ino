int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int sensorPin = A1; // select the input pin for the sensor
int sensorval = 0; // variable to store the value coming from the sensor
int sensorvalold = 0;
int sensorvaltot = 0;
int soglia = 30;
int durata = 0;
int sensibility = 7;

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

  for(int i =0; i<100; i++){
    sensorvaltot = sensorvaltot + analogRead(sensorPin);
  }
  soglia = sensorvaltot / 100;
  soglia = soglia / sensibility;
  soglia = soglia + 10;
  Serial.println(soglia);

}

// the loop routine runs over and over again forever:
void loop() {
  sensorval = analogRead(sensorPin); // read the value from the sensor
  sensorval = sensorval / sensibility;
  Serial.println(sensorval); // send it to the computer (as ASCII digits)

  if (sensorval == sensorvalold){
    sensorvalold = sensorval;
  }
  else{

    if (sensorval >= soglia) {
      digitalWrite(led1, LOW); 
      //Serial.println("Led 1");
      delay(durata);
    }
    else {digitalWrite(led1, HIGH);}

    if (sensorval >= soglia + 5) {
      digitalWrite(led2, LOW); 
      //Serial.println("Led 2");
      delay(durata);
    }
    else {digitalWrite(led2, HIGH);}

    if (sensorval >= soglia + 10) {
      digitalWrite(led3, HIGH); 
      //Serial.println("Led 3");
      delay(durata);
    }
    else {digitalWrite(led3, LOW);}

    if (sensorval >= soglia + 15) {
      digitalWrite(led4, HIGH); 
      //Serial.println("Led 4");
      delay(durata); 
    }
    else {digitalWrite(led4, LOW);}

    if (sensorval >= soglia + 20) {
      digitalWrite(led5, HIGH); 
      //Serial.println("Led 5");
      delay(durata);
    }
    else {digitalWrite(led5, LOW);}

    if (sensorval >= soglia + 25) {
      digitalWrite(led6, HIGH); 
      //Serial.println("Led 6");
      delay(durata);
    }
    else {digitalWrite(led6, LOW);}

    sensorvalold=sensorval;
  }
}