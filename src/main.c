#include <stdio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void main (void)
{
#ifdef STM32F1_MINIMAL	
	rcc_clock_setup_in_hse_8mhz_out_72mhz ();
	rcc_periph_clock_enable (RCC_GPIOC);
	
	gpio_set_mode (GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
	
	while (1) {	
		
		for (register uint32_t i = 24000000; i > 0; i--)
			;
			
		gpio_toggle (GPIOC, GPIO13);

	}
#endif
}
