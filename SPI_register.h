/*
 * SPI_register.h
 *
 *  Created on: Apr 22, 2020
 *      Author: Hesham Elsherbieny
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/* SPI1 Peripheral Base Address is 0x40013000 */

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_REG;


#define SPI1 ((volatile SPI_REG*)0x40013000)


/*

#define SPI_CR1		         (*(volatile*)0x40013000)
#define SPI_CR2		         (*(volatile*)0x40013004)
#define SPI_SR		         (*(volatile*)0x40013008)
#define SPI_DR		         (*(volatile*)0x4001300C)
#define SPI_CRCPR	         (*(volatile*)0x40013010)
#define SPI_RXCRCR	         (*(volatile*)0x40013014)
#define SPI_TXCRCR	         (*(volatile*)0x40013018)
#define SPI_I2SCFGR	         (*(volatile*)0x4001301C)
#define SPI_I2SPR	         (*(volatile*)0x40013020)
*/
#endif /* SPI_REGISTER_H_ */
