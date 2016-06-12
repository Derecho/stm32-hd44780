#include "hd44780.h"
#include "example.h"

void delay_ms(uint32_t delay)
{
    uint32_t cycles = (delay * 8000)/5;  // 8 Mhz, CMP+BEQ+NOP+ADDS+B
    uint32_t i = 0;
    while(i++ < cycles) {
        __asm__("nop");
    }
}

int main(void)
{
    lcd_setup();
    lcd_reset();
    lcd_display_settings(1, 1, 1);

    delay_ms(3000);

    lcd_write(0b00000001, 0);  // Clear display, cursor home
    lcd_write('A', 1);
    lcd_write('B', 1);
    lcd_write('C', 1);
    lcd_write(0b11000000, 0);  // Set display address to 0x40 (second line)
    lcd_print("stm32-hd44780");

    while(1);

    return 0;
}
