#pragma once


#include <common/types.h>
#include <common/console.h>
#include <common/graphicscontext.h>
#include <drivers/keyboard.h>

using namespace x86_OS::common;
using namespace x86_OS::drivers;
namespace x86_OS
{
    namespace gui
    {
        class Widget : public KeyboardEventHandler
        {
        protected:
            Widget* parent;
            int32_t x;
            int32_t y;
            vga_color color;
            bool focusable;

        public:
            int32_t w;
            int32_t h;

            Widget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color);
            ~Widget();

            virtual void GetFocus(Widget* widget);
            virtual void ModelToScreen(int32_t& x, int32_t& y);
            virtual bool ContainsCoordinate(int32_t x, int32_t y);
            virtual void Draw(GraphicsContext* gc);
            virtual void OnMouseDown(int32_t x, int32_t y, uint8_t button);
            virtual void OnMouseUp(int32_t x, int32_t y, uint8_t button);
            virtual void OnMouseMove(int32_t oldx, int32_t oldy, int32_t x, int32_t y);
            virtual void OnKeyDown(char) override;
            virtual void OnKeyUp(char) override;
        };
        
        class CompositeWidget : public Widget
        {
        private:
            Widget* children[100];
            int numChildren;
            Widget* focussedChild;
        public:
            CompositeWidget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color);
            ~CompositeWidget();

            virtual bool AddChild(Widget* child);
            virtual void GetFocus(Widget* widget) override;
            virtual void Draw(GraphicsContext* gc) override;
            virtual void OnMouseDown(int32_t x, int32_t y, uint8_t button) override;
            virtual void OnMouseUp(int32_t x, int32_t y, uint8_t button) override;
            virtual void OnMouseMove(int32_t oldx, int32_t oldy, int32_t x, int32_t y) override;

            virtual void OnKeyDown(char) override;
            virtual void OnKeyUp(char) override;
        };

    }
}