/*
 * Timer0.h
 *
 * Created: 11/19/2022 12:21:26 PM
 *  Author: safifi
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_macros.h"

void Timer0_normal_init(void);
void Timer0_CTC_init(uint8_t max);
void Timer0_freq_gen_init(uint8_t max);

#endif /* TIMER0_H_ */