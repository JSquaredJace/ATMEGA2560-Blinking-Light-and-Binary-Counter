/*
 * Lab02 - Blinking Light and Binary Counter
 * Author : Jace Johnson
 * Created: 2/1/2020 2:19:15 PM
 * 	Rev 1	2/1/2020
 * Description:	ATMEGA2560 turns on and off 4 LEDs in a binary counting 
 *				pattern. The count is iterated every 0.5 sec. This is done by
 *				incrementing PORTB's high nybble, which supply the 4 LEDs.
 *
 * Hardware:	ATMega 2560 operating at 16 MHz
 *		LEDs with series resistors connected to Digital Pins 10 - 13
 * 
 */


#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

/*
 * Function:  main 
 *
 *  Initializes Port B pins as output and turns LEDs on and off in one of two
 *  patterns (depending on commented code): Blinking LED OR Binary Counter
 *
 *  returns:	1	program exits unexpectedly
 */
int main(void)
{
	DDRB |= 0xF0;	//set port B pins 4 - 7 as output
	PORTB = 0x00;	//set port B to all low
	while(1){
		//Blink
		//PORTB ^= 0x80;	//toggle port B pin 7
		
		_delay_ms(500);	//wait 500 ms
		//Binary Count
		PORTB += 0x10;		//add 1 to port B high nybble
	}
	return 1;	//error if we leave the main loop
}