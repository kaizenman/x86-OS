#pragma once

#include "types.h"

namespace x86_OS
{
    namespace common
    {
        // Pentium Pro i440FX chipset memory map
        // Terms:
        //      PMC - PCI and Memory Controller
        //      TOM - Top Of Memory
        //      APIC - Advanced Programmable Interrupt Controller
        //      ISA - ISA 16-bit internal bus (Industry Standard Architecture)

        //      LAPIC - Local APIC
        //      IO APIC

        // SR440BX Motherboard http://www.elhvb.com/mobokive/Archive/Intel/SR440BX_73253401.pdf
        namespace io_memory_map
        {
            constexpr uint16_t SecondaryBusMasterIDERegisters            = 0xFFA8;  // 8 bytes
            constexpr uint16_t PrimaryBusMasterIDERegisters              = 0xFFA0;  // 8 bytes
            constexpr uint16_t WindowsSoundSystem                        = 0xEF00;  // 64 bytes
            constexpr uint16_t PCIConfigurationDataRegister              = 0x0CFC;  // 4 bytes
            constexpr uint16_t ResetControlRegisterTurbo                 = 0x0CF9;  // 1 byte
            constexpr uint16_t PCIConfigurationAddressRegister           = 0x0CF8;  // 4 bytes
            //constexpr uint16_t ECPPort                                   = 0x
            constexpr uint16_t WindowsSoundSystem2                       = 0x0530;  // or 0xE80, or 0xF40, 8 bytes
            constexpr uint16_t EdgeLevelTriggeredPIC                     = 0x04D0;  // 2 bytes
            constexpr uint16_t COM1                                      = 0x03F8;  // 8 bytes
            constexpr uint16_t PrimaryIDEChannelStatusPort               = 0x03F7;  // start bit 0, size 7 bit
            constexpr uint16_t DiketteDiskChangeChannel1                 = 0x03F7;  // start bit 7, size 1 bit
            constexpr uint16_t DiketteChannel1WriteCommandPort           = 0x03F7;  // 1 bytes
            constexpr uint16_t PrimaryIDEChannelCommandPort              = 0x03F6;  // 1 bytes
            constexpr uint16_t DisketteChannel1                          = 0x03F0;  // 6 bytes
            constexpr uint16_t COM3                                      = 0x03E8;  // 8 bytes
            constexpr uint16_t VGA7                                      = 0x03DA;  // 1 byte
            constexpr uint16_t VGA6                                      = 0x03D4;  // 2 bytes
            constexpr uint16_t VGA5                                      = 0x03CE;  // 2 bytes
            constexpr uint16_t VGA4                                      = 0x03CC;  // 1 byte
            constexpr uint16_t VGA3                                      = 0x03C0;  // 2 bytes
            constexpr uint16_t VGA2                                      = 0x03BA;  // 1 byte
            constexpr uint16_t VGA1                                      = 0x03B4;  // 2 bytes
            constexpr uint16_t FMsynthesizer                             = 0x0388;  // 6 bytes
            constexpr uint16_t LPT1                                      = 0x0378;  // 8 bytes
            constexpr uint16_t SecondaryIDEChannelStatusPort             = 0x0377;  // start bit 0, size 7 bits
            constexpr uint16_t FloppyDiskChangeChannel2                  = 0x0377;  // start bit 7, size 1 bit
            constexpr uint16_t FloppyChannel2Command                     = 0x0377;  // 1 byte
            constexpr uint16_t SecondaryIDEChannelCommandPort            = 0x0376;  // 1 byte
            constexpr uint16_t MIDI                                      = 0x0320;  // or 0x0330, or 0x340, or 0x0350, 8 bytes
            constexpr uint16_t COM2                                      = 0x02F8;  // 8 bytes
            constexpr uint16_t COM4Video                                 = 0x02E8;  // 8 bytes
            constexpr uint16_t LPT3                                      = 0x0228;  // 8 bytes
            constexpr uint16_t LPT2                                      = 0x0278;  // 8 bytes
            constexpr uint16_t AudioSoundBlasterCompatible               = 0x0240;  // 16 bytes
            constexpr uint16_t AudioSoundBlasterProPlusCompatible        = 0x0220;  // 16 bytes
            constexpr uint16_t AudioGamePort                             = 0x0200;  // or 0x208 or 0x210 or 0x218 can vary
            constexpr uint16_t PrimaryIDEChannel                         = 0x01F0;  // 8 bytes
            constexpr uint16_t SecondaryIDEChannel                       = 0x0170;  // 8 bytes
            constexpr uint16_t ResetNumericError                         = 0x00F0;  // 1 byte
            constexpr uint16_t PIIX4EDMA2                                = 0x00C0;  // 31 bytes
            constexpr uint16_t APMControl                                = 0x00B2;  // 2 bytes
            // ------------------ Secondary PIC (8259A PIC) 0x00A0 - 0x00A1  --------------------------------
            constexpr uint16_t SecondaryPICInterruptMaskRegister         = 0x00A1;  // 1 byte
            constexpr uint16_t SecondaryPICDataRegister                  = 0x00A1;  // 1 byte
            constexpr uint16_t SecondaryPICCommandRegister               = 0x00A0;  // 1 byte, Write only
            constexpr uint16_t SecondaryPICStatusRegister                = 0x00A0;  // 1 byte, Read only
            constexpr uint16_t PIIX4EInterruptController2                = 0x00A0;  // 2 bytes
            // --------------------------------------------------------------
            constexpr uint16_t PIIX4EDMAPageRegisters                    = 0x0080;  // 16 bytes
            constexpr uint16_t CMOSBank1                                 = 0x0072;  // 2 bytes
            constexpr uint16_t CMOSBank0                                 = 0x0070;  // 2 bytes
            constexpr uint16_t PIIX4ERealTimeClocData                    = 0x0071;  // 1 byte
            constexpr uint16_t PIIX4ERealTimeClockAddress                = 0x0070;  // start from bit 0 to bit 6, 7 bit size
            constexpr uint16_t PIIX4EEnableNMI                           = 0x0070;  // start from 7th bit 1 bit size
            constexpr uint16_t KeyboardControllerCMDStat                 = 0x0064;  // 1 byte
            constexpr uint16_t PIIX4ENMISpeakerControl                   = 0x0061;  // 1 byte
            constexpr uint16_t KeyboardControllerResetIRQ                = 0x0048;  // 1 byte
            constexpr uint16_t PIIX4ECounterTimer2                       = 0x004B;  // 4 bytes
            constexpr uint16_t PIIX4ECounterTimer1                       = 0x0040;  // 4 bytes
            // ------------------ Primary PIC (8259A PIC)  0x0020 - 0x0021  --------------------------------
            constexpr uint16_t PrimaryPICInterruptMaskRegister           = 0x0021;  // 1 byte
            constexpr uint16_t PrimaryPICDataRegister                    = 0x0021;  // 1 byte
            constexpr uint16_t PrimaryPICCommandRegister                 = 0x0020;  // 1 byte, Write only
            constexpr uint16_t PrimaryPICStatusRegister                  = 0x0020;  // 1 byte, Read only
            constexpr uint16_t PIIX4EInterruptController                 = 0x0020;  // 2 bytes
            // --------------------------------------------------------------
            constexpr uint16_t PIIX4EDMA1                                = 0x0000;  // 16 bytes
        }
    }


}