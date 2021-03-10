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

int minutepic=0;
int hourpic=0;
int m_daypic=0;
int monthpic=0;
int yearpic=0;
int Bandera=0b00000000;
int Start=0b11111111;

// set up the 'Led Verde' feed
AdafruitIO_Feed *Led_Verde = io.feed("Led Verde");
//AdafruitIO_Feed *Led_Rojo = io.feed("Led Roja");
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); 
 

  // connect to io.adafruit.com
  io.connect();

  // set up a message handler for the 'digital' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  Led_Verde->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }

  Led_Verde->get();
  //Led_Rojo->get();

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

}

// this function is called whenever an 'digital' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {



  digitalWrite(LED_BUILTIN, data->toPinLevel());
}
