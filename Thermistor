// THERMISTOR
#include <math.h>
int sensorPin = A3;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the sensor
float x, y;
float sum;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}

void loop() {
  sum = 0;
  // read the value from the sensor:
  sensorValue = analogRead(A3);
  //Serial.println(analogRead(A3));
  // stop the program for for <sensorValue> milliseconds:
  delay(100);
  x = sensorValue*= 0.0049;
  x -= 5;
  x = abs(sensorValue);
  x /= 1000;
  y = analogRead(A3)*0.0049/x;
  //x = (1/25) + (1/3950)*log(sensorValue);
  

  for(int i = 0; i < 20; i++) sum += abs(1000 -y - 25);
  Serial.println(sum/20);
}
