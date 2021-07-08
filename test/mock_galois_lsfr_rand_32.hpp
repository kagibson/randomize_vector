#include "gmock/gmock.h"
#include <cstdint>
#include "galois_lfsr_rand_32.hpp"

class MockGaloisLSFRRand32: public GaloisLFSRRand32
{
    public:
        MockGaloisLSFRRand32(uint32_t seed) : GaloisLFSRRand32(seed){};
        MOCK_METHOD0(rand, uint32_t());
};