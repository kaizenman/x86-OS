#pragma once

#include <drivers/vga.h>
#include <gui/widget.h>

namespace x86_OS
{
    namespace gui
    {
        class Window : public CompositeWidget
        {
        protected:
            bool dragging;
        public:
            Window(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color);
            ~Window();

            virtual void OnMouseDown(int32_t x, int32_t y, uint8_t button) override;
            virtual void OnMouseUp(int32_t x, int32_t y, uint8_t button) override;
            virtual void OnMouseMove(int32_t oldx, int32_t oldy, int32_t x, int32_t y) override;
        };
    }
}