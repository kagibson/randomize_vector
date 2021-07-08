add_executable(randomize_vector main.cpp galois_lfsr_rand_32.cpp vector_randomizer.cpp)
set_target_properties(randomize_vector
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)