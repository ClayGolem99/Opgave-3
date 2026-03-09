

#include <avr/io.h>
#include <math.h>
#define F_CPU 16000000UL // set Clock at 16MHz as sync clock //can also be set as 16e6
#include <util/delay.h>
#include <stdio.h> //using sprintf for formatting integers to ascii into an array
#include <stdlib.h>

#include "I2C.h"  //include library for i2c driver
#include "ssd1306.h" //include display driver
#include "SPI.h"

// Vi bruger SPI Mode 1, da CPOL = 0, da det ikke skal trække fra 5V

// static inline uint8_t SPItransfer(uint8_t tx)
// {
// 	SPDR = 0x00;
// 	while(!(SPSR & (1<<SPIF)));
// 	
// 	return SPDR;
// 	
// }


uint16_t getRawData(uint8_t data[2])
{
	int i; //init index i
	uint8_t MSB, LSB; //init Most- and lowest significant bits
	
	PORTB &=~ (1<<PB0); // set cs (ss-not to low)
	//ss clock frequency
	// cs is connected to pin 6 and on Atmega it is set to pin ss
	// for ss-not to low
	
	/*SPItransfer;*/
		for (i=0; i < 2; i++)
		{
			SPDR =0x00; //Serial Peripheral Data Register set to 0
			while (!(SPSR & (1<<SPIF)));
			
			// is data transmitted
			data[i] = SPDR;	
		}
  
		MSB = data[0];
		LSB = data[1];
		
		PORTB |= (1<<PB0);
		
		return ((uint16_t) MSB << 8)| LSB;
		

	
}


 SPI_init();
{
	DDRB |= (1<<PB0); //!SS er output
	//SPI enable + master mode(i hvor?)
	
	//Anvende mode 1 for CPOL != 5V for rising edge)
	
	// SCLK/MOSI som output
	
}

int main(void)
{ 
	SPI_init();
	
	int i;
	
	uint8_t data[2];
	
	getRawData(data);	
	
	
	
	
}
