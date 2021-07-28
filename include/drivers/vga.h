#pragma once

#include <common/types.h>
#include <hardware/port.h>
#include <drivers/driver.h>
#include <common/console.h>

using namespace x86_OS::hardware;
using namespace x86_OS::common;

namespace x86_OS
{
    namespace drivers
    {
        class VGA
        {
        protected:
            Port8Bit miscPort;
            Port8Bit crtcIndexPort;
            Port8Bit crtcDataPort;
            Port8Bit sequencerIndexPort;
            Port8Bit sequencerDataPort;
            Port8Bit graphicsControllerIndexPort;
            Port8Bit graphicsControllerDataPort;
            Port8Bit attributeControllerIndexPort;
            Port8Bit attributeControllerReadPort;
            Port8Bit attributeControllerWritePort;
            Port8Bit attributeControllerResetPort;

            void WriteRegisters(uint8_t* registers);
            uint8_t* GetFrameBufferSegment();
            virtual vga_color GetColor(uint8_t r, uint8_t g, uint8_t b);

        public:
            VGA();
            ~VGA();

            virtual bool SupportsMode(uint32_t width, uint32_t height, uint32_t colorDepth);
            virtual bool SetMode(uint32_t width, uint32_t height, uint32_t colorDepth);
            virtual void PutPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b);
            virtual void PutPixel(int32_t x, int32_t y, vga_color colorCode);
            virtual void FillRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, vga_color color);
        };
    }
}