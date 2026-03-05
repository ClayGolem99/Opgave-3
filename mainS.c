/*
 * spi_slave.c
 *
 * Created: 26-02-2026 11:40:41
 * Author : nazih
 */ 

#include <avr/io.h>
#include "I2C.h"      // Bibliotek til I2C driver (bruges af display)
#include "ssd1306.h"  // Bibliotek til OLED display driver
#include "SPI.h"      // Din egen SPI driver header-fil

int main(void)
{
	_i2c_address = 0X78; // Sæt I2C adresse for displayet
	I2C_Init(); // Initialiser I2C
	InitializeDisplay(); // Initialiser OLED displayet
	clear_display(); // Ryd skærmen før start
	
	SPI_SlaveInit(); // Initialiser MEGA2560 som SPI-slave
	char val = 0; // Variabel til at gemme modtaget data
	while (1)
	{
		val = SPI_SlaveReceive();// Vent på at modtage et tegn fra Masteren
		sendCharXY(val, 0, 0); // Skriv det modtagne tegn ud på OLED-displayet på position (0,0)
	}
}
