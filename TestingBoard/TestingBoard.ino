int chipSelect =4;
int upDown = 3;
int increment =2;
int potValue = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(increment, OUTPUT);
  pinMode(upDown, OUTPUT);
  pinMode(chipSelect, OUTPUT);
  
  digitalWrite(increment, HIGH);
  digitalWrite(upDown, LOW);// Counting Up

  /*digitalWrite(chipSelect, LOW);

  incrementPot(50);
  Serial.println("Done Incrementing");
  Serial.println();
  Serial.println();
  Serial.println();
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(increment, LOW);
  delay(20);
  digitalWrite(increment, HIGH);
  //Serial.print(" Value of Pot ");
  //Serial.println(potValue);
  delay(20);
  //saveVal();
}

void incrementPot(int steps) {
  digitalWrite(upDown, LOW);// Counting Up

  for (int i=0; i<steps; i++) {
    digitalWrite(increment, LOW);
    delay(50);
    digitalWrite(increment, HIGH);
    potValue++;
    Serial.print(" Value of Pot ");
    Serial.println(potValue);
    delay(50);
  }
}

void decrementPot(int steps) {
   digitalWrite(upDown, HIGH);// Counting Down

   for (int i=0; i<steps; i++) {
    digitalWrite(increment, LOW);
    delay(50);
    digitalWrite(increment, HIGH);
    potValue--;
    Serial.print(" Value of Pot ");
    Serial.println(potValue);
    delay(500);
  } 
}

void saveVal(void) {
  digitalWrite(increment, HIGH);
  digitalWrite(chipSelect, HIGH);
  delay(20);
  digitalWrite(chipSelect, LOW);
}

