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
            LCD_RS | LCD_CLOCK | LCD_4 | LCD_5 | LCD_6 | LCD_7);
}

void lcd_reset(void)
{
    // Resets display from any state to 4-bit mode, first nibble.

    // Set everything low first
    gpio_clear(LCD_PORT, LCD_RS | LCD_CLOCK | LCD_4 | LCD_5 | LCD_6 | LCD_7);

    // Reset strategy below as per wikipedia description, should recover
    // from any setting

    // Write 0b0011 twice
    gpio_set(LCD_PORT, LCD_5 | LCD_4);
    // Pulse clock
    gpio_set(LCD_PORT, LCD_CLOCK);
    gpio_clear(LCD_PORT, LCD_CLOCK);
    // Pulse clock
    gpio_set(LCD_PORT, LCD_CLOCK);
    gpio_clear(LCD_PORT, LCD_CLOCK);

    // Now write 0b0010
    gpio_clear(LCD_PORT, LCD_4);
    // Pulse clock
    gpio_set(LCD_PORT, LCD_CLOCK);
    gpio_clear(LCD_PORT, LCD_CLOCK);
}

void lcd_write(uint8_t byte, uint8_t rs)
{
    // Writes a byte to the display (rs must be either 0 or 1)

    // Retrieve current port state
    uint16_t port_state = gpio_port_read(LCD_PORT);

    // Write first nibble and register select
    port_state &= ~((0b1111 << LCD_4) | LCD_RS);
    port_state |= (((byte & 0b1111) << LCD_4) | (rs << LCD_RS));
    gpio_port_write(LCD_PORT, port_state);

    // Pulse clock
    gpio_set(LCD_PORT, LCD_CLOCK);
    gpio_clear(LCD_PORT, LCD_CLOCK);

    // Write second nibble (unchanged register select);
    port_state &= ~(0b1111 << LCD_4);
    port_state |= (((byte >> 4) & 0b1111) << LCD_4);
    gpio_port_write(LCD_PORT, port_state);

    // Pulse clock
    gpio_set(LCD_PORT, LCD_CLOCK);
    gpio_clear(LCD_PORT, LCD_CLOCK);
}
