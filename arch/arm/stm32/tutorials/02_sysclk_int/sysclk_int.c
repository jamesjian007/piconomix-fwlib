/* =============================================================================
     ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM
    |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /
    | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /
    |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \
    |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\

    Copyright (c) 2019 Pieter Conradie <https://piconomix.com>
 
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

============================================================================= */

/**
 *  @ingroup STM32_TUTORIALS 
 *  @defgroup STM32_TUT02_SYSCLK_INT 02_sysclk_int
 *  
 *  How to use the SysClk peripheral to generate a periodic interrupt.
 *  
 *  File(s): 
 *  - arch/arm/stm32/tutorials/02_sysclk_int/sysclk_int.c
 *  
 *  The LED flashes at 1 Hz (500 ms on; 500 ms off).
 *  
 */

#include "stm32l0xx.h"
#include "stm32l0xx_ll_bus.h"
#include "stm32l0xx_ll_gpio.h"

volatile uint32_t systick_delay;

// SysTick interrupt handler
void SysTick_Handler(void)
{
    // Delay started?
    if(systick_delay != 0)
    {
        // Decrement delay
        systick_delay--;
    }
}

void delay(void)
{
    // Reset delay to 500 ms
    systick_delay = 500;

    // Wait until delay has expired
    while(systick_delay != 0)
    {
        ;
    }
}

int main(void)
{
    // Enable GPIOH clock
    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOH);

    // Configure PH0 as a digital output
    LL_GPIO_SetPinMode(GPIOH, LL_GPIO_PIN_0, LL_GPIO_MODE_OUTPUT);

    // Configure SysTick peripheral to generate an interrupt every 1 ms
    SysTick_Config(2100);
    // Enable SysTick interrupt
    NVIC_EnableIRQ(SysTick_IRQn);

    // Repeat forever
    for(;;)
    {
        // Enable LED
        LL_GPIO_SetOutputPin(GPIOH, LL_GPIO_PIN_0);
        delay();

        // Disable LED
        LL_GPIO_ResetOutputPin(GPIOH, LL_GPIO_PIN_0);
        delay();
    }
}
