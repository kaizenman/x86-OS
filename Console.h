#ifndef __CONSOLE_H
#define __CONSOLE_H

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

class Console
{
private:
	Console() = default;
	~Console() = default;
public:
	static void Initialize();
	static void WriteLine(const char * c, vga_color fg = VGA_COLOR_WHITE, vga_color bg = VGA_COLOR_BLACK);

	static volatile uint16_t * pVGATextBuffer;
private:
	static const uint16_t xMax = 80;
	static const uint16_t yMax = 20;
	static uint16_t x;
	static uint16_t y;
};

#endif // __CONSOLE_H