#include "gtest/gtest.h"
#include "binary_operations.hpp"

TEST(invert_bits, intertbit)
{
   auto res = bopr::invertbit(0xFF125B89, 7);
   EXPECT_EQ(0xFF125B09, res);

   res = bopr::invertbit(0xFF125B09, 13);
   EXPECT_EQ(0xFF127B09, res);
}

TEST(invert_bits, invertbits)
{
   auto res = bopr::invertbits(0xFF125B89, 20, 4);
   EXPECT_EQ(0xFF0C5B89, res);

   res = bopr::invertbits(0xFF127B09, 21, 8);
   EXPECT_EQ(0xFF2DBB09, res);
}
