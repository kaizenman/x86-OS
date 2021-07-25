#pragma once


/*
namespace Interrupts
{
    namespace InterruptVectorTable
    {
        constexpr uint32_t Interrupt0  = 0x000; // Divide by zero
        constexpr uint32_t Interrupt1  = 0x004; // Single step (Debugger)
        constexpr uint32_t Interrupt2  = 0x008; // Non Maskable Interrupt (NMI) Pin
        constexpr uint32_t Interrupt3  = 0x00C; // Breakpoint (Debugger)
        constexpr uint32_t Interrupt4  = 0x010; // Overflow
        constexpr uint32_t Interrupt5  = 0x014; // Bounds check
        constexpr uint32_t Interrupt6  = 0x018; // Undefined Operation Code (OPCode instruction)
        constexpr uint32_t Interrupt7  = 0x01C; // No coprocessor
        constexpr uint32_t Interrupt8  = 0x020; // Double Fault
        constexpr uint32_t Interrupt9  = 0x024; // Coprocessor Segment Overrun
        constexpr uint32_t Interrupt10 = 0x028; // Invalid Task State Segment (TSS)
        constexpr uint32_t Interrupt11 = 0x02C; // Segment Not Present
        constexpr uint32_t Interrupt12 = 0x030; // Stack Segment Overrun
        constexpr uint32_t Interrupt13 = 0x034; // General Protection Fault (GPF)
        constexpr uint32_t Interrupt14 = 0x038; // Page Fault
        constexpr uint32_t Interrupt15 = 0x03C; // Unassigned
        constexpr uint32_t Interrupt16 = 0x040; // Coprocessor error
        constexpr uint32_t Interrupt17 = 0x044; // Alignment Check (486+ Only)
        constexpr uint32_t Interrupt18 = 0x048; // Machine Check (Pentium/586+ Only)
        constexpr uint32_t Interrupt19 = 0x04C; // Reserved
        constexpr uint32_t Interrupt20 = 0x050; // Reserved
        constexpr uint32_t Interrupt21 = 0x054; // Reserved
        constexpr uint32_t Interrupt22 = 0x058; // Reserved 
        constexpr uint32_t Interrupt23 = 0x05C; // Reserved
        constexpr uint32_t Interrupt24 = 0x060; // Reserved
        constexpr uint32_t Interrupt25 = 0x064; // Reserved
        constexpr uint32_t Interrupt26 = 0x068; // Reserved
        constexpr uint32_t Interrupt27 = 0x06C; // Reserved
        constexpr uint32_t Interrupt28 = 0x070; // Reserved
        constexpr uint32_t Interrupt29 = 0x074; // Reserved
        constexpr uint32_t Interrupt30 = 0x078; // Reserved
        constexpr uint32_t Interrupt31 = 0x07C; // Reserved
        
        constexpr uint32_t Interrupt32 = 0x080; constexpr uint32_t Interrupt64 = 0x100; constexpr uint32_t Interrupt96  = 0x180;
        constexpr uint32_t Interrupt33 = 0x084; constexpr uint32_t Interrupt65 = 0x104; constexpr uint32_t Interrupt97  = 0x184;
        constexpr uint32_t Interrupt34 = 0x088; constexpr uint32_t Interrupt66 = 0x108; constexpr uint32_t Interrupt98  = 0x188;
        constexpr uint32_t Interrupt35 = 0x08C; constexpr uint32_t Interrupt67 = 0x10C; constexpr uint32_t Interrupt99  = 0x18C;
        constexpr uint32_t Interrupt36 = 0x090; constexpr uint32_t Interrupt68 = 0x110; constexpr uint32_t Interrupt100 = 0x190;
        constexpr uint32_t Interrupt37 = 0x094; constexpr uint32_t Interrupt69 = 0x114; constexpr uint32_t Interrupt101 = 0x194;
        constexpr uint32_t Interrupt38 = 0x098; constexpr uint32_t Interrupt70 = 0x118; constexpr uint32_t Interrupt102 = 0x198;
        constexpr uint32_t Interrupt39 = 0x09C; constexpr uint32_t Interrupt71 = 0x11C; constexpr uint32_t Interrupt103 = 0x19C;
        constexpr uint32_t Interrupt40 = 0x0A0; constexpr uint32_t Interrupt72 = 0x120; constexpr uint32_t Interrupt104 = 0x1A0;
        constexpr uint32_t Interrupt41 = 0x0A4; constexpr uint32_t Interrupt73 = 0x124; constexpr uint32_t Interrupt105 = 0x1A4;
        constexpr uint32_t Interrupt42 = 0x0A8; constexpr uint32_t Interrupt74 = 0x128; constexpr uint32_t Interrupt106 = 0x1A8;
        constexpr uint32_t Interrupt43 = 0x0AC; constexpr uint32_t Interrupt75 = 0x12C; constexpr uint32_t Interrupt107 = 0x1AC;
        constexpr uint32_t Interrupt44 = 0x0B0; constexpr uint32_t Interrupt76 = 0x130; constexpr uint32_t Interrupt108 = 0x1B0;
        constexpr uint32_t Interrupt45 = 0x0B4; constexpr uint32_t Interrupt77 = 0x134; constexpr uint32_t Interrupt109 = 0x1B4;
        constexpr uint32_t Interrupt46 = 0x0B8; constexpr uint32_t Interrupt78 = 0x138; constexpr uint32_t Interrupt110 = 0x1B8;
        constexpr uint32_t Interrupt47 = 0x0BC; constexpr uint32_t Interrupt79 = 0x13C; constexpr uint32_t Interrupt111 = 0x1BC;
        constexpr uint32_t Interrupt48 = 0x0C0; constexpr uint32_t Interrupt80 = 0x140; constexpr uint32_t Interrupt112 = 0x1C0;
        constexpr uint32_t Interrupt49 = 0x0C4; constexpr uint32_t Interrupt81 = 0x144; constexpr uint32_t Interrupt113 = 0x1C4;
        constexpr uint32_t Interrupt50 = 0x0C8; constexpr uint32_t Interrupt82 = 0x148; constexpr uint32_t Interrupt114 = 0x1C8;
        constexpr uint32_t Interrupt51 = 0x0CC; constexpr uint32_t Interrupt83 = 0x14C; constexpr uint32_t Interrupt115 = 0x1CC;
        constexpr uint32_t Interrupt52 = 0x0D0; constexpr uint32_t Interrupt84 = 0x150; constexpr uint32_t Interrupt116 = 0x1D0;
        constexpr uint32_t Interrupt53 = 0x0D4; constexpr uint32_t Interrupt85 = 0x154; constexpr uint32_t Interrupt117 = 0x1D4;
        constexpr uint32_t Interrupt54 = 0x0D8; constexpr uint32_t Interrupt86 = 0x158; constexpr uint32_t Interrupt118 = 0x1D8;
        constexpr uint32_t Interrupt55 = 0x0DC; constexpr uint32_t Interrupt87 = 0x15C; constexpr uint32_t Interrupt119 = 0x1DC;
        constexpr uint32_t Interrupt56 = 0x0E0; constexpr uint32_t Interrupt88 = 0x160; constexpr uint32_t Interrupt120 = 0x1E0;
        constexpr uint32_t Interrupt57 = 0x0E4; constexpr uint32_t Interrupt89 = 0x164; constexpr uint32_t Interrupt121 = 0x1E4;
        constexpr uint32_t Interrupt58 = 0x0E8; constexpr uint32_t Interrupt90 = 0x168; constexpr uint32_t Interrupt122 = 0x1E8;
        constexpr uint32_t Interrupt59 = 0x0EC; constexpr uint32_t Interrupt91 = 0x16C; constexpr uint32_t Interrupt123 = 0x1EC;
        constexpr uint32_t Interrupt60 = 0x0F0; constexpr uint32_t Interrupt92 = 0x170; constexpr uint32_t Interrupt124 = 0x1F0;
        constexpr uint32_t Interrupt61 = 0x0F4; constexpr uint32_t Interrupt93 = 0x174; constexpr uint32_t Interrupt125 = 0x1F4;
        constexpr uint32_t Interrupt62 = 0x0F8; constexpr uint32_t Interrupt94 = 0x178; constexpr uint32_t Interrupt126 = 0x1F8;
        constexpr uint32_t Interrupt63 = 0x0FC; constexpr uint32_t Interrupt95 = 0x17C; constexpr uint32_t Interrupt127 = 0x1FC;

        constexpr uint32_t Interrupt128 = 0x200; constexpr uint32_t Interrupt160 = 0x280; constexpr uint32_t Interrupt192 = 0x300; constexpr uint32_t Interrupt224 = 0x380;
        constexpr uint32_t Interrupt129 = 0x204; constexpr uint32_t Interrupt161 = 0x284; constexpr uint32_t Interrupt193 = 0x304; constexpr uint32_t Interrupt225 = 0x384;
        constexpr uint32_t Interrupt130 = 0x208; constexpr uint32_t Interrupt162 = 0x288; constexpr uint32_t Interrupt194 = 0x308; constexpr uint32_t Interrupt226 = 0x388;
        constexpr uint32_t Interrupt131 = 0x20C; constexpr uint32_t Interrupt163 = 0x28C; constexpr uint32_t Interrupt195 = 0x30C; constexpr uint32_t Interrupt227 = 0x38C;
        constexpr uint32_t Interrupt132 = 0x210; constexpr uint32_t Interrupt164 = 0x290; constexpr uint32_t Interrupt196 = 0x310; constexpr uint32_t Interrupt228 = 0x390;
        constexpr uint32_t Interrupt133 = 0x214; constexpr uint32_t Interrupt165 = 0x294; constexpr uint32_t Interrupt197 = 0x314; constexpr uint32_t Interrupt229 = 0x394;
        constexpr uint32_t Interrupt134 = 0x218; constexpr uint32_t Interrupt166 = 0x298; constexpr uint32_t Interrupt198 = 0x318; constexpr uint32_t Interrupt230 = 0x398;
        constexpr uint32_t Interrupt135 = 0x21C; constexpr uint32_t Interrupt167 = 0x29C; constexpr uint32_t Interrupt199 = 0x31C; constexpr uint32_t Interrupt231 = 0x39C;
        constexpr uint32_t Interrupt136 = 0x220; constexpr uint32_t Interrupt168 = 0x2A0; constexpr uint32_t Interrupt200 = 0x320; constexpr uint32_t Interrupt232 = 0x3A0;
        constexpr uint32_t Interrupt137 = 0x224; constexpr uint32_t Interrupt169 = 0x2A4; constexpr uint32_t Interrupt201 = 0x324; constexpr uint32_t Interrupt233 = 0x3A4;
        constexpr uint32_t Interrupt138 = 0x228; constexpr uint32_t Interrupt170 = 0x2A8; constexpr uint32_t Interrupt202 = 0x328; constexpr uint32_t Interrupt234 = 0x3A8;
        constexpr uint32_t Interrupt139 = 0x22C; constexpr uint32_t Interrupt171 = 0x2AC; constexpr uint32_t Interrupt203 = 0x32C; constexpr uint32_t Interrupt235 = 0x3AC;
        constexpr uint32_t Interrupt140 = 0x230; constexpr uint32_t Interrupt172 = 0x2B0; constexpr uint32_t Interrupt204 = 0x330; constexpr uint32_t Interrupt236 = 0x3B0;
        constexpr uint32_t Interrupt141 = 0x234; constexpr uint32_t Interrupt173 = 0x2B4; constexpr uint32_t Interrupt205 = 0x334; constexpr uint32_t Interrupt237 = 0x3B4;
        constexpr uint32_t Interrupt142 = 0x238; constexpr uint32_t Interrupt174 = 0x2B8; constexpr uint32_t Interrupt206 = 0x338; constexpr uint32_t Interrupt238 = 0x3B8;
        constexpr uint32_t Interrupt143 = 0x23C; constexpr uint32_t Interrupt175 = 0x2BC; constexpr uint32_t Interrupt207 = 0x33C; constexpr uint32_t Interrupt239 = 0x3BC;
        constexpr uint32_t Interrupt144 = 0x240; constexpr uint32_t Interrupt176 = 0x2C0; constexpr uint32_t Interrupt208 = 0x340; constexpr uint32_t Interrupt240 = 0x3C0;
        constexpr uint32_t Interrupt145 = 0x244; constexpr uint32_t Interrupt177 = 0x2C4; constexpr uint32_t Interrupt209 = 0x344; constexpr uint32_t Interrupt241 = 0x3C4;
        constexpr uint32_t Interrupt146 = 0x248; constexpr uint32_t Interrupt178 = 0x2C8; constexpr uint32_t Interrupt210 = 0x348; constexpr uint32_t Interrupt242 = 0x3C8;
        constexpr uint32_t Interrupt147 = 0x24C; constexpr uint32_t Interrupt179 = 0x2CC; constexpr uint32_t Interrupt211 = 0x34C; constexpr uint32_t Interrupt243 = 0x3DC;
        constexpr uint32_t Interrupt148 = 0x250; constexpr uint32_t Interrupt180 = 0x2D0; constexpr uint32_t Interrupt212 = 0x350; constexpr uint32_t Interrupt244 = 0x3D0;
        constexpr uint32_t Interrupt149 = 0x254; constexpr uint32_t Interrupt181 = 0x2D4; constexpr uint32_t Interrupt213 = 0x354; constexpr uint32_t Interrupt245 = 0x3D4;
        constexpr uint32_t Interrupt150 = 0x258; constexpr uint32_t Interrupt182 = 0x2D8; constexpr uint32_t Interrupt214 = 0x358; constexpr uint32_t Interrupt246 = 0x3D8;
        constexpr uint32_t Interrupt151 = 0x25C; constexpr uint32_t Interrupt183 = 0x2DC; constexpr uint32_t Interrupt215 = 0x35C; constexpr uint32_t Interrupt274 = 0x3DC;
        constexpr uint32_t Interrupt152 = 0x260; constexpr uint32_t Interrupt184 = 0x2E0; constexpr uint32_t Interrupt216 = 0x360; constexpr uint32_t Interrupt248 = 0x3E0;
        constexpr uint32_t Interrupt153 = 0x264; constexpr uint32_t Interrupt185 = 0x2E4; constexpr uint32_t Interrupt217 = 0x364; constexpr uint32_t Interrupt249 = 0x3E4;
        constexpr uint32_t Interrupt154 = 0x268; constexpr uint32_t Interrupt186 = 0x2E8; constexpr uint32_t Interrupt218 = 0x368; constexpr uint32_t Interrupt250 = 0x3E8;
        constexpr uint32_t Interrupt155 = 0x26C; constexpr uint32_t Interrupt187 = 0x2EC; constexpr uint32_t Interrupt219 = 0x36C; constexpr uint32_t Interrupt251 = 0x3EC;
        constexpr uint32_t Interrupt156 = 0x270; constexpr uint32_t Interrupt188 = 0x2F0; constexpr uint32_t Interrupt220 = 0x370; constexpr uint32_t Interrupt252 = 0x3F0;
        constexpr uint32_t Interrupt157 = 0x274; constexpr uint32_t Interrupt189 = 0x2F4; constexpr uint32_t Interrupt221 = 0x374; constexpr uint32_t Interrupt253 = 0x3F4;
        constexpr uint32_t Interrupt158 = 0x278; constexpr uint32_t Interrupt190 = 0x2F8; constexpr uint32_t Interrupt222 = 0x378; constexpr uint32_t Interrupt254 = 0x3F8;
        constexpr uint32_t Interrupt159 = 0x27C; constexpr uint32_t Interrupt191 = 0x2FC; constexpr uint32_t Interrupt223 = 0x37C; constexpr uint32_t Interrupt255 = 0x3FC;
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
        ICW3Secondary(
            // bit 0 - 2 IRQ number the master PIC uses to connect to (In binary notation)
            // bit2 is IRQ2 the 80x86 architecture uses IRQ line 2 to connect the master PIC to the slave PIC.
            // bit 3 - 7 must be 0
            uint8_t masterPICIRQNumber, 
            uint8_t reserved = 0
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


    constexpr char *  IOChannelCheck                            = "NMI";
    constexpr uint8_t IRQ0_IntervalTimer                        = 0x00;
    constexpr uint8_t IRQ1_KeyboardBufferFull                   = 0x01; // Reserved
    constexpr uint8_t IRQ2_SlavePICInterrupt                    = 0x02; // Reserved
    constexpr uint8_t IRQ3_COM2                                 = 0x03; // Reserved
    constexpr uint8_t IRQ4_COM1                                 = 0x04;
    constexpr uint8_t IRQ5_LPT2                                 = 0x05;
    constexpr uint8_t IRQ6_DisketteDrive                        = 0x06;
    constexpr uint8_t IRQ7_LPT1                                 = 0x07;
    constexpr uint8_t IRQ8_RealTimeClock                        = 0x08;
    constexpr uint8_t IRQ9_PIIX4ESystemManagementBus            = 0x09; // Reserved
    constexpr uint8_t IRQ10                                     = 0x0A; // User available
    constexpr uint8_t IRQ11_WindowsSoundSystem                  = 0x0B; // User available
    constexpr uint8_t IRQ12_OnboardMousePort                    = 0x0C; // User available if not present
    constexpr uint8_t IRQ13_MathCoprocessor                     = 0x0D; // Reserved
    constexpr uint8_t IRQ14_PrimaryIDE                          = 0x0E; // user available if not present
    constexpr uint8_t IRQ15_SecondaryIDE                        = 0x0F; // user available if not present
}
*/

