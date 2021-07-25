#pragma once

#include "types.h"

namespace x86_OS
{
    namespace common
    {
        namespace cpu_memory_map
        {
            //-------------- Extended Pentium Pro Processor Memory -----------------
            constexpr uint32_t ExtendedPentiumProEnd                    = (uint32_t)0x3FFFFFFFFF;       // 64 GB
            constexpr uint32_t ExtendedPentiumProStart                  = (uint32_t) 0x400000000;       // 4 GB
            //-------------- Extended Memory ---------------------------------------
            //---------------PCI ---------------------------------------------------
            constexpr uint32_t PCIMemoryEnd                             = (uint32_t) 0x3FFFFFFFF;       // 4 GB
            constexpr uint32_t HighBIOSEnd                              = (uint32_t)  0xFFFFFFFF;
            constexpr uint32_t ResetVector                              = (uint32_t)  0xFFFFFFF0;       // CPU begins execution from here after reset
            constexpr uint32_t HighBIOSStart                            = (uint32_t)  0xFFE00000;       
            //--------------Local Vector Table--------------------------------------
            constexpr uint32_t LVTErrorRegister                         = (uint32_t)  0xFEE00370;
            constexpr uint32_t LVTLINT1Register                         = (uint32_t)  0xFEE00360;
            constexpr uint32_t LVTLINT0Register                         = (uint32_t)  0xFEE00350;
            constexpr uint32_t LVTPerformanceCounterRegister            = (uint32_t)  0xFEE00340;
            constexpr uint32_t LVTThermalMonitorRegister                = (uint32_t)  0xFEE00330;
            constexpr uint32_t LVTTimerRegister                         = (uint32_t)  0xFEE00320;
            constexpr uint32_t LVTCMCIRegister                          = (uint32_t)  0xFEE002F0;
            //--------------APIC ---------------------------------------------------
            constexpr uint32_t APICConfigurationEnd                     = (uint32_t)  0xFEC0FFFF;
            constexpr uint32_t APIC16Register                           = (uint32_t)  0xFEC0F000;
            constexpr uint32_t APIC15Register                           = (uint32_t)  0xFEC0E000;
            constexpr uint32_t APIC14Register                           = (uint32_t)  0xFEC0D000;
            constexpr uint32_t APIC13Register                           = (uint32_t)  0xFEC0C000;
            constexpr uint32_t APIC12Register                           = (uint32_t)  0xFEC0B000;
            constexpr uint32_t APIC11Register                           = (uint32_t)  0xFEC0A000;
            constexpr uint32_t APIC10Register                           = (uint32_t)  0xFEC09000;
            constexpr uint32_t APIC9Register                            = (uint32_t)  0xFEC08000;
            constexpr uint32_t APIC8Register                            = (uint32_t)  0xFEC07000;
            constexpr uint32_t APIC7Register                            = (uint32_t)  0xFEC06000;
            constexpr uint32_t APIC6Register                            = (uint32_t)  0xFEC05000;
            constexpr uint32_t APIC5Register                            = (uint32_t)  0xFEC04000;
            constexpr uint32_t APIC4Register                            = (uint32_t)  0xFEC03000;
            constexpr uint32_t APIC3Register                            = (uint32_t)  0xFEC02000;
            constexpr uint32_t APIC2Register                            = (uint32_t)  0xFEC01000;
            constexpr uint32_t APIC1Register                            = (uint32_t)  0xFEC00000;
            constexpr uint32_t APICConfigurationStart                   = (uint32_t)  0xFEC00000;       // 4 Gbytes minus 20 Mbytes
            constexpr uint32_t PCIMemoryStart                           = (uint32_t)  0x40000000;       
            //---------------DRAM --------------------------------------------------
            constexpr uint32_t MainDRAMEnd                              = (uint32_t)  0x3FFFFFFF;       // 1 GB
            constexpr uint32_t MainDRAMStart                            = (uint32_t)   0x1000000;
            constexpr uint32_t ExtendedISA                              = (uint32_t)    0x100000;       
            // ------------- DOS Compatibility -------------------------------------
            constexpr uint32_t UpperBIOSEnd                             = (uint32_t)     0xFFFFF;       // 1 MB
            constexpr uint32_t UpperBIOSStart                           = (uint32_t)     0xF0000;       
            constexpr uint32_t LowerBIOSEnd                             = (uint32_t)     0xEFFFF;       // 960 KB
            constexpr uint32_t LowerBIOSStart                           = (uint32_t)     0xE0000;       
            constexpr uint32_t ISAExpansionEnd                          = (uint32_t)     0xDFFFF;       // 896 KB
            constexpr uint32_t ISAExpansionStart                        = (uint32_t)     0xC0000;
            constexpr uint32_t PCIVideoMemoryTextModeEnd                = (uint32_t)     0xBFFFF;
            constexpr uint32_t PCIVideoMemoryTextModeStart              = (uint32_t)     0xB8000;       // 768 KB
            constexpr uint32_t PCIVideoMemoryGraphicalModeEnd           = (uint32_t)     0xB7FFF;       
            constexpr uint32_t PCIVideoMemoryGraphicalModeStart         = (uint32_t)     0xA0000;       
            // ------------- DOS Area -------------------------------------
            constexpr uint32_t DOSMemoryHoleEnd                         = (uint32_t)     0x9FFFF;       // 640 KB
            constexpr uint32_t DOSMemoryHoleStart                       = (uint32_t)     0x80000;
            constexpr uint32_t DOSPMCMainEnd                            = (uint32_t)     0x7FFFF;       // 512 KB
            constexpr uint32_t DOSPMCMainStart                          = (uint32_t)     0x00000;      
                                                                                                        // 0 KB
        }
    }
}