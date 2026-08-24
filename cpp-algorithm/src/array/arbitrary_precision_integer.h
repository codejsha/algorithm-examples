#ifndef CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H
#define CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H

#include <algorithm>
#include <string>
#include <vector>

namespace ArbitraryPrecision
{
    /**
     * \brief Adds one to a decimal number stored as a vector of digits.
     * \param num_arr A decimal digit array in big-endian order.
     * \return A new vector containing the incremented value.
     */
    std::vector<int> PlusOne(
        std::vector<int> num_arr);

    /**
     * \brief Adds two binary strings and returns the digit vector of the sum.
     * \param num_str1 A binary string.
     * \param num_str2 A binary string.
     * \return A vector of digits representing the sum in the same binary-digit style used by the implementation.
     */
    std::vector<int> StringAddition(
        const std::string& num_str1,
        const std::string& num_str2);

    /**
     * \brief Multiplies two signed decimal numbers stored as digit vectors.
     * \param num_arr1 A decimal digit array.
     * \param num_arr2 A decimal digit array.
     * \return A vector containing the product, with the leading zero digits removed.
     */
    std::vector<int> Multiply(
        std::vector<int>& num_arr1,
        std::vector<int>& num_arr2);
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::PlusOne(
    std::vector<int> num_arr)
{
    ++num_arr.back(); // Increment the least significant digit
    const int arr_size = static_cast<int>(num_arr.size());

    // Handle carry for digits that become 10
    for (int i = arr_size - 1; i > 0 && num_arr[i] == 10; --i)
    {
        num_arr[i] = 0;
        ++num_arr[i - 1];
    }

    // If the most significant digit becomes 10, we need to add a new digit at the front
    if (num_arr[0] == 10)
    {
        num_arr[0] = 1;
        num_arr.emplace_back(0);
    }

    return num_arr;
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::StringAddition(
    const std::string& num_str1,
    const std::string& num_str2)
{
    const int size1 = static_cast<int>(num_str1.size());
    const int size2 = static_cast<int>(num_str2.size());

    const int larger = size1 >= size2 ? size1 : size2;
    auto sum_arr = std::vector<int>(larger);

    // Initialize sum_arr with the first number's digits
    for (int i = size1 - 1; i >= 0; --i)
    {
        sum_arr[i] += num_str1.at(i) == '1' ? 1 : 0;
    }

    // Add the second number's digits and handle carry
    int carry = 0;
    for (int i = size2 - 1; i >= 0; --i)
    {
        sum_arr[i] += carry;
        sum_arr[i] += num_str2.at(i) == '1' ? 1 : 0;

        if (sum_arr[i] >= 2)
        {
            sum_arr[i] -= 2;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    // If there's still a carry after processing all digits,
    // we need to add a new digit at the front
    if (carry == 1)
    {
        sum_arr.emplace_back(1);
    }

    return sum_arr;
}

// ----------------------------------------------------------------------------
inline std::vector<int> ArbitraryPrecision::Multiply(
    std::vector<int>& num_arr1,
    std::vector<int>& num_arr2)
{
    const int sign = ((num_arr1.front() < 0) ^ (num_arr2.front() < 0)) ? -1 : 1;
    num_arr1.front() = std::abs(num_arr1.front());
    num_arr2.front() = std::abs(num_arr2.front());

    int size1 = static_cast<int>(num_arr1.size());
    int size2 = static_cast<int>(num_arr2.size());

    std::vector<int> result(size1 + size2, 0);
    for (int i = size1 - 1; i >= 0; --i)
    {
        for (int j = size2 - 1; j >= 0; --j)
        {
            result[i + j + 1] += num_arr1[i] * num_arr2[j]; // Multiply the digits and add to the corresponding position
            result[i + j] += result[i + j + 1] / 10;        // Handle carry to the next position
            result[i + j + 1] %= 10;                        // Keep only the last digit in the current position
        }
    }

    // Remove leading zeros from the result
    result = {
        std::ranges::find_if_not(
            begin(result),
            end(result),
            [](const int i) { return i == 0; }),
        end(result)};

    // If the result is empty, it means the product is zero
    if (std::empty(result))
    {
        return {0};
    }

    result.front() *= sign;
    return result;
}

#endif
