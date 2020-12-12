/*
 * SPI_program.c
 *
 *  Created on: Apr 22, 2020
 *      Author: Hesham Elsherbieny
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"

void SPI1_Init(void)
{
	/*
	 * phase = write then read
	 * polarity = idle low
	 * master mode
	 * BR-> PAB2 CLK /4
	 * SPI Enabled and MSB is first transmitted
	 * 8-Bit Data transmission
	 * SS is managed by SW (NSS Pin is disconnected and SSI is working instead)
	 * */
	SPI1 -> CR1 = 0x034D;
}

u8 SPI_SendSynch(u8 data)
{
	/* Send Data*/
	SPI1 -> DR = (u32) data;

	/* Wait for busy flag */
	while(GET_BIT((SPI1->SR),7) == 1);

	return (SPI1 -> DR);
}

