// *** Documentation section
// This program  calculates the area of square shaped rooms
// Author : Nirmal Kumar 
// Date : 31/07/2020

// Pre-processor Driectives Section
// INCLUDES :List any enternal libraries we will refer to using 
//  like a#include tag

#include <stdio.h> // Diamond braces for system libraries
#include "uart.h" // when using user libraries we use ""

//Subroutines SECTION

// MAIN : Mandatory subroutine for any c program

int main(void){
	UART_Init(); // Call subroutine to Init uart library
	
	printf("This is program calculates areas of square shaped rooms");
	
}

