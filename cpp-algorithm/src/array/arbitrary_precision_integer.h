#ifndef CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H
#define CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H

#include <algorithm>
#include <string>
#include <vector>

namespace ArbitraryPrecision
{
    /**
     * \brief Add one to the number represented by the array.
     * \param number_array given number array
     * \return result array
     */
    std::vector<int> PlusOne(
        std::vector<int> number_array);

    /**
     * \brief Add two numbers represented by strings.
     * \param number_string1 number string 1
     * \param number_string2 number string 2
     * \return result array
     */
    std::vector<int> StringAddition(
        const std::string& number_string1,
        const std::string& number_string2);

    /**
     * \brief Multiply two numbers represented by array.
     * \param number_array1 number array 1
     * \param number_array2 number array 2
     * \return result array
     */
    std::vector<int> Multiply(
        std::vector<int>& number_array1,
        std::vector<int>& number_array2);
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::PlusOne(
    std::vector<int> number_array)
{
    ++number_array.back();

    for (int i = static_cast<int>(number_array.size()) - 1; i > 0 && number_array[i] == 10; --i)
    {
        number_array[i] = 0;
        ++number_array[i - 1];
    }

    if (number_array[0] == 10)
    {
        number_array[0] = 1;
        number_array.emplace_back(0);
    }
    return number_array;
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::StringAddition(
    const std::string& number_string1,
    const std::string& number_string2)
{
    const int size1 = static_cast<int>(number_string1.size());
    const int size2 = static_cast<int>(number_string2.size());

    const int larger = size1 >= size2 ? size1 : size2;
    auto sum = std::vector<int>(larger);

    for (int i = size1 - 1; i >= 0; --i)
    {
        sum[i] += number_string1.at(i) == '1' ? 1 : 0;
    }

    int carry = 0;
    for (int i = size2 - 1; i >= 0; --i)
    {
        sum[i] += carry;
        sum[i] += number_string2.at(i) == '1' ? 1 : 0;

        if (sum[i] >= 2)
        {
            sum[i] -= 2;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    if (carry == 1)
    {
        sum.emplace_back(1);
    }

    return sum;
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::Multiply(
    std::vector<int>& number_array1,
    std::vector<int>& number_array2)
{
    const int sign = ((number_array1.front() < 0) ^ (number_array2.front() < 0)) ? -1 : 1;
    number_array1.front() = std::abs(number_array1.front());
    number_array2.front() = std::abs(number_array2.front());

    std::vector<int> result(number_array1.size() + number_array2.size(), 0);
    for (int i = static_cast<int>(number_array1.size()) - 1; i >= 0; --i)
    {
        for (int j = static_cast<int>(number_array2.size()) - 1; j >= 0; --j)
        {
            result[i + j + 1] += number_array1[i] * number_array2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    result = {std::ranges::find_if_not(begin(result), end(result), [](const int i) { return i == 0; }),
              end(result)};

    if (std::empty(result))
    {
        return {0};
    }

    result.front() *= sign;
    return result;
}

#endif
