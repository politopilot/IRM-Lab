/// Lab 02 - Analog Signal Acquisition
// Sample the analog output of the hall sensor sensor
// and print the value to the serial port

int incoming = 0;
int analogpin = A0;

void setup() {
  // setup the serial connection
  Serial.begin(115200);
  
  // set pin A0 as INPUT
  pinMode(analogpin, INPUT);
}

void loop() {

  // calculation: V = 3.3*(digital reading)/4095 
  // initialize your parameters
  float hlx_voltage = 0;
  int val = 0;
  int sum = 0;
  int avg_val = 0;
  int i;

  // check if the serial port is available and if something is received from the serial port
  if( Serial.available() )
  {
	  incoming = Serial.read();
    
    if(incoming == 48) // comparing input with character "0", then read and print voltage
    {
      // Read analog pin A0

      for(i = 0; i < 50; i++){
        val = analogRead(analogpin); 
        sum = sum + val; 
        }

      avg_val = sum / 50;
      // Print the digital sampled value to the serial port
      Serial.print(avg_val); // print
      sum = 0;
  
  }
   
  }
 delay(20);

}
