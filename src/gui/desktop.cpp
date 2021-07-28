#include <gui/desktop.h>
#include <gui/widget.h>

using namespace x86_OS::gui;

Desktop::Desktop(uint32_t w, uint32_t h, vga_color color): 
    CompositeWidget(0, 0, 0, w, h, color),
    MouseEventHandler()
{
    this->MouseX = w / 2;
    this->MouseY = h / 2;
}
Desktop::~Desktop()
{
}


void Desktop::Draw(GraphicsContext* gc)
{
    CompositeWidget::Draw(gc);

    for (int i = 0; i < 4; ++i)
    {
        gc->PutPixel(MouseX - i, MouseY, vga_color::VGA_COLOR_WHITE);
        gc->PutPixel(MouseX + i, MouseY, vga_color::VGA_COLOR_WHITE);
        gc->PutPixel(MouseX, MouseY - i, vga_color::VGA_COLOR_WHITE);
        gc->PutPixel(MouseX, MouseY + i, vga_color::VGA_COLOR_WHITE);
    }

}
void Desktop::OnMouseDown(uint8_t button)
{
    CompositeWidget::OnMouseDown(this->MouseX, this->MouseY, button);
}
void Desktop::OnMouseUp(uint8_t button)
{
    CompositeWidget::OnMouseUp(this->MouseX, this->MouseY, button);
}
void Desktop::OnMouseMove(int8_t x, int8_t y)
{
    x /= 4;
    y /= 4;
    
    int32_t newMouseX = MouseX + x;
    if(newMouseX < 0) newMouseX = 0;
    if(newMouseX >= w) newMouseX = w - 1;
    
    int32_t newMouseY = MouseY + y;
    if(newMouseY < 0) newMouseY = 0;
    if(newMouseY >= h) newMouseY = h - 1;
    
    CompositeWidget::OnMouseMove(MouseX, MouseY, newMouseX, newMouseY);
    
    MouseX = newMouseX;
    MouseY = newMouseY;
}
