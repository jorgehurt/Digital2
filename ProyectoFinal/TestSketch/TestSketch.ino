
#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0x5408,A2,A1,A3,A4,A0); //all dummy args

int CiclodeJuego =1;

int timertemp = 300;
int contadorJ1 =0;
int contadorJ2 =0;
int Ballx=random(100,200);
int Bally=random(80,120);
int BallSpeed = 10;
int BallRamp = 2;
int ResBally= 0;
int ResBallx= 0;

//Bar Game Position
const int BarLenght = 60;
//BarPos
int BarPosUpRight = 10;
int BarPosUpLeft = 10;
int BarPosDownRight = BarPosUpRight + BarLenght;
int BarPosDownLeft = BarPosUpLeft + BarLenght;


//Move Right Bar CTE
const int BarSteps = 30;//Bar Speed Movement
int ButtonUpRightBar = 0;
int ButtonDownRightBar = 0;
int RightBarCounter = BarPosUpRight;
int LeftBarCounter = BarPosUpLeft;

//Move Right Bar CTE
int ButtonUpLeftBar = 0;
int ButtonDownLeftBar = 0;

byte SendSerial = 0b00000000;




void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont); 

}

void loop()
{
  Serial.write(1);
  SendSerial=Serial.read();
  ButtonUpRightBar = bitRead(SendSerial,1);
  ButtonDownRightBar = bitRead(SendSerial,2);
  ButtonUpLeftBar = bitRead(SendSerial,3);
  ButtonDownLeftBar = bitRead(SendSerial,4);

  InitScreen ();
  delay(2000);
  if(ButtonDownRightBar==1 || ButtonDownLeftBar==1){
    myGLCD.fillScr(0, 0, 0); 
    CiclodeJuego =1;
    while(CiclodeJuego == 1){
      MoveBall ();
      delay(75);
      MoveRightBar ();
      delay(75);
      MoveLeftBar ();
      delay(75);
      GoalRightPlayer();
      delay(75);
          }
    }

/*

  
  //int buf[218];
  //Instructions:
  //myGLCD.fillRoundRect(0, 0, 315, 235); //Full Display Recomended Size
  //myGLCD.setColor(0, 255, 255); 
  //myGLCD.print("few seconds...", CENTER, 101);
  //myGLCD.setColor(0, 255, 0);
  //myGLCD.setBackColor(0, 0, 255);
  //myGLCD.print("Runtime: (msecs)", CENTER, 146);
  //myGLCD.printNumI(millis(), CENTER, 161);
  
  
  
  MoveBall ();
  ButtonUpRightBar = 1;
  MoveRightBar ();
  ButtonUpRightBar = 0;
  ButtonDownLeftBar = 1;
  MoveLeftBar ();
  ButtonDownLeftBar = 0;  
  delay(1000);


const unsigned char PROGMEM Bola[32] = {   
  0x1E, 0x00, //    ####   
  0x3F, 0x00, //   ######  
  0x3F, 0x80, //   ####### 
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0xF3, 0xC0, // ####  ####
  0xED, 0xC0, // ### ## ###
  0xE3, 0xC0, // ###   ####
  0xE9, 0xC0, // ### #  ###
  0xF5, 0xC0, // #### # ###
  0xF3, 0xC0, // ####  ####
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0x7F, 0x80, //  ######## 
  0x3F, 0x00, //   ######  
  0x1E, 0x00, //    ####
};

//myGLCD.drawBitmap(100,100,20,20,Bola) ;

*/





}

void InitScreen ()
{
  //Pantalla de Inicio
  myGLCD.fillScr(100, 250, 100);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(57, 150, 257,210);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(150, 150, 150);
  myGLCD.fillRoundRect(0, 20, 318, 55);
  myGLCD.setColor(255,255, 255);
  myGLCD.print("Pong!", CENTER, 32);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("Inicio", CENTER, 180);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 10 , 255);
  myGLCD.setColor(255, 100, 0);
  myGLCD.print("Click any key", CENTER, 105);
  myGLCD.print("to Start", CENTER, 125);
  myGLCD.setFont(BigFont);
}

void RightBar ()
{
  //Pantalla de Juego Barra derecha
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRoundRect(300, BarPosUpRight, 310, BarPosDownRight);//70
}

void GoalRightPlayer(){
  if (Ballx>=290){
    if(Bally < BarPosUpRight || Bally > BarPosDownRight){
      contadorJ1=contadorJ1+1;
      if (contadorJ1 >=3){
        WinnerScreenJ1 ();
        contadorJ1=0;
        contadorJ2=0;
        CiclodeJuego =0;
        Ballx=random(100,200);
        Bally=random(80,120);
        delay(1000);
        return;
        }
      ScoreScreen ();
      delay(1000);
      myGLCD.fillScr(0, 0, 0);
      Ballx=random(100,200);
      Bally=random(80,120);
      return;
      }
    
    }
  if (Ballx<=30){
    if(Bally < BarPosUpLeft || Bally > BarPosDownLeft){
      contadorJ2=contadorJ2+1;
      if (contadorJ2 >=3){
        WinnerScreenJ2 ();
        contadorJ1=0;
        contadorJ2=0;
        CiclodeJuego =0;
        Ballx=random(100,200);
        Bally=random(80,120);
        delay(1000);
        return;
        }
      ScoreScreen ();
      delay(1000);
      myGLCD.fillScr(0, 0, 0);
      Ballx=random(100,200);
      Bally=random(80,120);
      return;
      }
    
    }
  }


void ClearRightBar ()
{
  //Pantalla de Juego Barra derecha
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect(300, BarPosUpRight, 310, BarPosDownRight);//70
}

void MoveRightBar (){
  Serial.write(1);
  SendSerial=Serial.read();
  ButtonUpRightBar = bitRead(SendSerial,1);
  ButtonDownRightBar = bitRead(SendSerial,2);
  ButtonUpLeftBar = bitRead(SendSerial,3);
  ButtonDownLeftBar = bitRead(SendSerial,4);
  ClearRightBar ();
  if (ButtonUpRightBar == 1){
    if (RightBarCounter > 10){
      RightBarCounter = RightBarCounter - BarSteps;
      BarPosUpRight = RightBarCounter;
      BarPosDownRight = BarPosUpRight + BarLenght;
      }
      RightBar (); 
      return;
    }
  if (ButtonDownRightBar == 1){
    if (RightBarCounter < 150){
      RightBarCounter = RightBarCounter + BarSteps;
      BarPosUpRight = RightBarCounter;
      BarPosDownRight = BarPosUpRight + BarLenght; 
      }
      RightBar (); 
      return;    
    }

  BarPosUpRight = RightBarCounter;
  BarPosDownRight = BarPosUpRight + BarLenght;  
  RightBar (); 
  return;
  }

void LeftBar ()
{
  //Pantalla de Juego Barra Izquierda\
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRoundRect(10, BarPosUpLeft, 20, BarPosDownLeft);//170
}

void ClearLeftBar ()
{
  //Pantalla de Juego Barra derecha
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect(10, BarPosUpLeft, 20, BarPosDownLeft);//70
}

void MoveLeftBar (){
  Serial.write(1);
  SendSerial=Serial.read();
  ButtonUpRightBar = bitRead(SendSerial,1);
  ButtonDownRightBar = bitRead(SendSerial,2);
  ButtonUpLeftBar = bitRead(SendSerial,3);
  ButtonDownLeftBar = bitRead(SendSerial,4);
  ClearLeftBar ();
  if (ButtonUpLeftBar == 1){
    if (LeftBarCounter > 10){
      LeftBarCounter = LeftBarCounter - BarSteps;
      BarPosUpLeft = LeftBarCounter;
      BarPosDownLeft = BarPosUpLeft + BarLenght;
      }
      LeftBar (); 
      return;
    }
  if (ButtonDownLeftBar == 1){
    if (LeftBarCounter < 150){
      LeftBarCounter = LeftBarCounter + BarSteps;
      BarPosUpLeft = LeftBarCounter;
      BarPosDownLeft = BarPosUpLeft + BarLenght; 
      }
      LeftBar (); 
      return;    
    }
  BarPosUpLeft = LeftBarCounter;
  BarPosDownLeft = BarPosUpLeft + BarLenght;    
  LeftBar ();
  return;
  }

void Ball ()
{
  //Pelota
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillCircle(Ballx,Bally, 5);
}

void ClearBall ()
{
  //Pelota
  //myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillCircle(Ballx,Bally, 5);
}

void MoveBall ()
{
  Ball ();
  delay (BallSpeed);
  ClearBall (); 
  ResetBall();
  Ball ();
  delay (BallSpeed);
  return;

}

void ResetBall(){


  if (Ballx<296 && ResBallx == 0){
     Ballx=(Ballx+BallRamp);
     if (Ballx>=295){
       ResBallx =1;
     }
    }
  if (ResBallx ==1){
    if (Ballx<=30){
      ResBallx =0;
      }
     Ballx=(Ballx-BallRamp);
    }
  if (Bally<230 && ResBally ==0){
     Bally=(Bally+BallRamp);
     if (Bally>=229){
       ResBally =1;
     }
    }
  if (ResBally ==1){
    if (Bally<=20){
      ResBally =0;
      }
     Bally=(Bally-BallRamp);
    }
}

void ScoreScreen ()
{
  //Pantalla de Puntaje
  //myGLCD.clrScr();
  myGLCD.fillScr(100, 250, 100);
  myGLCD.setColor(150, 150, 150);
  myGLCD.setBackColor(150, 150, 150);
  myGLCD.fillRoundRect(0, 20, 315, 55);
  myGLCD.setColor(255,255, 255);
  myGLCD.print("Pong!", CENTER, 32);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J1", 40, 70);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J2", 170, 70);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(contadorJ1, 50, 90);
  myGLCD.printNumI(contadorJ2, 185, 90);
  myGLCD.setFont(BigFont);
}


void WinnerScreenJ1 ()
{  
// Winner Screen J1
//myGLCD.clrScr();
  myGLCD.fillScr(100, 250, 100);
  myGLCD.setColor(150, 150, 150);
  myGLCD.setBackColor(150, 150, 150);
  myGLCD.fillRoundRect(0, 20, 315, 55);
  myGLCD.setColor(255,255, 255);
  myGLCD.print("Pong!", CENTER, 32);
  myGLCD.setBackColor(255, 10, 255);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J1", 40, 70);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J2", 170, 70);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(255, 10, 255);
  myGLCD.setColor(0, 100, 255);
  myGLCD.printNumI(contadorJ1, 50, 90);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.printNumI(contadorJ2, 185, 90);
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(30, 160, 300,220);  
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("Winner!!!!!!!", CENTER, 200);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 10, 255);
  myGLCD.setColor(255, 100, 0);
  myGLCD.print("Click any key to retry!", CENTER, 145);
  myGLCD.setFont(BigFont);  
}



void WinnerScreenJ2 ()
{
// Winner Screen J2
//myGLCD.clrScr();
  myGLCD.fillScr(100, 250, 100);
  myGLCD.setColor(150, 150, 150);
  myGLCD.setBackColor(150, 150, 150);
  myGLCD.fillRoundRect(0, 20, 315, 55);
  myGLCD.setColor(255,255, 255);
  myGLCD.print("Pong!", CENTER, 32);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J1", 40, 70);
  myGLCD.setBackColor(255, 10, 255);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("J2", 170, 70);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.printNumI(contadorJ1, 50, 90);
  myGLCD.setBackColor(255, 10, 255);
  myGLCD.setColor(0, 100, 255);
  myGLCD.printNumI(contadorJ2, 185, 90);
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(30, 160, 300,220);  
  myGLCD.setBackColor(255, 10, 0);
  myGLCD.setColor(0, 100, 255);
  myGLCD.print("Winner!!!!!!!", CENTER, 200);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 10, 255);
  myGLCD.setColor(255, 100, 0);
  myGLCD.print("Click any key to retry!", CENTER, 145);
  myGLCD.setFont(BigFont);
}
