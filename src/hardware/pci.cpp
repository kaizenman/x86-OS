#include <common/console.h>
#include <hardware/pci.h>
#include <hardware/vendor_codes.h>

using namespace x86_OS::hardware;
using namespace x86_OS::common;

PCIDeviceDescriptor::PCIDeviceDescriptor()
{

}

PCIDeviceDescriptor::~PCIDeviceDescriptor()
{

}

PCI::PCI(): dataPort(0xCFC), commandPort(0xCF8)
{
    
}

PCI::~PCI()
{
}

uint32_t PCI::Read(uint16_t bus, uint16_t device, uint16_t function, uint32_t registeroffset)
{
    uint32_t id = 
        0x1 << 31
        | ((bus & 0xFF) << 16)
        | ((device & 0x1F) << 11)
        | ((function & 0x07) << 8)
        | (registeroffset & 0xFC);

    commandPort.Write(id);
    uint32_t result = dataPort.Read();
    return result >> (8* (registeroffset % 4));
}

void PCI::Write(uint16_t bus, uint16_t device, uint16_t function, uint32_t registeroffset, uint32_t value)
{
    uint32_t id = 
        0x1 << 31
        | ((bus & 0xFF) << 16)
        | ((device & 0x1F) << 11)
        | ((function & 0x07) << 8)
        | (registeroffset & 0xFC);
    
    commandPort.Write(id);
    dataPort.Write(value);
}

bool PCI::DeviceHasFunctions(uint16_t bus, uint16_t device)
{
    return Read(bus, device, 0, 0x0E) & (1<<7);
}

// Intel Corporation	8086	440FX - 82441FX PMC [Natoma]	1237
// Intel Corporation	8086	82371SB PIIX3 ISA [Natoma/Triton II]	7000
// Intel Corporation	8086	82371SB PIIX3 IDE [Natoma/Triton II]	7010
// Intel Corporation	8086	82371AB/EB/MB PIIX4 ACPI	7113
// Intel Corporation	8086	82540EM Gigabit Ethernet Controller	100e
// Red Hat, Inc.	1af4	Virtio GPU	1050
void PCI::SelectDrivers(DriverManager* driverManager, InterruptManager* interrupts)
{
    for (int bus = 0; bus < 8; ++bus)
    {
        for (int device = 0; device < 32; ++device)
        {
            int numFunctions = DeviceHasFunctions(bus, device) ? 8 : 1;
            for (int function = 0; function < numFunctions; ++function)
            {
                PCIDeviceDescriptor dev = GetDeviceDescriptor(bus, device, function);
                if (dev.vendor_id == 0x0000 || dev.vendor_id == 0xFFFF) 
                    continue;

                for (int barNum = 0; barNum < 6; ++barNum)
                {
                    BAR bar = GetBAR(bus, device, function, barNum);
                    if (bar.address && (bar.type == InputOutput))
                        dev.portBase = (uint32_t)bar.address;

                    Driver* driver = GetDriver(dev, interrupts);
                    if (driver != 0)
                        driverManager->AddDriver(driver);
                }

                Console::Write("PCI BUS ");
                Console::WriteHex(bus & 0xFF);
                Console::Write(", DEVICE ");
                Console::WriteHex(device & 0xFF);
                Console::Write(", FUNCTION ");
                Console::WriteHex(function & 0xFF);
                Console::Write(" = VENDOR ");
                Console::WriteHex((dev.vendor_id & 0xFF00) >> 8);
                Console::WriteHex(dev.vendor_id & 0xFF);
                Console::Write(", DEVICE ");
                Console::WriteHex((dev.device_id & 0xFF00) >> 8);
                Console::WriteHex(dev.device_id & 0xFF);
                Console::Write("\n");

                switch (dev.vendor_id)
                {
                    case vendor::intel:
                        switch(dev.device_id)
                        {
                            case 0x1237:
                                Console::Write("     Intel Corporation 8086 440FX - 82441FX PMC [Natoma] 1237\n");
                                break;
                            case 0x7000:
                                Console::Write("     Intel Corporation 8086 82371SB PIIX3 ISA [Natoma/Triton II] 7000\n");
                                break;
                            case 0x7010:
                                Console::Write("     Intel Corporation 8086 82371SB PIIX3 IDE [Natoma/Triton II] 7010");
                                break;
                            case 0x7113:
                                Console::Write("     Intel Corporation 8086 82371AB/EB/MB PIIX4 ACPI 7113");
                                break;
                            case 0x100E: // Intel Corporation 8086 82540EM Gigabit Ethernet Controller	100e
                                Console::Write("     Intel Corporation 8086 82540EM Gigabit Ethernet Controller 100e\n");
                                break;
                        }
                        break;
                    case vendor::redhat: // Red Hat, Inc.
                        switch(dev.device_id)
                        {
                            case 0x1050: // Red Hat, Inc. 1af4 Virtio GPU 1050
                                Console::Write("     Red Hat, Inc. 1af4 Virtio GPU \n");
                                break;
                        }
                        break;
                }

                switch(dev.class_id)
                {
                    case pci::device_class::unclassified:
                        break;
                    case pci::device_class::mass_storage_controller:
                        break;
                    case pci::device_class::network_controller:
                        Console::Write("     Network controller found\n");
                        break;
                    case pci::device_class::display_controller:
                        switch(dev.subclass_id)
                        {
                            case pci::display_controller_subclass::vga_compatible:
                                Console::Write("     VGA compatible\n");
                                break;
                        }
                        break;
                    
                }

            }
        }
    }
}

PCIDeviceDescriptor PCI::GetDeviceDescriptor(uint16_t bus, uint16_t device, uint16_t function)
{
    PCIDeviceDescriptor result;

    result.bus = bus;
    result.device = device;
    result.function = function;

    result.vendor_id = Read(bus, device, function, 0x00);
    result.device_id = Read(bus, device, function, 0x02);

    result.class_id = Read(bus, device, function, 0x0b);
    result.subclass_id = Read(bus, device, function, 0x0a);
    result.interface_id = Read(bus, device, function, 0x09);

    result.revision = Read(bus, device, function, 0x08);
    result.interrupt = Read(bus, device, function, 0x3c);

    return result;
}

BAR PCI::GetBAR(uint16_t bus, uint16_t device, uint16_t function, uint16_t bar)
{
    BAR result;

    uint32_t headertype = Read(bus, device, function, 0x0E) & 0x7F;
    int maxBARs = 6 - (4 * headertype);
    if (bar >= maxBARs)
        return result;

    uint32_t bar_value = Read(bus, device, function, 0x10 + 4*bar);
    result.type = (bar_value & 0x1) ? InputOutput : MemoryMapping;
    uint32_t temp;


    if (result.type == MemoryMapping)
    {
        // @todo
        switch ((bar_value >> 1) & 0x3)
        {
            case 0: // 32 Bit Mode
            case 1: // 20 Bit Mode
            case 2: // 64 Bit Mode
                break;
        }
        result.prefetchable = ((bar_value >> 3) & 0x1) == 0x1;
    }
    else // InputOutput
    {
        result.address = (uint8_t*)(bar_value & ~0x3);
        result.prefetchable = false;
    }


    return result;
}

Driver* PCI::GetDriver(PCIDeviceDescriptor dev, InterruptManager* interrupts)
{
    switch (dev.vendor_id)
    {
        switch (dev.vendor_id)
        {
            case vendor::intel:
                switch(dev.device_id)
                {
                    case 0x1237:
                        break;
                    case 0x7000:
                        break;
                    case 0x7010:
                        break;
                    case 0x7113:
                        break;
                    case 0x100E: // Intel Corporation 8086 82540EM Gigabit Ethernet Controller	100e
                        break;
                }
                break;
            case vendor::redhat: // Red Hat, Inc.
                switch(dev.device_id)
                {
                    case 0x1050: // Red Hat, Inc. 1af4 Virtio GPU 1050
                        break;
                }
                break;
        }

        switch(dev.class_id)
        {
            case pci::device_class::unclassified:
                break;
            case pci::device_class::mass_storage_controller:
                break;
            case pci::device_class::network_controller:
                break;
            case pci::device_class::display_controller:
                switch(dev.subclass_id)
                {
                    case pci::display_controller_subclass::vga_compatible:

                        break;
                }
                break;
            
        }
    }

    return 0;
}
