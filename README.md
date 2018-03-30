# sn76489_vgm_player
Very simple VGM player from a SN76489 IC

:Author: pensactius
:Email: pensactius@gmail.com
:Date: 28/03/2018
:Revision: version#
:License: Public Domain

= Project: sn76489_vgm_player

Reproduce la misma cancion en formato VGM almacenada en la Flash.

La cancion viene determinado por el array _vgm_song[] definido en vgmdata.h
que se almacena en la Flash mediante la directive PROGMEM.

El archivo vgmdata.h se ha obtenido con el siguiente comando de linux:

xxd song.vgm > vgmdata.h

donde: 
  xxd es un comando incluído en el editor VIM.

  song.vgm es el archvo VGM. 
  
  Se pueden descargar archivos VGM desde la URL: http://vgmrips.net/packs/chip/sn76489
Ojo que selen estar comprimidos con 7z y hay que descromprimirlos primero.

Debido al tamanyo de la Flash en Arduino UNO el array no puede superar los 30KB approx.
El archivo en este ejemplo ocupa unos 9KB.

== Step 1: Installation
Please describe the steps to install this project.

For example:

1. Open this file
2. Edit as you like
3. Release to the World!

== Step 2: Assemble the circuit

Assemble the circuit following the diagram layout.png attached to the sketch

Conexion SN 76489:

clk (14) ...... Arduino D1
~WE ( 5) ...... Arduino D12
Ready(4) ...... N.C
~CE ( 6) ...... Arduino (D10) (Conectar a GND si se necesita este PIN)
D0 - D7  ...... Arduino D2 - D9
VCC (16) ...... ARduino (+5V)
GND ( 8) ...... Arduino (GND)

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 sketch123                => Arduino sketch folder
  ├── sketch123.ino       => main Arduino file
  ├── schematics.png      => (optional) an image of the required schematics
  ├── layout.png          => (optional) an image of the layout
  └── ReadMe.adoc         => this file
....

=== License
This project is released under a {License} License.

=== Contributing
To contribute to this project please contact pensactius <pensactius@gmail.com>

=== BOM
Add the bill of the materials you need for this project.

|===
| ID | Part name      | Part number | Quantity
| R1 | 10k Resistor   | 1234-abcd   | 10       
| L1 | Red LED        | 2345-asdf   | 5        
| A1 | Arduino Zero   | ABX00066    | 1        
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents. 
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
