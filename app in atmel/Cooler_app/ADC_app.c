/*
 * ADC_app.c
 *
 * Created: 12/2/2022 1:29:02 PM
 *  Author: safifi
 */ 


#include "ADC.h"
#include "lcd.h"

int main(void)
{
	LCD_init();
	ADC_init();
    while(1)
    {
		LCD_write_command(0x1);
		LCD_write_number(ADC_read(0));
		_delay_ms(200);
        //TODO:: Please write your application code 
    }
}