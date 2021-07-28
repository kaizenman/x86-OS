#include <drivers/vga.h>

using namespace x86_OS::drivers;

void VGA::WriteRegisters(uint8_t* registers)
{
    // misc
    miscPort.Write(*(registers++));

    // sequencer
    for (uint8_t i = 0; i < 5; ++i) {
        sequencerIndexPort.Write(i);
        sequencerDataPort.Write(*(registers++));
    }

    // cathode ray tube controller
    crtcIndexPort.Write(0x03);
    crtcDataPort.Write(crtcDataPort.Read() | 0x80);
    crtcIndexPort.Write(0x11);
    crtcDataPort.Write(crtcDataPort.Read() & ~0x80);

    registers[0x03] = registers[0x03] | 0x80;
    registers[0x11] = registers[0x11] & ~0x80;

    for (uint8_t i = 0; i < 25; ++i) {
        crtcIndexPort.Write(i);
        crtcDataPort.Write(*(registers++));
    }

    // graphics controller
    for (uint8_t i = 0; i < 9; ++i) {
        graphicsControllerIndexPort.Write(i);
        graphicsControllerDataPort.Write(*(registers++));
    }

    // attribute controller
    for (uint8_t i = 0; i < 21; ++i) {
        attributeControllerResetPort.Read();
        attributeControllerIndexPort.Write(i);
        attributeControllerWritePort.Write(*(registers++));
    }

    attributeControllerResetPort.Read();
    attributeControllerIndexPort.Write(0x20);

}

uint8_t* VGA::GetFrameBufferSegment()
{
    graphicsControllerIndexPort.Write(0x06);
    uint8_t segmentNumber = (graphicsControllerDataPort.Read() >> 2) & 0x03;
    switch (segmentNumber)
    {
        case 0: return (uint8_t*)0x00000;
        case 1: return (uint8_t*)0xA0000;
        case 2: return (uint8_t*)0xB0000;
        case 3: return (uint8_t*)0xB8000;
        default:
            break;
    }

}
void VGA::PutPixel(int32_t x, int32_t y, vga_color colorCode)
{
    if(x < 0 || 320 <= x || y < 0 || 200 <= y)
        return;

    uint8_t* pixelAddress = GetFrameBufferSegment() + 320*y + x;
    *pixelAddress = colorCode;
}

void VGA::FillRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, vga_color color)
{
    for (int32_t Y = 0; Y < y + h; ++Y) {
        for (int32_t X = 0; X < x + w; ++X) {
            PutPixel(X, Y, color);
        }
    }
}

vga_color VGA::GetColor(uint8_t r, uint8_t g, uint8_t b)
{
    if (r == 0x00 && g == 0x00 && b == 0xA8)
        return vga_color::VGA_COLOR_BLUE;

    return vga_color::VGA_COLOR_RED;
}

VGA::VGA() :
    miscPort(0x3c2),
    crtcIndexPort(0x3d4),
    crtcDataPort(0x3d5),
    sequencerIndexPort(0x3c4),
    sequencerDataPort(0x3c5),
    graphicsControllerIndexPort(0x3ce),
    graphicsControllerDataPort(0x3cf),
    attributeControllerIndexPort(0x3c0),
    attributeControllerReadPort(0x3c1),
    attributeControllerWritePort(0x3c0),
    attributeControllerResetPort(0x3da)
{

}
VGA::~VGA()
{

}

bool VGA::SupportsMode(uint32_t width, uint32_t height, uint32_t colorDepth)
{
    return width == 320 && height == 200 && colorDepth == 8;
}
bool VGA::SetMode(uint32_t width, uint32_t height, uint32_t colorDepth)
{
    if (!SupportsMode(width, height, colorDepth)) return false;

    unsigned char g_320x200x256[] =
    {
    /* MISC */
        0x63,
    /* SEQ */
        0x03, 0x01, 0x0F, 0x00, 0x0E,
    /* CRTC */
        0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
        0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x9C, 0x0E, 0x8F, 0x28,	0x40, 0x96, 0xB9, 0xA3,
        0xFF,
    /* GC */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
        0xFF,
    /* AC */
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x41, 0x00, 0x0F, 0x00,	0x00
    };

    WriteRegisters(g_320x200x256);
    return true;

}
void VGA::PutPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b)
{
    PutPixel(x, y, GetColor(r, g, b));
}