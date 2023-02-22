/*
 * ADC.c
 *
 * Created: 12/2/2022 1:29:12 PM
 *  Author: safifi
 */ 
#include "ADC.h"

void ADC_init(void){
	SETBIT(ADMUX,6); // AVCC
	SETBIT(ADCSRA,ADEN); // ENABLE ADC
	ADCSRA |= 0b111; // prescaler 128 > freq = 125Khz
}
uint16_t ADC_read(uint8_t ch){//channel
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	SETBIT(ADCSRA,ADSC); // Start conversion
    while(READBIT(ADCSRA, ADSC) == 1){}
	//while(READBIT(ADCSRA, ADIF) == 0){}
	//SETBIT(ADCSRA,ADIF);
	
	return ADC;
}
