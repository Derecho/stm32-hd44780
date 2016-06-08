#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "hd44780.h"

#define LCD_PORT GPIOB
#define LCD_RCC RCC_GPIOB
#define LCD_RS GPIO10
#define LCD_CLOCK GPIO11
#define LCD_4 GPIO12
#define LCD_5 GPIO13
#define LCD_6 GPIO14
#define LCD_7 GPIO15

void lcd_setup(void)
{
    rcc_periph_clock_enable(LCD_RCC);
    gpio_set_mode(LCD_PORT, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,
            LCD_RS | LCD_CLOCK | LCD_4 | LCD_4 | LCD_5 | LCD_6 | LCD_7);
}

void lcd_write(uint8_t byte, uint8_t rs)
{
    // Writes a byte to the display (rs must be either 0 or 1)

    // TODO
}

void lcd_reset(void)
{
    // Reset display from any state to 4-bit mode, first nibble.

    // TODO
}
