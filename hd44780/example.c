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
    return 0;
}
