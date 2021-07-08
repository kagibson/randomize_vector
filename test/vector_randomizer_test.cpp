#include <iostream>
#include <vector>
#include <cstdint>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "vector_randomizer.hpp"
#include "mock_galois_lsfr_rand_32.hpp"

using std::vector;
using std::unique_ptr;
using std::move;
using testing::Return;

TEST(vector_randomizer_test, test_swap)
{
    MockGaloisLSFRRand32 *rand_gen_ptr (new MockGaloisLSFRRand32(0x01));
    unique_ptr<MockGaloisLSFRRand32> rand_gen (rand_gen_ptr);
    vector<uint32_t> vec = {0, 1, 2, 3, 4};
    VectorRandomizer randomizer(move(rand_gen), vec);

    EXPECT_CALL(*rand_gen_ptr, rand())
      .Times(4)
      .WillOnce(Return(125)) /* 0 when mod by 5, swap 4 and 0 */
      .WillOnce(Return(401)) /* 1 when mod by 4, swap 3 and 1 */
      .WillOnce(Return(5)) /* 2 when mod by 3, swap 2 and 2 */
      .WillOnce(Return(32000)) /* 0 when mod by 2, swap 1 and 0 */
      ;

    vector<uint32_t>random_vec = randomizer.randomize();
    vector<uint32_t>test_vec = {3, 4, 2, 1, 0};
    ASSERT_EQ(random_vec, test_vec);
}
