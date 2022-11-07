#include "permutation.h"

#include <gtest/gtest.h>

TEST(PermutationTest, Simple)
{
    const auto str = "abc";

    Permutation::Permutation(str, "");
    // result:
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
}
