#include "Console.h"
#include "Memory.h"

volatile uint16_t * Console::pVGATextBuffer = 0;
uint16_t Console::rowIndex = 0;
uint16_t Console::columnIndex = 0;



void Console::Initialize()
{
    pVGATextBuffer = (volatile uint16_t *) CPUMemoryMap::PCIVideoMemoryTextModeStart;
}

void Console::WriteChar(unsigned char c, unsigned char forecolour, unsigned char backcolour, uint8_t x, uint8_t y)
{
     uint16_t attrib = (backcolour << 4) | (forecolour & 0x0F);
     volatile uint16_t * where;
     where = (volatile uint16_t *)CPUMemoryMap::PCIVideoMemoryTextModeStart + (y * 80 + x) ;
     *where = c | (attrib << 8);
}

void Console::Update_cursor(int x, int y)
{
	uint16_t pos = y * maxColumnChars + x;
    asm volatile ("outb %0, %1" : : "a" (0x3D4), "Nd" (0x0F));
    asm volatile ("outb %0, %1" : : "a" (0x3D5), "Nd" ((uint8_t) (pos & 0xFF)));
    asm volatile ("outb %0, %1" : : "a" (0x3D4), "Nd" (0x0E));
    asm volatile ("outb %0, %1" : : "a" (0x3D5), "Nd" ((uint8_t) ((pos >> 8) & 0xFF)));
}



void Console::Write(const char * str, vga_color fg, vga_color bg)
{
    static uint16_t* VideoMemory = (uint16_t*)CPUMemoryMap::PCIVideoMemoryTextModeStart;

    static uint8_t x=0,y=0;

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