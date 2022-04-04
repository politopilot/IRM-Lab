// Make sure these libraries are installed
// If not the case, use Tools > Manage Libraries
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// declaring variables

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int servo_num = 0;
int servo_freq = 50;

int pos, MinPulse, MaxPulse;  // current position, minimum (0°) & maximum (180°) pulse length of the servo in µs             
float secondStep;             // unrounded pulse length increase in µs that corresponds to an increase of 1 second
float exactPos;               // Exact, unrounded position of the servo in µs
char serialVariable;          // Character received through the serial communication

void setup() {
  Serial.begin(115200);                 // open serial communication

  //_________________Begin - Setup_______________
  pwm.begin();
  pwm.setPWMFreq(servo_freq);

  MinPulse = 550;
  MaxPulse = 2400;
  secondStep = (2400 - 550)/150;
  //_________________End - Setup_______________

}

void loop() {
  
  // Only run the loop if the serial communication is available
  if( Serial.available())
  {
    
    // read the incoming character and save it in "serialVariable"
    serialVariable = Serial.read();

    // If "a" is received reset the servo to its starting position.
    
    //_________________Begin - Reset_______________
    if (serialVariable == 'a') {
  exactPos = 550;
    pwm.writeMicroseconds(servo_num, 550);
    }
  
    //_________________End - Reset_______________


    // If "b" is received move the motor by one step.
    
    //_________________Begin - Advance_______________
    if (serialVariable == 'b') {
  exactPos += secondStep;
    pwm.writeMicroseconds(servo_num, (int) exactPos);
    }
 
    //_________________End - Advance_______________

    
  }
}
