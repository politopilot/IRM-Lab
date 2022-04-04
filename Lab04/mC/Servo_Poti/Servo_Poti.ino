// Make sure these libraries are installed
// If not the case, use Tools > Manage Libraries
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// declare variables
int servo_num = 0;
int servo_freq = 50;

// create a pwm object to control the servo
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  
  // _______________ Begin - Setup _______________

  // Begin the serial communication
  Serial.begin(115200);
  // Begin PWM communication and set servo frequency
  pwm.begin();
  pwm.setPWMFreq(servo_freq);
  

  pinMode(A0,INPUT);
  // _______________ End - Setup _______________
  
}

void loop() {
  // _______________ Begin - Loop _______________

  // Read values from the analog pin and map/scale them to the movment range of the servo.
  float voltage_bits = analogRead(A0);
  
  // Optionally display the reading from the potentiometer on the serial monitor
  Serial.println(voltage_bits);

  // Set the servo position according to the mapped/scaled value
  int pwm_us;
  pwm_us = map(voltage_bits, 0, 4095, 550, 2400);
  
  pwm.writeMicroseconds(servo_num, pwm_us);
  
  

  // _______________ End - Loop _______________
  
  delay(15); // wait for the servo to get there
}
