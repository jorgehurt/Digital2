/* Jorge Rafael Hurtado Garcia
 *  18052
 *  Lab5
 */

#include <SPI.h>
#include <SD.h>

File root;
File myFile;

int Ingreso = Serial.read();

void setup(){
  //Inicializacion de Puerto
  Serial.begin(115200);
  //Inicializamos comunicacion SPI
  SPI.setModule(0);
  //Configuracion de Pines
  pinMode(10,OUTPUT);
  Serial.println("Menu de seleccion de archivo. Use 3 , 4  y 5 como index del archivo");
  if (!SD.begin(32)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/"); 

  Ingreso = 0;
  }

  void loop () { 
    printDirectory(root, 0);
    while (Serial.available()){
      Ingreso = Serial.read();
      Cases ();
    }
    }

void Cases (){
  if (Ingreso == 51){
    myFile = SD.open("dog3.txt");
    if (myFile) {
      Serial.println("dogecoin:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Ingreso = 0;
    }
    }
  if (Ingreso == 52){
    myFile = SD.open("pacman4.txt");
    if (myFile) {
      Serial.println("pacman:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Ingreso = 0;
    }
    }
  if (Ingreso == 53){
    myFile = SD.open("sandia5.txt");
    if (myFile) {
      Serial.println("sandia: ");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Ingreso = 0;
    }
    }
  }
  
void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //dir.rewindDirectory();
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
