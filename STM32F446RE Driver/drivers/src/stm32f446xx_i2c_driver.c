/*
 * stm32f446xx_i2c_driver.c
 *
 *  Created on: May 18, 2021
 *      Author: Nirmal Kumar
 */
#include "stm32f446xx.h"

//AHB Prescalar values
uint16_t  AHB_Prescalar[9]= {2,4,8,16,32,64,128,256,512};
//APB1 Prescalar values
uint16_t APB1_Prescalar[4] = {2,4,8,16};

/****************************************Function Prototypes****************************************************/
static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx);
static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr);
static void I2C_ClearADDRFlag(I2C_Handle_t *pI2C_Handle);
static void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);
static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr);
void I2C_ManagaeAcking(I2C_RegDef_t *pI2Cx,uint8_t EnorDi);
void I2C_ClearSBFlag(I2C_RegDef_t *pI2Cx);

/*********************************************************Helper Functions***************************************/
static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx)
{
	pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_START);
}

static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
	//shift register by 1 , to fill r/w bit
	SlaveAddr = SlaveAddr << 1 ;
	SlaveAddr &= ~(1);							//To clear the first bit (Slave address + r/w bit ) W=0;
	//put into Data buffer
	pI2Cx->DR = SlaveAddr;
}

static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
	//Shift the register by 1, to fill R/W bit
	SlaveAddr = SlaveAddr <<1;
	SlaveAddr |= 1;
	//Put into Data Register
	pI2Cx->DR = SlaveAddr;
}

static void I2C_ClearADDRFlag(I2C_Handle_t *pI2C_Handle)
{
	uint32_t dummyRead ;
	dummyRead = pI2C_Handle->pI2Cx->SR1;
	dummyRead = pI2C_Handle->pI2Cx->SR2;
	(void)dummyRead;
}

static void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx)
{
	pI2Cx->I2C_CR1  |= ( 1 << I2C_CR1_STOP );
}

void I2C_ManagaeAcking(I2C_RegDef_t *pI2Cx,uint8_t EnorDi)
{
	if (EnorDi == I2C_ACK_ENABLE)
	{
		pI2Cx->I2C_CR1 |= ( 1 << I2C_CR1_ACK);		//Enable
	}
	if (EnorDi == I2C_ACK_DISABLE)
	{
		pI2Cx->I2C_CR1 &= ~( 1 << I2C_CR1_ACK); //Disable
	}
}

void I2C_ClearSBFlag(I2C_RegDef_t *pI2Cx)
{
	uint32_t temp = pI2Cx->SR1;
	(void)temp;
}

/************************************************************************************************
 *
  * @fn					- I2C_PeriClockControl
  *
  * @brief				- Which controls the I2C clock Enable or Disable.
  *
  *	@param[in]			-  Address of RegDef_t Structure
  *	@param[in]			-  Enable or Disable value(MACROS)
  *	@param[in]			-
  *
  *	return				- none
  *
  *	@Note				- none

*/
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx,uint8_t EnorDI)
{
	if (EnorDI == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_PCLK_EN();
		}
		else if (pI2Cx == I2C2)
		{
			I2C2_PCLK_EN();
		}
		else if (pI2Cx == I2C3)
		{
			I2C3_PCLK_EN();
		}

	}else
	{
		if(pI2Cx == I2C1)
		{
			I2C1_PCLK_DI();
		}
		else if (pI2Cx == I2C2)
		{
			I2C2_PCLK_DI();
		}
		else if (pI2Cx == I2C3)
		{
			I2C3_PCLK_DI();
		}
	}
}

//Creating a fucntion to get the value of PLL

uint32_t RCC_GetPLLOutputClk(void)
{
	return 0;
}

//Function to calculate the value of FREQ on APB1 bus (pclk1)

//1. identify the clock source
//2. Identify the AHB prescalar value
//3. Identify the APB1 prescalar value

uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1;
	uint8_t clksrc, temp, ahbp,apb1p;
	uint32_t systemClk;

	//1. Identify the clock source
	clksrc = ((RCC->CFGR >> 2 ) & 0x3);

	if (clksrc ==0)
	{
		systemClk = 16000000;
	}
	else if (clksrc == 1 )
	{
		systemClk = 8000000;
	}
	else if (clksrc == 2 )
	{
		systemClk = RCC_GetPLLOutputClk();
	}

	//2.Identify the AHP Prescalar value
	//Read the value of HPRE in clock Configuration Register

	temp  = ((RCC->CFGR >> 4 ) & 0xF);

	if (temp < 8 )
	{
		ahbp = 1;
	}
	else
	{
		ahbp = AHB_Prescalar[temp - 8 ]; // To get the first value from array
	}

	//3. Identify the APB PreScaler

	temp = ((RCC->CFGR >> 10) & 0x7);
	if (temp <4)
	{
		apb1p = 1;
	}
	else
	{
		apb1p = APB1_Prescalar[temp - 4];
	}

	//Finally getting the PCLK1 -> verify in clock diagram
	pclk1 = (systemClk / ahbp) / apb1p;

	return pclk1;
}


/************************************************************************************************
 *
  * @fn					- I2C_init()
  *
  * @brief				- Which initiazise the I2C peripheral
  *
  *	@param[in]			-  Address of RegDef_t Structure
  *	@param[in]			-  Enable or Disable value(MACROS)
  *	@param[in]			-
  *
  *	return				- none
  *
  *	@Note				- none

*/
void I2C_Init(I2C_Handle_t  *pI2C_Handle_t)
{
	//.Creating the temp variable and trise variable

	uint32_t tempreg = 0 ;

	//Enable the I2C peripheral Clock
	I2C_PeriClockControl(pI2C_Handle_t->pI2Cx, ENABLE);


	//1. ACK control Bit
	//tempreg |= (pI2C_Handle_t->I2C_Config.I2C_ACKControl   << I2C_CR1_ACK) ;
	 pI2C_Handle_t->pI2Cx->I2C_CR1 |= ( 1 << 10);

	//2. Configure the FREQ field

	tempreg = 0;
	tempreg |= RCC_GetPCLK1Value() / 1000000U ;   //Because we want only the number. eg 16
	pI2C_Handle_t->pI2Cx->I2C_CR2 = (tempreg & 0x3F);

	//3. Configure the device own  address in OWN register

	tempreg= 0 ;

	tempreg |= (pI2C_Handle_t->I2C_Config.I2C_DeviceAddress  << 1 );  // Because 1st bit is dont care in 7bit addressing Mode
	//Read reference manual 14th bit kept at 1 by software (Reserved)
	tempreg |= (1 << 14);
	pI2C_Handle_t->pI2Cx->OAR1 = tempreg;
	//Read reference manual 14th bit kept at1 by software

	//4. CCR calculation

	uint16_t ccr_value = 0;
	tempreg = 0;

	//First to find the Speed mode

	if (pI2C_Handle_t->I2C_Config.I2C_SCLSpeed <= I2C_SCL_SPEED_SM)
	{
		//Then it is standard Mode
		//By default the standard Mode is configured in CCR Register in 15th Bit
		//calculation for CCR in SM mode

		ccr_value = (RCC_GetPCLK1Value() / (2* pI2C_Handle_t->I2C_Config.I2C_SCLSpeed) );  // CCR = pclock / (2* SCK by user)
		tempreg |= (ccr_value & 0xFFF); //masking only ccr bit fields

	}
	else
	{
		//the mode is Fast Mode
		//Set fast mode in Bit 15th

		tempreg |= (1 << 15);
		//then set the duty cycle

		tempreg |= (pI2C_Handle_t->I2C_Config.I2C_FMDuty_Cycle <<  14 );
		//Based on duty cycle use formular

		if (pI2C_Handle_t->I2C_Config.I2C_FMDuty_Cycle == I2C_FM_DUTY_2)
		{
			ccr_value = (RCC_GetPCLK1Value() / (3 * pI2C_Handle_t->I2C_Config.I2C_SCLSpeed));
		}
		else
		{
			ccr_value = (RCC_GetPCLK1Value() / (25 * pI2C_Handle_t->I2C_Config.I2C_SCLSpeed));
		}
		tempreg |= (ccr_value & 0xFFF);
	}
	pI2C_Handle_t->pI2Cx->CCR |= tempreg;


		//5.  TRISE configuration
		//First check the Mode Sm or Fm

	if (pI2C_Handle_t->I2C_Config.I2C_SCLSpeed == I2C_SCL_SPEED_SM)
	{
		//Mode is Standard Mode
		tempreg = 0;
		tempreg = (RCC_GetPCLK1Value()  / 1000000U ) + 1 	;//Formula : (Pclk1 * Trise)+1 ,  we can simply say , trise = 1us ,so we divide by 1MHZ


	}
	else
	{
		//Mode is Fast Mode
		tempreg =0;
		tempreg = ( (RCC_GetPCLK1Value() * 300 ) / 1000000000U ) +1;					//Fast Mode trise = 300ns
	}

	pI2C_Handle_t->pI2Cx->TRISE |= (tempreg & 0x3F);


}


/***********************************************************************************************************************************
 *
  * @fn					- I2C_DeInit
  *
  * @brief				- Which Reset the I2C peripheral
  *
  *	@param[in]			-  Address of RegDef_t Structure
  *	@param[in]			-
  *	@param[in]			-
  *
  *	return				- none
  *
  *	@Note				- none

*/

void I2C_DeInit(I2C_RegDef_t   *pI2Cx)
{
	if (pI2Cx == I2C1)
	{
		I2C1_REG_RESET();
	}
	else if (pI2Cx == I2C2)
	{
		I2C2_REG_RESET();
	}
	else if (pI2Cx == I2C3)
	{
		I2C3_REG_RESET();
	}
}

/*********************************************************************************************************************************************
 *
  * @fn					- I2C Master Send Data
  *
  * @brief				- Which Transmits the data from I2Cx peripheral
  *
  *	@param[in]			-  Handle Structure of I2Cx
  *	@param[in]			-  Buffer address pointer
  *	@param[in]			-  Length information
  *	@param[in]			-  Slave address information
  *	@param[in]			- Repeated Start
  *
  *	return				- none
  *
  *	@Note				- none

*/

void I2C_MasterSendData (I2C_Handle_t *pI2C_Handle_t , uint8_t *pTxbuffer, uint32_t Len, uint8_t SlaveAddr,uint8_t Sr )
{
	//1.	Generate the Start Conditioin(creating helper function)
	I2C_GenerateStartCondition(pI2C_Handle_t->pI2Cx);

	//2. 	Confirm the start Generation is completed by checking the SB flag in the SR1 Register
	//		note : Utill the SB is cleared the SCL will be stretched (Pulled to Low)
	//		wait untill the SB is cleared
	while( !  I2C_Get_FlagStatus(pI2C_Handle_t->pI2Cx, I2C_FLAG_SR1_SB) );


	//3.	Send the Address of the slave with r/w bit , Set to W(0)  (Total 8 bits)
	I2C_ExecuteAddressPhaseWrite(pI2C_Handle_t->pI2Cx, SlaveAddr);

	//4. 	Confirm the address phase is completed by Checking in ADDR flag in SR1 register
	while( !  I2C_Get_FlagStatus(pI2C_Handle_t->pI2Cx, I2C_FLAG_SR1_ADDR) );

	//5.	 Clear the ADDR flag according to its software Sequence
	//		 ADDR FLAG can be cleared by reading SR1 and SR2 , check RM in SR1 register
	I2C_ClearADDRFlag(pI2C_Handle_t);

	//6.	Send the data untill Len becomes =0
	//		before sending the data , first check the TXE flag ,whether the data buffer is empty or not

	while (Len >0)
	{
		while ( ! I2C_Get_FlagStatus(pI2C_Handle_t->pI2Cx, I2C_FLAG_SR1_TXE));		//Wait Till TXE is SET
		pI2C_Handle_t->pI2Cx->DR = *pTxbuffer;
		pTxbuffer ++;
		Len--;
	}

	//7.	When Len becomes 0, wait for TXE=1 and BTF =1 before Generating the STOP condition
	//		Note :  TXE=1 and BTF = 1, means the SR and DR registers are empty and next transmission should begin
	//		when  BTF = 1  SCL will be stretched (Pulled to LOW)

	while ( ! 	(  I2C_Get_FlagStatus(pI2C_Handle_t->pI2Cx, I2C_FLAG_SR1_TXE) ) );

	while ( !   ( I2C_Get_FlagStatus(pI2C_Handle_t->pI2Cx, I2C_FLAG_SR1_BTF) ) );

	//8. 	Generate the STOP Condition and master need not to wait for the completion of STOP Condition
	//		Note: Generating STOP , will automatically clears the BTF

	if(Sr == I2C_DISABLE_SR)
	{
	I2C_GenerateStopCondition(pI2C_Handle_t->pI2Cx);

	}





}


/**********************************************************************************************************************************
 *
  * @fn					- I2C_MasterReceiverData
  *
  * @brief				- Which Receives the data from the Slave with 1 byte option and multiple byte option
  *
  *	@param[in]			- I2C_Handle_t structure
  *	@param[in]			-  RxBuffer address
  *	@param[in]			- Length Information
  *	@param[in]			- Slave address
  *	@param[in]			- Repeated Start
  *
  *	return				- none
  *
  *	@Note				- none

*/

void I2C_MasterReceiverData( I2C_Handle_t *pI2C_Handle, uint8_t *pRxBuffer, uint8_t len, uint8_t Slaveaddress,uint8_t Sr)
{
	//1.	Generate Start Condition
	I2C_GenerateStartCondition(pI2C_Handle->pI2Cx);

	//2.	Confirm the start Condition by checking the SB flag  in SR1 register
	//Note: 	Ultill the SB bit is cleared the SCL line will be Stretched Low(pulled to Low)
	while ( ! I2C_Get_FlagStatus(pI2C_Handle->pI2Cx, I2C_FLAG_SR1_SB));

	//3.	Send the Address of the slave in 7bit mode with Read information bit R=1. (Total 8 bits)
	I2C_ExecuteAddressPhaseRead(pI2C_Handle->pI2Cx, Slaveaddress);

	//4. Wait Untill the Address phase is completed by checking the ADDR Flag in SR1 register

	while ( ! I2C_Get_FlagStatus(pI2C_Handle->pI2Cx, I2C_FLAG_SR1_ADDR));

	/// Procedure to Read Only one Byte

	if (len ==1)
	{
		//Disable the ACK
		I2C_ManagaeAcking(pI2C_Handle->pI2Cx,I2C_ACK_DISABLE);

		//Clear the ADDR flag ,by reading SR1 followed by the SR2, check RM
		I2C_ClearADDRFlag(pI2C_Handle);


		//Wait untill the RxNE becomes 1
		while ( ! I2C_Get_FlagStatus(pI2C_Handle->pI2Cx, I2C_FLAG_SR1_RXNE));

		//Generate Stop Condition
		if (Sr == I2C_DISABLE_SR)
		{
		I2C_GenerateStopCondition(pI2C_Handle->pI2Cx);
		}

		//Read Data into the buffer
		*pRxBuffer = pI2C_Handle->pI2Cx->DR;  			//for only 1 byte , no need for buffer++(increment)


	}

	//	Procedure if the length is greater than one  (len >1)
	if( len >1)
	{
		//Clear the ADDR flag
		I2C_ClearADDRFlag(pI2C_Handle);

		for ( uint32_t i= len; i >0  ; i --)
		{

			//Wait untill the RxNE becomes 1
			while (! I2C_Get_FlagStatus(pI2C_Handle->pI2Cx, I2C_FLAG_SR1_RXNE));

			if ( i == 2)
			{
				//	Clear the Ack bit
				I2C_ManagaeAcking(pI2C_Handle->pI2Cx,I2C_ACK_DISABLE);

				//	Generate the Stop Bit
				if (Sr == I2C_DISABLE_SR)
				{
				I2C_GenerateStopCondition(pI2C_Handle->pI2Cx);
				}

			}
			//Read the data from Data Register into the buffer
			*pRxBuffer = pI2C_Handle->pI2Cx->DR;
			pRxBuffer++;


		}

	}

	//Re-Enable the ACK
	if (pI2C_Handle->I2C_Config.I2C_ACKControl == I2C_ACK_ENABLE) 		//if ack is enabled in structure ,then only enables the Ack in register
	{
	I2C_ManagaeAcking(pI2C_Handle->pI2Cx,I2C_ACK_ENABLE);
	}

}



/**********************************************************************************************************************************
 *
  * @fn					- I2C peripheral Control
  *
  * @brief				- Which controls the I2C peripheral
  *
  *	@param[in]			-  Address of RegDef_t Structure
  *	@param[in]			-  Enable or disable
  *	@param[in]			-
  *
  *	return				- none
  *
  *	@Note				- none

*/

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx , uint8_t EnorDi)
{

	if (EnorDi == ENABLE)
	{
		pI2Cx->I2C_CR1 |= (1 << I2C_CR1_PE);
	}
	else
	{
		pI2Cx->I2C_CR1 &= ~(1 << I2C_CR1_PE);
	}
}




/**********************************************************************************************************************************
 *
  * @fn					- I2C Get Flag Status
  *
  * @brief				- Which gives the flag status in SR register
  *
  *	@param[in]			-  Address of RegDef_t Structure
  *	@param[in]			-  flag name
  *	@param[in]			-
  *
  *	return				- none
  *
  *	@Note				- none

*/

uint8_t I2C_Get_FlagStatus(I2C_RegDef_t *pI2Cx, uint32_t Flag_Name)
{
	if (pI2Cx->SR1 & Flag_Name)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}





