#pragma once

#include <common/types.h>
#include <drivers/driver.h>
#include <hardware/interrupts.h>
#include <hardware/port.h>

namespace x86_OS
{
    namespace drivers
    {
        using namespace common;

        class KeyboardEventHandler;
        class KeyboardDriver : public hardware::InterruptHandler, public Driver
        {
            hardware::Port8Bit dataPort;
            hardware::Port8Bit commandPort;

            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(hardware::InterruptManager* manager, KeyboardEventHandler* handler);
            ~KeyboardDriver();

            virtual uint32_t HandleInterrupt(uint32_t esp);
            virtual void Activate();
        };

        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();

            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };

        class PrintKeyboardEventHandler : public KeyboardEventHandler
        {
        public:
            PrintKeyboardEventHandler();
            void OnKeyDown(char);
            void OnKeyUp(char);
        };

    }
}

