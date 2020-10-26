
/* 
 * File:   blink_led.c
 * Author: nirmal kumar
 *
 * Created on 26 October, 2020, 6:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000ul

int main(void) {
    DDRB|=1<<5;
  while(1){
    PORTB|=1<<5;
    _delay_ms(500);
    PORTB&=~(1<<5);
    _delay_ms(500);
  }
  
    return 0;
}