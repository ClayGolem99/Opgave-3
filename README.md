Flowchart for SPImaster-transmit(sende)







<img width="395" height="856" alt="image" src="https://github.com/user-attachments/assets/93ecdccd-a28d-460f-a447-b16bf6d48937" />






Når der skrives en byte til SPDR (SPI Data Register), starter transmissionen automatisk. Masteren genererer clock-signal på SCK pinden og sender data ud på MOSI pinden. Programmet venter mens data sendes. Dette tager 8 clock cycles. SPIF (SPI Interrupt Flag) i SPSR (SPI Status Register) sættes automatisk af hardware når transmissionen er færdig. Og  når SPIF = 1 er transmissionen færdig. Hvis ikke, venter programmet og tjekker igen.





Flowchart for Slave-receive(modtage)






<img width="448" height="966" alt="image" src="https://github.com/user-attachments/assets/2474b37c-fcb9-4d52-b706-3ced1afc9e16" />








Som slave venter MEGA2560 på at masteren starter en transmission ved at sende clock-signal. Når masteren har sendt 8 clock pulses og data er modtaget, sættes SPIF bit i SPSR automatisk. Hvis SPIF = 1 er data modtaget. Hvis ikke, fortsætter programmet med at vente. Når SPIF er 1, hentes det modtagne data fra SPDR (SPI Data Register). Funktionen returnerer det modtagne data (char) til den kaldende funktion.


