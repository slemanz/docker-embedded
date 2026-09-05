#ifndef INC_GPIO_BITS_H_
#define INC_GPIO_BITS_H_

// pure bit math for the GPIO registers, no hardware access
// the firmware uses it and the host tests check it
#include <stdint.h>

/*
 * GPIO pin possible modes
 */

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1

/*
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

/********************************************************************************************
 * 								APIs supported by this module
 ********************************************************************************************/

uint32_t gpio_moder_set(uint32_t moder, uint8_t pin, uint8_t mode);
uint32_t gpio_otyper_set(uint32_t otyper, uint8_t pin, uint8_t otype);
uint32_t gpio_odr_toggle(uint32_t odr, uint8_t pin);

#endif /* INC_GPIO_BITS_H_ */