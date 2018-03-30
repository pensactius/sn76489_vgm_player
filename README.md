# sn76489_vgm_player
Reproductor de ficheros VGM muy simple usando el chip SN76489

Reproduce la misma cancion en formato VGM almacenada en la Flash.

La cancion viene determinado por el array `_vgm_song[]` definido en *vgmdata.h*
que se almacena en la Flash mediante la directive `PROGMEM`.

El archivo *vgmdata.h* se ha obtenido con el siguiente comando de linux:

`xxd song.vgm > vgmdata.h`

donde: 

  `xxd` es un comando incluído en el editor VIM.

  `song.vgm` es el archvo VGM. 
  
  Se pueden descargar archivos VGM desde la URL: http://vgmrips.net/packs/chip/sn76489
  
Ojo que selen estar comprimidos con 7z y hay que descromprimirlos primero.

Debido al tamaño de la Flash en Arduino UNO el array no puede superar los 30KB approx.

El archivo en este ejemplo ocupa unos 9KB.

## Conexiones

Conexion SN 76489:
`
clk (14) ...... Arduino D1

~WE ( 5) ...... Arduino D12

Ready(4) ...... N.C

~CE ( 6) ...... Arduino (D10) (Conectar a GND si se necesita este PIN)

D0 - D7  ...... Arduino D2 - D9

VCC (16) ...... ARduino (+5V)

GND ( 8) ...... Arduino (GND)

`

## Contenido del directorio
`
....

 sn76489_vgm_player                => Carpeta del proyecto Arduino
 
  ├── sn76489_vgm_player.ino       => Fichero principal Arduino
  
  ├── sn76489.h/.cpp               => Funciones de control y escritura al IC sn76489
  
  ├── VGMPlayer.h/.cpp             => Funciones para reproducir el archivo de música
  
  ├── vgmdata.h                    => Volcado del archivo VGM en formato de array (vgm_song[])
  
  └── Readme.md                    => Este archivo
  
....
`
