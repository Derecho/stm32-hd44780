#include <stdint.h>

void delay_ms(uint32_t delay);
void lcd_clock(void);
void lcd_setup(void);
void lcd_reset(void);
void lcd_write(uint8_t byte, uint8_t rs);
void lcd_display_settings(uint8_t on, uint8_t underline, uint8_t blink);
void lcd_print(char string[]);
