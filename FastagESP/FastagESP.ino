unsigned long currentMillis1 = 0;
unsigned long previousMillis = 0;
unsigned long interval = 5000;
String dats;
byte manas;
uint8_t donebit = 0;
byte arr[20];
String fin_arr;
void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  //  Serial1.begin(115200); // opens serial port, sets data rate to 9600 bps
  //  pinMode(13, OUTPUT);
  //  delay(1000);
  //  digitalWrite(13, HIGH);
  //  delay(1000);
  //  digitalWrite(13, LOW);
  //  delay(1000);
  //  digitalWrite(13, HIGH);
  Serial.println();
  Serial.println("0 ACS");
  //  Serial1.println("1 ACS");
}

void loop()
{
  while (Serial.available() > 0)
  {
    manas = Serial.read();
    //    Serial.print(manas, HEX);
    if (manas == 0xE2)
    {
      fin_arr = "";
      arr[0] = manas;
      printdata(arr[0]);
      for (uint8_t k = 1; k <= 11; k++)
      {
        if (Serial.available() > 0)
        {
          byte restdata = Serial.read();
          arr[k] = restdata;
          printdata(arr[k]);
        }
      }
      donebit = 1;
    }
  }

  //  delay(1000);
  if (donebit == 1)
  {
    if (fin_arr != "E28011702000054E80B909A5")
      Serial.println(fin_arr);
    donebit = 0;
  }
}

void printdata(byte xyz)
{
  byte msb = xyz >> 4;
  msb = msb & 0x0F;
  byte lsb = xyz & 0x0F;
  //  Serial.print(msb, HEX);
  //  Serial.println(lsb, HEX);
  hex_to_printable_ascii(msb);
  hex_to_printable_ascii(lsb);
}

void hex_to_printable_ascii(byte hexx)
{
  //    Serial.print(hexx);
  //    Serial.print(" : ");
  char temp;
  if (hexx < 0x0A)
  {
    temp = hexx + 48;
    //    Serial.println(temp);
  }
  else if ((hexx > 0x09) && (hexx < 0x10))
  {
    temp = hexx + 55;
    //    Serial.println(temp);
  }
  fin_arr += String(temp);
  //      Serial.println(fin_arr);
}
