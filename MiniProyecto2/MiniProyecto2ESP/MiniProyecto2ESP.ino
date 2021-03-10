
#include <AdafruitIO_MQTT.h>


int minutepic=0;
int hourpic=0;
int m_daypic=0;
int monthpic=0;
int yearpic=0;
int Bandera=0b00000100;
int Start=0b11111111;
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  Serial.write(Start);
  serialEvent(minutepic);
  serialEvent(hourpic);
  serialEvent(m_daypic);
  serialEvent(monthpic);
  serialEvent(yearpic);
  Serial.write(Bandera);
}

void serialEvent(int data) {
  while (Serial.available()) {
    data = (int)Serial.read();
  }
}
