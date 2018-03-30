#include <Arduino.h>
#include "vgmdata.h"  // _vgm_song: datos VGM de musica
#include "VGMPlayer.h"
#include "sn76489.h"

// Declaracion forward (su implementacion esta definida al final del fichero)
uint32_t _read_vgm_data32(uint8_t* addr); // Read 32bits from Flash memory
uint32_t _read_vgm_data(uint8_t* addr);   // Read 8bits from Flash memory

// 
uint32_t vgm_data_offset = (uint32_t) _vgm_song[0x34];
unsigned long parseLocation = 0x34 + vgm_data_offset;
uint8_t addr, data;

void Play() {
  
  while (1) {
    //Serial.print(parseLocation, HEX); Serial.print(": "); 
    data = _read_vgm_data (_vgm_song + parseLocation);
    if (parseLocation == 0x34+vgm_data_offset) {
      Serial.println("Begin Play");
    }
    /*Serial.print("(");
    Serial.print(data, HEX);
    Serial.print(" ");
    */
    
    // Interpreta los diferentes comandos VGM
    switch (data) {
      
      // 0x50 dd : SN76489 Escribe valor dd 
      case 0x50:
        ++parseLocation;
        data = _read_vgm_data(_vgm_song + parseLocation++);
        WriteData (data);
        //Serial.print("data: "), Serial.println(data, HEX);
        break;
      
      case 0x61:
      {
        ++parseLocation;
        uint8_t lo = _read_vgm_data (_vgm_song + parseLocation++);
        uint8_t hi = _read_vgm_data (_vgm_song + parseLocation++);
        uint32_t wait = (uint32_t)word (hi, lo);
        delay (1000 * wait / 44100);
        break;
      }
      case 0x62:
        ++parseLocation;
        delay (WAIT60TH);
        break;
        
      case  0x70:
      case  0x71:
      case  0x72:
      case  0x73:
      case  0x74:
      case  0x75:
      case  0x76:
      case  0x77:
      case  0x78:
      case  0x79:
      case  0x7A:
      case  0x7B:   
      case  0x7C:
      case  0x7D:
      case  0x7E:
      case  0x7F:
      {
        ++parseLocation;
        uint32_t wait = data & 0x0F;
        delay (1000 * wait / 44100);
        break;
      }
      //0x66 : End of Sound Data
      case 0x66:
      {
        uint32_t loopOffset = _read_vgm_data32 (_vgm_song + 0x1C);
        parseLocation = loopOffset + 0x1C;
        Serial.println("End of Song Data (Loop)");
        //return;
        break;
      }
        
      default:
        ++parseLocation;
        Serial.print(parseLocation, HEX); Serial.print(": "); 
        Serial.print("(");
        Serial.print(data, HEX);
        Serial.print(" ");
        Serial.println("UNKNOWN cmd!");
        SN76489_Off();
    } // switch
  } // while
}

uint32_t _read_vgm_data32(uint8_t* addr) {
  return pgm_read_dword_near (addr);
}

uint32_t _read_vgm_data(uint8_t* addr) {
  return pgm_read_byte_near (addr);
}