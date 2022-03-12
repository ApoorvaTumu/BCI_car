#define m1 2
#define m2 3
#define m3 4
#define m4 5

#include <SoftwareSerial.h>
int mov = 0;

SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

char incomingByte;
String readBuffer = "";


void setup() {
  Serial.begin(9600);             // Open serial port to computer
  HC12.begin(9600);               // Open serial port to HC12
  
  // put your setup code here, to run once:
 pinMode (m1,OUTPUT);
 pinMode (m2,OUTPUT);
 pinMode (m3,OUTPUT);
 pinMode (m4,OUTPUT);
}

void loop() {
   readBuffer = "";
  boolean start = false;
  // Reads the incoming angle
  while (HC12.available()) {             // If HC-12 has data
    incomingByte = HC12.read();          // Store each icoming byte from HC-12
    delay(5);
    // Reads the data between the start "s" and end marker "e"
    if (start == true) {
      if (incomingByte != 'e') {
        readBuffer += char(incomingByte);    // Add each byte to ReadBuffer string variable
      }
      else {
        start = false;
      }
    }
    // Checks whether the received message statrs with the start marker "s"
    else if ( incomingByte == 's') {
      start = true; // If true start reading the message
    }
  }
  // Converts the string into integer
  mov = readBuffer.toInt();


//forward
if (int mov = 100) {
    digitalWrite (m1, HIGH);
    digitalWrite (m2, LOW);
    digitalWrite (m3, HIGH);
    digitalWrite (m4, LOW);
    delay(10000);
    }
 else
{
    digitalWrite (m1, LOW);
    digitalWrite (m2, LOW);
    digitalWrite (m3, LOW);
    digitalWrite (m4, LOW);
    delay(10000);
}


//left
if (int mov = 20) {
    digitalWrite (m1, LOW);
    digitalWrite (m2, LOW);
    digitalWrite (m3, HIGH);
    digitalWrite (m4, LOW);
    delay(10000);
  }
else
{
    digitalWrite (m1, LOW);
    digitalWrite (m2, LOW);
    digitalWrite (m3, LOW);
    digitalWrite (m4, LOW);
    delay(10000);
}
}
