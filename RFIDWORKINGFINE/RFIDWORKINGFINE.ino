//const int BUFFER_SIZE = 100;
//char buf[BUFFER_SIZE];
unsigned  long currentMillis1 = 0;
unsigned long previousMillis = 0;
unsigned long interval = 500;
String dats;
byte manas;
uint8_t donebit = 0;
uint8_t busybit = 0;
byte arr[15];
byte fin_arr[20];
uint8_t counters = 0;
void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  Serial.println("0 ACS");
  delay(1000);
  Serial.println("1 ACS");
}

void loop() {
  while (Serial.available() > 0)
  {
    manas = Serial.read();
    //    Serial.write(manas);
    if (busybit == 1)
    {
      arr[counters] = manas;
      //      Serial.write(arr[counters]);
      counters++;
    }
    if (manas == 0xE2 && busybit == 0)
    {
      arr[0] = manas;
      busybit = 1;
      counters = 1;
      //      Serial.write(arr[0]);
    }

    if (counters == 14)
    {
      busybit = 0;
      counters = 0;
      if(arr[13] == 0x0A)
      {
      donebit = 1;        
      }
    }
  }
  currentMillis1 = millis();
  if (currentMillis1 - previousMillis >= interval)
  {
    previousMillis = currentMillis1;
    if (donebit == 1)
    {
      for (int i = 0; i < 14; i++)
      {
        Serial.write(arr[i]);
      }
      donebit = 0;
    }
  }
}
