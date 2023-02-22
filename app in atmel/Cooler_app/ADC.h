/*
 * ADC.h
 *
 * Created: 12/2/2022 1:29:21 PM
 *  Author: safifi
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "std_macros.h"

void ADC_init(void);

uint16_t ADC_read(uint8_t ch);

#endif /* ADC_H_ */