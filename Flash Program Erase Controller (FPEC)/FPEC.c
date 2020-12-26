/*
 * FPEC.c
 *
 *  Created on: Aug 20, 2020
 *      Author: Hesham Elsherbieny
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC.h"

/* KEYS used for unlocking flash memory to authorize FPEC to deal with it*/
#define KEY1				((uint32_t)0x45670123)
#define KEY2				((uint32_t)0xCDEF89AB)

/* When option byte is programmed with this KEY, read access to the Flash memory is allowed */
#define RDPRT_KEY			((uint16_t)0x00A5)


/************************************* FLASH Registers ******************************************/

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 OBR;
	u32 WRPR;
}FLASH_t;


/**************************** FLASH Memory Interface Base Address *******************************/
#define FLASH ((volatile FLASH_t*)0x40022000)


/**************************** Static Functions Implementation ***********************************/


/* This function shall get Current FLASH Operation Status */
static FlashStatus_t GetFlashStatus(void)
{
	FlashStatus_t status = FLASH_COMPLETE;

	switch(FLASH->SR & FLASH_SR_MASK)
	{
		case FLASH_SR_BSY:      status = FLASH_BUSY;      break;
		case FLASH_SR_PGERR:    status = FLASH_PG_ERROR;  break;
		case FLASH_SR_WRPRTERR: status = FLASH_WRP_ERROR; break;
		case FLASH_SR_EOP:      status = FLASH_COMPLETE;  break;
		default:                status = FLASH_COMPLETE;  break;
	}
	/* Return FLASH Operation Status */
	return status;
}

/* This Function shall wait until current flash operation is completed or a timeout occurred */
static FlashStatus_t WaitForOperation(void)
{
  FlashStatus_t status = FLASH_COMPLETE;
  uint8_t TimoutCounter = OP_WAIT_TIMEOUT;

  /* Wait for a Flash operation to complete or a TIMEOUT to occur */
  do
  {
	  /* Check and update the Flash Status */
	  status = GetFlashStatus();
	  /* Decrement Timeout Counter each loop*/
	  TimoutCounter--;

  }while((status == FLASH_BUSY) && (TimoutCounter != 0x00));

  /* In case of Timeout occurrence */
  if(TimoutCounter == 0x00 )
  {
    status = FLASH_TIMEOUT;
  }
  /* Return the operation status */
  return status;
}
/***** Implementation of Public APIs Used to Perform FPEC Basic Operations on FLASH Memory *****/

/* This API shall do the unlocking procedure sequence to deal with FLASH*/
FlashStatus_t FLASH_Unlock(void)
{
	FlashStatus_t status = FLASH_BUSY;

	/* Doing the unlocking operation sequence by writing KEY1 then key2 to KEYR register*/
	FLASH->KEYR = KEY1;
	FLASH->KEYR = KEY2;

	/* Wait to verify  */
	//status = WaitForOperation();

	return status;
}

/* This API shall lock FLASH after being unlocked */
FlashStatus_t FLASH_Lock(void)
{

}

