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

        class MouseEventHandler;
        class MouseDriver : public hardware::InterruptHandler, public Driver
        {
            hardware::Port8Bit dataPort;
            hardware::Port8Bit commandPort;

            /*
            * in communication with a mouse when something happens
            * (if you move, press button) you get 3 different bytes 
            */
            uint8_t buffer[3];
            uint8_t offset;
            uint8_t buttons;
            MouseEventHandler* handler;
        public:
            MouseDriver(hardware::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();

            virtual uint32_t HandleInterrupt(uint32_t esp);

            virtual void Activate();

        };

        class MouseEventHandler
        {
        protected:
            int8_t x = 0;
            int8_t y = 0;
        public:
            MouseEventHandler();

            virtual void OnActivate();

            virtual void OnMouseDown(uint8_t button);
            virtual void OnMouseUp(uint8_t button);
            virtual void OnMouseMove(int xoffset, int yoffset);
        };


        class MouseToConsole : public MouseEventHandler
        {
        public:
            MouseToConsole() {}
            void OnMouseDown(uint8_t button);
            void OnMouseMove(int xoffset, int yoffset);
        };

    }
}
