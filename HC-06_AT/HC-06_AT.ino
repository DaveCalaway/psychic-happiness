#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // TX HC-06 , RX HC-06 voltage divider

void setup()  
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600); // velocità seriale
  
  
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200); //velocità risposta BT
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
