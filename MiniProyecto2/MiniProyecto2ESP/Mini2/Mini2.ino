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


/************************ Example Starts Here *******************************/


int minutepic=2;
int secondpic=25;
int hourpic=3;
byte Bandera=0b00000000;
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
  Serial.begin(9600);
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
  digital3->get();
  digital4->get();
}

void loop() {
  io.run();
  WriteData();
  if (Serial.available()>0)
  {
    hourpic=Serial.read();
    Serial.write(Bandera);
  }
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

void handleMessage(AdafruitIO_Data *data) {
  bitWrite(Bandera,1,data->toPinLevel());
  digitalWrite(LED_BUILTIN,bitRead(Bandera,1));
}
void handleMessage2(AdafruitIO_Data *data) {
  bitWrite(Bandera,2,data->toPinLevel());
  digitalWrite(LED_BUILTIN,bitRead(Bandera,2));
}
