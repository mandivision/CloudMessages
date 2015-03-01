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

int incomingByte = 0; //for incoming serial data
int count = 0;
String mystring;
char mychar;
int set1 = 9;
int set2 = 12;
int set3 = 8;
int set4 = 11;
int set5 = 13;
int set6 = 10;
int control1=30;
int thunderdelay;
int cycle;
int interval;

void setup()
{  
  // Default pins set to 9 and 8 for REQN and RDYN
  // Set your REQN and RDYN here before ble_begin() if you need
  //ble_set_pins(3, 2);
  
  // Set your BLE Shield name here, max. length 10
  ble_set_name("The Cloud");
  
  // Init. and start BLE library.
  ble_begin();
  
  // Enable serial debug
  
  Serial.begin(57600);
   pinMode(set1, OUTPUT); 
  pinMode(set2, OUTPUT);
  pinMode(set3, OUTPUT); 
 pinMode(set4, OUTPUT); 
pinMode(set5, OUTPUT); 
pinMode(set6, OUTPUT); 
  
}

unsigned char len = 0;

unsigned char str[50]={0};

void loop()
{
  // This section recieves data from the app
  
  if ( ble_available() )
  { 
    
    
    mystring="";
    
    while ( ble_available() ){
     str[count]=ble_read();
      count= count + 1;
    }
     int i;
      for (i = 0; i < count; i = i + 1) {
        if ( str[i] != 0){
          mychar = str[i];
         mystring += mychar;
  
        
        }
     }
  
  char str[50] = {0};
  count=0;
  
 
  }
  
  if(mystring == "all"){
    digitalWrite(set1, HIGH); 
    digitalWrite(set2, HIGH); 
    digitalWrite(set3, HIGH); 
    digitalWrite(set4, HIGH); 
    digitalWrite(set5, HIGH); 
    digitalWrite(set6, HIGH); 
  }
  
   else if(mystring == "no"){
    digitalWrite(set1, LOW);
    digitalWrite(set2, LOW); 
    digitalWrite(set3, LOW); 
    digitalWrite(set4, LOW); 
    digitalWrite(set5, LOW); 
    digitalWrite(set6, LOW); 
  }
  
 else{
  if(mystring=="1") { cycle=1;}
  if(mystring=="2") { cycle=2;}
  if(mystring=="3") { cycle=3;}
  if(mystring=="4") { cycle=4;}
  if(mystring=="5") { cycle=5;}
  if(mystring=="6") { cycle = 6;}
  if(mystring=="6") { cycle=random(1,6);}
  
   thunderdelay=random(1500,3500);
interval= random(10,150);
int med= random(150,300);
int lon= random(300,800);
Serial.println(cycle);
  if (cycle == 1){
                                                      //CYCLE ONE
  digitalWrite(set3, HIGH);
  delay(150);
  digitalWrite(set3, LOW);
  delay(interval);
  
  digitalWrite(set3,HIGH);
  
  
    digitalWrite(set6, HIGH);
  delay(100);
  digitalWrite(set6, LOW);
  digitalWrite(set3,LOW);
  delay(thunderdelay);
  
  
    digitalWrite(set5, HIGH);
  delay(50);
  digitalWrite(set5, LOW);  
  
  digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  
    digitalWrite(set5, HIGH);
  delay(50);
  digitalWrite(set5, LOW);
  
    digitalWrite(set6, HIGH);
  delay(70);
  digitalWrite(set6, LOW);
  
  digitalWrite(set5, HIGH);
  delay(50);
  digitalWrite(set5, LOW);  
  
  digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  
    digitalWrite(set5, HIGH);
  delay(50);
  digitalWrite(set5, LOW);
  
    digitalWrite(set1, HIGH);
  delay(500);
  digitalWrite(set1, LOW);    // end of first burst
  
  delay(thunderdelay); 
  }
  
  if(cycle == 2){
                                                                      //CYCLE TWO
    digitalWrite(set1, HIGH);   //begining of short bursts
  delay(40);
  digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set1, HIGH);
  delay(40);
  digitalWrite(set1, LOW);
  delay(50);
  
      digitalWrite(set1, HIGH);   //begining of short bursts
  delay(40);
  digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set2, HIGH);
       digitalWrite(set1, HIGH);
  delay(40);
  digitalWrite(set2, LOW);
  delay(50);
      digitalWrite(set3, HIGH);   //begining of short bursts
  delay(40);
  digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set1, HIGH);
  delay(40);
  digitalWrite(set1, LOW);
     digitalWrite(set3, LOW);
  delay(interval);
  digitalWrite(set2, HIGH);   //begining of short bursts
  delay(40);
  digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set1, HIGH);
    digitalWrite(set4,HIGH);
  delay(40);
  digitalWrite(set1, LOW);
     digitalWrite(set2, LOW);
     digitalWrite(set4, LOW);
  delay(50);
  
   delay(thunderdelay); 
  }
  
  if(cycle == 3){
     digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set1, HIGH);
  delay(interval);
  digitalWrite(set1, LOW);
     digitalWrite(set3, LOW);
     digitalWrite(set5,HIGH);
     digitalWrite(set6,HIGH);
     delay(100);
     digitalWrite(set5, LOW);
     delay(50);
     digitalWrite(set5,HIGH);
     delay(250);
     digitalWrite(set6,LOW);
     delay(120);
     digitalWrite(set5, LOW);
     
          digitalWrite(set1, LOW);
  delay(250);
    digitalWrite(set3, HIGH);
  delay(interval);
  digitalWrite(set1, LOW);
     digitalWrite(set3, LOW);
     digitalWrite(set5,HIGH);
     digitalWrite(set6,HIGH);
     delay(100);
     digitalWrite(set5, LOW);
     delay(50);
     digitalWrite(set5,HIGH);
     delay(70);
     digitalWrite(set6,LOW);
     delay(20);
     digitalWrite(set5, LOW);
     delay(thunderdelay); 
    
  }
  
  if (cycle == 4){
     digitalWrite(set6,HIGH);
     delay(20);
     digitalWrite(set5, HIGH); 
     delay(interval);
     digitalWrite(set5,LOW);
     digitalWrite(set4,HIGH);
     digitalWrite(set6,LOW);
     delay(100);
     digitalWrite(set4,LOW);
     digitalWrite(set6, HIGH);
         digitalWrite(set5,HIGH);
     delay(20);
     digitalWrite(set6, LOW);
     digitalWrite(set3, HIGH); 
     delay(interval);
     digitalWrite(set3,LOW);
     digitalWrite(set5,LOW);
     digitalWrite(set6,HIGH);
     delay(interval);
     digitalWrite(set6, LOW);
     digitalWrite(set4,HIGH);
     digitalWrite(set5,HIGH);
     delay(100);
     digitalWrite(set5,LOW);
     delay(30);
     digitalWrite(set4,LOW);
    delay(thunderdelay); 
     digitalWrite(set1, HIGH);
  delay(70);
  digitalWrite(set1, LOW);
  
  digitalWrite(set2, HIGH);
  delay(50);
  digitalWrite(set2, LOW);  
  delay(10);
  digitalWrite(set4,HIGH);
  delay(40);
  digitalWrite(set3, HIGH);
  digitalWrite(set4,LOW);
  
  delay(interval);
  digitalWrite(set3, LOW);
  
  digitalWrite(set5, HIGH);
  delay(interval);
  digitalWrite(set5, LOW);
  delay(70);
   digitalWrite(set5, HIGH);
  delay(interval);
  digitalWrite(set5, LOW);
  delay(20);
   digitalWrite(set5, HIGH);
  delay(interval);
  digitalWrite(set5, LOW);
   delay(20);
   digitalWrite(set5, HIGH);
  delay((interval*2));
  digitalWrite(set5, LOW);
  
 
  
   delay(thunderdelay);
  
    
  }
  
  if(cycle == 5){
    digitalWrite(set6,HIGH);
    delay(40);
    digitalWrite(set5,HIGH);
    digitalWrite(set6,LOW);
    delay(interval);
    digitalWrite(set4, HIGH);
    digitalWrite(set3,HIGH);
    digitalWrite(set5, LOW);
    delay(interval);    
    digitalWrite(set4,LOW);
    delay(30);
    digitalWrite(set3,LOW);
    digitalWrite(set4,HIGH);
    delay(20);
    digitalWrite(set4,LOW);
    
     digitalWrite(set6, HIGH);
  delay(70);
  digitalWrite(set6, LOW);
  
  digitalWrite(set5, HIGH);
  delay(50);
  digitalWrite(set5, LOW);  
  
  digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  
  delay(thunderdelay);
  }
  
    if(cycle == 6){
 digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  delay(10);
  
 
  
   digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  delay(10);
  
   digitalWrite(set5, HIGH);
  delay(interval);
  digitalWrite(set5, LOW);
  delay(10);
  
   digitalWrite(set4, HIGH);
  delay(interval);
  digitalWrite(set4, LOW);
  delay(10);
  
   digitalWrite(set3, HIGH);
  delay(interval);
  digitalWrite(set3, LOW);
  delay(10);
  
  
  delay(thunderdelay);
  }
  
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

