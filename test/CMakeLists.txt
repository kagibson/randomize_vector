# Create lib of galois_lfsr_rand_32 in order to test classs
add_library(galois_lfsr_rand_32_lib STATIC ${randomize_vector_SOURCE_DIR}/src/galois_lfsr_rand_32.cpp)

# Create lib of vector_randomizer in order to test class
add_library(vector_randomizer_lib STATIC ${randomize_vector_SOURCE_DIR}/src/vector_randomizer.cpp)

# Create test executable and link libraries
add_executable(galois_lfsr_rand_32_test galois_lfsr_rand_32_test.cpp)
add_test(NAME galois_lfsr_rand_32_test COMMAND galois_lfsr_rand_32_test)
target_link_libraries(galois_lfsr_rand_32_test gtest_main galois_lfsr_rand_32_lib)
add_executable(vector_randomizer_test vector_randomizer_test.cpp)
add_test(NAME vector_randomizer_test COMMAND vector_randomizer_test)
target_link_libraries(vector_randomizer_test gtest_main gmock_main vector_randomizer_lib galois_lfsr_rand_32_lib)