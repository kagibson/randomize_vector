#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "vector_randomizer.hpp"
#include "galois_lfsr_rand_32.hpp"

using std::vector;
using std::cout;
using std::cerr;
using std::stoi;
using std::move;

void print_usage(void)
{
    cerr << "Usage: ./randomize_vector 2 3 4 1\n";
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage();
        exit(EXIT_FAILURE);
    }

    /* Get vector from command line args */
    vector<uint32_t> input_vector;
    for (int i=1; i < argc; i++)
    {   
        try
        {
            input_vector.push_back(stoi(argv[i]));
        }
        catch(const std::invalid_argument& e)
        {
            cerr << "Command line argument is wrong type.\n";
            print_usage();
            exit(EXIT_FAILURE);
        }
        catch(const std::out_of_range& e)
        {
            cerr << "Command line argument is out of range.\n";
            print_usage();
            exit(EXIT_FAILURE);
        }
    }

    /* Create Galois LSFR psuedo-random 32-bit number generator
       and seed using system time */
    time_t seed = time(NULL);
    if (seed == -1)
    {
        printf("Error getting system time.");
        exit(EXIT_FAILURE);
    }
    unique_ptr <GaloisLFSRRand32> rand_gen (new GaloisLFSRRand32(seed));

    /* Create array randomizer class with vector */
    VectorRandomizer vector_rand(move(rand_gen), input_vector);
    
    /* Print out 10 iterations */
    for (int i_=0; i_ < 10; i_++)
    {
        vector<uint32_t> randomized_vector = vector_rand.randomize();
        for (auto j_ = randomized_vector.begin(); j_ != randomized_vector.end(); j_++)
        {
            cout << *j_ << ' ';
        }
        cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}