#ifndef CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H
#define CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H

#include <string>
#include <vector>

namespace ArbitraryPrecision
{
    /// @brief Add one to the number represented by the vector.
    /// @param v given number vector
    /// @return result vector
    auto PlusOne(std::vector<int> v) -> std::vector<int>;

    /// @brief Add two numbers represented by strings.
    /// @param str1 number string 1
    /// @param str2 number string 2
    /// @return addition result vector
    auto StringAddition(const std::string& str1, const std::string& str2) -> std::vector<int>;

    /// @brief Multiply two numbers represented by vectors.
    /// @param num1 number vector 1
    /// @param num2 number vector 2
    /// @return multiplication result vector
    auto Multiply(std::vector<int>& num1, std::vector<int>& num2) -> std::vector<int>;
}

#endif
