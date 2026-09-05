#include "gpio_bits.h"


uint32_t gpio_moder_set(uint32_t moder, uint8_t pin, uint8_t mode)
{
	moder &= ~(0x3U << (2U * pin));
	moder |=  ((mode & 0x3U) << (2U * pin));

	return moder;
}

uint32_t gpio_otyper_set(uint32_t otyper, uint8_t pin, uint8_t otype)
{
	otyper &= ~(0x1U << pin);
	otyper |=  ((otype & 0x1U) << pin);

	return otyper;
}

uint32_t gpio_odr_toggle(uint32_t odr, uint8_t pin)
{
	return (odr ^ (0x1U << pin));
}