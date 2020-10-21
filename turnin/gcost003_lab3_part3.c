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
	DDRA = 0x00;  PORTA = 0xFF;  
	DDRC = 0xFF;  PORTC = 0x00; 

	unsigned char fuelLVL;  
	unsigned char LED;	

    /* Insert your solution beLOW_FUEL */
    while (1) {
	fuelLVL = PINA & 0x0F; //fuel-level sensor that sets PA3..PA0
	LED = 0x00;
	unsigned char LOW_FUEL = 0;
	unsigned char key = PINA & 0x10;
	unsigned char seated = PINA & 0x20;
	unsigned char seatbelt = PINA & 0x40;

	if (PINA <= 4){
		LOW_FUEL = 1;
	}
	if (fuelLVL == 0x01 || fuelLVL == 0x02){
		LED = LED | 0x20;
	}
	else if (fuelLVL== 3 || fuelLVL== 4){
		LED = LED | 0x30;
	}
	else if(fuelLVL == 5 || fuelLVL == 6){
		LED = LED | 0x38;
	}
	else if (fuelLVL >=  7 && fuelLVL <= 9){
		LED = LED | 0x3C;
	}
	else if (fuelLVL >= 10 && fuelLVL <=12){
		LED = LED | 0x3E;
	}
	else if (fuelLVL >= 13 && fuelLVL <= 15){
		LED = LED | 0x3F;
	}
		
	if(LOW_FUEL == 1){
		LED = LED | 0x40;	
	}
	if((key == 0x10) && (seated == 0x20) && (seatbelt == 0x00)) {
		LED = LED | 0x80;
	}
	PORTC = LED;
    }
    return 1;
}

