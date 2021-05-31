/*
 * stm32f446xx_i2c_driver.h
 *
 *  Created on: May 18, 2021
 *      Author: Nirmal Kumar
 */



#ifndef INC_STM32F446XX_I2C_DRIVER_H_
#define INC_STM32F446XX_I2C_DRIVER_H_

#include "stm32f446xx.h"
/*
 * Creating a Configuration Structure for 12Cx peripheral
 */

typedef struct{

	uint32_t I2C_SCLSpeed;
	uint8_t 	  I2C_DeviceAddress;
	uint8_t   I2C_ACKControl;
	uint16_t I2C_FMDuty_Cycle;

}I2C_Config_t;

/*
 * Creating Handle Structure for I2Cx Peripheral
 */

typedef struct{

	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;

}I2C_Handle_t;

/*
 * Creating Speed Macros
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM		 100000
#define I2C_SCL_SPEED_FM4K	 400000
#define I2C_SCL_SPEED_FM2K	 200000

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_ENABLE			1
#define I2C_ACK_DISABLE			0

/*
 * @I2C_FMDuty_Cycle
 */
#define I2C_FM_DUTY_2			1
#define I2C_FM_DUTY_16_9		0


/********************************************************************************************************************************************
 * 																			API supported By this driver
 * 														For More information check this function definition
 * *******************************************************************************************************************************************
 */

/*
 * Peripheral Clock Setup for I2C
 */

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx,uint8_t EnorDI);

void I2C_ManagaeAcking(I2C_RegDef_t *pI2Cx,uint8_t EnorDi);


/*
 * Init or DeInit
 */
void I2C_Init(I2C_Handle_t  *pI2C_Handle_t);
void I2C_DeInit(I2C_RegDef_t   *pI2Cx);

/*
 * Data Send and Receive
 */

void I2C_MasterSendData(I2C_Handle_t *pI2C_Handle_t, uint8_t *pTxbuffer, uint32_t Len , uint8_t SlaveAddr,uint8_t Sr);
void I2C_MasterReceiverData( I2C_Handle_t *pI2C_Handle, uint8_t *pRxBuffer, uint8_t len, uint8_t Slaveaddress,uint8_t Sr);







/*
 * Data Send and Receive in Interrupt Mode
 */
uint8_t  I2C_SendDataIT(I2C_Handle_t *pI2C_Handle , uint8_t *pTxBuffer , uint32_t Len)	;	// Base address pointer , TxBuffer pointer, how may bytes to send

uint8_t I2C_ReceiveDataIT(I2C_Handle_t *pI2C_Handle ,  uint8_t  *pRxBuffer , uint32_t Len );			// Base address pointer , RxBuffer pointer, how may bytes to send


/*
 * IRQ configuration and ISR Handling
 */
void I2C_IRQInterruptConfig(uint8_t IRQnumber, uint8_t EnorDI);															//Setting the priority of the IRQ(IRQ number EnorDI)
void I2C_IRQPriorityConfig(uint8_t IRQnumber ,uint8_t IRQPriority);

/*
 * Peripheral Control API's
 */

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx , uint8_t EnorDi);
uint8_t I2C_Get_FlagStatus(I2C_RegDef_t *pI2Cx, uint32_t Flag_Name);



/*
 * Applicatioin Call back
 */
void I2C_ApplicationEventCallback(I2C_Handle_t *pI2C_Handle, uint8_t AppEv	);


/*
 * I2Cx related SR1 Register Flag Macros
 */
#define I2C_FLAG_SR1_SB					(1 << I2C_SR1_SB)
#define I2C_FLAG_SR1_ADDR			(1 << I2C_SR1_ADDR)
#define I2C_FLAG_SR1_BTF				(1 << I2C_SR1_BTF)
#define I2C_FLAG_SR1_ADD10			(1 << I2C_SR1_ADD10)
#define I2C_FLAG_SR1_STOPF			(1 << I2C_SR1_STOPF)
#define I2C_FLAG_SR1_RXNE				(1 << I2C_SR1_RxNE)
#define I2C_FLAG_SR1_TXE				(1 << I2C_SR1_TxE)
#define I2C_FLAG_SR1_BERR				(1 << I2C_SR1_BERR)
#define I2C_FLAG_SR1_ARLO				(1 << I2C_SR1_ARLO)
#define I2C_FLAG_SR1_AF					(1 << I2C_SR1_AF)
#define I2C_FLAG_SR1_OVR				(1 << I2C_SR1_OVR)
#define I2C_FLAG_SR1_PECERR			(1 << I2C_SR1_PECERR)
#define I2C_FLAG_SR1_TIMEOUT		(1 << I2C_SR1_TIMEOUT)
#define I2C_FLAG_SR1_SMBALERT		(1 << I2C_SR1_SMBALERT)

/*
 * Macros for I2C Sr

 */
#define I2C_DISABLE_SR							0
#define I2C_ENABLE_SR								1


#endif /* INC_STM32F446XX_I2C_DRIVER_H_ */
