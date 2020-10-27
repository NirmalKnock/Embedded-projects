/* 
 * File:   Switch_Led.c
 * Author: Nirmal kumar
 *
 * Created on 26 October, 2020, 10:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000ul    // That is 16MHZ clock



int main(void){
    DDRB |= (1<<5); // Set DDRB as OUTPUT Mode B5
    //  Set DDRB INPUT Mode B0 as default
    PORTB |= 0<<5;
    
    while(1){
        if(!(PINB & 0x01)){ 
            _delay_ms(1);//read Pin state , if NOT 1 , then execute this 
            PORTB |= (1<<5);  // PORTB5 will Turn On (1)
            _delay_ms(1);
        }
        else{
            PORTB &= ~(1<<5);  // Else PORTB5 will OFF (0)
            _delay_ms(1);
        }
    }
 
    
    return 0; 
}
