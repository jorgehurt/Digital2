// Adafruit IO Digital Output Example
// Tutorial Link: https://learn.adafruit.com/adafruit-io-basics-digital-output
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

// include Serial Special functions
#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);


/************************ Example Starts Here *******************************/


int minutepic=1;
int secondpic=25;
int hourpic=5;
int Bandera=0b00000100;
int Start=0b11111111;
unsigned long previousMillis = 0;
const long interval = 15000;

// set up the 'digital' feed
AdafruitIO_Feed *digital = io.feed("Luz Verde");
AdafruitIO_Feed *digital2 = io.feed("Luz Roja");
AdafruitIO_Feed *digital3 = io.feed("minuto");
AdafruitIO_Feed *digital4 = io.feed("Hora");


void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  // start the serial connection
  s.begin(10417);
  Serial.begin(115200);
  io.connect();

  digital->onMessage(handleMessage);
  digital2->onMessage(handleMessage2);
  digital3->save(minutepic);
  digital4->save(hourpic);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }
  digital->get();
  digital2->get();
}

void loop() {
  io.run();
  WriteData();
  s.write(Bandera);
  //Serial.println("Si pasa por alla");
  //hourpic=s.read();
  /*
  Serial.println(hourpic);
  if (s.available()>0)
    {
      hourpic=s.read();
      Serial.println("Si pasa por aqui");
      Serial.println(hourpic);
    }
*/
  
}
void WriteData(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digital4->save(hourpic);
    digital3->save(minutepic);
  }
  return;
  }
/*
void serialEvent(int data) {
  while (Serial.available()) {
    data = (int)Serial.read();
  }
}

void Serialpic() {
  //Serial.write(Start);
  serialEvent(minutepic);
  serialEvent(hourpic);
  Serial.write(Bandera);
}

void Serialpic() {
  if (s.available()>0)
    {
      hourpic=s.read();
      Serial.println(hourpic);
    }
}
*/
void handleMessage(AdafruitIO_Data *data) {
  //Bandera[2]=data->toPinLevel();
  bitWrite(Bandera,1,data->toPinLevel());
  digitalWrite(LED_BUILTIN,bitRead(Bandera,1));
}
void handleMessage2(AdafruitIO_Data *data) {
  //Bandera[2]=data->toPinLevel();
  bitWrite(Bandera,2,data->toPinLevel());
  digitalWrite(LED_BUILTIN,bitRead(Bandera,2));
}
