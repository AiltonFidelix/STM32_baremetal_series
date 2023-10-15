#include "stm32f4xx.h"

int main(void) {

	RCC->AHB1ENR |= (1U << 2);  // Enable the clock access for GPIOC bus
	GPIOC->MODER |= (1U << 26); // Set PC13 as output

	while (1) {
		GPIOC->ODR ^= (1U << 13);         // Toggle PC13
		for (int i = 0; i < 150000; i++); // Wait for a while
	}
}

