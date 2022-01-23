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
  Serial1.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  Serial.println("0 ACS");
  Serial1.println("1 ACS");
}

void loop() {
  // check if data is available
  //  Serial.println("0 ACS");
  //  delay(1000);
  //  Serial.println("0 ACS");
  while (Serial.available() > 0)
  {
    manas = Serial.peek();
    if (manas == 0xE2)
    {
      dats = Serial.readStringUntil('\n');
      Serial.print(dats);
      if ((dats.length() == 13))
      {
        donebit = 1;
      }
      else
      {
        donebit = 0;
      }
    }
  }
  currentMillis1 = millis();
  if (currentMillis1 - previousMillis >= interval)
  {
    previousMillis = currentMillis1;
//    digitalWrite(13, (!digitalRead(13)));
    //    Serial.println("Done");
    if (donebit == 1)
    {
      Serial.print("OK");
      Serial1.print(dats);
      Serial1.print('\n');
      donebit = 0;
    }
  }
}
