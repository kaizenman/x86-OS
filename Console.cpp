#include "Console.h"

volatile uint16_t * Console::pVGATextBuffer = 0;
uint16_t Console::x = 0;
uint16_t Console::y = 0;

void Console::Initialize()
{
    pVGATextBuffer = (volatile uint16_t *) 0xB8000;
}

void Console::WriteLine(const char * c, vga_color fg, vga_color bg)
{
    pVGATextBuffer = (volatile uint16_t *) 0xB8000 + uint16_t(y * 80 + x);
    for (const char * it = c; *it != '\0'; ++it) {
        if (x == 80)
        {
            x = 0;
            y++;
        }

        if (y == 20)
        {
            y = 0;
        }

        *pVGATextBuffer = *it | (fg | bg << 4) << 8;
        ++pVGATextBuffer;
        x++;
    }

    y++;
    x = 0;
}