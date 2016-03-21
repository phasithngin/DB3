// make global variables for pin numbers
int chipSelect = 4;  
int upDown = 3; 
int increment = 2; 

// setup runs one time when arduino turns on
void setup() {
  // get the arduino ready to listen/talk on serial port
  // 9600 is the baud rate; it means 9600 bits per second
  Serial.begin(9600);
  
  // Set up the input/output pins on arduino
  // we want all these pins to be output so they can
  // send 0V or 5V to the pot at the right time
  pinMode(chipSelect, OUTPUT);
  pinMode(upDown, OUTPUT);
  pinMode(increment, OUTPUT);

  // set the starting values for the output pins
  digitalWrite(chipSelect, LOW);
  digitalWrite(increment, HIGH); 
  digitalWrite(upDown, LOW);
  //-----------------------------------------No need to change any code above this line 

  // THIS IS THE ONLY LINE YOU NEED TO CHANGE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  changeResistance(12, 10); //start, stop
}

void loop() {

  // use the code below if you want the value of R to keep changing
  // you can cycle through a lot of values quickly and check that
  // they are right, but you can't stay at one set value
  /*
  delay(1000);
  for (int i = 0; i < 10; i++) {
    digitalWrite(increment, LOW);
    delay(20);
    Serial.println("Changed resistor value.");
    digitalWrite(increment, HIGH);
    delay(20);
  }
  delay(1000);
  */
}


void changeResistance(int startVal, int stopVal) {

    //Serial.print("Start value: ");
    //Serial.println(startVal);
    //Serial.print("Stop value: ");
    //Serial.println(stopVal);
    
    if(startVal > stopVal) { // count down
       digitalWrite(upDown, HIGH); // choose count-down mode
       for (int i = startVal; i < stopVal; i--) {
          digitalWrite(increment, LOW);
          delay(20);
          //Serial.println("Changed resistor value.");
          digitalWrite(increment, HIGH);
          delay(20);
       }
    }
    else { // count up
       digitalWrite(upDown, LOW); // choose count-up mode
       for (int i = startVal; i > stopVal; i++) {
          digitalWrite(increment, LOW);
          delay(20);
          //Serial.println("Changed resistor value.");
          digitalWrite(increment, HIGH);
          delay(20);
       }
    }
} 

