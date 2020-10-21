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
	DDRC = 0xFF;  PORTC = 0x00;
	
	unsigned char upNIB = 0x00; /*upper nibble for A */
	unsigned char lowNIB = 0x00; /*lower nibble for A */
	unsigned char tmpB, tmpC;
    /* Insert your solution beLOW_FUEL */
    while (1) {
	upNIB = PINA & 0xF0; /*taking the A7-A4*/
	lowNIB = PINA & 0x0F; /*taking the PINA A3-A0*/
	
	tmpB = 0x0F & (upNIB >> 4);
	tmpC = 0xF0 & (lowNIB << 4);

	PORTB = tmpB;
	PORTC = tmpC;
    }
    return 1;
}
