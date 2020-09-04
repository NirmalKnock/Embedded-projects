/*
 * main.c
 *
 *  Created on: 04-Sep-2020
 *      Author: nirmal kumar
 */

#include<stdio.h>
int main(void){
	float number1,number2,numbers3;
	float average;
	printf("\nEnter the 1st number :");
	fflush(stdout);
	scanf("%f",&number1);
	printf("\nEnter the 2nd number :");
	fflush(stdout);
	scanf("%f",&number2);
	printf("\n Enter the 3rd number :");
	fflush(stdout);
	scanf("%f",&numbers3);

	average=(number1+number2+numbers3)/3;

	printf("\nThe average is : %f",average);

	//After screen closes automaticaty due to no data at final scan at buffer
	// so implement the baset way using while with char

	printf("Press enter to exit \n");

	while(getchar()!='\n'){

	}

	getchar();


}

