#include "replace_element.h"

#include <gtest/gtest.h>

GTEST_TEST(ReplaceStringTest, ReplaceAndRemoveString1)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    const auto expected = std::vector<std::string>{"d", "d", "c", "d", "c", "d", "d"};
    const auto result = ReplaceElement::ReplaceAndRemoveString1(arr, "a", "b");
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ReplaceStringTest, ReplaceAndRemoveString2)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    const auto expected = std::vector<std::string>{"d", "d", "c", "d", "c", "d", "d"};
    const auto result = ReplaceElement::ReplaceAndRemoveString2(arr, "a", "b");
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ReplaceStringTest, TelexEncoding)
{
    auto arr_dot = std::vector<std::string>{"."};
    auto expected_dot = std::vector<std::string>{"D", "O", "T"};
    auto result_dot = ReplaceElement::TelexEncoding(arr_dot);
    EXPECT_EQ(expected_dot, result_dot);

    auto arr_comma = std::vector<std::string>{","};
    auto expected_comma = std::vector<std::string>{"C", "O", "M", "M", "A"};
    auto result_comma = ReplaceElement::TelexEncoding(arr_comma);
    EXPECT_EQ(expected_comma, result_comma);

    auto arr_question = std::vector<std::string>{"?"};
    auto expected_question = std::vector<std::string>{"Q", "U", "E", "S", "T", "I", "O", "N", "_", "M", "A", "R", "K"};
    auto result_question = ReplaceElement::TelexEncoding(arr_question);
    EXPECT_EQ(expected_question, result_question);

    auto arr_exclamation = std::vector<std::string>{"!"};
    auto expected_exclamation = std::vector<std::string>{"E", "X", "C", "L", "A", "M", "A", "T", "I", "O", "N", "_", "M", "A", "R", "K"};
    auto result_exclamation = ReplaceElement::TelexEncoding(arr_exclamation);
    EXPECT_EQ(expected_exclamation, result_exclamation);
}
