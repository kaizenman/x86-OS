#pragma once

#include <common/types.h>
#include <drivers/driver.h>
#include <hardware/interrupts.h>
#include <hardware/port.h>

using namespace x86_OS::drivers;

namespace x86_OS
{
    namespace hardware
    {
        namespace pci
        {
            namespace device_class {

                // provide backward compatibility for devices that were built before Class Code field was defined.
                // No new devices should use this value and existing devices should switch to a more appropriate value if possible
                constexpr uint8_t unclassified                                        = 0x00;
                // all types of mass storage controllers        
                constexpr uint8_t mass_storage_controller                             = 0x01;
                // all types of network controllers     
                constexpr uint8_t network_controller                                  = 0x02;
                // all types of display controllers
                constexpr uint8_t display_controller                                  = 0x03;
                // all types of multimedia devices
                constexpr uint8_t multimedia_device                                   = 0x04;
                // all types of memory controllers
                constexpr uint8_t memory_controller                                   = 0x05;
                // all types of bridge devices
                // A PCI bridge is any PCI devices that maps PCI resources
                // (memory or I/O) from one side of the device to the other
                constexpr uint8_t bridge_device                                       = 0x06;
                // all types of simple communication controllers
                constexpr uint8_t simple_communication_controllers                    = 0x07;
                // all types of generic system peripherals
                constexpr uint8_t base_system_peripherals                             = 0x08;
                // all types of input devices
                constexpr uint8_t input_devices                                       = 0x09;
                // all types of docking stations
                constexpr uint8_t docking_stations                                    = 0x0a;
                // all types of processors
                constexpr uint8_t processors                                          = 0x0b;
                // all types of serial bus controllers
                constexpr uint8_t serial_bus_controllers                              = 0x0c;
                // all wireless controllers
                constexpr uint8_t wireless_controller                                 = 0x0d;
                // intelligent I/O controllers
                constexpr uint8_t intelligent_io_controllers                          = 0x0e;
                // sattelite communication controllers
                constexpr uint8_t satellite_communication_controllers                 = 0x0f;
                // encryption and decription controllers
                constexpr uint8_t encryption_decription_controllers                   = 0x10;
                // all types of data acquisition and signal processing controllers
                constexpr uint8_t data_acquisition_and_signal_processing_controllers  = 0x11;
                // processing accelerators
                constexpr uint8_t processing_accelarators                             = 0x12;
                // for Functions that provide component/platform instrumentations
                // capabilities not essential to normal run-time operations
                constexpr uint8_t non_essential_instrumentation                       = 0x13;
                // 0x14 - 0xfe - reserved
                constexpr uint8_t does_not_fit_in_any_classes                         = 0xff;
            };

            namespace unclassified_subclass 
            {
                constexpr uint8_t non_vga_compatible                                  = 0x00;
                constexpr uint8_t vga_compatible                                      = 0x01;
            };

            namespace  display_controller_subclass
            {
                constexpr uint8_t vga_compatible = 0x00;
                constexpr uint8_t xga_controller = 0x01;
                constexpr uint8_t non_vga = 0x02;
                constexpr uint8_t other = 0x80;
            }

        }

        enum BARType
        {
            MemoryMapping = 0,
            InputOutput = 1

        };
        // Base Address Register (BAR)
        // - can be used to hold memory addresses used by the device 
        // - typycally, memory address BARs need to be located in physical ram while I/O space BARs can
        //   reside at any memory address

        class BAR
        {
        public:
            bool prefetchable;
            uint8_t* address;
            uint32_t size;
            BARType type;
        };

        class PCIDeviceDescriptor
        {
        public:
            uint32_t portBase;
            uint32_t interrupt;
            
            uint16_t bus;
            uint16_t device;
            uint16_t function;

            uint16_t vendor_id;
            uint16_t device_id;
            
            uint8_t class_id;
            uint8_t subclass_id;
            uint8_t interface_id;

            uint8_t revision;
            
            PCIDeviceDescriptor();
            ~PCIDeviceDescriptor();

        };

        class PCI
        {
            Port32Bit dataPort;
            Port32Bit commandPort;
        public:
            PCI();
            ~PCI();

            uint32_t Read(uint16_t bus, uint16_t device, uint16_t function, uint32_t registerOffset);
            void Write(uint16_t bus, uint16_t device, uint16_t function, uint32_t registerOffset, uint32_t value);
            bool DeviceHasFunctions(uint16_t bus, uint16_t device);
            void SelectDrivers(DriverManager* manager, InterruptManager* interrupts);
            PCIDeviceDescriptor GetDeviceDescriptor(uint16_t bus, uint16_t device, uint16_t function);
            BAR GetBAR(uint16_t bus, uint16_t device, uint16_t function, uint16_t bar);
            Driver* GetDriver(PCIDeviceDescriptor dev, InterruptManager* interrupts);
        };
    }
}