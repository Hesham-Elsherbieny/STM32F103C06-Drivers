/********************************************************************************************
 *                                                                                          *
 * File Name   : RCC.h                                                                      *
 *                                                                                          *
 * Author      : Hesham Elsherbieny                                                         *
 *                                                                                          *
 * contacts:   : h.elsherbieny@gmail.com					                                *
 *                                                                                          *
 * Date        : Jan 2020                                                                   *
 *                                                                                          *
 * Version     : 2.1.1                                                                      *
 *                                                                                          *
 * Description : specifies Reset and Clock Control (RCC) module and the required macros and *
 *               needed APIs for Cortex M3 STM32F103 microcontroller                        *                                                       *
 *                                                                                          *
 ********************************************************************************************/

#ifndef RCC_H_
#define RCC_H_

/* Includeing Standard Types Library */
#include "STD_TYPES.h"
/************************************************************************************/
/*  Defining bit masks and modes Macros                                             */
/************************************************************************************/

/***********************************control modes********************/
#define HIGH      1
#define LOW       0

/*****************************RCC_CR bit Masks***************************************/

/*      HSI Controlling bits             */
#define HSION           0x00000001
#define HSIOFF          0x00000001
#define HSIRDY          0x00000002

/*      HSI trimming bits                */
#define HSITRIM_CLR     0xFFFFFF07
#define HSITRIM         0x000000F8

/*      HSI calibration bits             */
#define HSICAL          0x0000FF00   

/*      HSE controlling bits             */
#define HSEON           0x00010000
#define HSEOFF			0x00010000
#define HSERDY          0x00020000
#define HSEBYP          0x00040000

/*controlling CSS (clock security system)*/
#define CSSON           0x00080000

/*      PLL controlling bits             */
#define PLLON           0x01000000
#define PLLOFF           0x01000000
#define PLLRDY          0x02000000




/******************************RCC_CFGR bits******************************************/

/*       system clock switch bit Masks        */
#define CLK_CLR         0xFFFFFFFC

#define HSI           0x00000000
#define HSE           0x00000001
#define PLL           0x00000002

/*    system clock switch status bits    */
#define CLOCK_STATUS    0x0000000C

#define HSI_SWS         0x00000000
#define HSE_SWS         0x00000004
#define PLL_SWS			0x00000008

/*            AHB prescaler              */
#define AHB_PRECLR      0xFFFFFF0F

#define AHB_PRE1        0x00000070
#define AHB_PRE2        0x00000080
#define AHB_PRE4        0x00000090
#define AHB_PRE8        0x000000A0
#define AHB_PRE16       0x000000B0
#define AHB_PRE64       0x000000C0
#define AHB_PRE128      0x000000D0
#define AHB_PRE256      0x000000E0
#define AHB_PRE512      0x000000F0

/*      APB1 low-speed prescaler         */
#define APB1_PRECLR     0xFFFFF8FF

#define APB1_PRE1       0x00000300
#define APB1_PRE2       0x00000400
#define APB1_PRE4       0x00000500
#define APB1_PRE8       0x00000600
#define APB1_PRE16      0x00000700     

/*      APB2 High-speed prescaler       */
#define APB2_PRECLR     0xFFFFC7FF

#define APB2_PRE1       0x00001800
#define APB2_PRE2       0x00002000
#define APB2_PRE4       0x00002800
#define APB2_PRE8       0x00003000
#define APB2_PRE16      0x00003800

/*        ADCPRE ADC prescaler          */
#define ADC_PRECLR      0xFFFF3FFF

#define ADC_PRE2        0x00000000
#define ADC_PRE4        0x00004000
#define ADC_PRE6        0x00008000
#define ADC_PRE8        0x0000C000

/*      Clear for PLL entry       */
#define PLL_CLRSRC          0xFFFCFFFF
/*      PLL entry clock source          */
#define PLLSRC_HSI_PRE2     0x00000000
#define PLLSRC_HSE_PRE1     0x00010000
#define PLLSRC_HSE_PRE2     0x00030000         


/*      PLL multiplication factor       */
#define PLLMUL_CLR      0xFFC3FFFF

#define PLLMUL2         0x00000000
#define PLLMUL3         0x00040000
#define PLLMUL4         0x00080000
#define PLLMUL5         0x000C0000
#define PLLMUL6         0x00100000
#define PLLMUL7         0x00140000
#define PLLMUL8         0x00180000
#define PLLMUL9         0x001C0000
#define PLLMUL10        0x00200000
#define PLLMUL11        0x00240000
#define PLLMUL12        0x00280000
#define PLLMUL13        0x002C0000
#define PLLMUL14        0x00300000
#define PLLMUL15        0x00340000
#define PLLMUL16        0x00380000



/*           USB Prescaler              */
#define USB_PRECLR		 0xFFBFFFFF

#define USB_PRE1         0x00400000
#define USB_PRE1_5       0x00000000

/*    Microcontroller clock output      */
#define MCO_CLR         0xF8FFFFFFF

#define MCO_OFF			0x000000000
#define MCO_SYSCLK      0x040000000
#define MCO_HSI         0x050000000
#define MCO_HSE         0x060000000
#define MCO_PLL         0x070000000




/**********************RCC_CIR BITs************************/


/*LSI config bits*/
#define LSIRDY_FLAG      0x00000001
#define LSIRDY_INTEN     0x00000100
#define LSIRDY_CLRFLAG   0x00010000 

/*LSE config bits*/
#define LSERDY_FLAG      0x00000002
#define LSERDY_INTEN     0x00000200
#define LSERDY_CLRFLAG   0x00020000 

/*HSI config bits*/
#define HSIRDY_FLAG      0x00000004
#define HSIRDY_INTEN     0x00000400
#define HSIRDY_CLRFLAG   0x00040000 

/*HSE config bits*/
#define HSERDY_FLAG      0x00000008
#define HSERDY_INTEN     0x00000800
#define HSERDY_CLRFLAG   0x00080000 

/*PLL config bits*/
#define PLLRDY_FLAG      0x00000010
#define PLLRDY_INTEN     0x00001000
#define PLLRDY_CLRFLAG   0x00100000 

/*CSS config bits*/
#define CSS_FLAG         0x00000080
#define CSS_CLRFLAG      0x00800000




/********************************RCC_APB2RSTR***************************/


/*      AFIORST: Alternate function IO reset      */
#define AFIO_RST        0x00000001

/*            IO ports reset Masks                */
#define IOPA_RST        0x00000004
#define IOPB_RST        0x00000008
#define IOPC_RST        0x00000010
#define IOPD_RST        0x00000020
#define IOPE_RST        0x00000040
#define IOPF_RST        0x00000080
#define IOPG_RST        0x00000100

/*            ADC 1 interface reset               */
#define ADC1_RST        0x00000200        

/*            ADC 2 interface reset               */
#define ADC2_RST        0x00000400

/*            ADC 3 interface reset               */
#define ADC3_RST        0x00008000


/*              timer 1 reset                     */
#define TIM1_RST        0x00000800

/*              timer 8 reset                     */
#define TIM8_RST        0x00002000

/*              timer 9 reset                     */
#define TIM9_RST        0x00080000

/*              timer 10 reset                    */
#define TIM10_RST       0x00100000

/*              timer 11 reset                    */
#define TIM11_RST       0x00200000


/*              SPI 1 reset                       */
#define SPI1_RST        0x00001000

/*              USART 1 reset                     */
#define USART1_RST      0x00004000





/********************************RCC_APB1RSTR***************************/

/*              timer 2 reset                     */
#define TIM2_RST        0x00000001
/*              timer 3 reset                     */
#define TIM3_RST        0x00000002
/*              timer 4 reset                     */
#define TIM4_RST        0x00000004
/*              timer 5 reset                     */
#define TIM5_RST        0x00000008
/*              timer 6 reset                     */
#define TIM6_RST        0x00000010
/*              timer 7 reset                     */
#define TIM7_RST        0x00000020
/*              timer 12 reset                    */
#define TIM12_RST       0x00000040
/*              timer 13 reset                    */
#define TIM13_RST       0x00000080
/*              timer 14 reset                    */
#define TIM14_RST       0x00000100


/*             WatchDog Timer reset               */
#define WWDG_RST        0x00000800


/*              SPI 2 reset                       */
#define SPI2_RST        0x00004000  
/*              SPI 3 reset                       */
#define SPI3_RST        0x00008000


/*              USART 2 reset                      */
#define USART2_RST      0x00020000
/*              USART 3 reset                      */
#define USART3_RST      0x00040000
/*              USART 4 reset                      */
#define USART4_RST      0x00080000
/*              USART 5 reset                      */
#define USART5_RST      0x00100000


/*                ISC 1 reset                      */
#define ISC1_RST        0x00200000
#define ISC2_RST        0x00400000


/*                USB reset                        */
#define USB_RST         0x00800000


/*                CAN reset                      */
#define CAN_RST         0x02000000


/*              Backup interface reset                  */
#define BKP_RST         0x08000000


/*              Power interface reset                      */
#define PWR_RST         0x10000000


/*                    DAC reset                      */
#define DAC_RST         0x20000000





/************************************RCC_AHBENR***************************/
#define AHB             0

/*                DMA 1  Enable                    */
#define DMA1_EN         0x00000001
/*                DMA 2  Enable                    */
#define DMA2_EN         0x00000002


/*                  SRAM Enable                    */
#define SRAM_EN         0x00000004


/*                FLITF clock  Enable                  */
#define FLITF_EN        0x00000010  


/*                CRC clock  Enable                  */
#define CRC_EN          0x00000040


/*                FSMC clock  Enable                  */
#define FSMC_EN         0x00000100


/*                SDIO clock  Enable                  */
#define SDIO_EN         0x00000400




/****************************RCC_APB2ENR*****************************/
#define APB2            1
/*                     AFIO Enable                        */
#define AFIOEN          0x00000001


/*                   IO Ports Enable                      */
#define IOPA_EN         0x00000004
#define IOPB_EN         0x00000008
#define IOPC_EN         0x00000010
#define IOPD_EN         0x00000020
#define IOPE_EN         0x00000040
#define IOPF_EN         0x00000080
#define IOPG_EN         0x00000100


/*                     ADC1 Enable                        */
#define ADC1_EN         0x00000200   
/*                     ADC2 Enable                        */
#define ADC2_EN         0x00000400


/*                   Timer1 Enable                        */
#define TIM1_EN         0x00000800    
/*                   Timer8 Enable                        */
#define TIM8_EN         0x00002000
/*                   Timer9 Enable                        */
#define TIM9_EN         0x00080000
/*                   Timer10 Enable                        */
#define TIM10_EN        0x00100000
/*                   Timer11 Enable                        */
#define TIM11_EN        0x00200000


/*                   SPI1 Enable                        */
#define SPI1_EN         0x00001000


/*                   USART1 Enable                        */
#define USART1_EN       0x00004000


/*                   ADC3 Enable                        */
#define ADC3_EN         0x00008000   




/****************************RCC_APB1ENR*****************************/
#define APB1            2

/*                   Timer2 Enable                        */
#define TIM2_EN         0x00000001
/*                   Timer3 Enable                        */
#define TIM3_EN         0x00000002
/*                   Timer4 Enable                        */
#define TIM4_EN         0x00000004
/*                   Timer5 Enable                        */
#define TIM5_EN         0x00000008
/*                   Timer6 Enable                        */
#define TIM6_EN         0x00000010
/*                   Timer7 Enable                        */
#define TIM7_EN         0x00000020
/*                   Timer12 Enable                        */
#define TIM12_EN        0x00000040
/*                   Timer13 Enable                        */
#define TIM13_EN        0x00000080
/*                   Timer14 Enable                        */
#define TIM14_EN        0x00000100


/*                watchdogtimer Enable                      */
#define WWDG_EN         0x00000800


/*                   SPI2 Enable                        */
#define SPI2_EN         0x00004000
/*                   SPI3 Enable                        */
#define SPI3_EN         0x00008000


/*                   USART2 Enable                        */
#define USART2_EN       0x00020000
/*                   USART3 Enable                        */
#define USART3_EN       0x00040000


/*                   UART4 Enable                        */
#define UART4_EN        0x00080000
/*                   UART5 Enable                        */
#define UART5_EN        0x00100000


/*                   I2C1 Enable                        */
#define I2C1_EN         0x00200000
/*                   I2C2 Enable                        */
#define I2C2_EN         0x00400000


/*                   USB Enable                        */
#define USB_EN          0x00800000


/*                   CAN Enable                        */
#define CAN_EN          0x02000000


/*               Backup interface clock Enable                      */
#define BKP_EN          0x08000000


/*               Power interface clock Enable                        */
#define PWR_EN          0x10000000


/*                    DAC Enable                        */
#define DAC_EN          0x20000000

/**********Different Types Low-Speed Clock Sources***********/

/* Macros to differentiate between LSI/LSE types of low-speed
 * clock sources as they are affecting two different registers
 * with same mask value */

#define LSI			0x00
#define LSE			0x01

/**************************RCC_BDCR***************************/


/*          LSE Controlling bits             */
#define LSEON           0x00000001
#define LSERDY          0x00000002
#define LSEBYP          0x00000004


/*           RTC clock source selection             */
#define RTC_NOCLK       0xFFFFFCFF
#define RTC_LSE         0x00000100
#define RTC_LSI         0x00000200
#define RTC_HSE         0x00000300


/*           RTC clock Enable             */
#define RTC_EN          0x00008000


/*           Backup domain software reset             */
#define BD_RST          0x00010000




/***************************RCC_CSR****************************/

/*          LSI Controlling bits             */
#define LSION           0x00000001
#define LSIRDY          0x00000002


/*          Remove reset flag             */
#define RMV_FLAG        0x01000000


/*          PIN reset flag             */
#define PIN_RSTFLAG     0x04000000


/*          POR/PDR reset flag             */
#define POR_RSTFLAG     0x08000000


/*          software reset flag             */
#define SFT_RSTFLAG     0x10000000


/*      independent watchdog timer reset flag       */
#define IWDG_RSTFLAG    0x20000000


/*          watchdog timer reset flag             */
#define WWDG_RSTFLAG    0x40000000


/*          low power reset flag             */
#define LPWR_RSTFLAG    0x80000000

/******************** APIs prototypes *****************************/

/*
 * HS -> High Speed
 * LS -> Low Speed
 */
 
/* This API shall Enable High Speed Clock source
 * Parameters : RCC_HSClockName and have the following available Options:-
 * 				- HSION
 *				- HSEON
 *				- HSEBYP
 *				- PLLON
 */
ERROR_t RCC_EnablelHSClock(u32 RCC_HSClockName);

/* This API shall Disable High Speed Clock source
 * Parameters : RCC_HSClockName and have the following available Options:-
 * 				- HSIOFF
 *				- HSEOFF
 *				- HSEBYP
 *				- PLLOFF
 */
ERROR_t RCC_DisablelHSClock(u32 RCC_HSClockName);

/* This API shall Enable Low Speed Clock source
 * Parameters : RCC_LSClockName and have the following available Options:-
 * 				- LSI
 *				- LSE
 *				- LSEBYP
 */
ERROR_t RCC_EnablelLSClock(u32 RCC_LSClockName);

/* This API shall Disable Low Speed Clock source
 * Parameters : RCC_LSClockName and have the following available Options:-
 * 				- LSI
 *				- LSE
 *				- LSEBYP
 */
ERROR_t RCC_DisablelLSClock(u32 RCC_LSClockName);

/* This API shall Enable peripheral clock
 * Parameters : - RCC_Bus and have the following available Options:-
 * 				  - AHB
 * 				  - APB1
 * 				  - APB2
 * 				- RCC_PeriName and have the following Formula:-
 * 					      [PeripheralName]_EN
 * 				  where [PeripheralName] : The Name Of the needed peripheral as mentiond in the above sections
 * 						e.g, IOPA_EN, ADC1_EN,...,etc.
 */
ERROR_t RCC_EnablePrephiral(u8 RCC_Bus, u8 RCC_PeriName);

/* This API shall disable peripheral clock
 * Parameters : - RCC_Bus and have the following available Options:-
 * 				  - AHB
 * 				  - APB1
 * 				  - APB2
 * 				- RCC_PeriName and have the following Formula:-
 * 					      [PeripheralName]_EN
 * 				  where [PeripheralName] : The Name Of the needed peripheral as mentiond in the above sections
 * 						e.g, IOPA_EN, ADC1_EN,...,etc.
 */
ERROR_t RCC_DisablePrephiral(u8 RCC_Bus, u8 RCC_PeriName);

/* This API shall configure system clock source select
 * Parameters : RCC_ClockName and have the following available Options:-
 * 				- HSI
 * 				- HSE
 * 				- PLL
 */
ERROR_t RCC_SetSysClk(u32 RCC_ClockName);

/* This API shall configure PLL clock select
 * Parameters : - RCC_SrcClkName and have the following available Options:-
 * 				  - PLLSRC_HSI_PRE2
 *				  - PLLSRC_HSE_PRE1
 *				  - PLLSRC_HSE_PRE2
 *				- RCC_PLL_Mul and have the following available Options:-
 *				  - PLLMUL2,3,4,...,16
 */
ERROR_t RCC_ConfigPLL(u32 RCC_SrcClkName, u8 RCC_PLL_Mul);

/* This API shall Configure AHB Bus Clock as a division of SYSCLK
 * Parameters : RCC_SYSCLK_Prescaler and have the following available Options:-
 * 				 - AHB_PRE1,2,4,8,16,...,512
 */
ERROR_t RCC_ConfigHCLK(u32 RCC_SYSCLK_Prescaler);

/* This API shall Configure APB1 Bus Clock as a division of AHB CLK
 * Parameters : RCC_HCLK_Prescaler and have the following available Options:-
 *  		     - APB1_PRE1,2,4,8,16
 */
ERROR_t RCC_ConfigPCLK1(u32 RCC_HCLK_Prescaler);

/* This API shall Configure APB2 Bus Clock as a division of AHB CLK
 * Parameters : RCC_HCLK_Prescaler and have the following available Options:-
 *  		     - APB2_PRE1,2,4,8,16
 */
ERROR_t RCC_ConfigPCLK2(u32 RCC_HCLK_Prescaler);

/* This API shall Configure ADC peripheral Clock as a division of PLL CLK
 * Parameters : RCC_PCLK2_Prescaler and have the following available Options:-
 *  		     - ADC_PRE2,4,6,8
 */
ERROR_t RCC_ConfigADCCLK(u32 RCC_PCLK2_Prescaler);

/* This API shall Configure USB peripheral Clock as a division of PCLK2
 * Parameters : RCC_PLL_Prescaler and have the following available Options:-
 *  		     - USB_PRE1
 *  		     - USB_PRE1_5
 */
ERROR_t RCC_ConfigUSBCLK(u32 RCC_PLL_Prescaler);

/* This API shall Configure MCO Pin Source Clock or turn it off
 * Parameters : RCC_MCO_Config and have the following available Options:-
 * 				 - MCO_OFF
 *				 - MCO_SYSCLK
 *				 - MCO_HSI
 *               - MCO_HSE
 *               - MCO_PLL
 */
ERROR_t RCC_ConfigMCO(u32 RCC_MCO_Config);

#endif /* RCC_H_ */
