/* Jorge Rafael Hurtado Garcia
 *  18052
 *  Lab5
 */

#include <SPI.h>
#include <SD.h>

File root;
File myFile;



void setup(){
  //Inicializacion de Puerto
  Serial.begin(115200);
  //Inicializamos comunicacion SPI
  SPI.setModule(0);
  //Configuracion de Pines
  pinMode(10,OUTPUT);
  Serial.println("Menu de seleccion de archivo.");
  root = SD.open("/");
  }
