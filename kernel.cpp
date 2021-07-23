#include "types.h"
#include "Console.h"
#include "gdt.h"
#include "interrupts.h"

typedef void * (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
    	(*i)();
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t checksum) {
	Console::Initialize();
	Console::WriteLine("kernelMain");
	
	GlobalDescriptorTable gdt;
	InterruptManager interrupts(0x20, &gdt);

	interrupts.Activate();

    while(1)
    {
        
    }
}
