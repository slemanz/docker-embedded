#include "stm32f411xx.h"
#include "gpio_bits.h"

// WeAct BlackPill: user LED is on PC13 and it is active low
#define LED_PORT		GPIOC
#define LED_PIN			13

#define BLINK_DELAY		400000U


static void delay(__vo uint32_t count)
{
	while(count--);
}

static void led_setup(void)
{
	GPIOC_PCLK_EN();

	LED_PORT->MODER  = gpio_moder_set(LED_PORT->MODER, LED_PIN, GPIO_MODE_OUT);
	LED_PORT->OTYPER = gpio_otyper_set(LED_PORT->OTYPER, LED_PIN, GPIO_OP_TYPE_PP);
}

int main(void)
{
	led_setup();

	while(1)
	{
		LED_PORT->ODR = gpio_odr_toggle(LED_PORT->ODR, LED_PIN);
		delay(BLINK_DELAY);
	}
}