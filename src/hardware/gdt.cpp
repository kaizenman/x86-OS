#include <hardware/gdt.h>

using namespace x86_OS::hardware;
using namespace x86_OS::common;

GlobalDescriptorTable::GlobalDescriptorTable() : 
    nullSegmentSelector(0, 0, 0),
    unusedSegmentSelector(0, 0, 0),
    codeSegmentSelector(0, 64 * 1024 * 1024, 0x9A),
    dataSegmentSelector(0, 64 * 1024 * 1024, 0x92)
{
    uint32_t i[2];
    i[1] = (uint32_t)this;
    i[0] = sizeof(GlobalDescriptorTable) << 16;

    //volatile auto p = ((uint8_t *) i)+2;
    asm volatile("lgdt (%0)": :"p" (((uint8_t *) i)+2));
}

GlobalDescriptorTable::~GlobalDescriptorTable()  {}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
}

uint16_t GlobalDescriptorTable::DataSegmentSelector()
{
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags) 
{
    uint8_t* target = (uint8_t*)this;

    //if 16 bit limit
    if (limit <= 65536)
    { 
        // tell processor that this is a 16bit entry
        target[6] = 0x40;
    
    } else {
        
        // if the last 12 bits of limit are not 1s
        if ((limit & 0xFFF) != 0xFFF)
        {
            limit = (limit >> 12) - 1;
            
        } else {
            limit >>= 12;
        }
        
        // indicate that there was a shift of 12 done
        target[6] = 0xC0;

    }

    // set the lower and upper 2 lowest bytes of limit
    target[0] = limit & 0xFF;
    target[1] = (limit >> 8) & 0xFF;

    //the rest of limit must go in lower 4 bit of byte 6, and byte 5
    target[6] |= (limit >> 16) & 0xF;

    //encode the pointer
    target[2] =  base & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;

    // set the flags 
    target[5] = flags;
    
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Base()
{
    uint8_t* target = (uint8_t*) this;
    uint32_t result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];

    return result;
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    uint8_t* target = (uint8_t *)this;
    uint32_t result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];
    
    //check if there was a shift of 12
    if (target[6] & 0xC0 == 0xC0)
    {
        result = (result << 12) & 0xFFF;
    }

    return result;
}
