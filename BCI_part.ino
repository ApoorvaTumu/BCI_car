#include <Brain.h>
 
int meditation;
int meditation_t;
int attention;
SoftwareSerial HC12(10, 11);
 
 

Brain brain(Serial);
 
 
void setup()
   {
    // Start the hardware serial.
 Serial.begin(9600);             // Serial port to computer
 HC12.begin(9600);               // Serial port to HC12

   }
 
 
void loop()
   {
    // Expect packets about once per second.
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update())
       {
        //Serial.println(brain.readErrors());
        
        Serial.println(brain.readCSV());
        
        meditation = brain.readMeditation();
        
        
        Serial.print("Meditation = ");
        Serial.println(meditation);
        
        /*
        Serial.print(brain.readSignalQuality());
        Serial.print("   ");
        Serial.print(brain.readDelta());
        Serial.print("   ");
        Serial.print(brain.readTheta());
        Serial.print("   ");
        Serial.print(brain.readLowAlpha());
        Serial.print("   ");
        Serial.print(brain.readLowBeta());
        Serial.print("   ");
        Serial.println(brain.readHighBeta());
        */    
        
        
        
        meditation_t = map(meditation,0,100,0,90);

        
        if ((meditation_t >= 0) && (meditation_t < 25))
           {
            mov = 20;
           }
           
           
           if ((meditation_t >= 50) && (meditation_t < 90))
           {
            mov = 100;
           }
           int mov = int(mov);
         
           Serial.println(mov);
      String mov = String(mov);
        HC12.print("s" + mov + "e");
      delay(10);
                   
       }
   }
