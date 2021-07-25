#include <hardware/port.h>

using namespace x86_OS::common;
using namespace x86_OS::hardware;

void Port8Bit::Write(uint8_t data)
{
    asm volatile ("outb %0, %1" : : "a" (data), "Nd" (portnumber));
}
uint8_t Port8Bit::Read() 
{
    uint8_t result;
    asm volatile ("inb %1, %0" : "=a" (result) : "Nd" (portnumber));
    return result;
}

void Port8BitSlow::Write(uint8_t data)
{
    asm volatile ("outb %0, %1\njmp 1f\n1: jmp 1f\n1: " : : "a" (data), "Nd" (portnumber));
}

void Port16Bit::Write(uint16_t data)
{
    asm volatile ("outw %0, %1" : : "a" (data), "Nd" (portnumber));
}
uint16_t Port16Bit::Read() 
{
    uint16_t result;
    asm volatile ("inw %1, %0" : "=a" (result) : "Nd" (portnumber));
    return result;
}

void Port32Bit::Write(uint32_t data)
{
    asm volatile ("outl %0, %1" : : "a" (data), "Nd" (portnumber));
}
uint32_t Port32Bit::Read() 
{
    uint32_t result;
    asm volatile ("inl %1, %0" : "=a" (result) : "Nd" (portnumber));
    return result;
}
