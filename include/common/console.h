#pragma once
#include "types.h"

namespace x86_OS
{
    namespace common
    {
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

            static void Update_cursor(int x, int y);

        public:
            static void Write(const char* str, vga_color fg = VGA_COLOR_WHITE, vga_color bg = VGA_COLOR_BLACK);
            static void WriteHex(uint8_t key, vga_color fg = VGA_COLOR_WHITE, vga_color bg = VGA_COLOR_BLACK);
            static void WriteNumber(int8_t c, vga_color fg = VGA_COLOR_WHITE, vga_color bg = VGA_COLOR_BLACK);

            static volatile uint16_t * pVGATextBuffer;
        private:
            static const uint16_t maxRowChars 	 = 20;
            static const uint16_t maxColumnChars = 80;
            static uint16_t rowIndex;
            static uint16_t columnIndex;
        };
    }
}
