#include "miller_rabin.h"

#include <gtest/gtest.h>

GTEST_TEST(MillerRabinTest, MillerRabinPrimalityTest)
{
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(2, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(3, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(5, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(7, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(11, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(13, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(17, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(19, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(23, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(29, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(31, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(37, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(41, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(43, 4));
    ASSERT_TRUE(MillerRabin::MillerRabinPrimalityTest(47, 4));

    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(4, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(6, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(8, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(9, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(10, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(12, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(14, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(15, 4));
    ASSERT_FALSE(MillerRabin::MillerRabinPrimalityTest(16, 4));
}
