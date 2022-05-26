//--------------------------------------------------------
//                Bluetooth           /*B*/
//--------------------------------------------------------
#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

const unsigned long BAUD_RATE = 9600;

// Bluetooth TX -> D8, RX -> D7  <<< for the UNO
const int BLUETOOTH_TX = 8;
const int BLUETOOTH_RX = 7;

int button;

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth); //pass "bluetooth" to "ARduinoBlue" to be initialized
