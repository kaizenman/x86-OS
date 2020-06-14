#include "types.h"
#include "Console.h"

typedef void * (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
    	(*i)();
}

extern "C" void kernelMain() {
	Console::Initialize();
	Console::WriteLine("kernelMain");
	
    while(1)
    {
        
    }
}
