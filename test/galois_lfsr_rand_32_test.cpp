#include <iostream>
#include <vector>
#include <cstdint>
#include "gtest/gtest.h"
#include "galois_lfsr_rand_32.hpp"

using std::vector;

TEST(galois_lfsr_rand_32_test, shift_test)
{
    uint32_t seed = 0x1;
    GaloisLFSRRand32 rand_gen(seed);
    
    /* With seed of 0x1 and output bit not set,
    bit should continually shift until at MSB */
    for (uint32_t val=0x2; val<0x80000000; val <<= 1)
    {
        EXPECT_EQ(rand_gen.rand(), val);
    }
}

TEST(galois_lfsr_rand_32_test, feedback_test)
{
    uint32_t seed = 0x80000000;
    GaloisLFSRRand32 rand_gen(seed);
    
    /* Taps (bits 0, 25, 26 and 30) should be flipped 
    (XORed with output) */
    EXPECT_EQ(rand_gen.rand(), 0x46000001);

    /* Ones should be shifted into taps (bits 0, 25, 26, 30)
    and flipped (XORed with output) */
    seed = 0xA3000000;
    rand_gen = GaloisLFSRRand32(seed);

    EXPECT_EQ(rand_gen.rand(), 0x1);
}