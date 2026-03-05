/*
 * spi_demo.c
 *
 * Created: 26-02-2026 11:31:28
 * Author : nazih
 */ 

#include "SPI.h"
#include <avr/io.h>

int main(void) {
    SPI_MasterInit(); // Initialiserer SPI som master (hentes fra SPI.c)
    
    while(1) {
        SPI_MasterTransmit('a'); // Sender tegnet 'a' (hentes fra SPI.c)
    }
}