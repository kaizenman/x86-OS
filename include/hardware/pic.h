#pragma once

#include <common/types.h>

namespace x86_OS
{
    namespace hardware
    {
        using namespace common;
        // 8259A PIC Microcontroller
        namespace PIC
        {
            // Initialization Control Word1 (ICW1))
            // In order to initialize the PIC, we must send a command byte (ICW - Initialization Control Word)
            // --> Send to PIC Command Register

            struct ICW1
            {
                ICW1(
                    bool bIC4,                         // if 1 we can sent ICW4     
                    bool bCascading,                   // if 1 we have only one PIC
                    bool bInitialization,              // if 1 PIC is to be initialized
                    bool bCallAddressInterval = 0,     // if 1 call address interval is 4, else 8, default 0
                    bool bEdgeLevelTriggeredMode = 0,  // if 1 level triggered mode, else edge triggered, default 0
                    uint8_t interruptVectorAddress = 0 // must be 0 (3 bits)
                ) {
                    byte |= bIC4 ? 1 : 0;                                // bit 0
                    byte |= bCascading ? 1 << 1 : 0 << 1;                // bit 1
                    byte |= bCallAddressInterval ? 1 << 2 : 0 << 2;      // bit 2
                    byte |= bEdgeLevelTriggeredMode ? 1 << 3 : 0 << 3;   // bit 3
                    byte |= bInitialization ? 1 << 4 : 0 << 4;           // bit 4
                    byte |= (interruptVectorAddress << 5) & 0b11100000;  // bits 5..7
                }
                uint8_t byte = 0;
            } __attribute__((packed));

            // Initialization Control Word2 (ICW2))
            // We need to send ICW 2 to the PICs to tell them where the base address of the IRQ's to use 
            // map a base IRQ address
            // --> Send to PIC Data Register
            // --> Be careful at where you map the PIC, first 31 interrupts (0x0 - 0x1F) are reserved
            // 
            struct ICW2 {
                ICW2(
                    uint8_t A8_A10,  // bits 0-2 - 3 bits A8,A9,A10
                    uint8_t A11_A15  // bits 3-7 In 80x86 mode, specifies the interrupt vector address.
                ) {
                    byte |= A8_A10 & 0b00000111;
                    byte |= (A11_A15 << 3) & 0b11111000;
                }
                uint8_t byte = 0;
            } __attribute__((packed));

            struct ICW3Primary {
                ICW3Primary(
                    uint8_t slavePICIRQNumber // S0 - S7 Specifies what Interrupt Request (IRQ) is connected to slave PIC
                ) {
                    byte = slavePICIRQNumber;
                }
                uint8_t byte = 0;
            } __attribute__((packed));

            // We must send an ICW 3 whenever we enable cascading within ICW 1
            struct ICW3Secondary {
                ICW3Secondary(
                    uint8_t masterPICIRQNumber, // bit 0 - 2 IRQ number the master PIC uses to connect to (In binary notation)
                                                // bit2 is IRQ2 the 80x86 architecture uses IRQ line 2 to connect the master PIC to the slave PIC.
                    uint8_t reserved = 0        // bit 3 - 7 must be 0
                ) {
                    byte = masterPICIRQNumber & 0b00000011;
                    byte |= reserved << 3 & 0b11111100;
                }
                uint8_t byte = 0;
            }__attribute__((packed));

            // final initialization control word 
            struct ICW4 {
                ICW4(
                    bool b80x86Mode,                // bit 0, If set (1), it is in 80x86 mode. Cleared if MCS-80/86 mode
                    bool autoEOIonLastAck,          // bit 1, If set, on the last interrupt acknowledge pulse, controller automatically performs End of Interrupt (EOI) operation
                    bool bufferMaster,              // bit 2, Only use if BUF is set. If set (1), selects buffer master. Cleared if buffer slave.
                    bool bufferedMode,              // bit 3, If set, controller operates in buffered mode
                    bool specialFullyNestedMode,    // bit 4, Special Fully Nested Mode. Used in systems with a large amount of cascaded controllers.
                    uint8_t reserved                // bits 5-7
                ) {
                    byte |= b80x86Mode;
                    byte |= autoEOIonLastAck << 1;
                    byte |= bufferMaster << 2;
                    byte |= bufferedMode << 3;
                    byte |= specialFullyNestedMode << 4;
                    byte |= (reserved << 5) & 0b11100000;
                }
                uint8_t byte = 0;
            }__attribute__((packed));
        }
    }
}
