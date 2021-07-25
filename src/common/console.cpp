#include <common/console.h>
#include <common/io_memory_map.h>
#include <common/cpu_memory_map.h>

using namespace x86_OS::common;
volatile uint16_t * Console::pVGATextBuffer = (volatile uint16_t *) cpu_memory_map::PCIVideoMemoryTextModeStart;
uint16_t Console::rowIndex = 0;
uint16_t Console::columnIndex = 0;
uint8_t x=0,y=0;

void Console::WriteHex(uint8_t key, vga_color forecolour, vga_color backcolour)
{
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    Console::Write(foo);
}

void Console::WriteNumber(int8_t c, vga_color forecolour, vga_color backcolour)
{
    static uint16_t* VideoMemory = (uint16_t*)cpu_memory_map::PCIVideoMemoryTextModeStart;
    bool negative = c < 0;
    if (negative)
        c *= -1;
    char str[4];
    str[2] = '\0';
    str[0] = negative ? '-' : '+';
    uint8_t i = 2;
    while (c > 0 && i >= 0) {
        uint8_t d = c % 10;
        str[i] = d + '0';
        c /= 10;
        --i;
    }

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }


}
/*
void Console::Update_cursor(int x, int y)
{
    uint16_t pos = y * maxColumnChars + x;
    asm volatile ("outb %0, %1" : : "a" (0x3D4), "Nd" (0x0F));
    asm volatile ("outb %0, %1" : : "a" (0x3D5), "Nd" ((uint8_t) (pos & 0xFF)));
    asm volatile ("outb %0, %1" : : "a" (0x3D4), "Nd" (0x0E));
    asm volatile ("outb %0, %1" : : "a" (0x3D5), "Nd" ((uint8_t) ((pos >> 8) & 0xFF)));
}
*/



void Console::Write(const char * str, vga_color fg, vga_color bg)
{
    static uint16_t* VideoMemory = (uint16_t*)cpu_memory_map::PCIVideoMemoryTextModeStart;

    

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}
