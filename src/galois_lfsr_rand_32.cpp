#include <iostream>
#include "galois_lfsr_rand_32.hpp"
#include <cstdint>

GaloisLFSRRand32::GaloisLFSRRand32(uint32_t seed) : state_(seed) {}

GaloisLFSRRand32::~GaloisLFSRRand32() {}

void GaloisLFSRRand32::step()
{
    bool y_ = y_mask_ & state_;
    state_ <<= 1;
    if (y_)
    {
        state_ ^= taps_;
    }
}

uint32_t GaloisLFSRRand32::rand()
{
    step();
    return state_;
}