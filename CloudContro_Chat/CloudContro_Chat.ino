/*

Copyright (c) 2012-2014 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

/*
 *    Chat
 *
 *    Simple chat sketch, work with the Chat iOS/Android App.
 *    Type something from the Arduino serial monitor to send
 *    to the Chat App or vice verse.
 *
 */

//"services.h/spi.h/boards.h" is needed in every new project
#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>

char reed;         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int incomingByte = 0; //for incoming serial data
int count = 0;
String mystring;
char mychar;

void setup()
{  
  // Default pins set to 9 and 8 for REQN and RDYN
  // Set your REQN and RDYN here before ble_begin() if you need
  //ble_set_pins(3, 2);
  
  // Set your BLE Shield name here, max. length 10
  //ble_set_name("My Name");
  
  // Init. and start BLE library.
  ble_begin();
  
  // Enable serial debug
  Serial.begin(57600);
  
}

unsigned char buf[16] = {0};

unsigned char len = 0;

unsigned char str[50];

void loop()
{
  // This section recieves data from the app
  
  if ( ble_available() )
  { 
    
    
    Serial.println("Start Command");
    
    while ( ble_available() ){
     count= count + 1;
     
      //Serial.print("Count =");
      //Serial.println(count);
      reed=char(ble_read());
      Serial.print("Reed is equal to:");
      Serial.println(reed);
      str[count-1]=reed;
      //Serial.write(ble_read());
      //inputString = Serial.read();
      
       // This will Print the Message Array once it's stored
    }
     int i;
      for (i = 0; i < 16; i = i + 1) {
        if ( str[i] != 0){
          mychar = buf[i];
         mystring += mychar;
        Serial.print(mychar);
        Serial.print(",");
        
        }
        
        
  
      
     
     
  
  }
  
      Serial.print("My String is says");
      
      Serial.println(mystring);
  
  Serial.println("Command Finished");
  char buf[16] = {0};
  count=0;
  }
 
  
  
  
  //This Section sends data to the App
  if ( Serial.available() )
  {
    delay(5);
    
    while ( Serial.available() )
       
        ble_write( Serial.read() );
        
  }
  
  ble_do_events();
  

}

