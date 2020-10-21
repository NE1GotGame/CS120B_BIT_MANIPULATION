/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x00;
	
	unsigned char tmpD;
	unsigned char tmpB;
    /* Insert your solution beLOW_FUEL */
    while (1) {
	tmpD = PIND & 0xFF;
	tmpB = PINB & 0x01;
	unsigned char airbagSensor = 0x00;
	unsigned short weight = ((tmpD << 1) | tmpB);
	
	if(weight >= 40){
			airbagSensor = 0x02;
		}
		else if( (weight > 5) && (weight <= 70) ){
			airbagSensor = 0x04;
		}
		else{
			airbagSensor = 0x00;
		}

		PORTB = airbagSensor;
    	}	
    return 1;
}
