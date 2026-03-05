/*
 * SPI.c
 *
 * Created: 27-02-2026 17:38:28
 *  Author: nazih
 */ 
#include "SPI.h" //Inkluder SPI.h filen

void SPI_MasterInit(void) {
	DDRB |= (1<<DDB2) | (1<<DDB1) | (1<<DDB0); // Sæt MOSI (PB2), SCK (PB1) og SS (PB0) som output
	// SPE: Enable SPI
	// MSTR: Sæt som Master
	// CPOL: 1 (Clock er høj som default - krav i opgaven)
	// SPR1: 1 (Divider 64 giver 250kHz ved 16MHz clock)
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<CPOL) | (1<<SPR1);
}

void SPI_MasterTransmit(char cData) {
	// Start transmission ved at skrive til dataregisteret
	SPDR = cData; 
	// Vent på at transmissionen er færdig (SPIF bitten i SPSR bliver 1)
	while(!(SPSR & (1<<SPIF)));
}

void SPI_SlaveInit(void) {
	DDRB |= (1<<DDB3);	// Sæt MISO (PB3) som output
	SPCR = (1<<SPE); // Enable SPI (MSTR er 0 som standard, så den bliver slave)
}

char SPI_SlaveReceive(void) {
	while(!(SPSR & (1<<SPIF))); // Vent på at der er modtaget data
	return SPDR;// Returner det modtagne tegn fra dataregisteret
}