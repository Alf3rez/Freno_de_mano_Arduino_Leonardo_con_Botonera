#include <Key.h>
#include <Keypad.h>
#include <Joystick.h>

// Introduccion de variables

int SENSOR;
int RESET;
char TECLA;
int i=0;

// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
            16, 0,                    // Botones, Hat switches
            false, false, true,       //Ejes X, Y, Z
            false, false, false,      //Ejes RX, RY, RZ
            false, false,             //Rudder, Throtle
            false, false, false);     //Acelerador, Freno, Direccion

// Declaración de la matriz numérica

  const byte filas = 4;                //Usaremos 4 filas de nuestro teclado
  const byte columnas = 4;             // Tenemos también 4 columnas en nuestro teclado
  byte pinesF[filas] = {9,8,7,6};      // Definimos los pines correspondientes a las filas
  byte pinesC[columnas] =  {5,4,3,2};  // Definimos los pines correspondientes a las columnas

// Definimos la matriz de nuestras teclas y sus nombres

  char teclas[filas][columnas] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
  };

// Realizamos nuestro mapeo del teclado matricial tal como

  Keypad teclado = Keypad(makeKeymap(teclas), pinesF, pinesC, filas, columnas);

void setup() {
  // las entradas analogicas no requieren inicialización
  Serial.begin(9600);
  
  // Inicializo la emulación como Joystick
  Joystick.begin();
  
}

void loop() {

  /*SENSOR = analogRead(A0);
  Serial.println(SENSOR);
  delay(500);*/
  
  TECLA = teclado.getKey();
  botones();
  
  //delay(0);
}

void botones (){
  
  // Mapeo los botones


  if (TECLA == '1') {
    Joystick.pressButton(0);
  } else {
    Joystick.releaseButton(0);
    }

  if (TECLA == '2') {
    Joystick.pressButton(1);
  } else {
    Joystick.releaseButton(1);
    }

  if (TECLA == '3') {
    Joystick.pressButton(2);
  } else {
    Joystick.releaseButton(2);
    }

  if (TECLA == 'A') {
    Joystick.pressButton(3);
  } else {
    Joystick.releaseButton(3);
    }

  if (TECLA == '4') {
    Joystick.pressButton(4);
  } else {
    Joystick.releaseButton(4);
    }

  if (TECLA == '5') {
    Joystick.pressButton(5);
  } else {
    Joystick.releaseButton(5);
    }

  if (TECLA == '6') {
    Joystick.pressButton(6);
  } else {
    Joystick.releaseButton(6);
    }

  if (TECLA == 'B') {
    Joystick.pressButton(7);
  } else {
    Joystick.releaseButton(7);
    }

  if (TECLA == '7') {
    Joystick.pressButton(8);
  } else {
    Joystick.releaseButton(8);
    }

  if (TECLA == '8') {
    Joystick.pressButton(9);
  } else {
    Joystick.releaseButton(9);
    }

  if (TECLA == '9') {
    Joystick.pressButton(10);
  } else {
    Joystick.releaseButton(10);
    }

  if (TECLA == 'C') {
    Joystick.pressButton(11);
  } else {
    Joystick.releaseButton(11);
    }

  if (TECLA == '*') {
    Joystick.pressButton(12);
  } else {
    Joystick.releaseButton(12);
    }

  if (TECLA == '0') {
    Joystick.pressButton(13);
  } else {
    Joystick.releaseButton(13);
    }

  if (TECLA == '#') {
    Joystick.pressButton(14);
  } else {
    Joystick.releaseButton(14);
    }

  if (TECLA == 'D') {
    Joystick.pressButton(15);
  } else {
    Joystick.releaseButton(15);
    }
}
