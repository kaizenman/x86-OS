#pragma once

#include <drivers/mouse.h>
#include <common/types.h>
#include <common/console.h>
#include <common/graphicscontext.h>
#include <gui/widget.h>

using namespace x86_OS::drivers;
using namespace x86_OS::common;

namespace x86_OS
{
    namespace gui
    {
        class Desktop : public CompositeWidget, public MouseEventHandler
        {
        protected:
            uint32_t MouseX;
            uint32_t MouseY;
        public:
            Desktop(uint32_t w, uint32_t h, vga_color color);
            ~Desktop();

            void Draw(GraphicsContext* gc) final;
            void OnMouseDown(uint8_t button) final;
            void OnMouseUp(uint8_t button) final;
            void OnMouseMove(int8_t xoffset, int8_t yoffset) final;
        };
    }
}