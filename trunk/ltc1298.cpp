#include "ltc1298.h"
#include "Arduino.h"


void ltc1298_Init(){
  SPI_MasterInit();
}

uint16_t ltc1298_Read(uint8_t mode, uint8_t bitOrder ){
  uint16_t Data_SPI;
  PORTB &= ~DD_SS;
  SPI_MasterTransmit(mode | bitOrder);
  Data_SPI =SPI_MasterTransmit(0)<<5;
  Data_SPI +=SPI_MasterTransmit(0)>>3;
  PORTB |= DD_SS;
return Data_SPI;
}


void SPI_MasterInit(void){
  /* Set SCK, MOSI & SS as outputs, left unchanged others
   (MISO must!!! be set as input as default of SPI master mode) */
  DDRB = DD_MOSI | DD_SCK | DD_SS;
  PORTB |= ((1<<DD_SS)|(1<<DD_MOSI) | (1<<DD_SCK));

  /* Set mode 0, Enable SPI, set clock, master mode and order */
  SPSR &= ~(1<<SPI2X);
  SPCR &= ~((1<<SPIE) | (1<<CPHA) | (1<<DORD)| (1<<CPOL)) ;  
  SPCR |=  (1<<SPE) | (1<<MSTR)  | (1<<SPR1) | (1<<SPR0);
}


uint8_t SPI_MasterTransmit(uint8_t cData){
  SPDR=cData;
  while(!(SPSR & (1<<SPIF)))
    ;
  return SPDR;
}
