/*
 * Cooler_app.c
 *
 * Created: 2/17/2023 3:00:56 PM
 * Author : Dell_G3
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Seven_Seg.h"
#include "ADC.h"

uint8_t getTemp();
void display_Temp_Speed(uint8_t temp,uint8_t speed);
uint8_t getSpeed(uint8_t temp);
int main(void)
{
    /* Replace with your application code */
	seven_seg_init();
	LCD_init();
	ADC_init();
	PWM1_OC1A_init();
	SETBIT(DDRD,6);//IN2 pin is output
     //IN1 -->clock wise
	

   SETBIT(DDRB,3);//led & buzzer

    while (1) {
		uint8_t temperature = getTemp();				// Get current temperature
		uint8_t speed_duty_cycle = getSpeed(temperature);			// Get speed of motor according to the current temperature
		PWM1_OC1A_duty(speed_duty_cycle);	//to apply speed to a motor 
		display_Temp_Speed(temperature, speed_duty_cycle);			// Display temperature and speed of motor on screen
		
    }
}


uint8_t getTemp()
{	
	/* 4.88 m.v for level --> 5 V / 1023 
	   ADC_read return number of the level multiply it by 4.88 = V_out m.v from sens 
	   T c = V_out m.v / 10.00 m.v --> 10 mv/c */
	uint8_t temp = ((ADC_read(0)*4.88)/10.00) ;	//temp in C
	return temp;
}
uint8_t getSpeed(uint8_t temp)
{
	uint8_t duty_cycle;
	if(temp>35){
		SETBIT(PORTB,3);//led & buzzer  ON
		if((temp >  35 ) && (temp < 38 ))		duty_cycle = 50;
		else if((temp >= 38 ) && (temp < 40 ))	duty_cycle = 60;
		else if((temp >= 40 ) && (temp < 42 ))	duty_cycle = 70;
		else if((temp >= 42 ) && (temp < 45 ))	duty_cycle = 80;
		else if((temp >= 45 ) && (temp < 48 ))	duty_cycle = 90;
		else	duty_cycle = 100;
	}
	else{
		duty_cycle=0;
		CLRBIT(PORTB,3);//led & buzzer  OFF
	}
	return duty_cycle;
}
void display_Temp_Speed(uint8_t temp,uint8_t speed){
	for(uint8_t i=0;i<125;i++){
		seven_seg_write(temp/10,1);
		seven_seg_write(temp%10,2);
	}
	LCD_write_command(0x01); // clear
	LCD_write_number(temp);
		
	LCD_write_command( 0xc0);//second line
	LCD_write_number(speed);
}
