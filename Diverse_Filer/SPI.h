/*
 * SPI.h
 *
 * Created: 27-02-2026 17:35:42
 *  Author: nazih
 */ 


#ifndef SPI_H_
#define SPI_H_

	void SPI_MasterInit(void); // Opsætter MEGA2560 som Master	
	void SPI_MasterTransmit(char cData); // Sender en byte data
	void SPI_SlaveInit(void); // Opsætter MEGA2560 som Slave
	char SPI_SlaveReceive(void); // Modtager en byte data

#endif /* SPI_H_ */
