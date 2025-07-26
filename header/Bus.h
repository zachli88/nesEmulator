#include <cstdint>
#include "olc6502.h"

class Bus {
    public:
        Bus();
        ~Bus();

    public: // devices
        olc6502 cpu;
        std::array<uint8_t, 64*1024> ram;

        
    public: // read and write from bus
        void write(uint16_t addr, uint8_t data);
        uint8_t read(uint16_t addr, bool bReadOnly = false);
};

