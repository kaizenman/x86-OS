#include <common/console.h>
#include <common/types.h>
#include <drivers/driver.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <hardware/gdt.h>
#include <hardware/interrupts.h>

using namespace x86_OS::common;
using namespace x86_OS::drivers;
using namespace x86_OS::hardware;

typedef void * (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t checksum) {
    GlobalDescriptorTable gdt;
    InterruptManager interrupts(&gdt);
    DriverManager drvManager;
    PrintKeyboardEventHandler keyboardEventHandler;
    MouseToConsole mouseEventHandler;
    KeyboardDriver keyboard(&interrupts, &keyboardEventHandler);
    drvManager.AddDriver(&keyboard);
    MouseDriver mouse(&interrupts, &mouseEventHandler);
    drvManager.AddDriver(&mouse);
    drvManager.ActivateAll();
    interrupts.Activate();

    while(1)
    {
        
    }
}
