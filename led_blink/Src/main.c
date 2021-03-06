/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Nirmal Kumar
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
int main(void)
{
	//Address of clock control register (AHB1ENR)
	// base address + ENR offset value: 0x4002 3800 + 0x30 ==> 0x40023830
	uint32_t *pClockControlRegister = (uint32_t *)0x40023830;

	//Address of PortMode Register(GPIOA) +GPIO Port Mode Register(GPIO_Moder),we use 5TH
	// base address of GPIOA + GPIO Port Mode :0x4002 0000 + 0x00 ==>0x40020000
	uint32_t *pPortModeRegister =	  (uint32_t*)0x40020000;

	//Address of GPIO OUTPUT Register and offset value of that 5th
	// Base Address of GPIO output Register + offset value of that : 0x40020000 + 0x14 ==>0x40020014
	uint32_t *pPortAOutRegister =	  (uint32_t*)0x40020014;


	//1st enable the clock for GPIO A peripheral
	// creating a temp varialble to derefernce
	/*
	uint32_t temp=*pClockControlRegister; // This is Read Operation
	temp= temp | 0x01; 		//.Modifiy
	*pClockControlRegister=temp; //This is Write Operation
	*/

	//This is Short Hand
	*pClockControlRegister=*pClockControlRegister | (2>>1);



	//Configure the mode of I/O
	*pPortModeRegister = *pPortModeRegister &(~(3<<5));
	*pPortModeRegister |= (1<<10);

	while(1){
	//Configure the Port Out
	//Using the software delay
	*pPortAOutRegister |= (1<<5);

	for(uint32_t i =0;i<300000;i++);
	*pPortAOutRegister  = *pPortAOutRegister & (~(1<<5));

	for(uint32_t i =0;i<4500000;i++);
	}
}



