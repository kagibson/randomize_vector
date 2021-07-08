#ifndef GALOIS_LFSR_RAND_32_HPP
#define GALOIS_LFSR_RAND_32_HPP

#include <cstdint>

/**
 * @brief Psuedo-random number generator based on an implementation of a maximal-length 32-bit 
 * Galois linear feedback shift register. The seed of the generator is used as the initial state
 * of the LFSR. The taps chosen are bits 30, 26, 25 and 0.
 * 
 */
class GaloisLFSRRand32
{

    public:
        GaloisLFSRRand32(){};
        /**
         * @brief Construct a new Galois LSFR 32-bit psuedo-random generator.
         * 
         * @param seed - Used to set the initial state of the LSFR.
         */
        GaloisLFSRRand32(uint32_t seed);

        virtual ~GaloisLFSRRand32();
    
        /**
         * @brief Returns a psuedo-random unsigned 32-bit integer.
         * 
         * @returns psuedo-random 32-bit integer.
         */
        virtual uint32_t rand();

    protected:
        uint32_t state_;
        uint32_t taps_ = 0x46000001; /* Bits 30, 26, 25, and 0 for maximal length LSFR */
        uint32_t y_mask_ = 0x80000000; /* Bit 31 is output */

        /**
         * @brief Steps the LSFR. Equivalent to a clock pulse.
         * 
         */
        void step();

};

#endif