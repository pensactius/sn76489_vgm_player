#include <Arduino.h>
#include "sn76489.h"

void _set_bus_out();

void SetClock() {

  // Inicializa D11 (PB3) como salida
   DDRB  |=  _BV(PORTB3);
  // Toggle OC2A on compare match
  TCCR2A &= ~_BV(COM2A1);
  TCCR2A |=  _BV(COM2A0);
  // Clear Timer on Compare match
  TCCR2B &= ~_BV(WGM22);
  TCCR2A |=  _BV(WGM21);
  TCCR2A &= ~_BV(WGM20);
  // Use CLK I/O without prescaling
  TCCR2B &= ~_BV(CS22);
  TCCR2B &= ~_BV(CS21);
  TCCR2B |=  _BV(CS20);
  // Divide the 16MHz clock by 8 -> 2MHz
  OCR2A = DIV_4MHz; 
}

void WriteData(char data) {
/*
El bus de datos está conectado de la siguiente manera:

  7   6   5   4   3   2   1   0     sn76489 data 
PB1  PB0 PD7 PD6 PD5 PD4  PD3 PD2   Avr naming)
 D9   D8  D7  D6  D5  D4   D3  D2   Arduino naming

Por tanto hay que seleccionar los bits y posicionarlos correctamente
a la hora de enviarlos por el puerto correspondiente (PORTD o PORTB).

*/
  // Envia bits 5-0 a PD7-PD2
  PORTD = (PORTD & 0x02) | ( (data & B00111111) << 2 );
  
  // Envia bits 7-6 a PB1-PB0
  PORTB = (PORTB & 0xfc) | ( (data & B11000000) >> 6 );
  
  // ~WE y ~CE a low (Active)
  PORTB &= B11101011;
  
  _delay_us (10);
  // ~WE y ~CE a high (InActive)
  PORTB |= B00010100;
}

void SetBUS() {
  
  DDRB |= 0x17; // Bits PB4, PB2, PB1 and PB0 (D12, D10, D9,D8) como Salida
  DDRD |= 0xfc; // Bits PD2 to PD7  (D2-D7) como Salida

  // ~WE y ~CE a high (InActive)
  PORTB |= B00010100;
}

void SN76489_Off() {
  WriteData(B10011111);
  WriteData(B10111111);
  WriteData(B11011111);
  WriteData(B11111111);
}