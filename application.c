/* 
 * File:   application.c
 * Author: Abdelrahman Mansour
 *
 * Created on August 4, 2024, 10:56 PM
 */

#include "application.h"
Std_ReturnType ret = E_NOT_OK;
uint8 dis;


/*
 * 
 */
lcd_8bit_t lcd_obj = {
  .lcd_rs.port = PORTA_INDEX,
  .lcd_rs.pin = PIN5,
  .lcd_rs.direction = GPIO_OUTPUT ,
  .lcd_rs.direction = LOW ,
  .lcd_en.port = PORTA_INDEX,
  .lcd_en.pin = PIN6,
  .lcd_en.direction = GPIO_OUTPUT ,
  .lcd_en.direction = LOW ,
  .lcd_data[0].port = PORTB_INDEX,
  .lcd_data[0].pin = PIN0,
  .lcd_data[0].direction = GPIO_OUTPUT,
  .lcd_data[0].logic = LOW,
  .lcd_data[1].port = PORTB_INDEX,
  .lcd_data[1].pin = PIN1,
  .lcd_data[1].direction = GPIO_OUTPUT,
  .lcd_data[1].logic = LOW,
  .lcd_data[2].port = PORTB_INDEX,
  .lcd_data[2].pin = PIN2,
  .lcd_data[2].direction = GPIO_OUTPUT,
  .lcd_data[2].logic = LOW,
  .lcd_data[3].port = PORTB_INDEX,
  .lcd_data[3].pin = PIN3,
  .lcd_data[3].direction = GPIO_OUTPUT,
  .lcd_data[3].logic = LOW,
  .lcd_data[4].port = PORTB_INDEX,
  .lcd_data[4].pin = PIN4,
  .lcd_data[4].direction = GPIO_OUTPUT,
  .lcd_data[4].logic = LOW,
  .lcd_data[5].port = PORTB_INDEX,
  .lcd_data[5].pin = PIN5,
  .lcd_data[5].direction = GPIO_OUTPUT,
  .lcd_data[5].logic = LOW,
  .lcd_data[6].port = PORTB_INDEX,
  .lcd_data[6].pin = PIN6,
  .lcd_data[6].direction = GPIO_OUTPUT,
  .lcd_data[6].logic = LOW,
  .lcd_data[7].port = PORTB_INDEX,
  .lcd_data[7].pin = PIN7,
  .lcd_data[7].direction = GPIO_OUTPUT,
  .lcd_data[7].logic = LOW,
};



int main() {
    ret = lcd_8bit_init(&lcd_obj);
    ret = lcd_8bit_send_string_pos(&lcd_obj,1,1,"distance=");
    init_ultrasonic();
    while(1){
        dis = measure_distance();
        ret = lcd_8bit_send_char_data_pos(&lcd_obj ,1,10,(dis/10)+48);
		ret = lcd_8bit_send_char_data_pos(&lcd_obj ,1,11,(dis%10)+48);
	    ret = lcd_8bit_send_string_pos(&lcd_obj,1,13,"cm");
		__delay_ms(500);
 
    }

    return (EXIT_SUCCESS);
}

