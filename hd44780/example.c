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
    // We are using a 16x2 LCD, second line starting on address 0x40.
    // These settings are optional but enable smart functions.
    lcd_chars = 16;
    lcd_lines = 2;
    uint8_t addresses[] = {0x40};
    lcd_line_addresses = addresses;

    // Initial stuff
    lcd_setup();
    lcd_reset();
    lcd_display_settings(1, 1, 1);

    delay_ms(1000);

    while(1) {
        // Simple functions
        lcd_clear();
        lcd_write('A', 1);
        lcd_write('B', 1);
        lcd_write('C', 1);
        lcd_display_address(0x40);
        lcd_print("stm32-hd44780");
        delay_ms(3000);

        // Smart functions (1)
        lcd_clear();
        lcd_print("Foo\n   Bar");
        delay_ms(3000);

        // Smart functions (2)
        lcd_clear();
        lcd_print("A longer sentence");
        delay_ms(3000);
    }

    return 0;
}
