/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with an LED
  
  This example code is in the public domain.
*/
// Definimos Los pines donde se encuentran los leds.
// most launchpads have a red LED
#define LEDR0 PD_0
#define LEDR1 PD_1
#define LEDR2 PD_2
#define LEDR3 PD_3
#define LEDR4 PE_1
#define LEDR5 PE_2
#define LEDR6 PE_3
#define LEDR7 PA_7
#define LEDG0 PB_5
#define LEDG1 PB_0
#define LEDG2 PB_1
#define LEDG3 PE_4
#define LEDG4 PE_5
#define LEDG5 PB_4
#define LEDG6 PA_5
#define LEDG7 PA_6
#define RGBLEDG GREEN_LED
#define RGBLEDR RED_LED

//Configuramos las variables de Inicio de la funcion.
const int  buttonPin1 = PUSH1;
const int  buttonPin2 = PUSH2;
int Contador1A=0;
int Contador2A=0;
byte Led_Rojo= 0b00000000;
byte Led_Verde=0b00000000;
int  Start=0;
byte valuecontador=0b00000000;
int value = 0;
int InitContador=1;

//Configuramos los pines como inputs o outputs.

void setup() {                
  // Configura los Leds Rojos como salidas.
  pinMode(LEDR0, OUTPUT);
  pinMode(LEDR1, OUTPUT);
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDR3, OUTPUT);
  pinMode(LEDR4, OUTPUT);
  pinMode(LEDR5, OUTPUT);
  pinMode(LEDR6, OUTPUT);
  pinMode(LEDR7, OUTPUT);
  // Configura los Leds Verdes como salidas.
  pinMode(LEDG0, OUTPUT);
  pinMode(LEDG1, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDG3, OUTPUT);
  pinMode(LEDG4, OUTPUT);
  pinMode(LEDG5, OUTPUT);
  pinMode(LEDG6, OUTPUT);
  pinMode(LEDG7, OUTPUT);  
  // Configuracion de los LEDs RGB
  pinMode(RGBLEDG, OUTPUT);
  pinMode(RGBLEDR, OUTPUT);
  // Configuracion de los Botones
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  //Configuramos las Interrupciones del puerto. Para cuando recien apachemos el boton asi configuramos el debouncing.
  attachInterrupt(digitalPinToInterrupt(buttonPin1), Push1A, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), Push2A, RISING);
}

// the loop routine runs over and over again forever:
void loop() {
  //Iniciamos la funcion de semaforo cuando el buttonpin1 o el buttonpin2 inicia siempre y cuando estemos listos para la secuencia de inicio.
  if ((digitalRead(buttonPin1)==0||digitalRead(buttonPin2)==0)&&Start==0){
    Semaforo ();
    }
}
//Configuramos la interrupcion para el Primer Pushbutton.
void Push1A (){
    if (Start ==1){
      delay(450);
      // Incrementamos el Contador.
      Contador1A=Contador1A+1;
      //Imprimimos el contador en el los leds indicados en la funcion printleds.
      Led_Rojo=ByteToPort (Contador1A);
      PrintLeds ();
    }
    return;
  }
void Push2A (){
    if (Start ==1){
      delay(450);
      // Incrementamos el Contador.
      Contador2A=Contador2A+1;
      //Imprimimos el contador en el los leds indicados en la funcion printleds.
      Led_Verde=ByteToPort (Contador2A);
      PrintLeds ();
    }
    return;
  }
//Iniciamos la secuencia del semaforo antes de iniciar la carrera. y mandamos el bit de inicio para confirmar que este listo para el juego.
void Semaforo (){
  digitalWrite(RGBLEDG, LOW);
  digitalWrite(RGBLEDR, HIGH);
  delay(1000);
  digitalWrite(RGBLEDG, HIGH);
  digitalWrite(RGBLEDR, HIGH);
  delay(1000);
  digitalWrite(RGBLEDG, HIGH); 
  digitalWrite(RGBLEDR, LOW); 
  delay(1000);
  digitalWrite(RGBLEDG, LOW);
  digitalWrite(RGBLEDR, LOW);
  Start=1; 
  return;
  }
//Con el mapeo correspondiente se procede a hacer la impresion de los valores extraidos del contador directamente en cada led.
void PrintLeds () {
  // Configuracion Led Rojo
    digitalWrite(LEDR0,bitRead(Led_Rojo,0));
    digitalWrite(LEDR1,bitRead(Led_Rojo,1));
    digitalWrite(LEDR2,bitRead(Led_Rojo,2));
    digitalWrite(LEDR3,bitRead(Led_Rojo,3));
    digitalWrite(LEDR4,bitRead(Led_Rojo,4));
    digitalWrite(LEDR5,bitRead(Led_Rojo,5));
    digitalWrite(LEDR6,bitRead(Led_Rojo,6));
    digitalWrite(LEDR7,bitRead(Led_Rojo,7));
    //Configuracion Led Verde
    digitalWrite(LEDG0,bitRead(Led_Verde,0));
    digitalWrite(LEDG1,bitRead(Led_Verde,1));
    digitalWrite(LEDG2,bitRead(Led_Verde,2));
    digitalWrite(LEDG3,bitRead(Led_Verde,3));
    digitalWrite(LEDG4,bitRead(Led_Verde,4));
    digitalWrite(LEDG5,bitRead(Led_Verde,5));
    digitalWrite(LEDG6,bitRead(Led_Verde,6));
    digitalWrite(LEDG7,bitRead(Led_Verde,7));
    return;
  }
//En esta funcion es una tabla de valores para ver que se debe mostrar en el puerto.
byte ByteToPort (int value) {
  if(value==1){
    return 0b00000001 ;
    }
  if(value==2){
    return 0b00000010 ;
    }
  if(value==3){
    return 0b00000100 ;
    }
  if(value==4){
    return 0b00001000 ;
    }
  if(value==5){
    return 0b00010000 ;
    }
  if(value==6){
    return 0b00100000 ;
    }
  if(value==7){
    return 0b01000000 ;
    }  
  if(value==8){
    return 0b10000000 ;
    } 
  else{
    if(Contador1A==9){
      //Al llegar a 9 uno de los dos contadores se termina la ejecucion del juego y se imprime quien es el ganador. Se limpian las variables y se reinicia todo.
      digitalWrite(RGBLEDR, HIGH);
      Led_Rojo = 0b11111111;
      PrintLeds ();
      delay(1000);
      }
    if(Contador2A==9){
      digitalWrite(RGBLEDG, HIGH);
      Led_Verde = 0b11111111;
      PrintLeds ();
      delay(1000);
      }
    Contador1A=0;
    Contador2A=0;
    Start = 0; 
    Led_Rojo = 0b00000000;
    Led_Verde = 0b00000000;
    return 0b00000000 ;
    }
  }
