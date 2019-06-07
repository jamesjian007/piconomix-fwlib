/* =============================================================================
     ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM
    |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /
    | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /
    |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \
    |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\

    Copyright (c) 2018 Pieter Conradie <https://piconomix.com>
 
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
    
    Title:          px_flash.h : Internal FLASH write routines
    Author(s):      Pieter Conradie
    Creation Date:  2018-11-21

============================================================================= */

/* _____STANDARD INCLUDES____________________________________________________ */

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "px_flash.h"
#include "px_lib_stm32cube.h"
#include "px_dbg.h"

/* _____LOCAL DEFINITIONS____________________________________________________ */
PX_DBG_DECL_NAME("px_flash");

/* _____MACROS_______________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____LOCAL VARIABLES______________________________________________________ */

/* _____LOCAL FUNCTION DECLARATIONS__________________________________________ */

/* _____LOCAL FUNCTIONS______________________________________________________ */

/* _____GLOBAL FUNCTIONS_____________________________________________________ */
PX_ATTR_RAMFUNC void px_flash_unlock(void)
{
    uint32_t primask;

    // Save interrupt status
    primask = __get_PRIMASK();
    // Disable interrupts
    px_interrupts_disable();
    // Unlock PELOCK
    FLASH->PEKEYR = 0x89abcdef;
    FLASH->PEKEYR = 0x02030405;
    // Unlock PRGLOCK
    FLASH->PRGKEYR = 0x8c9daebf;
    FLASH->PRGKEYR = 0x13141516;
    // Restore interrupt status
    __set_PRIMASK(primask);
}

PX_ATTR_RAMFUNC void px_flash_lock(void)
{
    uint32_t primask;

    // Save interrupt status
    primask = __get_PRIMASK();
    // Disable interrupts
    px_interrupts_disable();
    // Lock PRGLOCK
    FLASH->PECR |= FLASH_PECR_PRGLOCK;
    // Lock PELOCK
    FLASH->PECR |= FLASH_PECR_PELOCK;
    // Restore interrupt status
    __set_PRIMASK(primask);
}

PX_ATTR_RAMFUNC void px_flash_erase_page(const uint32_t address)
{
    uint32_t primask;

    // Save interrupt status
    primask = __get_PRIMASK();
    // Disable interrupts
    px_interrupts_disable();
    // Enable page erase
    FLASH->PECR |= (FLASH_PECR_PROG | FLASH_PECR_ERASE);
    // Write 32-bit value in page to start erase sequence
    *(uint32_t *)address = (uint32_t)0;
    // Wait until erase has finished (not busy)
    while ((FLASH->SR & FLASH_SR_BSY) != 0)
    {
        continue;
    }
    // EOP (End Of Programming) Flag set?
    if((FLASH->SR & FLASH_SR_EOP) != 0)
    {
        // Reset EOP flag
        FLASH->SR = FLASH_SR_EOP;
    }
    // Disable page erase
    FLASH->PECR &= ~(FLASH_PECR_ERASE | FLASH_PECR_PROG);
    // Restore interrupt status
    __set_PRIMASK(primask);
}

PX_ATTR_RAMFUNC void px_flash_wr_half_page(const uint32_t address, const uint32_t * data)
{
    uint8_t i;
    uint32_t primask;

    // Save interrupt status
    primask = __get_PRIMASK();
    // Disable interrupts
    px_interrupts_disable();
    // Enable half page programming
    FLASH->PECR |= (FLASH_PECR_PROG | FLASH_PECR_FPRG);
    // Write half page by copying data (32-bits at a time)
    // The same address can be used as it is incremented internally
    for (i = 0; i < PX_FLASH_HALF_PAGE_SIZE_WORDS; i++)
    {
        *(uint32_t*)(address) = *data++;
    }
    // Wait until programming has finished (not busy)
    while ((FLASH->SR & FLASH_SR_BSY) != 0)
    {
        continue;
    }
    // EOP (End Of Programming) Flag set?
    if((FLASH->SR & FLASH_SR_EOP) != 0)
    {
        // Reset EOP flag
        FLASH->SR = FLASH_SR_EOP;
    }
    // Disable half page programming
    FLASH->PECR &= ~(FLASH_PECR_PROG | FLASH_PECR_FPRG);
    // Restore interrupt status
    __set_PRIMASK(primask);
}

