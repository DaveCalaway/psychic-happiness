#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // TX HC-06 , RX HC-06 voltage divider

void setup()  
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600); // frequenza alla quale la seriale gli scrive
  
  
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200); //frequenza alla quale risponde
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
