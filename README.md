# stm32-hd44780
Simple library to drive an HD44780-compatible display with an STM32F1
microcontroller. Most character displays commonly used in hobby projects use
this display controller. Code should be easy to port to other
libopencm3-compatible processors.

## Running the example

    git clone https://git.drk.sc/Derecho/stm32-hd44780.git
    cd stm32-hd44780
    git submodule update --init
    cd libopencm3 && make && cd ..
    cd hd44780 && make
   
Having compiled the example you can now flash `example.elf` onto your microcontroller.

## Customised behaviour
As can be seen in the example, the library allows for you to set several
properties specific to your LCD unit. While this is not a requirement, doing so
enhances the ease of use of the library's functions.

These displays operate relatively slow compared to the ARM microcontrollers
you'll want to run this code on, and as such the library has to make use of
delays in the display driving code. The default delay implemented is not much
short of an ugly hack, and is hardcoded to an 8 Mhz clock speed (default on my
STM32F103C8T6). It is highly recommended to supply your own better delay
function, by setting the lcd_delay_ms function pointer.
