//--------------------------------------------------------
//                Accelerometer       /*A*/
//--------------------------------------------------------
#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 accel(Wire); //Initialize the IMU. set wire = &w, offsets, and the filter coeffs

double X, Y, Z;
float vec[3];
float magnitude, velocity, velocity_old = 0; 

float velocityFunction() { //the function called to compute the velocity
  // V = Vo[velocity_old] + a[magnitude]*t[millis() - timer]
  X = accel.getAngleZ()*0.0174533;
  Y = accel.getAngleY()*0.0174533;
  Z = accel.getAngleX()*0.0174533;
  str = "";
  double matrix[3][3] = { //the rotation matrix in pitch[m][0], yaw[m][1], and roll[m][2]
    {cos(Z)*sin(Y),  cos(Z)*sin(Y)*sin(X) - sin(Z)*cos(X),   cos(Z)*sin(Y)*cos(X) + sin(Z)*sin(X)},
    {sin(Z)*cos(Y),  sin(Z)*sin(Y)*sin(X) + cos(Z)*cos(X),   sin(Z)*sin(Y)*cos(X) - cos(Z)*sin(X)},
    {-sin(Y),        cos(Y)*sin(X),                          cos(Y)*cos(X)}};
  
  for(int m = 0; m < 3; m++){
    vec[m] = ( matrix[m][0]*accel.getAccZ() + matrix[m][1]*accel.getAccY() + matrix[m][2]*accel.getAccX() )/2;//do the rotate
  }
  //the acceleration is actually set up as a multiple of two, so now we are bringing it back to where it should be

  
  magnitude = sqrt(pow(vec[2], 2)+pow(vec[1], 2));//the magnitude of acceleration on the x-y plane.
  velocity = velocity_old + magnitude*(millis()-timer)/1000; 
  velocity_old = velocity;//V equation. Note millis() & timer are converted from ms to s
  return velocity;
}
