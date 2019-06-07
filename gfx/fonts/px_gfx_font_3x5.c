/*******************************************************************************
*      ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM   *
*     |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /      *
*     | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /       *
*     |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \       *
*     |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\      *
*                                                                              *
*******************************************************************************/
#include "px_gfx.h"

static const uint8_t px_gfx_font_3x5_data[] = 
{

    // ' ' ; w = 3, h = 6,
    0x20,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '!' ; w = 3, h = 6,
    0x21,
    // .O.
    // .O.
    // .O.
    // ...
    // .O.
    // ...
    0x40, 
    0x40, 
    0x40, 
    0x00, 
    0x40, 
    0x00,

    // '"' ; w = 3, h = 6,
    0x22,
    // O.O
    // O.O
    // ...
    // ...
    // ...
    // ...
    0xa0, 
    0xa0, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '#' ; w = 3, h = 6,
    0x23,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '$' ; w = 3, h = 6,
    0x24,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '%' ; w = 3, h = 6,
    0x25,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '&' ; w = 3, h = 6,
    0x26,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // ''' ; w = 3, h = 6,
    0x27,
    // .O.
    // .O.
    // ...
    // ...
    // ...
    // ...
    0x40, 
    0x40, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // '(' ; w = 3, h = 6,
    0x28,
    // .O.
    // O..
    // O..
    // O..
    // .O.
    // ...
    0x40, 
    0x80, 
    0x80, 
    0x80, 
    0x40, 
    0x00,

    // ')' ; w = 3, h = 6,
    0x29,
    // O..
    // .O.
    // .O.
    // .O.
    // O..
    // ...
    0x80, 
    0x40, 
    0x40, 
    0x40, 
    0x80, 
    0x00,

    // '*' ; w = 3, h = 6,
    0x2a,
    // ...
    // .O.
    // OOO
    // .O.
    // ...
    // ...
    0x00, 
    0x40, 
    0xe0, 
    0x40, 
    0x00, 
    0x00,

    // '+' ; w = 3, h = 6,
    0x2b,
    // ...
    // .O.
    // OOO
    // .O.
    // ...
    // ...
    0x00, 
    0x40, 
    0xe0, 
    0x40, 
    0x00, 
    0x00,

    // ',' ; w = 3, h = 6,
    0x2c,
    // ...
    // ...
    // ...
    // .O.
    // O..
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x40, 
    0x80, 
    0x00,

    // '-' ; w = 3, h = 6,
    0x2d,
    // ...
    // ...
    // OOO
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0xe0, 
    0x00, 
    0x00, 
    0x00,

    // '.' ; w = 3, h = 6,
    0x2e,
    // ...
    // ...
    // ...
    // .O.
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x40, 
    0x00, 
    0x00,

    // '/' ; w = 3, h = 6,
    0x2f,
    // ...
    // ..O
    // .O.
    // O..
    // ...
    // ...
    0x00, 
    0x20, 
    0x40, 
    0x80, 
    0x00, 
    0x00,

    // '0' ; w = 3, h = 6,
    0x30,
    // OOO
    // O.O
    // O.O
    // O.O
    // OOO
    // ...
    0xe0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0xe0, 
    0x00,

    // '1' ; w = 3, h = 6,
    0x31,
    // .O.
    // OO.
    // .O.
    // .O.
    // OOO
    // ...
    0x40, 
    0xc0, 
    0x40, 
    0x40, 
    0xe0, 
    0x00,

    // '2' ; w = 3, h = 6,
    0x32,
    // OOO
    // ..O
    // .O.
    // O..
    // OOO
    // ...
    0xe0, 
    0x20, 
    0x40, 
    0x80, 
    0xe0, 
    0x00,

    // '3' ; w = 3, h = 6,
    0x33,
    // OOO
    // ..O
    // .OO
    // ..O
    // OOO
    // ...
    0xe0, 
    0x20, 
    0x60, 
    0x20, 
    0xe0, 
    0x00,

    // '4' ; w = 3, h = 6,
    0x34,
    // O.O
    // O.O
    // OOO
    // ..O
    // ..O
    // ...
    0xa0, 
    0xa0, 
    0xe0, 
    0x20, 
    0x20, 
    0x00,

    // '5' ; w = 3, h = 6,
    0x35,
    // OOO
    // O..
    // OOO
    // ..O
    // OOO
    // ...
    0xe0, 
    0x80, 
    0xe0, 
    0x20, 
    0xe0, 
    0x00,

    // '6' ; w = 3, h = 6,
    0x36,
    // OOO
    // O..
    // OOO
    // O.O
    // OOO
    // ...
    0xe0, 
    0x80, 
    0xe0, 
    0xa0, 
    0xe0, 
    0x00,

    // '7' ; w = 3, h = 6,
    0x37,
    // OOO
    // ..O
    // ..O
    // .O.
    // .O.
    // ...
    0xe0, 
    0x20, 
    0x20, 
    0x40, 
    0x40, 
    0x00,

    // '8' ; w = 3, h = 6,
    0x38,
    // OOO
    // O.O
    // OOO
    // O.O
    // OOO
    // ...
    0xe0, 
    0xa0, 
    0xe0, 
    0xa0, 
    0xe0, 
    0x00,

    // '9' ; w = 3, h = 6,
    0x39,
    // OOO
    // O.O
    // OOO
    // ..O
    // OOO
    // ...
    0xe0, 
    0xa0, 
    0xe0, 
    0x20, 
    0xe0, 
    0x00,

    // ':' ; w = 3, h = 6,
    0x3a,
    // ...
    // .O.
    // ...
    // .O.
    // ...
    // ...
    0x00, 
    0x40, 
    0x00, 
    0x40, 
    0x00, 
    0x00,

    // ';' ; w = 3, h = 6,
    0x3b,
    // ...
    // .O.
    // ...
    // .O.
    // O..
    // ...
    0x00, 
    0x40, 
    0x00, 
    0x40, 
    0x80, 
    0x00,

    // '<' ; w = 3, h = 6,
    0x3c,
    // ..O
    // .O.
    // O..
    // .O.
    // ..O
    // ...
    0x20, 
    0x40, 
    0x80, 
    0x40, 
    0x20, 
    0x00,

    // '=' ; w = 3, h = 6,
    0x3d,
    // ...
    // OOO
    // ...
    // OOO
    // ...
    // ...
    0x00, 
    0xe0, 
    0x00, 
    0xe0, 
    0x00, 
    0x00,

    // '>' ; w = 3, h = 6,
    0x3e,
    // O..
    // .O.
    // ..O
    // .O.
    // O..
    // ...
    0x80, 
    0x40, 
    0x20, 
    0x40, 
    0x80, 
    0x00,

    // '?' ; w = 3, h = 6,
    0x3f,
    // .O.
    // O.O
    // ..O
    // .O.
    // .O.
    // ...
    0x40, 
    0xa0, 
    0x20, 
    0x40, 
    0x40, 
    0x00,

    // '\x0040' ; w = 3, h = 6,
    0x40,
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00, 
    0x00,

    // 'A' ; w = 3, h = 6,
    0x41,
    // OOO
    // O.O
    // OOO
    // O.O
    // O.O
    // ...
    0xe0, 
    0xa0, 
    0xe0, 
    0xa0, 
    0xa0, 
    0x00,

    // 'B' ; w = 3, h = 6,
    0x42,
    // OO.
    // O.O
    // OO.
    // O.O
    // OO.
    // ...
    0xc0, 
    0xa0, 
    0xc0, 
    0xa0, 
    0xc0, 
    0x00,

    // 'C' ; w = 3, h = 6,
    0x43,
    // .OO
    // O..
    // O..
    // O..
    // .OO
    // ...
    0x60, 
    0x80, 
    0x80, 
    0x80, 
    0x60, 
    0x00,

    // 'D' ; w = 3, h = 6,
    0x44,
    // OO.
    // O.O
    // O.O
    // O.O
    // OO.
    // ...
    0xc0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0xc0, 
    0x00,

    // 'E' ; w = 3, h = 6,
    0x45,
    // OOO
    // O..
    // OO.
    // O..
    // OOO
    // ...
    0xe0, 
    0x80, 
    0xc0, 
    0x80, 
    0xe0, 
    0x00,

    // 'F' ; w = 3, h = 6,
    0x46,
    // OOO
    // O..
    // OOO
    // O..
    // O..
    // ...
    0xe0, 
    0x80, 
    0xe0, 
    0x80, 
    0x80, 
    0x00,

    // 'G' ; w = 3, h = 6,
    0x47,
    // .OO
    // O..
    // O.O
    // O.O
    // .OO
    // ...
    0x60, 
    0x80, 
    0xa0, 
    0xa0, 
    0x60, 
    0x00,

    // 'H' ; w = 3, h = 6,
    0x48,
    // O.O
    // O.O
    // OOO
    // O.O
    // O.O
    // ...
    0xa0, 
    0xa0, 
    0xe0, 
    0xa0, 
    0xa0, 
    0x00,

    // 'I' ; w = 3, h = 6,
    0x49,
    // OOO
    // .O.
    // .O.
    // .O.
    // OOO
    // ...
    0xe0, 
    0x40, 
    0x40, 
    0x40, 
    0xe0, 
    0x00,

    // 'J' ; w = 3, h = 6,
    0x4a,
    // ..O
    // ..O
    // ..O
    // O.O
    // .O.
    // ...
    0x20, 
    0x20, 
    0x20, 
    0xa0, 
    0x40, 
    0x00,

    // 'K' ; w = 3, h = 6,
    0x4b,
    // O.O
    // O.O
    // OO.
    // O.O
    // O.O
    // ...
    0xa0, 
    0xa0, 
    0xc0, 
    0xa0, 
    0xa0, 
    0x00,

    // 'L' ; w = 3, h = 6,
    0x4c,
    // O..
    // O..
    // O..
    // O..
    // OOO
    // ...
    0x80, 
    0x80, 
    0x80, 
    0x80, 
    0xe0, 
    0x00,

    // 'M' ; w = 3, h = 6,
    0x4d,
    // O.O
    // OOO
    // O.O
    // O.O
    // O.O
    // ...
    0xa0, 
    0xe0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0x00,

    // 'N' ; w = 3, h = 6,
    0x4e,
    // O.O
    // OOO
    // OOO
    // O.O
    // O.O
    // ...
    0xa0, 
    0xe0, 
    0xe0, 
    0xa0, 
    0xa0, 
    0x00,

    // 'O' ; w = 3, h = 6,
    0x4f,
    // OOO
    // O.O
    // O.O
    // O.O
    // OOO
    // ...
    0xe0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0xe0, 
    0x00,

    // 'P' ; w = 3, h = 6,
    0x50,
    // OO.
    // O.O
    // O.O
    // OO.
    // O..
    // ...
    0xc0, 
    0xa0, 
    0xa0, 
    0xc0, 
    0x80, 
    0x00,

    // 'Q' ; w = 3, h = 6,
    0x51,
    // .O.
    // O.O
    // O.O
    // OOO
    // .OO
    // ...
    0x40, 
    0xa0, 
    0xa0, 
    0xe0, 
    0x60, 
    0x00,

    // 'R' ; w = 3, h = 6,
    0x52,
    // OO.
    // O.O
    // O.O
    // OO.
    // O.O
    // ...
    0xc0, 
    0xa0, 
    0xa0, 
    0xc0, 
    0xa0, 
    0x00,

    // 'S' ; w = 3, h = 6,
    0x53,
    // OOO
    // O..
    // OOO
    // ..O
    // OOO
    // ...
    0xe0, 
    0x80, 
    0xe0, 
    0x20, 
    0xe0, 
    0x00,

    // 'T' ; w = 3, h = 6,
    0x54,
    // OOO
    // .O.
    // .O.
    // .O.
    // .O.
    // ...
    0xe0, 
    0x40, 
    0x40, 
    0x40, 
    0x40, 
    0x00,

    // 'U' ; w = 3, h = 6,
    0x55,
    // O.O
    // O.O
    // O.O
    // O.O
    // OOO
    // ...
    0xa0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0xe0, 
    0x00,

    // 'V' ; w = 3, h = 6,
    0x56,
    // O.O
    // O.O
    // O.O
    // O.O
    // .O.
    // ...
    0xa0, 
    0xa0, 
    0xa0, 
    0xa0, 
    0x40, 
    0x00,

    // 'W' ; w = 3, h = 6,
    0x57,
    // O.O
    // O.O
    // O.O
    // OOO
    // O.O
    // ...
    0xa0, 
    0xa0, 
    0xa0, 
    0xe0, 
    0xa0, 
    0x00,

    // 'X' ; w = 3, h = 6,
    0x58,
    // O.O
    // O.O
    // .O.
    // O.O
    // O.O
    // ...
    0xa0, 
    0xa0, 
    0x40, 
    0xa0, 
    0xa0, 
    0x00,

    // 'Y' ; w = 3, h = 6,
    0x59,
    // O.O
    // O.O
    // .O.
    // .O.
    // .O.
    // ...
    0xa0, 
    0xa0, 
    0x40, 
    0x40, 
    0x40, 
    0x00,

    // 'Z' ; w = 3, h = 6,
    0x5a,
    // OOO
    // ..O
    // .O.
    // O..
    // OOO
    // ...
    0xe0, 
    0x20, 
    0x40, 
    0x80, 
    0xe0, 
    0x00,

    // The End
    0x00,
};

const px_gfx_font_t px_gfx_font_3x5 =
{
    .width  = 3,
    .height = 6,
    .data   = px_gfx_font_3x5_data,
};
