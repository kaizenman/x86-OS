#pragma once

#include <common/types.h>

namespace x86_OS
{
    namespace hardware
    {
        using namespace common;
        class Port
        {
        protected:
            Port(uint16_t portnumber) : portnumber(portnumber) {}
            ~Port() = default;
            uint16_t portnumber;
        };


        class Port8Bit : public Port
        {
        public:
            Port8Bit(uint16_t portnumber) : Port(portnumber) {}
            ~Port8Bit() = default;

            // @todo: if we want to use virtual functions, we need to support virtual destructors
            virtual void Write(uint8_t data);
            uint8_t Read();
        };

        class Port8BitSlow : public Port8Bit
        {
        public:
            Port8BitSlow(uint16_t portnumber) : Port8Bit(portnumber) {}
            ~Port8BitSlow() = default;

            virtual void Write(uint8_t data);
        };

        class Port16Bit : public Port
        {
        public:
            Port16Bit(uint16_t portnumber) : Port(portnumber) {}
            ~Port16Bit() = default;

            virtual void Write(uint16_t data);
            uint16_t Read();
        };

        class Port32Bit : public Port
        {
        public:
            Port32Bit(uint16_t portnumber) : Port(portnumber) {}
            ~Port32Bit() = default;

            virtual void Write(uint32_t data);
            uint32_t Read();
        };
    }
}

