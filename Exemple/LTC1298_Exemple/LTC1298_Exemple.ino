/*
 *******************************************************
 *  Name:		LTC1298 Exemple	
 *
 *  Author:		Joan Martínez
 *
 *  Start Date:         1 Sept 2012        
 *
 *  Version Date:       1 Sept 2012 
 *
 *  Description:	Arduino as SPI Master controlling
 *                      an ADC LTC1298 from Linear Technology.
 *			The library includes SPI driver. Take 
 *			that in acount.
 *  Platform:           Arduino (Any...)
 *
 *******************************************************/

#include <ltc1298.h>

#define MEASURES 100

long int value;	     /* Stores the read value */


void setup(){
  Serial.begin(9600);  /* Inicialize serial port */
  ltc1298_Init();      /* Inicialize the comunication with LTC1298 */
}


void loop(){
	/* Make 100 measures. Every read value 
	is added to the former one and then the 
	total is divided by 100. The result is 
	mapped and presented in a convenient way */

  value=0;
  for(int i=0; i<MEASURES; i++) value+=ltc1298_Read(CH0, MSB); /* ltc1298_Read() sends the 4-bit
								   programming word for LTC1298
								   and reads the Data from it */
  value=value/MEASURES;
  uint16_t newValue=map(value,0,4095,0,4899);
  uint8_t integerValue=newValue/1000;
  uint16_t decimalValue=newValue-1000*integerValue;
  Serial.print(integerValue);
  Serial.print('.');
  if(decimalValue<100) Serial.print('0');
  if(decimalValue<10) Serial.print('0');
  Serial.print(decimalValue);
  Serial.println(" V");  
  delay(1000);
}

