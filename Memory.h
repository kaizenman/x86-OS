#ifndef __MEMORY_H
#define __MEMORY_H

// Pentium Pro i440FX chipset memory map
// Terms:
//      PMC - PCI and Memory Controller
//      TOM - Top Of Memory
//      APIC - Advanced Programmable Interrupt Controller
//      ISA - ISA 16-bit internal bus (Industry Standard Architecture)

//      LAPIC - Local APIC
//      IO APIC

// SR440BX Motherboard http://www.elhvb.com/mobokive/Archive/Intel/SR440BX_73253401.pdf
namespace IOMemoryMap
{
    const uint16_t SecondaryBusMasterIDERegisters            = 0xFFA8;  // 8 bytes
    const uint16_t PrimaryBusMasterIDERegisters              = 0xFFA0;  // 8 bytes
    const uint16_t WindowsSoundSystem                        = 0xEF00;  // 64 bytes
    const uint16_t PCIConfigurationDataRegister              = 0x0CFC;  // 4 bytes
    const uint16_t ResetControlRegisterTurbo                 = 0x0CF9;  // 1 byte
    const uint16_t PCIConfigurationAddressRegister           = 0x0CF8;  // 4 bytes
    //const uint16_t ECPPort                                   = 0x
    const uint16_t WindowsSoundSystem                        = 0x0530;  // or 0xE80, or 0xF40, 8 bytes
    const uint16_t EdgeLevelTriggeredPIC                     = 0x04D0;  // 2 bytes
    const uint16_t COM1                                      = 0x03F8;  // 8 bytes
    const uint16_t PrimaryIDEChannelStatusPort               = 0x03F7;  // start bit 0, size 7 bit
    const uint16_t DiketteDiskChangeChannel1                 = 0x03F7;  // start bit 7, size 1 bit
    const uint16_t DiketteChannel1WriteCommandPort           = 0x03F7;  // 1 bytes
    const uint16_t PrimaryIDEChannelCommandPort              = 0x03F6;  // 1 bytes
    const uint16_t DisketteChannel1                          = 0x03F0;  // 6 bytes
    const uint16_t COM3                                      = 0x03E8;  // 8 bytes
    const uint16_t VGA7                                      = 0x03DA;  // 1 byte
    const uint16_t VGA6                                      = 0x03D4;  // 2 bytes
    const uint16_t VGA5                                      = 0x03CE;  // 2 bytes
    const uint16_t VGA4                                      = 0x03CC;  // 1 byte
    const uint16_t VGA3                                      = 0x03C0;  // 2 bytes
    const uint16_t VGA2                                      = 0x03BA;  // 1 byte
    const uint16_t VGA1                                      = 0x03B4;  // 2 bytes
    const uint16_t FMsynthesizer                             = 0x0388;  // 6 bytes
    const uint16_t LPT1                                      = 0x0378;  // 8 bytes
    const uint16_t SecondaryIDEChannelStatusPort             = 0x0377;  // start bit 0, size 7 bits
    const uint16_t FloppyDiskChangeChannel2                  = 0x0377;  // start bit 7, size 1 bit
    const uint16_t FloppyChannel2Command                     = 0x0377;  // 1 byte
    const uint16_t SecondaryIDEChannelCommandPort            = 0x0376;  // 1 byte
    const uint16_t MIDI                                      = 0x0320;  // or 0x0330, or 0x340, or 0x0350, 8 bytes
    const uint16_t COM2                                      = 0x02F8;  // 8 bytes
    const uint16_t COM4Video                                 = 0x02E8;  // 8 bytes
    const uint16_t LPT3                                      = 0x0228;  // 8 bytes
    const uint16_t LPT2                                      = 0x0278;  // 8 bytes
    const uint16_t AudioSoundBlasterCompatible               = 0x0240;  // 16 bytes
    const uint16_t AudioSoundBlasterProPlusCompatible        = 0x0220;  // 16 bytes
    const uint16_t AudioGamePort                             = 0x0200;  // or 0x208 or 0x210 or 0x218 can vary
    const uint16_t PrimaryIDEChannel                         = 0x01F0;  // 8 bytes
    const uint16_t SecondaryIDEChannel                       = 0x0170;  // 8 bytes
    const uint16_t ResetNumericError                         = 0x00F0;  // 1 byte
    const uint16_t PIIX4EDMA2                                = 0x00C0;  // 31 bytes
    const uint16_t APMControl                                = 0x00B2;  // 2 bytes
    // ------------------ Primary PIC (8259A PIC) --------------------------------
    const uint16_t SecondaryPICInterruptMaskRegister         = 0x0021;  // 1 byte
    const uint16_t SecondaryPICDataRegister                  = 0x0021;  // 1 byte
    const uint16_t SecondaryPICCommandRegister               = 0x0020;  // 1 byte, Write only
    const uint16_t SecondaryPICStatusRegister                = 0x0020;  // 1 byte, Read only
    const uint16_t PIIX4EInterruptController2                = 0x0020;  // 2 bytes
    // --------------------------------------------------------------
    const uint16_t PIIX4EDMAPageRegisters                    = 0x0080;  // 16 bytes
    const uint16_t CMOSBank1                                 = 0x0072;  // 2 bytes
    const uint16_t CMOSBank0                                 = 0x0070;  // 2 bytes
    const uint16_t PIIX4ERealTimeClocData                    = 0x0071;  // 1 byte
    const uint16_t PIIX4ERealTimeClockAddress                = 0x0070;  // start from bit 0 to bit 6, 7 bit size
    const uint16_t PIIX4EEnableNMI                           = 0x0070;  // start from 7th bit 1 bit size
    const uint16_t KeyboardControllerCMDStat                 = 0x0064;  // 1 byte
    const uint16_t PIIX4ENMISpeakerControl                   = 0x0061;  // 1 byte
    const uint16_t KeyboardControllerResetIRQ                = 0x0048;  // 1 byte
    const uint16_t PIIX4ECounterTimer2                       = 0x004B;  // 4 bytes
    const uint16_t PIIX4ECounterTimer1                       = 0x0040;  // 4 bytes
    // ------------------ Primary PIC (8259A PIC) --------------------------------
    const uint16_t PrimaryPICInterruptMaskRegister           = 0x0021;  // 1 byte
    const uint16_t PrimaryPICDataRegister                    = 0x0021;  // 1 byte
    const uint16_t PrimaryPICCommandRegister                 = 0x0020;  // 1 byte, Write only
    const uint16_t PrimaryPICStatusRegister                  = 0x0020;  // 1 byte, Read only
    const uint16_t PIIX4EInterruptController                 = 0x0020;  // 2 bytes
    // --------------------------------------------------------------
    const uint16_t PIIX4EDMA1                                = 0x0000;  // 16 bytes
}

namespace Interrupts
{
    namespace InterruptVectorTable
    {
        const uint32_t Interrupt0  = 0x000; // Divide by zero
        const uint32_t Interrupt1  = 0x004; // Single step (Debugger)
        const uint32_t Interrupt2  = 0x008; // Non Maskable Interrupt (NMI) Pin
        const uint32_t Interrupt3  = 0x00C; // Breakpoint (Debugger)
        const uint32_t Interrupt4  = 0x010; // Overflow
        const uint32_t Interrupt5  = 0x014; // Bounds check
        const uint32_t Interrupt6  = 0x018; // Undefined Operation Code (OPCode instruction)
        const uint32_t Interrupt7  = 0x01C; // No coprocessor
        const uint32_t Interrupt8  = 0x020; // Double Fault
        const uint32_t Interrupt9  = 0x024; // Coprocessor Segment Overrun
        const uint32_t Interrupt10 = 0x028; // Invalid Task State Segment (TSS)
        const uint32_t Interrupt11 = 0x02C; // Segment Not Present
        const uint32_t Interrupt12 = 0x030; // Stack Segment Overrun
        const uint32_t Interrupt13 = 0x034; // General Protection Fault (GPF)
        const uint32_t Interrupt14 = 0x038; // Page Fault
        const uint32_t Interrupt15 = 0x03C; // Unassigned
        const uint32_t Interrupt16 = 0x040; // Coprocessor error
        const uint32_t Interrupt17 = 0x044; // Alignment Check (486+ Only)
        const uint32_t Interrupt18 = 0x048; // Machine Check (Pentium/586+ Only)
        const uint32_t Interrupt19 = 0x04C; // Reserved
        const uint32_t Interrupt20 = 0x050; // Reserved
        const uint32_t Interrupt21 = 0x054; // Reserved
        const uint32_t Interrupt22 = 0x058; // Reserved 
        const uint32_t Interrupt23 = 0x05C; // Reserved
        const uint32_t Interrupt24 = 0x060; // Reserved
        const uint32_t Interrupt25 = 0x064; // Reserved
        const uint32_t Interrupt26 = 0x068; // Reserved
        const uint32_t Interrupt27 = 0x06C; // Reserved
        const uint32_t Interrupt28 = 0x070; // Reserved
        const uint32_t Interrupt29 = 0x074; // Reserved
        const uint32_t Interrupt30 = 0x078; // Reserved
        const uint32_t Interrupt31 = 0x07C; // Reserved
        
        const uint32_t Interrupt32 = 0x080; const uint32_t Interrupt64 = 0x100; const uint32_t Interrupt96  = 0x180;
        const uint32_t Interrupt33 = 0x084; const uint32_t Interrupt65 = 0x104; const uint32_t Interrupt97  = 0x184;
        const uint32_t Interrupt34 = 0x088; const uint32_t Interrupt66 = 0x108; const uint32_t Interrupt98  = 0x188;
        const uint32_t Interrupt35 = 0x08C; const uint32_t Interrupt67 = 0x10C; const uint32_t Interrupt99  = 0x18C;
        const uint32_t Interrupt36 = 0x090; const uint32_t Interrupt68 = 0x110; const uint32_t Interrupt100 = 0x190;
        const uint32_t Interrupt37 = 0x094; const uint32_t Interrupt69 = 0x114; const uint32_t Interrupt101 = 0x194;
        const uint32_t Interrupt38 = 0x098; const uint32_t Interrupt70 = 0x118; const uint32_t Interrupt102 = 0x198;
        const uint32_t Interrupt39 = 0x09C; const uint32_t Interrupt71 = 0x11C; const uint32_t Interrupt103 = 0x19C;
        const uint32_t Interrupt40 = 0x0A0; const uint32_t Interrupt72 = 0x120; const uint32_t Interrupt104 = 0x1A0;
        const uint32_t Interrupt41 = 0x0A4; const uint32_t Interrupt73 = 0x124; const uint32_t Interrupt105 = 0x1A4;
        const uint32_t Interrupt42 = 0x0A8; const uint32_t Interrupt74 = 0x128; const uint32_t Interrupt106 = 0x1A8;
        const uint32_t Interrupt43 = 0x0AC; const uint32_t Interrupt75 = 0x12C; const uint32_t Interrupt107 = 0x1AC;
        const uint32_t Interrupt44 = 0x0B0; const uint32_t Interrupt76 = 0x130; const uint32_t Interrupt108 = 0x1B0;
        const uint32_t Interrupt45 = 0x0B4; const uint32_t Interrupt77 = 0x134; const uint32_t Interrupt109 = 0x1B4;
        const uint32_t Interrupt46 = 0x0B8; const uint32_t Interrupt78 = 0x138; const uint32_t Interrupt110 = 0x1B8;
        const uint32_t Interrupt47 = 0x0BC; const uint32_t Interrupt79 = 0x13C; const uint32_t Interrupt111 = 0x1BC;
        const uint32_t Interrupt48 = 0x0C0; const uint32_t Interrupt80 = 0x140; const uint32_t Interrupt112 = 0x1C0;
        const uint32_t Interrupt49 = 0x0C4; const uint32_t Interrupt81 = 0x144; const uint32_t Interrupt113 = 0x1C4;
        const uint32_t Interrupt50 = 0x0C8; const uint32_t Interrupt82 = 0x148; const uint32_t Interrupt114 = 0x1C8;
        const uint32_t Interrupt51 = 0x0CC; const uint32_t Interrupt83 = 0x14C; const uint32_t Interrupt115 = 0x1CC;
        const uint32_t Interrupt52 = 0x0D0; const uint32_t Interrupt84 = 0x150; const uint32_t Interrupt116 = 0x1D0;
        const uint32_t Interrupt53 = 0x0D4; const uint32_t Interrupt85 = 0x154; const uint32_t Interrupt117 = 0x1D4;
        const uint32_t Interrupt54 = 0x0D8; const uint32_t Interrupt86 = 0x158; const uint32_t Interrupt118 = 0x1D8;
        const uint32_t Interrupt55 = 0x0DC; const uint32_t Interrupt87 = 0x15C; const uint32_t Interrupt119 = 0x1DC;
        const uint32_t Interrupt56 = 0x0E0; const uint32_t Interrupt88 = 0x160; const uint32_t Interrupt120 = 0x1E0;
        const uint32_t Interrupt57 = 0x0E4; const uint32_t Interrupt89 = 0x164; const uint32_t Interrupt121 = 0x1E4;
        const uint32_t Interrupt58 = 0x0E8; const uint32_t Interrupt90 = 0x168; const uint32_t Interrupt122 = 0x1E8;
        const uint32_t Interrupt59 = 0x0EC; const uint32_t Interrupt91 = 0x16C; const uint32_t Interrupt123 = 0x1EC;
        const uint32_t Interrupt60 = 0x0F0; const uint32_t Interrupt92 = 0x170; const uint32_t Interrupt124 = 0x1F0;
        const uint32_t Interrupt61 = 0x0F4; const uint32_t Interrupt93 = 0x174; const uint32_t Interrupt125 = 0x1F4;
        const uint32_t Interrupt62 = 0x0F8; const uint32_t Interrupt94 = 0x178; const uint32_t Interrupt126 = 0x1F8;
        const uint32_t Interrupt63 = 0x0FC; const uint32_t Interrupt95 = 0x17C; const uint32_t Interrupt127 = 0x1FC;

        const uint32_t Interrupt128 = 0x200; const uint32_t Interrupt160 = 0x280; const uint32_t Interrupt192 = 0x300; const uint32_t Interrupt224 = 0x380;
        const uint32_t Interrupt129 = 0x204; const uint32_t Interrupt161 = 0x284; const uint32_t Interrupt193 = 0x304; const uint32_t Interrupt225 = 0x384;
        const uint32_t Interrupt130 = 0x208; const uint32_t Interrupt162 = 0x288; const uint32_t Interrupt194 = 0x308; const uint32_t Interrupt226 = 0x388;
        const uint32_t Interrupt131 = 0x20C; const uint32_t Interrupt163 = 0x28C; const uint32_t Interrupt195 = 0x30C; const uint32_t Interrupt227 = 0x38C;
        const uint32_t Interrupt132 = 0x210; const uint32_t Interrupt164 = 0x290; const uint32_t Interrupt196 = 0x310; const uint32_t Interrupt228 = 0x390;
        const uint32_t Interrupt133 = 0x214; const uint32_t Interrupt165 = 0x294; const uint32_t Interrupt197 = 0x314; const uint32_t Interrupt229 = 0x394;
        const uint32_t Interrupt134 = 0x218; const uint32_t Interrupt166 = 0x298; const uint32_t Interrupt198 = 0x318; const uint32_t Interrupt230 = 0x398;
        const uint32_t Interrupt135 = 0x21C; const uint32_t Interrupt167 = 0x29C; const uint32_t Interrupt199 = 0x31C; const uint32_t Interrupt231 = 0x39C;
        const uint32_t Interrupt136 = 0x220; const uint32_t Interrupt168 = 0x2A0; const uint32_t Interrupt200 = 0x320; const uint32_t Interrupt232 = 0x3A0;
        const uint32_t Interrupt137 = 0x224; const uint32_t Interrupt169 = 0x2A4; const uint32_t Interrupt201 = 0x324; const uint32_t Interrupt233 = 0x3A4;
        const uint32_t Interrupt138 = 0x228; const uint32_t Interrupt170 = 0x2A8; const uint32_t Interrupt202 = 0x328; const uint32_t Interrupt234 = 0x3A8;
        const uint32_t Interrupt139 = 0x22C; const uint32_t Interrupt171 = 0x2AC; const uint32_t Interrupt203 = 0x32C; const uint32_t Interrupt235 = 0x3AC;
        const uint32_t Interrupt140 = 0x230; const uint32_t Interrupt172 = 0x2B0; const uint32_t Interrupt204 = 0x330; const uint32_t Interrupt236 = 0x3B0;
        const uint32_t Interrupt141 = 0x234; const uint32_t Interrupt173 = 0x2B4; const uint32_t Interrupt205 = 0x334; const uint32_t Interrupt237 = 0x3B4;
        const uint32_t Interrupt142 = 0x238; const uint32_t Interrupt174 = 0x2B8; const uint32_t Interrupt206 = 0x338; const uint32_t Interrupt238 = 0x3B8;
        const uint32_t Interrupt143 = 0x23C; const uint32_t Interrupt175 = 0x2BC; const uint32_t Interrupt207 = 0x33C; const uint32_t Interrupt239 = 0x3BC;
        const uint32_t Interrupt144 = 0x240; const uint32_t Interrupt176 = 0x2C0; const uint32_t Interrupt208 = 0x340; const uint32_t Interrupt240 = 0x3C0;
        const uint32_t Interrupt145 = 0x244; const uint32_t Interrupt177 = 0x2C4; const uint32_t Interrupt209 = 0x344; const uint32_t Interrupt241 = 0x3C4;
        const uint32_t Interrupt146 = 0x248; const uint32_t Interrupt178 = 0x2C8; const uint32_t Interrupt210 = 0x348; const uint32_t Interrupt242 = 0x3C8;
        const uint32_t Interrupt147 = 0x24C; const uint32_t Interrupt179 = 0x2CC; const uint32_t Interrupt211 = 0x34C; const uint32_t Interrupt243 = 0x3DC;
        const uint32_t Interrupt148 = 0x250; const uint32_t Interrupt180 = 0x2D0; const uint32_t Interrupt212 = 0x350; const uint32_t Interrupt244 = 0x3D0;
        const uint32_t Interrupt149 = 0x254; const uint32_t Interrupt181 = 0x2D4; const uint32_t Interrupt213 = 0x354; const uint32_t Interrupt245 = 0x3D4;
        const uint32_t Interrupt150 = 0x258; const uint32_t Interrupt182 = 0x2D8; const uint32_t Interrupt214 = 0x358; const uint32_t Interrupt246 = 0x3D8;
        const uint32_t Interrupt151 = 0x25C; const uint32_t Interrupt183 = 0x2DC; const uint32_t Interrupt215 = 0x35C; const uint32_t Interrupt274 = 0x3DC;
        const uint32_t Interrupt152 = 0x260; const uint32_t Interrupt184 = 0x2E0; const uint32_t Interrupt216 = 0x360; const uint32_t Interrupt248 = 0x3E0;
        const uint32_t Interrupt153 = 0x264; const uint32_t Interrupt185 = 0x2E4; const uint32_t Interrupt217 = 0x364; const uint32_t Interrupt249 = 0x3E4;
        const uint32_t Interrupt154 = 0x268; const uint32_t Interrupt186 = 0x2E8; const uint32_t Interrupt218 = 0x368; const uint32_t Interrupt250 = 0x3E8;
        const uint32_t Interrupt155 = 0x26C; const uint32_t Interrupt187 = 0x2EC; const uint32_t Interrupt219 = 0x36C; const uint32_t Interrupt251 = 0x3EC;
        const uint32_t Interrupt156 = 0x270; const uint32_t Interrupt188 = 0x2F0; const uint32_t Interrupt220 = 0x370; const uint32_t Interrupt252 = 0x3F0;
        const uint32_t Interrupt157 = 0x274; const uint32_t Interrupt189 = 0x2F4; const uint32_t Interrupt221 = 0x374; const uint32_t Interrupt253 = 0x3F4;
        const uint32_t Interrupt158 = 0x278; const uint32_t Interrupt190 = 0x2F8; const uint32_t Interrupt222 = 0x378; const uint32_t Interrupt254 = 0x3F8;
        const uint32_t Interrupt159 = 0x27C; const uint32_t Interrupt191 = 0x2FC; const uint32_t Interrupt223 = 0x37C; const uint32_t Interrupt255 = 0x3FC;
    }


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
            byte |= (interruptVectorAddress << 5) & 0b11100000; // bits 5..7
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
        ICW3Primary(
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


    const char *  IOChannelCheck                            = "NMI";
    const uint8_t IRQ0_IntervalTimer                        = 0x00;
    const uint8_t IRQ1_KeyboardBufferFull                   = 0x01; // Reserved
    const uint8_t IRQ2_SlavePICInterrupt                    = 0x02; // Reserved
    const uint8_t IRQ3_COM2                                 = 0x03; // Reserved
    const uint8_t IRQ4_COM1                                 = 0x04;
    const uint8_t IRQ5_LPT2                                 = 0x05;
    const uint8_t IRQ6_DisketteDrive                        = 0x06;
    const uint8_t IRQ7_LPT1                                 = 0x07;
    const uint8_t IRQ8_RealTimeClock                        = 0x08;
    const uint8_t IRQ9_PIIX4ESystemManagementBus            = 0x09; // Reserved
    const uint8_t IRQ10                                     = 0x0A; // User available
    const uint8_t IRQ11_WindowsSoundSystem                  = 0x0B; // User available
    const uint8_t IRQ12_OnboardMousePort                    = 0x0C; // User available if not present
    const uint8_t IRQ13_MathCoprocessor                     = 0x0D; // Reserved
    const uint8_t IRQ14_PrimaryIDE                          = 0x0E; // user available if not present
    const uint8_t IRQ15_SecondaryIDE                        = 0x0F; // user available if not present
}

namespace CPUMemoryMap
{
    //-------------- Extended Pentium Pro Processor Memory -----------------
    const uint32_t ExtendedPentiumProEnd                    = (uint32_t)0x3FFFFFFFFF;       // 64 GB
    const uint32_t ExtendedPentiumProStart                  = (uint32_t) 0x400000000;       // 4 GB
    //-------------- Extended Memory ---------------------------------------
    //---------------PCI ---------------------------------------------------
    const uint32_t PCIMemoryEnd                             = (uint32_t) 0x3FFFFFFFF;       // 4 GB
    const uint32_t HighBIOSEnd                              = (uint32_t)  0xFFFFFFFF;
    const uint32_t ResetVector                              = (uint32_t)  0xFFFFFFF0;       // CPU begins execution from here after reset
    const uint32_t HighBIOSStart                            = (uint32_t)  0xFFE00000;       
    //--------------Local Vector Table--------------------------------------
    const uint32_t LVTErrorRegister                         = (uint32_t)  0xFEE00370;
    const uint32_t LVTLINT1Register                         = (uint32_t)  0xFEE00360;
    const uint32_t LVTLINT0Register                         = (uint32_t)  0xFEE00350;
    const uint32_t LVTPerformanceCounterRegister            = (uint32_t)  0xFEE00340;
    const uint32_t LVTThermalMonitorRegister                = (uint32_t)  0xFEE00330;
    const uint32_t LVTTimerRegister                         = (uint32_t)  0xFEE00320;
    const uint32_t LVTCMCIRegister                          = (uint32_t)  0xFEE002F0;
    //--------------APIC ---------------------------------------------------
    const uint32_t APICConfigurationEnd                     = (uint32_t)  0xFEC0FFFF;
    const uint32_t APIC16Register                           = (uint32_t)  0xFEC0F000;
    const uint32_t APIC15Register                           = (uint32_t)  0xFEC0E000;
    const uint32_t APIC14Register                           = (uint32_t)  0xFEC0D000;
    const uint32_t APIC13Register                           = (uint32_t)  0xFEC0C000;
    const uint32_t APIC12Register                           = (uint32_t)  0xFEC0B000;
    const uint32_t APIC11Register                           = (uint32_t)  0xFEC0A000;
    const uint32_t APIC10Register                           = (uint32_t)  0xFEC09000;
    const uint32_t APIC9Register                            = (uint32_t)  0xFEC08000;
    const uint32_t APIC8Register                            = (uint32_t)  0xFEC07000;
    const uint32_t APIC7Register                            = (uint32_t)  0xFEC06000;
    const uint32_t APIC6Register                            = (uint32_t)  0xFEC05000;
    const uint32_t APIC5Register                            = (uint32_t)  0xFEC04000;
    const uint32_t APIC4Register                            = (uint32_t)  0xFEC03000;
    const uint32_t APIC3Register                            = (uint32_t)  0xFEC02000;
    const uint32_t APIC2Register                            = (uint32_t)  0xFEC01000;
    const uint32_t APIC1Register                            = (uint32_t)  0xFEC00000;
    const uint32_t APICConfigurationStart                   = (uint32_t)  0xFEC00000;       // 4 Gbytes minus 20 Mbytes
    const uint32_t PCIMemoryStart                           = (uint32_t)  0x40000000;       
    //---------------DRAM --------------------------------------------------
    const uint32_t MainDRAMEnd                              = (uint32_t)  0x3FFFFFFF;       // 1 GB
    const uint32_t MainDRAMStart                            = (uint32_t)   0x1000000;
    const uint32_t ExtendedISA                              = (uint32_t)    0x100000;       
    // ------------- DOS Compatibility -------------------------------------
    const uint32_t UpperBIOSEnd                             = (uint32_t)     0xFFFFF;       // 1 MB
    const uint32_t UpperBIOSStart                           = (uint32_t)     0xF0000;       
    const uint32_t LowerBIOSEnd                             = (uint32_t)     0xEFFFF;       // 960 KB
    const uint32_t LowerBIOSStart                           = (uint32_t)     0xE0000;       
    const uint32_t ISAExpansionEnd                          = (uint32_t)     0xDFFFF;       // 896 KB
    const uint32_t ISAExpansionStart                        = (uint32_t)     0xC0000;
    const uint32_t PCIVideoMemoryTextModeEnd                = (uint32_t)     0xBFFFF;
    const uint32_t PCIVideoMemoryTextModeStart              = (uint32_t)     0xB8000;       // 768 KB
    const uint32_t PCIVideoMemoryGraphicalModeEnd           = (uint32_t)     0xB7FFF;       
    const uint32_t PCIVideoMemoryGraphicalModeStart         = (uint32_t)     0xA0000;       
    // ------------- DOS Area -------------------------------------
    const uint32_t DOSMemoryHoleEnd                         = (uint32_t)     0x9FFFF;       // 640 KB
    const uint32_t DOSMemoryHoleStart                       = (uint32_t)     0x80000;
    const uint32_t DOSPMCMainEnd                            = (uint32_t)     0x7FFFF;       // 512 KB
    const uint32_t DOSPMCMainStart                          = (uint32_t)     0x00000;      
                                                                                            // 0 KB
}

#endif // __MEMORY_H