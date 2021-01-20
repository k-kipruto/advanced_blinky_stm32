#include "registers.h"

void gpio_set_mode(GPIO_Type* GPIOx, uint8_t mode, uint8_t cnf, uint16_t pin){
	uint16_t offset=0;
	/*
	 * finding offset of the MODE and CNF for the pin
	 */
	offset=(pin<8)? (pin*4):((pin-8)*4);

	/*
	 * determing if the pin can be configured using CRH or CRL
	 * registers
	 */
	if(pin<8){
		GPIOx->CRL &= ~(0xf<<offset);
		GPIOx->CRL |= (mode<<offset) | (cnf<<(offset+2));
	}
	else if(pin>7){
		GPIOx->CRH &= ~(0xf<<offset);
		GPIOx->CRH |= (mode<<offset) | (cnf<<(offset+2));
	}

}



