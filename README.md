# ARDUINO - ATTINY - WIRELESS - IOT

Table of contents
=================

* [IoT with Arduino and RPi](#iot-with-arduino-and-rpi)
* [Wifi module ESP8266](#wifi-module-esp8266)
* [NRF24l01](#nrf24l01)
* [Funduino mini pro](#funduino-mini-pro-atmega328p)
* [ATtiny85](#attiny85)
* [Transmision de video en tiempo real](#transmision-de-video-en-tiempo-real)

IoT with Arduino and RPi
----------------------------

### Raspberry (gateway) and Arduino (node sensor)

Ejemplo de arquitectua hardware:

![alt tag](static/Arduino_Raspberry_Arch.jpg)


[Fuente - parte 1](http://thenewstack.io/tutorial-prototyping-a-sensor-node-and-iot-gateway-with-arduino-and-raspberry-pi-part-1/)

[Fuente - parte 2](http://thenewstack.io/tutorial-configuring-a-sensor-node-and-iot-gateway-to-collect-and-visualize-data-part-2/)


Wifi module ESP8266
--------------------

Sirven para añadir WIFI al microcontrolador

- Se alimenta a 3.3v
- Alimentarlo con una fuente externa al Arduino, tiene picos de 200ma (al arrancar).
- Es un SoC: microcontrolador más wifi.


![alt tag](static/WiFi-Serial-Transceiver-Module-ESP8266.jpg)
![alt tag](static/esp8266-pinout-800x379.jpg)


[Comparando Arduino y el ESP8266](http://polaridad.es/compara-arduino-esp8266/)


NRF24l01
-----------

[Tutorial](http://www.prometec.net/nrf2401/)

Dispositivos de radio basados en el chip de Nordic semiconductor  NRF24.

Estos modulos son TRANCEPTORES, es decir mediante programacion los podemos poner como emisores o como receptores o configurarlos para que hagan ambas cosas. Puede llegar a transmitir datos a 2Mbps , en distancias menores a 40 metros al aire libre y a 1Mbps a 8 metros de distancia.

- Operan en la banda de 2.4Ghz, que es de libre uso a nivel mundial (no tenemos garantía de que no haya alguien más emitiendo en esta banda en las cercanías, lo que puede producir interferencias)
- Velocidad configurable de 250kb, 1 Mb o 2Mb por segundo.
- Muy bajo consumo en Stand By (Cuando no se usan
- Podemos encontrar modelos con antenas más eficaces que aumentan el alcance hasta casi un km.
- Estos módulos usan el bus SPI.

[Arduino driver for nRF24L01](https://github.com/maniacbug/RF24)

![alt tag](static/24L01Pinout-800-500x229.jpg)

| PIN   |  Arduino uno      |
|----------|:-------------:|
| MOSI | 11 |
| MISO | 12 |
| SCK | 13 |
| CS | 10 |
| CE | 9 |

### Soluciones a posibles problemas

- Es muy conveniente conectar un capacitor de 10NanoFaradios entre VCC y GND, para eliminar el ruido
Alimentacion a 3.3V o 5V.
- La manera más sencilla de evitar problemas ha sido asegurarme de que el emisor tiene una alimentación correcta y abundante, mediante un alimentador externo (al arduino).


Funduino pro mini ATMEGA328P
----------------------------
![alt tag](static/funduino-pro-mini-pinout.png)
Alimentación: 3.3V o 5V


ATtiny85
--------------

![alt tag](static/attiny85pinout1.png)

### Programar el ATtiny

Los microcontroladores AVR permiten la programación "in circuit". (ISP). No es necesario extraer el microcontrolador
de la placa de circuito impreso para reprogramarlo.


- binutils-avr --> herramientas como el ensamblador, enlazador, etc.
- gcc-avr --> compilador C GNU (compatible con ANSI C)
- avr-libc --> librería AVR C
- gdb-avr --> debugger
- avr-dude --> programador
- AVRStudio --> descarga gratis desde www.atmel.com (solo Windows)

```bash
$ apt-get install avrdude binutils-avr gcc-avr avr-libc gdb-avr

# Compilar 
$ avr-gcc -g -Os -mmcu=attiny88 -c hola_mundo_attiny85.c
$ avr-gcc -g -mmcu=attiny88 -o hola_mundo_attiny85.out hola_mundo_atttiny85.o

# Crear el hex. 
$ avr-objcopy -j .text -O ihex hola_mundo_atttiny85.out hola_mundo_attiny85.hex

# cargar el .hex en el attiny usando un programador.
```
Programa básico
```c
#include<avr/io.h>

int main(void)
{
        for(;;)
        {

        }
}

```
Programador ISP

![alt tag](static/programador-usbasp-isp-para-atmel-avr.jpg)

Pinout
![alt tag](static/attiny_pinout_programmer.png)

1. MISO
2. Vcc
3. SCK
4. MOSI
5. Reset
6. Ground




### Programar el ATtiny con arduino

[Programar el ATtiny con Arduino](http://aerobotclubderobticadeaeronuticos.blogspot.com.es/2011/06/micros-pequenos-para-proyectos-pequenos.html)

[Programming an ATtiny with arduino](http://highlowtech.org/?p=1229)

Utilizamos el arduino como programador ISP
- Descárgate y copia la carpeta (attiny45_85.zip) en la carpeta Hardware en la carpeta del Arduino. (...\arduino-0022\hardware\attiny45_85)
- Cierra el programa y vuelve abrirlo. Comprobaras que ahora en Tools/Board, te han aparecido muchas más opciones que antes.
- Monta el circuito de la figura:

![alt tag](static/attiny_program_with_arduino.png)

- Conecta tu tarjeta de Arduino al ordenador: selecciónala en Board y el Puerto Serie que le corresponde.
- En la sección de “Ejemplos” de Arduino abre, compila y descarga a tu tarjeta el ejemplo de ArduinoISP (le estamos diciendo al Arduino que funcione como granador).
- Seleccionaremos en Tools/Board/ ATtinny85 (w/Arduino as ISP).
- Darle al botón de descargar programa.
- El ATTiny ya esta programado y listo para ser usado.

### Pinout ATtiny44_85

[Tutorial ATtiny 85](http://www.raspberrypi-es.com/category/attiny85/)

![alt tag](static/attiny_44_84_Pinout.png)

### Transmision de video en tiempo real

Fuente: transmisión de video desde drones.

ELEMENTOS
- Camara o micro-camara --> resolución, angulo de visión, a 12v o 5v(las micro), proteger la electrónica
- Transmisor de video
- Receptor de video
- Receptor de radiocontrol
- Monitor, LCD, TFT ...

CAMARA CCD, CMOS, FPV, CMOS HD, etc
- En una camara CCD, la lente recoge la luz y la enfoca hacia un sensor de imagen (CCD  ó CMOS) que convierte la luz en pulsos eléctricos para más tarde  procesarlos mediante circuitos electrónicos y poder crear así la señal de video.
- Color y "blanco y negro"
- Medio de transmisión: inalambrio por radiofrecuencia
- Señal digital
- Número de pixeles: 128x128 
- Captar video, imagenes o sonido
- FPV --> First Person View
- VTX --> Video transmiter
- VRX --> Video receiver
- Camara FPV --> frecuencias: 900 Mhz, 1.2 ghz, 1.3 ghz, 2.4 ghz y 5.8 ghz
- No puede haber latencia (por eso es tiempo real)

CODECS y COMPRESIÓN
- Los códecs MPEG (Moving Picture Experts Group ), el MPEG-2, sucesor del MPEG-1 que permite transmitir a velocidades entre  4 y 9 kbps y es capaz de soportar televisión en alta definición (HDTV).

TRANSMISIÓN DE LA SEÑAL
- Partes de la modulación
Señal de imagen
Señal de sincronización de video
Señal de voz
Señal de información de control

- Tarjeta de radiofrecuencia halfduplex 100kbps
El enlace se controla por una Raspberry Pi
La camara se controla con un servomotor

SISTEMA REAL

  [Fuente](http://www.dronesbaratoscaseros.com/) 
  
  [Video](https://www.youtube.com/watch?v=kKph_ks6C2M)

 - Transmisor (400mW) --> Boscam FPV 5.8G 400mW AV Transmitter Module TS353
 - Transmisor (200mW) --> TS351 (FPV 5,8 GHz 200mw) --> unos 12€
 - Transmisor (600mW) --> Eachine TX600 FPV 5.8GHz 600mW 32CH AV Transmitter Mushroom Antenna --> 32€
 - Receptor --> Eachine RC832 Boscam FPV 5.8GHz 32CH Wireless AV Receiver --> 19€
 - Receptor --> FR632 (FPV 5.8 GHz 32 canales), el tipo de antena es importante viene con unas baratas --> unos 70€-80€
 - Receptor --> RC305 (FPV 5.8 GHz 8 canales 200mW) --> unos 15€
 - Camara --> DAL 700TVL FPV HD 1/4' CMOS (12V) --> 8€
 - Camara --> Eachine 700TVL 2.8mm CMOS (5-12V) --> 12€
 - Camara --> Tarot 12V 600TVL 120° 2.8mm FPV Camera TL300M PAL --> 16€
 - Antenas --> 5.8G Gain Petals Clover Mushrooms Antenna Set For FPV System --> 7€
 - Monitor (5 pulgadas) --> Blue Sky 5 Inch HD Digital Panel Display 800x480 Snowflakes Screen --> 29€
 - Monitores para FPV --> http://www.banggood.com/search/fpv-monitor.html?p=722409786759201409UR
 - Bateria recargable (2200 ma) --> ZOP Power 11.1V 2200MAH 8C Lipo Battery For Devo JR WFLY Transmitter --> 11€
 - Bateria recargable (1300 ma) --> Ace High Quality 11.1v 1300mah 25c lipo battery --> 20€
 - Grabador de viceo --> 1CH Mini DVR C-DVR Motion Detection Video Radio Recorder --> 28€
 - Camara + transmisor --> Eachine 700TVL 1/3 Cmos FPV 148 Degree Camera w/32CH Transmission --> 25€
 - Camara +`transmisor --> Eachine 700TVL 1/3 Cmos FPV 110 Degree Camera w/32CH Transmission --> 20€
 - Transmisor + receptor --> Boscam FPV 5.8G 400mW AV Receiver RC805 with Transmitter TS353 --> 55€
 - Cargador de baterias LIPO --> Imax b6-ac cargador del balance de la batería de NiMH 3s lipo B6AC rc --> 32€
 - Cargador de baterias LIPO --> SKYRC E3 2S 3S LiPo AKKU Battery Balance Charger AC 110V-240V --> 10€
 - Separadores de nailon --> M3 Nylon Hex Spacers Screw Nut Assortment Kit Accessories Set --> 6€










