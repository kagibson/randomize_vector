#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include "vector_randomizer.hpp"

using std::vector;
using std::iter_swap;
using std::unique_ptr;
using std::move;

VectorRandomizer::VectorRandomizer(unique_ptr<GaloisLFSRRand32> rand_gen, vector<uint32_t> &vec)
{
    vec_ = vec;
    rand_gen_ = move(rand_gen);
};

/*
Naive solution, N^2 possible outcomes

vector<uint32_t> VectorRandomizer::randomize()
{
    vector<uint32_t> randomized_vec = vec_;

    size_t vec_size = randomized_vec.size();

    for (int i=0; i < vec_size; i++)
    {
        int rand_index = rand_gen_.rand() % vec_size;
        int tmp = randomized_vec[i];
        randomized_vec[i] = randomized_vec[rand_index];
        randomized_vec[rand_index] = tmp; 
    }

    return randomized_vec;
}
*/

/*
More optimal solution, N! equally-likely outcomes. O(N) time.
*/
vector<uint32_t> VectorRandomizer::randomize()
{
    vector<uint32_t> randomized_vec = vec_;

    size_t vec_size = randomized_vec.size();

    for (uint32_t i_=vec_size-1; i_ > 0; i_--)
    {
        uint32_t rand_index = rand_gen_->rand() % (i_ + 1); /* Not exactly equally likely if 
                                                 2^32 not divisible by i_ + 1 */
        std::iter_swap(randomized_vec.begin() + rand_index, randomized_vec.begin() + i_);
    }

    return randomized_vec;
}

