
/*
 * struct_pointrer.c
 *
 *  Created on: Sep 16, 2020
 *      Author: nirmal kumar
 */

#include<stdio.h>
#include<stdint.h>


//  Creating the structure
struct Bigdata{
	uint32_t data1;
	uint16_t data2;
	uint8_t  data3;
	float    data4;

};


void displayMembersElements(struct Bigdata *pdata);



int main(void ){

	struct Bigdata data;
	data.data1=20;
	data.data2=30;
	data.data3=40;
	data.data4=5.5;
	printf("Data of before using the pointer %ld\n",data.data1);

	displayMembersElements(&data); // calling the function

	// This method is for use single pointer and hard to do , so we go another method
	//To change the value based on the Base address ,then
	/*

	uint32_t *pPtr =(uint32_t*)&data;
	//Modify the first element
	*pPtr=100;
	*/

	//Another Method while using the Pointer
	/*
	struct Bigdata *pData;

	*pData =&data// from the struct variable

	pData->data1= 100;
	pData->data2= 200;
	pData->data3= 300;
	pData->data4= 7.3
	printf("Data of after using the pointer %d\n",data.data1);
	*/


	// access the address to another functionn


	return 0;

}

void displayMembersElements(struct Bigdata *pdata){
	//Accessing the data from main function
	printf("The address of data1 is %d",pdata->data2);
	printf("The address of data1 is %d",pdata->data3);
	printf("The address of data1 is %f",pdata->data4);
	printf("The address of data1 is %ld",pdata->data1);

}

