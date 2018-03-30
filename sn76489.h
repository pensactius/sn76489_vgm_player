#ifndef __SN76489_H__
#define __SN76489_H__

#define DIV_4MHz  2 // No. de bits para conseguir 4MHz a partir de 
                    // la señal de reloj de 16MHz de Arduino.

// Crea una señal de clk de 4MHz por el pin 11.
void SetClock();

// Establece el volumen de los cuatro canales al minimo
void SN76489_Off();

// Envia 8 bits de datos por el BUS
void WriteData(char data);

// Configura el BUS como salida
void SetBUS();

#endif