/********************************************************************************************
 *                                                                                          *
 * File Name   : RCC.c                                                                      *
 *                                                                                          *
 * Author      : Hesham Elsherbieny                                                         *
 *                                                                                          *
 * contacts:   : h.elsherbieny@gmail.com					                                *
 *                                                                                          *
 * Date        : Jan 2020                                                                   *
 *                                                                                          *
 * Version     : 2.1.2                                                                      *
 *                                                                                          *
 * Description : specifies Reset and Clock Control (RCC) module and the required macros and *
 *               needed APIs for Cortex M3 STM32F103 microcontroller                        *                                                       *
 *                                                                                          *
 ********************************************************************************************/

#include "STD_TYPES.h"

#include "RCC.h"

/*********************************RCC Registers**************************************/
typedef struct
{
	u32 CR;        
	u32 CFGR;      
	u32 CIR;       
	u32 APB2RSTR;  
	u32 APB1RSTR;  
	u32 AHBENR;    
	u32 APB2ENR;   
	u32 APB1ENR;   
	u32 BDCR;      
	u32 CSR;       
}RCC_Reg;

/******* RCC Base Address ************/
#define RCC ((volatile RCC_Reg*)0x40021000)

/* This API shall Enable High Speed Clock Source          */
ERROR_t RCC_EnablelHSClock(u32 RCC_HSClockName)
{
  ERROR_t Status = NOK;
  u32 ClkFlag;
	/*	Set the clock on bit */
	RCC->CR |= RCC_HSClockName;
	/*	Check the clock ready bit till rise
	* to make sure the clock is enabled*/
  switch(RCC_HSClockName)
  {
    case HSION : ClkFlag = HSIRDY; break;
    case HSEON : ClkFlag = HSERDY; break;
    case HSEBYP: ClkFlag = HSEBYP; break;
    case PLLON : ClkFlag = PLLRDY; break;
    default: ClkFlag = HSIRDY; break;
  }
	while(!(RCC->CR & ClkFlag));
	Status = OK;
  
	return Status;
}

/* This API shall Disable High Speed Clock Source          */
ERROR_t RCC_DisablelHSClock(u32 RCC_HSClockName)
{
  ERROR_t Status = NOK;
  u32 ClkFlag;
  /*	Clear the clock on bit */
	RCC->CR &= ~RCC_HSClockName;
	/*	Check the clock ready bit till clear
	*to make sure the Clock is disabled	*/
  switch(RCC_HSClockName)
  {
    case HSIOFF: ClkFlag = HSIRDY; break;
    case HSEOFF: ClkFlag = HSERDY; break;
    case HSEBYP: ClkFlag = HSEBYP; break;
    case PLLOFF: ClkFlag = PLLRDY; break;
    default: ClkFlag = HSIRDY; break;
  }
	while(RCC->CR & ClkFlag);
	Status = OK;
  
  return Status;
}

/*  This API shall configure system clock source Switch               */
ERROR_t RCC_SetSysClk(u32 RCC_ClockName)
{
  ERROR_t Status = NOK;
  u32 Clk_SWS;
	/*Clear System clock switch bits*/
	RCC->CFGR &= CLK_CLR;
	/*Select System clock switch name*/
	RCC->CFGR |= RCC_ClockName;
  switch(RCC_ClockName)
  {
    case HSI: Clk_SWS = HSI_SWS; break;
    case HSE: Clk_SWS = HSE_SWS; break;
    case PLL: Clk_SWS = PLL_SWS; break;
    default:  Clk_SWS = HSI_SWS; break;
  }
	/*Check if the clock is selected*/
	if((RCC->CFGR & CLOCK_STATUS) == Clk_SWS )
	{
		Status = OK;
	}
	return Status;
}

/*  This API shall configure PLL source clock select */
ERROR_t RCC_ConfigPLL(u32 RCC_SrcClkName, u8 RCC_PLL_Mul)
{
	ERROR_t Status = NOK;
	u32 TempRegVal=0;


	/* load value of CFGR register */
	TempRegVal  = RCC->CFGR;

	/* Clear PLL CLK source bit */
	TempRegVal &= PLL_CLRSRC;
	/* Clear PLL MUL bits before applying the needed value */
	TempRegVal &= PLLMUL_CLR;

	/* SET PLL CLK source bits to the needed clock source */
	TempRegVal |= RCC_SrcClkName;
	/* SET PLL MUL Factor bits to the needed prescaler value */
	TempRegVal |= RCC_PLL_Mul;

	/* Assign the value after being changed to the Clock source
	 * and multiplier to CFGR Register */
	RCC->CFGR = TempRegVal;

	Status = OK;
	return Status;

}


/*  Description : This API shall Enable Low Speed Clock Source  */
ERROR_t RCC_EnablelLSClock(u32 RCC_LSClockName)
{
	ERROR_t Status = NOK;
	u32 ClkFlag;
	u32 Local_RccReg;

	/* Set the clock on bit */
	switch(RCC_LSClockName)
	{
	case LSI   :
		RCC->CSR    |= LSION;
		ClkFlag      = LSIRDY;
		Local_RccReg = RCC->CSR;
		break;
	case LSE   :
		RCC->BDCR   |= LSEON;
		ClkFlag      = LSERDY;
		Local_RccReg = RCC->BDCR;
		break;
	case LSEBYP:
		RCC->BDCR   |= LSEBYP;
		ClkFlag      = LSEBYP;
		Local_RccReg = RCC->BDCR;
		break;
	default:
		ClkFlag      = LSIRDY;
		Local_RccReg = RCC->CSR;
		break;
	}
	/* Check the clock ready bit till rise
	 * to make sure the Clock is enabled */
	while(!(Local_RccReg & ClkFlag));
	Status = OK;

	return Status;
}

/*  Description : This API shall Disable Low Speed Clock Source        */
ERROR_t RCC_DisablelLSClock(u32 RCC_LSClockName)
{
  ERROR_t Status = NOK;
  u32 ClkFlag;
  u32 Local_RccReg;

  /* Clear the clock on bit */
  switch(RCC_LSClockName)
  {
    case LSI   :
    	RCC->CSR    &= ~LSION;
    	ClkFlag      =  LSIRDY;
    	Local_RccReg =  RCC->CSR;
    	break;
    case LSE   :
    	RCC->BDCR   &= ~LSEON;
    	ClkFlag      =  LSERDY;
    	Local_RccReg =  RCC->CSR;
    	break;
    case LSEBYP:
    	RCC->BDCR   &= ~LSEBYP;
    	ClkFlag      =  LSEBYP;
    	Local_RccReg =  RCC->CSR;
    	break;
    default:
    	ClkFlag      = LSIRDY;
    	Local_RccReg = RCC->CSR;
    	break;
  }
  /* Check the clock ready bit till clear
   * to make sure the Clock is disabled */
	while(Local_RccReg & ClkFlag);
	Status = OK;
  
  return Status;
}


/*  This API Shall Enable peripheral clock                                              */
ERROR_t RCC_EnablePrephiral(u8 RCC_Bus, u8 RCC_PeriName)
{
  ERROR_t state = NOK;
  switch(RCC_Bus)
  {
    case AHB:
      RCC->AHBENR  |= RCC_PeriName;
      state = OK;
      break;
    case APB2:
      RCC->APB2ENR |= RCC_PeriName;
      state = OK;
      break;
    case APB1:
      RCC->APB1ENR |= RCC_PeriName;
      state = OK;
      break;
  }
  return state;
}


/*  This API Shall Disable prepheral clock                                              */
ERROR_t RCC_DisablePrephiral(u8 RCC_Bus, u8 RCC_PeriName)
{
  ERROR_t state = NOK;
  switch(RCC_Bus)
  {
    case AHB:
      RCC->AHBENR  &= ~RCC_PeriName;
      state = OK;
      break;
    case APB2:
      RCC->APB2ENR &= ~RCC_PeriName;
      state = OK;
      break;
    case APB1:
      RCC->APB1ENR &= ~RCC_PeriName;
      state = OK;
      break;
  }
  return state;
}


/* This API shall Configure AHB Bus Clock as a division of SYSCLK */
ERROR_t RCC_ConfigHCLK(u32 RCC_SYSCLK_Prescaler)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= AHB_PRECLR;
	TempRegVal |= RCC_SYSCLK_Prescaler;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;
}

/* This API shall Configure APB1 Bus Clock as a division of AHB CLK */
ERROR_t RCC_ConfigPCLK1(u32 RCC_HCLK_Prescaler)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= APB1_PRECLR;
	TempRegVal |= RCC_HCLK_Prescaler;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;

}

/* This API shall Configure APB2 Bus Clock as a division of AHB CLK */
ERROR_t RCC_ConfigPCLK2(u32 RCC_HCLK_Prescaler)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= APB2_PRECLR;
	TempRegVal |= RCC_HCLK_Prescaler;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;

}

/* This API shall Configure ADC peripheral Clock as a division of PLL CLK */
ERROR_t RCC_ConfigADCCLK(u32 RCC_PCLK2_Prescaler)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= ADC_PRECLR;
	TempRegVal |= RCC_PCLK2_Prescaler;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;

}

/* This API shall Configure USB peripheral Clock as a division of PCLK2 */
ERROR_t RCC_ConfigUSBCLK(u32 RCC_PLL_Prescaler)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= USB_PRECLR;
	TempRegVal |= RCC_PLL_Prescaler;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;

}

/* This API shall Configure MCO Pin Source Clock or turn it off */
ERROR_t RCC_ConfigMCO(u32 RCC_MCO_Config)
{
	ERROR_t Status = NOK;
	u32 TempRegVal = 0;

	TempRegVal  = RCC->CFGR;
	TempRegVal &= MCO_CLR;
	TempRegVal |= RCC_MCO_Config;
	RCC->CFGR   = TempRegVal;

	Status = OK;

	return Status;

}
