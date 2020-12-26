/*
 * FPEC.h
 *
 *  Created on: Aug 20, 2020
 *      Author: Hesham Elsherbieny
 */

#ifndef FPEC_H_
#define FPEC_H_

/* Maximum Waiting Time for underlying FPEC Operation, after which a timeout occurs */
#define  OP_WAIT_TIMEOUT 	(uint8_t)0x05

/*************************** Type definition for each flash Status *******************************
 Range:-
  			1-FLASH_BUSY
			2-FLASH_PG_ERROR
			3-FLASH_WRP_ERROR
			4-FLASH_TIMEOUT
			5-FLASH_COMPLETE
*/
typedef uint8_t FlashStatus_t;

#define FLASH_BUSY			(FlashStatus_t)1
#define FLASH_PG_ERROR		(FlashStatus_t)2
#define FLASH_WRP_ERROR		(FlashStatus_t)3
#define FLASH_TIMEOUT		(FlashStatus_t)4
#define FLASH_COMPLETE		(FlashStatus_t)5


/*  Macros for FLASH Status Register Bits */
#define FLASH_SR_MASK		(uint32_t)0x000000FF
#define FLASH_SR_BSY		(uint32_t)0x00000001
#define FLASH_SR_PGERR		(uint32_t)0x00000004
#define FLASH_SR_WRPRTERR	(uint32_t)0x00000010
#define FLASH_SR_EOP		(uint32_t)0x00000020

/******* Prototypes for Public APIs Used to Perform FPEC Basic Operations on FLASH Memory *******/

/* This API shall do the unlocking procedure sequence to deal with FLASH*/
FlashStatus_t FLASH_Unlock(void);

/* This API shall lock FLASH after being unlocked */
FlashStatus_t FLASH_Lock(void);


#endif /* FPEC_H_ */
