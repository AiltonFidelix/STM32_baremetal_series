#include "stm32f4xx.h"

#define LED_ON  GPIOC->ODR &= ~(1U << 13)
#define LED_OFF GPIOC->ODR |= (1U << 13)
#define BUTTON (1U<<0)

#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)

int main(void) {

	RCC->AHB1ENR |= GPIOAEN;  // Enable the clock access for GPIOA bus
	RCC->AHB1ENR |= GPIOCEN;  // Enable the clock access for GPIOC bus
	GPIOC->MODER |= (1U << 26); // Set PC13 as output

	// Set PA0 as input cleaning the bits 0 and 1
	GPIOA->MODER &= ~(1U << 0);
	GPIOA->MODER &= ~(1U << 1);

	while (1) {
		if (!(GPIOA->IDR & BUTTON)) {
			LED_ON;
		} else {
			LED_OFF;
		}
	}
}

