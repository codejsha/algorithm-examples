#include "remove_first_name_duplicate.h"

#include <gtest/gtest.h>

GTEST_TEST(EliminateDuplicate, Successful1)
{
    std::vector<std::string> seq = {"John", "John", "John", "John", "John", "John", "John", "John", "John", "John"};
    const std::vector<std::string> expected = {"John"};
    RemoveFirstNameDuplicate::EliminateDuplicate(seq);
    EXPECT_EQ(expected.size(), seq.size());
    EXPECT_EQ(expected, seq);
}

GTEST_TEST(EliminateFirstNameDuplicate, Successful1)
{
    std::vector<std::string> seq = {"Ian Botham", "David Gower", "Ian Bell", "Ian Chappell"};
    const std::vector<std::string> expected = {"David Gower", "Ian Bell"};
    RemoveFirstNameDuplicate::EliminateFirstNameDuplicate(seq);
    EXPECT_EQ(expected.size(), seq.size());
    EXPECT_EQ(expected, seq);
}
