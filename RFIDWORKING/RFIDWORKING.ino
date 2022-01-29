//const int BUFFER_SIZE = 100;
//char buf[BUFFER_SIZE];
unsigned long currentMillis1 = 0;
unsigned long previousMillis = 0;
unsigned long interval = 500;
String dats;
byte manas;
int donebit = 0;
void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  //  Serial1.begin(115200); // opens serial port, sets data rate to 9600 bps
  Serial.println("1 ACS");
  delay(1000);
  Serial.println("1 ACS");
}

void loop() {
  // check if data is available
  //  Serial.println("0 ACS");
  //  delay(1000);
  //  Serial.println("0 ACS");
  while (Serial.available() > 0)
  {
    dats = Serial.readStringUntil('\n');
//    Serial.write(Serial.read());
    Serial.print(dats);
    //
  }
  //  currentMillis1 = millis();
  //  if (currentMillis1 - previousMillis >= interval)
  //  {
  //    previousMillis = currentMillis1;
  //    //    digitalWrite(13, (!digitalRead(13)));
  //    //    Serial.println("Done");
  //    if (donebit == 1)
  //    {
  //      //      Serial.print("OK");
  //      Serial.print(dats);
  //      Serial.print('\n');
  //      donebit = 0;
  //    }
  //  }
}
