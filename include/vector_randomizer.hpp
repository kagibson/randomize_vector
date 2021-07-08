#ifndef VECTOR_RANDOMIZER_HPP
#define VECTOR_RANDOMIZER_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include "galois_lfsr_rand_32.hpp"

using std::vector;
using std::unique_ptr;

/**
 * @brief Class that takes in an arbitrarily-sized vector of integers and randomizes
 * the order.
 * 
 */
class VectorRandomizer
{
    public:
        /**
         * @brief Constructs a new VectorRandomizer object. 
         * 
         * @param rand_gen - 32-bit psuedo-random integer generator used for randomizing
         * the vector order.
         * @param vec - Initial vector of integers. Can be any size.
         */
        VectorRandomizer(unique_ptr<GaloisLFSRRand32> rand_gen, vector<uint32_t> &vec);

        /**
         * @brief Returns a new vector of integers that is the same as the original
         * but with the integers in a random order.
         * 
         * @return vector<int> - randomized vector.
         */
        vector<uint32_t> randomize();
    private:
        vector<uint32_t> vec_;
        unique_ptr<GaloisLFSRRand32> rand_gen_;

};
#endif