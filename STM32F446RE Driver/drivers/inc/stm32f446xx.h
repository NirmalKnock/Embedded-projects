/*
 * ******************************************************************************
 * stm32f446xx.h																|
 *																				|
 *  Created on: Nov 30, 2020													|
 *      Author: Nirmal Kumar													|
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	|
 *******************************************************************************																				|
*/

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

/*************************************************************************************************************************
 * Writing SRAM and FLASH base address
 * SRAM1 is base and we can update SRAM2 in Future
 */

#define FLASH_BASEADDR  				0x08000000U  						//Base address of Flash Memory
#define SRAM1_BASEADDR					0x20000000U							//Base address of SRAM1 Memory
#define SRAM							SRAM1_BASEADDR
#define SRAM2_BASEADDR					0x20001C00U							//Base address of SRAM2	Memory
#define ROM								0x1FFF0000U							//Bass address of ROM   Memory

/**************************************************************************************************************************
 * Writing AHBx and APBx peripheral Base address
 */

#define PERIPH_BASEADDR 				0x40000000U 						//Base address of PERIPHERAL
#define APB1_PERIPH_BASEADDR			PERIPH_BASE							//Base address of APB1 BUS
#define APB2_PERIPH_BASEADDR			0x40010000U							//Base address of APB2 BUS

#define AHB1_PERIPH_BASEADDR			0x40020000U							//Base address of AHB1 BUS
#define AHB2_PERIPH_BASEADDR			0x50000000U							//Base address of AHB2 BUS

/**************************************************************************************************************************
 * Writing all Peripherals base address
 */

#define GPIOA_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x0000)		//Base address of AHB1 BUS + GPIOA offset
#define GPIOB_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x0400)		//Base address of AHB1 BUS + GPIOB offset
#define GPIOC_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x0800)		//Base address of AHB1 BUS + GPIOC offset
#define GPIOD_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x0C00)		//Base address of AHB1 BUS + GPIOD offset
#define GPIOE_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x1000)		//Base address of AHB1 BUS + GPIOE offset
#define GPIOF_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x1400)		//Base address of AHB1 BUS + GPIOF offset
#define GPIOG_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x1800)		//Base address of AHB1 BUS + GPIOG offset
#define GPIOH_BASSADDR					(AHB1_PERIPH_BASEADDR + 0x1C00)		//Base address of AHB1 BUS + GPIOH offset


/**************************************************************************************************************************
 * Writing Base address of peripherals hanging on APB1 BUS
 */

#define I2C1_BASEADDR					(APB1_PERIPH_BASEADDR + 0x5400)		//Base address of APB1 BUS + I2C1 offset
#define I2C2_BASEADDR					(APB1_PERIPH_BASEADDR + 0x5800)		//Base address of APB1 BUS + I2C2 offset
#define I2C3_BASEADDR					(APB1_PERIPH_BASEADDR + 0x5C00)		//Base address of APB1 BUS + I2C3 offset

#define SPI2_BASEADDR					(APB1_PERIPH_BASEADDR + 0x3800)		//Base address of APB1 BUS + SPI2 offset
#define SPI3_BASEADDR					(APB1_PERIPH_BASEADDR + 0x3C00)		//Base address of APB1 BUS + SPI3 offset

#define USART2_BASEADDR					(APB1_PERIPH_BASEADDR + 0x4400)		//Base address of APB1 BUS + USART2 offset
#define USART3_BASEADDR					(APB1_PERIPH_BASEADDR + 0x4800)		//Base address of APB1 BUS + USART3 offset
#define UART4_BASEADDR					(APB1_PERIPH_BASEADDR + 0x4C00)		//Base address of APB1 BUS + UART4 offset
#define UART5_BASEADDR					(APB1_PERIPH_BASEADDR + 0x5000)		//Base address of APB1 BUS + UART5 offset
/**************************************************************************************************************************
 * Writing Base address of peripherals hanging on APB2 bus
 */
#define USART1_BASEADDR					(APB2_PERIPH_BASEADDR + 0x1000)		//Base address of APB2 BUS + UART1 offset
#define USART6_BASEADDR					(APB2_PERIPH_BASEADDR + 0x1400)		//Base address of APB2 BUS + UART6 offset

#define  EXTI_BASEADDR    				(APB2_PERIPH_BASEADDR + 0x3C00)		//Base address of APB2 BUS + EXTI offset

#define SPI1_BASEADDR					(APB2_PERIPH_BASEADDR + 0x3000)		//Base address of APB2 BUS + SPI1 offset
#define SYSCFG_BASEADDR					(APB2_PERIPH_BASEADDR + 0x3800)		//Base address of APB2 BUS + SYSCFG offset

/*
 *
 */
#endif /* INC_STM32F446XX_H_ */
