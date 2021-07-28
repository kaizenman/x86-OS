#include <gui/window.h>
#include <gui/widget.h>
#include <common/types.h>


using namespace x86_OS::gui;

Window::Window(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color)
: CompositeWidget(parent, x, y, w, h, color)
{
    dragging = false;
}

Window::~Window()
{

}

void Window::OnMouseDown(int32_t x, int32_t y, uint8_t button)
{
    dragging = button == 1;
    CompositeWidget::OnMouseDown(x, y, button);
}
void Window::OnMouseUp(int32_t x, int32_t y, uint8_t button)
{
    dragging = false;
    CompositeWidget::OnMouseUp(x, y, button);
}
void Window::OnMouseMove(int32_t oldx, int32_t oldy, int32_t x, int32_t y)
{
    if (dragging)
    {
        this->x += x - oldx;
        this->y += y - oldy;
    }

    CompositeWidget::OnMouseMove(oldx, oldy, x, y);
}