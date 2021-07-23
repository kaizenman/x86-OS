
#ifndef __INTERRUPTMANAGER_H
#define __INTERRUPTMANAGER_H

#include "gdt.h"
#include "types.h"
#include "port.h"


namespace Interrupts {
    constexpr uint8_t HardwareInterruptOffset = 0x20;
    constexpr uint8_t Timer = HardwareInterruptOffset + 0;             // IRQ0 reserved
    constexpr uint8_t Keyboard = HardwareInterruptOffset + 1;          // IRQ1 reserved
    constexpr uint8_t CascadeInterrupt = HardwareInterruptOffset + 2;  // IRQ2 reserved
    constexpr uint8_t COM2 = HardwareInterruptOffset + 3;              // IRQ3, can be changed
    constexpr uint8_t COM1 = HardwareInterruptOffset + 4;              // IRQ4
    constexpr uint8_t LPT2 = HardwareInterruptOffset + 5;              // IRQ5
    constexpr uint8_t DisketteDrive = HardwareInterruptOffset + 6;     // IRQ6
    constexpr uint8_t LPT1 = HardwareInterruptOffset + 7;              // IRQ7
    constexpr uint8_t RealtimeClock = HardwareInterruptOffset + 8;     // IRQ8
    constexpr uint8_t Reserved = HardwareInterruptOffset + 9;          // IRQ9 reserved for PIIX4E system management
    constexpr uint8_t UserAvailable1 = HardwareInterruptOffset + 10;    // IRQ10
    constexpr uint8_t UserAvailable2 = HardwareInterruptOffset + 11;    // IRQ11 - Windows Sound System / available
    constexpr uint8_t MousePort = HardwareInterruptOffset + 12;         // IRQ12 - if present / else available
    constexpr uint8_t MathCoprocessor = HardwareInterruptOffset + 13;   // IRQ13 - Reserved
    constexpr uint8_t PrimaryIDE = HardwareInterruptOffset + 14;        // IRQ14 - if present / else available
    constexpr uint8_t SecondaryIDE = HardwareInterruptOffset + 15;      // IRQ15 - if present / else available
}

class InterruptManager;
class InterruptHandler
{
protected:
    uint8_t interrupt;
    InterruptManager* interruptManager;

    InterruptHandler(uint8_t interrupt, InterruptManager* interruptManager);
    ~InterruptHandler();
public:
    virtual uint32_t HandleInterrupt(uint32_t esp);
};

class InterruptManager
{
    friend class InterruptHandler;
    protected:
        // we want to access ports which are nonstatic objects
        // so we need to call nonstatic function DoHandleInterrupt from static pointer
        static InterruptManager* ActiveInterruptManager;
        InterruptHandler* handlers[256];
        
        struct GateDescriptor
        {
            uint16_t handlerAddressLowBits;
            uint16_t gdt_codeSegmentSelector;
            uint8_t reserved;
            uint8_t access;
            uint16_t handlerAddressHighBits;
        } __attribute__((packed));

        static GateDescriptor interruptDescriptorTable[256];

        struct InterruptDescriptorTablePointer
        {
            uint16_t size;
            uint32_t base;
        } __attribute__((packed));

        static void SetInterruptDescriptorTableEntry(uint8_t interrupt,
            uint16_t codeSegmentSelectorOffset, void (*handler)(),
            uint8_t DescriptorPrivilegeLevel, uint8_t DescriptorType);


        static void InterruptIgnore();

        static void HandleInterruptRequest0x00();
        static void HandleInterruptRequest0x01();
        static void HandleInterruptRequest0x02();
        static void HandleInterruptRequest0x03();
        static void HandleInterruptRequest0x04();
        static void HandleInterruptRequest0x05();
        static void HandleInterruptRequest0x06();
        static void HandleInterruptRequest0x07();
        static void HandleInterruptRequest0x08();
        static void HandleInterruptRequest0x09();
        static void HandleInterruptRequest0x0A();
        static void HandleInterruptRequest0x0B();
        static void HandleInterruptRequest0x0C();
        static void HandleInterruptRequest0x0D();
        static void HandleInterruptRequest0x0E();
        static void HandleInterruptRequest0x0F();
        static void HandleInterruptRequest0x31();

        static void HandleException0x00();
        static void HandleException0x01();
        static void HandleException0x02();
        static void HandleException0x03();
        static void HandleException0x04();
        static void HandleException0x05();
        static void HandleException0x06();
        static void HandleException0x07();
        static void HandleException0x08();
        static void HandleException0x09();
        static void HandleException0x0A();
        static void HandleException0x0B();
        static void HandleException0x0C();
        static void HandleException0x0D();
        static void HandleException0x0E();
        static void HandleException0x0F();
        static void HandleException0x10();
        static void HandleException0x11();
        static void HandleException0x12();
        static void HandleException0x13();

        static uint32_t HandleInterrupt(uint8_t interrupt, uint32_t esp);
        
        uint32_t DoHandleInterrupt(uint8_t interrupt, uint32_t esp);

        Port8BitSlow programmableInterruptControllerMasterCommandPort;
        Port8BitSlow programmableInterruptControllerMasterDataPort;
        Port8BitSlow programmableInterruptControllerSlaveCommandPort;
        Port8BitSlow programmableInterruptControllerSlaveDataPort;

    public:
        InterruptManager(GlobalDescriptorTable* globalDescriptorTable);
        ~InterruptManager();
        void Activate();
        void Deactivate();
};
#endif