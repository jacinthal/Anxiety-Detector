//========================================================
//                Setup
//========================================================
void setup() {
  Serial.begin(BAUD_RATE); 
  
  bluetooth.begin(BAUD_RATE);

  hrbegin();
  Wire.begin(); //initialize wire
  byte status = accel.begin(); //initialize a, the IMU, and report on the status if it fails
 // for testing it is commented out while(status!=0){Serial.println(status);} // stop everything if could not connect to MPU6050
  delay(1000); // wait 1 second while calculating offsets
  accel.calcOffsets(true,true); // gyro and accelero offsets
  Serial.println("Blueetooth setup complete");
}

//========================================================
//                Loop
//========================================================
void loop() {
  accel.update();
  n = 0;
  start = millis();
  reader = 0.;
  do {
     reader += analogRead (sensorPin);
     n++;
     timer = millis();
   }while (timer < start + 20);
  hrGetReading();
 button = phone.getButton();
  Serial.print(print_value);
  Serial.print(velocity);
  Serial.println();
  velocityFunction();
  if(button != -1) {
   str +="Velocity: ";
    str += velocity;
   str +=" maybe in m/s";
   phone.sendMessage(str);
    str = "Heartbeat: ";
    str += print_value;
    /*B*/phone.sendMessage(str);
  }
  
}
