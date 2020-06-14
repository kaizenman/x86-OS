#include "types.h"

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

void print(const char * c, vga_color fg = VGA_COLOR_WHITE, vga_color bg = VGA_COLOR_BLACK)
{
    uint16_t * textBuffer = (uint16_t *) 0xB8000;
    for (const char * it = c; *it != '\0'; ++it)
    {
        *textBuffer = *it | (fg | bg << 4) << 8;
        ++textBuffer;
    }
}

extern "C" void kernelMain()
{
    const char* a = "aaaaa";

    print(a, VGA_COLOR_RED, VGA_COLOR_GREEN);

    while(1)
    {
        
    }
}
