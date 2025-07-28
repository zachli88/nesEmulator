#pragma once
#include <cstdint>
#include "olc6502.h"
#include "olc2C02.h"
#include "Cartridge.h"

class Bus {
    public:
        Bus();
        ~Bus();

    public: // devices
        olc6502 cpu;
        olc2C02 ppu;
        std::array<uint8_t, 2048> cpuRam;
        std::shared_ptr<Cartridge> cart;

        
    public: // read and write from bus
        void cpuWrite(uint16_t addr, uint8_t data);
        uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

    public: // read and write from bus
        void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
        void reset();
        void clock();

    private:
        uint32_t nSystemClockCounter = 0;
};

