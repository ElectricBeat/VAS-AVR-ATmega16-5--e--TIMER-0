/*
 * TIMER0.c
 *
 * Created: 09-07-2024 13:00:22
 * Author : SRIDHAR
 */ 

#include <avr/io.h>

void T0delay();

int main(void)
{
	DDRB	=	0xFF;				/* PORTB as output */
	PORTB	=	0x00;

    	while(1)  					/* Repeat forever */
    	{
			PORTB	=	~PORTB;
			T0delay();
    	}
}

void T0delay()
{
	TCCR0 = (1<<CS00);				/* Timer0, normal mode, /No prescalar */
	TCNT0 = 0xF6;					/* Load TCNT0, count for 35us */
	while((TIFR&0x01)==0);			/* Wait for TOV0 to roll over */
	TCCR0 = 0;
	TIFR = 0x01;					/* Clear TOV0 flag */
}