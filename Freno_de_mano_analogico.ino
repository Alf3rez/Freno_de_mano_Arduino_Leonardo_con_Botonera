#include <UwUKeypad.h>
#include <Joystick.h>

// Introduccion de variables
int SENSOR;
int RESET;
bool TeclasPresionadas[16];


// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
            20, 0,                    // Botones, Hat switches
            false, false, true,       //Ejes X, Y, Z
            false, false, false,      //Ejes RX, RY, RZ
            false, false,             //Rudder, Throtle
            false, false, false);     //Acelerador, Freno, Direccion


// Crear el Keypad
UwUKeypad teclado = UwUKeypad(2, 3, 4, 5, 6, 7, 8, 9);

void setup()
{
  Serial.begin(9600);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
  pinMode(A0, INPUT);

  Joystick.setZAxisRange(20, 1000);
  
  // Inicializo la emulación como Joystick
  Joystick.begin();
}

void loop()
{
  SENSOR = analogRead(A0);
  /*Serial.println(SENSOR);
  delay(500);*/
  
  //TECLA = teclado.getKey();
  botones();
  interruptores();
  Joystick.setZAxis(SENSOR);
  
  //delay(0);
}

// Mapeo los botones
void botones()
{
  teclado.getKeysState(TeclasPresionadas);
  for(byte i = 0; i < 16; i++)
  {
    if(TeclasPresionadas[i])
    {
      Joystick.releaseButton(i);
    }
    else
    {
      Joystick.pressButton(i);
    }
  }
}

void interruptores()
{
  for(byte j = 10; j < 14; j++)
  {
    if(digitalRead(j) == LOW)
    {
      Joystick.pressButton(j+6); 
    }
    else
    {
      Joystick.releaseButton(j+6);
    }
  }
}
