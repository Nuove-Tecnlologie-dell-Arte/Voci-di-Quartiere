int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int sensorPin = A1; // select the input pin for the sensor
int sensorval = 0; // variable to store the value coming from the sensor
int soglia = 30;
int durata = 40;
int sensibility = 8;

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
  sensorval = sensorval / sensibility;
  //Serial.println(sensorval); // send it to the computer (as ASCII digits)

  if (sensorval < soglia - 1){
    Serial.println("Led 0");
    }

  if (sensorval >= soglia) {
    digitalWrite(led1, HIGH); 
    Serial.println("Led 1");
    delay(durata);
      if (sensorval >= soglia + 5) {
        digitalWrite(led2, HIGH); 
        Serial.println("Led 2");
        delay(durata);
        if (sensorval >= soglia + 10) {
          digitalWrite(led3, HIGH); 
          Serial.println("Led 3");
          delay(durata);
            if (sensorval >= soglia + 15) {
              digitalWrite(led4, HIGH); 
              Serial.println("Led 4");
              delay(durata);
                if (sensorval >= soglia + 20) {
                  digitalWrite(led5, HIGH); 
                  Serial.println("Led 5");
                  delay(durata);
                  if (sensorval >= soglia + 25) {
                    digitalWrite(led6, HIGH); 
                    Serial.println("Led 6");
                    delay(durata);
                    }
                  else {digitalWrite(led6, LOW);}
                }
                else {digitalWrite(led5, LOW);}
              }
            else {digitalWrite(led4, LOW);}
          }
          else {digitalWrite(led3, LOW);}
      }
      else {digitalWrite(led2, LOW);}
    }
  else {digitalWrite(led1, LOW);}

  if (sensorval >= soglia + 25) { 
    digitalWrite(led6, LOW);
    delay(durata);
  }

  if (sensorval >= soglia + 20) { 
    digitalWrite(led5, LOW);
    delay(durata);
  }

  if (sensorval >= soglia + 15) { 
    digitalWrite(led4, LOW);
    delay(durata);
  }

  if (sensorval >= soglia + 10) { 
    digitalWrite(led3, LOW);
    delay(durata);
  }

  if (sensorval >= soglia + 5) { 
    digitalWrite(led2, LOW);
    delay(durata);
  }

  if (sensorval >= soglia) { 
    digitalWrite(led1, LOW);
    delay(durata);
  }
  
}