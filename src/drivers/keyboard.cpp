#include <common/console.h>
#include <drivers/keyboard.h>
#include <hardware/interrupts.h>

using namespace x86_OS::drivers;
using namespace x86_OS::hardware;

KeyboardDriver::KeyboardDriver(InterruptManager* manager, KeyboardEventHandler* handler): 
    InterruptHandler(Interrupts::Keyboard, manager), 
    dataPort(0x60), 
    commandPort(0x64)
{
    this->handler = handler;
}

KeyboardDriver::~KeyboardDriver()
{

}

void KeyboardDriver::Activate()
{
    while (commandPort.Read() & 0x1)
        dataPort.Read();

    commandPort.Write(0xAE);    // activate interrupts
    commandPort.Write(0x20);    // give current state
    uint8_t status = (dataPort.Read() | 1) & ~0x10;
    commandPort.Write(0x60);    // change state
    dataPort.Write(status);
    dataPort.Write(0xF4);
}

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{
    if (handler == 0)
        return esp;


    uint8_t key = dataPort.Read();

    static bool Shift = false;

    if (key == 0x2A) { Shift = true; return esp; }
    if (key == 0xAA) { Shift = false; return esp; }
    // print keyboard key
    // we get 2 interrupts (key press + key release) with 1 bit difference (first bit)
    
    // everything after 0x80 is key release
    if (key < 0x80)
    {
        switch (key)
        {
            case 0xFA:
            case 0x45:
            case 0xC5:
                break;
                
            case 0x02: handler->OnKeyDown(Shift ? '!' : '1'); break;
            case 0x03: handler->OnKeyDown(Shift ? '@' : '2'); break;
            case 0x04: handler->OnKeyDown(Shift ? '#' : '3'); break;
            case 0x05: handler->OnKeyDown(Shift ? '$' : '4'); break;
            case 0x06: handler->OnKeyDown(Shift ? '%' : '5'); break;
            case 0x07: handler->OnKeyDown(Shift ? '^' : '6'); break;
            case 0x08: handler->OnKeyDown(Shift ? '&' : '7'); break;
            case 0x09: handler->OnKeyDown(Shift ? '*' : '8'); break;
            case 0x0A: handler->OnKeyDown(Shift ? '(' : '9'); break;
            case 0x0B: handler->OnKeyDown(Shift ? ')' : '0'); break;
            case 0x0C: handler->OnKeyDown(Shift ? '_' : '-'); break;
            case 0x0D: handler->OnKeyDown(Shift ? '+' : '='); break;
            case 0x10: handler->OnKeyDown(Shift ? 'Q' : 'q'); break;
            case 0x11: handler->OnKeyDown(Shift ? 'W' : 'w'); break;
            case 0x12: handler->OnKeyDown(Shift ? 'E' : 'e'); break;
            case 0x13: handler->OnKeyDown(Shift ? 'R' : 'r'); break;
            case 0x14: handler->OnKeyDown(Shift ? 'T' : 't'); break;
            case 0x15: handler->OnKeyDown(Shift ? 'Y' : 'y'); break;
            case 0x16: handler->OnKeyDown(Shift ? 'U' : 'u'); break;
            case 0x17: handler->OnKeyDown(Shift ? 'I' : 'i'); break;
            case 0x18: handler->OnKeyDown(Shift ? 'O' : 'o'); break;
            case 0x19: handler->OnKeyDown(Shift ? 'P' : 'p'); break;
            case 0x1A: handler->OnKeyDown(Shift ? '{' : '['); break;
            case 0x1B: handler->OnKeyDown(Shift ? '}' : ']'); break;
            //case 0x1C: Console::Write("\n"); break;
            // case 0x1D: Console::Write("Ctrl") break; 
            case 0x1E: handler->OnKeyDown(Shift ? 'A' : 'a'); break;
            case 0x1F: handler->OnKeyDown(Shift ? 'S' : 's'); break;
            case 0x20: handler->OnKeyDown(Shift ? 'D' : 'd'); break;
            case 0x21: handler->OnKeyDown(Shift ? 'F' : 'f'); break;
            case 0x22: handler->OnKeyDown(Shift ? 'G' : 'g'); break;
            case 0x23: handler->OnKeyDown(Shift ? 'H' : 'h'); break;
            case 0x24: handler->OnKeyDown(Shift ? 'J' : 'j'); break;
            case 0x25: handler->OnKeyDown(Shift ? 'K' : 'k'); break;
            case 0x26: handler->OnKeyDown(Shift ? 'L' : 'l'); break;
            case 0x27: handler->OnKeyDown(Shift ? ':' : ';'); break;
            //case 0x28: handler->OnKeyDown(Shift ? '\\' : '\''); break;
            //case 0x29: Console::Write("a") break;
            //case 0x2B: handler->OnKeyDown(Shift ? '|' : '\\'); break;
            case 0x2C: handler->OnKeyDown(Shift ? 'Z' : 'z'); break;
            case 0x2D: handler->OnKeyDown(Shift ? 'X' : 'x'); break;
            case 0x2E: handler->OnKeyDown(Shift ? 'C' : 'c'); break;
            case 0x2F: handler->OnKeyDown(Shift ? 'V' : 'v'); break;
            case 0x30: handler->OnKeyDown(Shift ? 'B' : 'b'); break;
            case 0x31: handler->OnKeyDown(Shift ? 'N' : 'n'); break;
            case 0x32: handler->OnKeyDown(Shift ? 'M' : 'm'); break;
            case 0x33: handler->OnKeyDown(Shift ? '<' : ','); break;
            case 0x34: handler->OnKeyDown(Shift ? '>' : '.'); break;
            case 0x35: handler->OnKeyDown(Shift ? '?' : '/'); break;
            case 0x39: handler->OnKeyDown(' '); break;
            case 0x1C: handler->OnKeyDown('\n'); break;

            default:
                Console::Write("KEYBOARD 0x");
                Console::WriteHex(key);
                Console::Write("\n");
        }

    }

    return esp;
}


KeyboardEventHandler::KeyboardEventHandler()
{

}

void KeyboardEventHandler::OnKeyDown(char c)
{

}
void KeyboardEventHandler::OnKeyUp(char)
{

}

PrintKeyboardEventHandler::PrintKeyboardEventHandler() 
{

}

void PrintKeyboardEventHandler::OnKeyDown(char c)
{
    char* foo = " ";
    foo[0] = c;
    Console::Write(foo);
}

void PrintKeyboardEventHandler::OnKeyUp(char c)
{

}

