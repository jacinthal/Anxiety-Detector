# Anxiety-Detector
Anxiety detector implemented using Arduino, 3 different types of sensors (thermistor, accelerometer, and heart rate moniter), and Bluetooth.

![image](https://user-images.githubusercontent.com/85028729/170580382-8bbc49af-c894-411b-ae87-acb57ecd965a.png)

List of Components:
1. Sensors:
-	Accelerometer
-	Heart-rate
-	Thermistor
2. Data Processing (Arduino Uno)
-	Arduino Uno
3. Communication:
-	Bluetooth

How to wire:
```
 Accelerometer:
  Vcc -> 5v
  GND -> gnd
  SCL -> A5
  SDL -> A4
  INT -> 2 (Not A2)
  
 Bluetooth:
  Tx -> 8
  Rx -> 7
  Vcc -> 5v
  GND -> gnd
 
 Heart rate:
  - -> GND
  Middle -> 5v
  Last pin -> A0
```
