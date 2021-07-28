#include <gui/widget.h>

using namespace x86_OS::gui;

Widget::Widget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color)
: KeyboardEventHandler(), parent(parent), x(x), y(y), color(color), focusable(true), w(w), h(h)
{

}
Widget::~Widget()
{
}
void Widget::GetFocus(Widget* widget)
{
    if (parent)
        parent->GetFocus(widget);

}
void Widget::ModelToScreen(int32_t& x, int32_t& y)
{
    if (parent)
        parent->ModelToScreen(x, y);
    
    this->x += x;
    this->y += y;
}

bool Widget::ContainsCoordinate(int32_t x, int32_t y)
{
    return this->x <= x && x < this->x + this->w
        && this->y <= y && y < this->y + this->h;
}
void Widget::Draw(GraphicsContext* gc)
{
    int32_t X = 0;
    int32_t Y = 0;
    ModelToScreen(X, Y);
    gc->FillRectangle(X, Y, w, h, color);
}
void Widget::OnMouseDown(int32_t x, int32_t y, uint8_t button)
{
    if (focusable)
        GetFocus(this);
}
void Widget::OnMouseUp(int32_t x, int32_t y, uint8_t button)
{
}
void Widget::OnMouseMove(int32_t oldx, int32_t oldy, int32_t x, int32_t y)
{
}
void Widget::OnKeyDown(char)
{

}
void Widget::OnKeyUp(char)
{

}


CompositeWidget::CompositeWidget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, vga_color color)
: Widget(parent, x, y, w, h, color)
{
    focussedChild = 0;
    numChildren = 0;
}
CompositeWidget::~CompositeWidget()
{

}

bool CompositeWidget::AddChild(Widget* widget)
{
    if (numChildren == 100)
        return false;
    children[numChildren] = widget;
    numChildren++;
    return true;
}

void CompositeWidget::GetFocus(Widget* widget)
{
    this->focussedChild = widget;
    if (parent)
        parent->GetFocus(this);
}
void CompositeWidget::Draw(GraphicsContext* gc)
{
    Widget::Draw(gc);
    for (int i = numChildren - 1; i >= 0; --i)
    {
        children[i]->Draw(gc);
    }
}

void CompositeWidget::OnMouseDown(int32_t X, int32_t Y, uint8_t button)
{
    for (int i = 0; i < numChildren; ++i)
    {
        if (children[i]->ContainsCoordinate(X - this->x, Y - this->y))
        {
            children[i]->OnMouseDown(X - this->x, Y - this->y, button);
            break;
        }
    }
}
void CompositeWidget::OnMouseUp(int32_t X, int32_t Y, uint8_t button)
{
    for (int i = 0; i < numChildren; ++i)
    {
        if (children[i]->ContainsCoordinate(X - this->x, Y - this->y))
        {
            children[i]->OnMouseUp(X - this->x, Y - this->y, button);
            break;
        }
    }
}
void CompositeWidget::OnMouseMove(int32_t oldx, int32_t oldy, int32_t newx, int32_t newy)
{
    int firstchild = -1;
    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(oldx - this->x, oldy - this->y))
        {
            children[i]->OnMouseMove(oldx - this->x, oldy - this->y, newx - this->x, newy - this->y);
            firstchild = i;
            break;
        }

    for(int i = 0; i < numChildren; ++i)
        if(children[i]->ContainsCoordinate(newx - this->x, newy - this->y))
        {
            if(firstchild != i)
                children[i]->OnMouseMove(oldx - this->x, oldy - this->y, newx - this->x, newy - this->y);
            break;
        }
}
void CompositeWidget::OnKeyDown(char)
{

}
void CompositeWidget::OnKeyUp(char)
{

}