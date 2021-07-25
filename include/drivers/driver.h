#pragma once

namespace x86_OS
{
    namespace drivers
    {
        class Driver
        {
        public:
            Driver();
            ~Driver();

            virtual void Activate();
            virtual int Reset();
            virtual void Deactivate();
        };

        class DriverManager
        {
        private:
            Driver* drivers[256];
            int numDrivers;
        public:
            void AddDriver(Driver* driver);
            void ActivateAll();
        };
    }
}
