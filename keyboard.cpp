#include "keyboard.h"
#include "Console.h"


KeyboardDriver::KeyboardDriver(InterruptManager* manager): 
    InterruptHandler(Interrupts::Keyboard, manager), 
    dataPort(0x60), 
    commandPort(0x64)
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

KeyboardDriver::~KeyboardDriver()
{

}

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{
    uint8_t key = dataPort.Read();

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
                
            case 0x02: Console::Write("1"); break;
            case 0x03: Console::Write("2"); break;
            case 0x04: Console::Write("3"); break;
            case 0x05: Console::Write("4"); break;
            case 0x06: Console::Write("5"); break;
            case 0x07: Console::Write("6"); break;
            case 0x08: Console::Write("7"); break;
            case 0x09: Console::Write("8"); break;
            case 0x0A: Console::Write("9"); break;
            case 0x0B: Console::Write("0"); break;
            case 0x10: Console::Write("q"); break;
            case 0x11: Console::Write("w"); break;
            case 0x12: Console::Write("e"); break;
            case 0x13: Console::Write("r"); break;
            case 0x14: Console::Write("t"); break;
            case 0x15: Console::Write("y"); break;
            case 0x16: Console::Write("u"); break;
            case 0x17: Console::Write("i"); break;
            case 0x18: Console::Write("o"); break;
            case 0x19: Console::Write("p"); break;
            case 0x1A: Console::Write("["); break;
            case 0x1B: Console::Write("]"); break;
            //case 0x1C: Console::Write("\n"); break;
            // case 0x1D: Console::Write("Ctrl") break; 
            case 0x1E: Console::Write("a"); break;
            case 0x1F: Console::Write("s"); break;
            case 0x20: Console::Write("d"); break;
            case 0x21: Console::Write("f"); break;
            case 0x22: Console::Write("g"); break;
            case 0x23: Console::Write("h"); break;
            case 0x24: Console::Write("j"); break;
            case 0x25: Console::Write("k"); break;
            case 0x26: Console::Write("l"); break;
            case 0x27: Console::Write(";"); break;
            case 0x28: Console::Write("'"); break;
            //case 0x29: Console::Write("a") break;
            case 0x2B: Console::Write("\\"); break;
            case 0x2C: Console::Write("z"); break;
            case 0x2D: Console::Write("x"); break;
            case 0x2E: Console::Write("c"); break;
            case 0x2F: Console::Write("v"); break;
            case 0x30: Console::Write("b"); break;
            case 0x31: Console::Write("n"); break;
            case 0x32: Console::Write("m"); break;
            case 0x33: Console::Write(","); break;
            case 0x34: Console::Write("."); break;
            case 0x35: Console::Write("/"); break;
            case 0x39: Console::Write(" "); break;
            case 0x1C: Console::Write("\n"); break;

            default:
                char* foo = "KEYBOARD 0x00 ";
                char* hex = "0123456789ABCDEF";
                foo[11] = hex[(key >> 4) & 0x0F];
                foo[12] = hex[key & 0x0F];
                Console::Write(foo);
        }

    }



    return esp;
}