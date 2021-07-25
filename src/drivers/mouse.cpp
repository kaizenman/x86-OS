
#include <common/console.h>
#include <common/cpu_memory_map.h>
#include <common/io_memory_map.h>
#include <common/types.h>
#include <drivers/mouse.h>

using namespace x86_OS::drivers;
using namespace x86_OS::common;
using namespace x86_OS::hardware;

uint16_t* VideoMemory = (uint16_t*)cpu_memory_map::PCIVideoMemoryTextModeStart;

MouseDriver::MouseDriver(InterruptManager* manager, MouseEventHandler* handler): 
    InterruptHandler(Interrupts::MousePort, manager), 
    dataPort(0x60), 
    commandPort(0x64)
{
    this->handler = handler;
}

MouseDriver::~MouseDriver()
{

}

void MouseDriver::Activate()
{
    offset = 0;
    buttons = 0;

    commandPort.Write(0xA8); // activate interrupts
    commandPort.Write(0x20); // get current state
    uint8_t status = dataPort.Read() | 2;
    commandPort.Write(0x60); // set state
    dataPort.Write(status);


    commandPort.Write(0xD4);
    dataPort.Write(0xF4);
    dataPort.Read();
}


uint32_t MouseDriver::HandleInterrupt(uint32_t esp)
{
    uint8_t status = commandPort.Read();
    if (!(status & 0x20))
        return esp;

    buffer[offset] = dataPort.Read();

    if (handler == 0)
        return esp;

    offset = (offset + 1) % 3;

    if(offset == 0)
    {
        int8_t xoffset = (int8_t)buffer[1];
        int8_t yoffset = -(int8_t)buffer[2];

        if(xoffset != 0 || yoffset != 0)
        {
            handler->OnMouseMove(xoffset, yoffset);
        }

        for (uint8_t i = 0; i < 3; ++i) {
            if ((buttons & (0x01 << i)) != (buffer[0] & (0x01 << i)))
            {
                handler->OnMouseDown(i);
            }
        }

        buttons = buffer[0];
    }

    return esp;
}

MouseEventHandler::MouseEventHandler()
{

}
void MouseEventHandler::OnActivate()
{

}

void MouseEventHandler::OnMouseDown(uint8_t button)
{

}

void MouseEventHandler::OnMouseUp(uint8_t button)
{

}

void MouseEventHandler::OnMouseMove(int xoffset, int yoffset)
{

}

void MouseToConsole::OnMouseDown(uint8_t button)
{
    static uint16_t* VideoMemory = (uint16_t*)cpu_memory_map::PCIVideoMemoryTextModeStart;
    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                    | (VideoMemory[80*y+x] & 0xF000) >> 4
                    | (VideoMemory[80*y+x] & 0x00FF);
}

void MouseToConsole::OnMouseMove(int xoffset, int yoffset)
{
    static uint16_t* VideoMemory = (uint16_t*)cpu_memory_map::PCIVideoMemoryTextModeStart;
    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                        | (VideoMemory[80*y+x] & 0xF000) >> 4
                        | (VideoMemory[80*y+x] & 0x00FF);

    x += xoffset;
    if(x >= 80) x = 79;
    if(x < 0) x = 0;
    y += yoffset;
    if(y >= 25) y = 24;
    if(y < 0) y = 0;

    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                        | (VideoMemory[80*y+x] & 0xF000) >> 4
                        | (VideoMemory[80*y+x] & 0x00FF);
    /*                    
    Console::Write("x: ");
    Console::WriteNumber(x);
    Console::Write(" | ");
    Console::Write("y: ");
    Console::WriteNumber(y);
    Console::Write("\n");
    */
}


