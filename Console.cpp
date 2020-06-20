#include "Console.h"
#include "Memory.h"

volatile uint16_t * Console::pVGATextBuffer = 0;
uint16_t Console::rowIndex = 0;
uint16_t Console::columnIndex = 0;

void Console::Initialize()
{
    pVGATextBuffer = (volatile uint16_t *) CPUMemoryMap::PCIVideoMemoryTextModeStart;
}

void Console::WriteLine(const char * c, vga_color fg, vga_color bg)
{
    pVGATextBuffer = (volatile uint16_t *) CPUMemoryMap::PCIVideoMemoryTextModeStart + uint16_t(columnIndex * 80 + rowIndex);
    for (const char * it = c; *it != '\0'; ++it) {
        if (rowIndex == maxRowChars)
        {
            rowIndex = 0;
            columnIndex++;
        }

        if (columnIndex == maxColumnChars)
        {
            columnIndex = 0;
        }

        *pVGATextBuffer = *it | (fg | bg << 4) << 8;
        ++pVGATextBuffer;
        rowIndex++;
    }

    columnIndex++;
    rowIndex = 0;
}