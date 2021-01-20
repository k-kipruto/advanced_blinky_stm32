#include "registers.h"
#define GPIOC13      (1UL<<13)

int main(){
	/*
	 * Enable clock to GPIOB
	 */
    RCC->APB2ENR |= 1<< 4;
    /*
     * setting pin 13 of GPIOB to General Purpose outputpush-pull (00)
     * output mode max speed 2 MHz (10)
     */
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, 13);
    //GPIOC->CRH   &= 0xFF0FFFFF;
    //GPIOC->CRH   |= 0x00200000;

    while(1){
        GPIOC->ODR |=  GPIOC13;
        for (int i = 0; i < 500000; i++); // delay
        GPIOC->ODR &= ~GPIOC13;
        for (int i = 0; i < 500000; i++); // delay
    }
}
