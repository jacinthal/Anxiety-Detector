//--------------------------------------------------------
//                Heart Rate          /*H*/  Credit to Johan Ha for his code
//--------------------------------------------------------
#define sample_size 4
#define rise_threshold 5

int sensorPin = 0; //What pin is the HR sensor on? Analog pin #

float hrReadings[sample_size], sum;
float last, reader, start;
float first, second, third, before, print_value;
bool rising;
int rise_count;
int n;
long int last_beat, ptr;

void hrbegin() {
    for (n = sample_size; n > 0 ; n--) hrReadings[n] = 0; 
   sum = ptr = 0;
}

void hrGetReading() {
  reader /= n;  // we got an average
  sum -= hrReadings[ptr];
  sum += reader;
  hrReadings[ptr] = reader;
  last = sum / sample_size;
  if (last > before) { //rising edge
       rise_count++;
       if (!rising && rise_count > rise_threshold){
         rising = true; //dont double trigger on the same beat
         first = millis() - last_beat;
         last_beat = millis();
         print_value = 60000. / (0.4 * first + 0.3 * second + 0.3 * third);
         // weighted average of heartbeat rate based on the last 3 beats
         third = second;
         second = first;
       }
     }else  { //falling edge
       rising = false;
       rise_count = 0;
     }
     rise_count = 0;
     before = last;
     ptr++;
     ptr %= sample_size;
}
