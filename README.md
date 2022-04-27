# Freno de mano Analógico + Botonera
Creación de un freno de mano analógico en Arduino con una botonera.

Se utilizará para el caso un ~~Arduino Nano~~ y ~~un sensor magnético de efecto hall~~. La idea es obtener un controlador que simule un freno de mano para simracing que sea preciso ~~y no sufra los defectos de los potenciometros con el tiempo debido al desgaste y la suciedad~~.

Debido a mi inutilidad, tenía el microcontrolador equivocado, así que el proyecto se convierte en un freno con botonera para tener unos botones extra que poder darle cualquier uso. Para ello se empleará un Arduino Leonardo y los mismos sensores, con la librería de *Joystick* se podrá crear un controlador USB.

La botonera consistirá en una matriz de 16 botones que ~~emplea la librería *Keypad* para funcionar, con ella se define la posición de cada uno en una matriz y después se realizarán las consultas para tecla de mi mando virtual~~. Empleaba la librería *Keypad*, gracias al trabajo de [*USERNAME*] *(Muchas gracias ^^)* se ha evitado su uso de forma que se han subsanado los problemas de detección que causaba al principio. 

Debido a que los sensonres de efecto hall no eran precisos de forma analógica y para simplificar el proyecto, se utilizará finalmente un potenciometro clásico lineal.
Por otro lado, se incorporarán dos interruptores de palanca y otro con forma de llave de contacto para tener otros tantos botones extra con funciones más concretas.
