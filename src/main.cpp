/*	Name: Jihan Shende
	Objective : Create a PWM signal output using 16bit Timer1 
	Frequency 1kHz on OC1A or OC1B

	OC1A on D9(Port B5)
	OC1B on D10(Port B6)
	OC1C on D11(Port B7)
	*/

#include <Arduino.h>

float DUTYPERCENT = 50;									// Duty cycle percent between 0 - 100 %

#define DUTYCYCLE  ((DUTYPERCENT/100)*8000) 			// Changes the duty cycle for the fast PWM signal

void setup() {
// put your setup code here, to run once:
	DDRB |= (1<<6);										// setting port B6 ON(D10 pin on the board)
	TCCR1A = 0b00100011;								// setting TCCR1A to fast pwm with channel B set to clear at compare

	TCCR1B = 0b00011001;								// setting TCCR1B to fast pwm with prescaler set of 1 to get better resolution

	TCCR1C = 0b00000000;								// Its 0x00 because we dont need to set any register for force compare on any channels

	OCR1A = 8000;										// 8MHz / 1kHz = 8000
	OCR1B = DUTYCYCLE;									// to set the duty cycle
}

void loop() {
// put your main code here, to run repeatedly:

DUTYPERCENT += 10;

// updates the duty cyle from 0 - 100 
//	if (DUTYPERCENT > 100)
// 		DUTYPERCENT = 0;
//	OCR1B = DUTYCYCLE;
//	delay(500);
}