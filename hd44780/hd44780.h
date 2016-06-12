#include <stdint.h>

// It is recommended to supply your own delay function to the lcd_delay_ms
// function pointer.

void _lcd_delay_ms(uint32_t delay);
void lcd_clock(void);
void lcd_setup(void);
void lcd_reset(void);
void lcd_write(uint8_t byte, uint8_t rs);
void lcd_display_settings(uint8_t on, uint8_t underline, uint8_t blink);
void lcd_print(char string[]);
