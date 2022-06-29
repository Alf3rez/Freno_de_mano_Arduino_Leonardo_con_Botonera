#include <UwUKeypad.h>
#include <Joystick.h>

// Introduccion de variables
int SENSOR;
int RESET;
bool TeclasPresionadas[16];


// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
            16, 0,                    // Botones, Hat switches
            false, false, true,       //Ejes X, Y, Z
            false, false, false,      //Ejes RX, RY, RZ
            false, false,             //Rudder, Throtle
            false, false, false);     //Acelerador, Freno, Direccion


// Crear el Keypad
UwUKeypad teclado = UwUKeypad(2, 3, 4, 5, 6, 7, 8, 9);

void setup()
{
  Serial.begin(9600);
  
  // Inicializo la emulación como Joystick
  Joystick.begin();
}

void loop()
{
  /*SENSOR = analogRead(A0);
  Serial.println(SENSOR);
  delay(500);*/
  
  //TECLA = teclado.getKey();
  botones();
  
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
      Joystick.pressButton(i);
    }
    else
    {
      Joystick.releaseButton(i);
    }
  }
}
