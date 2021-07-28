#include <common/console.h>
#include <common/types.h>
#include <drivers/driver.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <drivers/vga.h>
#include <hardware/gdt.h>
#include <hardware/interrupts.h>
#include <hardware/pci.h>
#include <gui/desktop.h>
#include <gui/window.h>

using namespace x86_OS::common;
using namespace x86_OS::drivers;
using namespace x86_OS::hardware;
using namespace x86_OS::gui;

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

    Desktop desktop(320, 200, vga_color::VGA_COLOR_BLUE);

    DriverManager drvManager;
    PrintKeyboardEventHandler keyboardEventHandler;
    //MouseToConsole mouseEventHandler;
    // MouseDriver mouse(&interrupts, &mouseEventHandler);

    MouseDriver mouse(&interrupts, &desktop); 
    KeyboardDriver keyboard(&interrupts, &desktop);

    //KeyboardDriver keyboard(&interrupts, &keyboardEventHandler);
    //drvManager.AddDriver(&keyboard);
    
    drvManager.AddDriver(&mouse);

    PCI pciController;
    pciController.SelectDrivers(&drvManager, &interrupts);
    VGA vga;

    drvManager.ActivateAll();
    interrupts.Activate();

    vga.SetMode(320, 200, 8);

    Window win1(&desktop, 10, 10, 20, 20, vga_color::VGA_COLOR_RED);
    desktop.AddChild(&win1);
    Window win2(&desktop, 40, 15, 30, 30, vga_color::VGA_COLOR_GREEN);
    desktop.AddChild(&win2);
    
    // VGA_COLOR_BLUE
    // VGA_COLOR_BLACK
    // VGA_COLOR_GREEN
    // VGA_COLOR_RED
    // VGA_COLOR_WHITE
    while(1)
    {
        desktop.Draw(&vga);

    }
}
