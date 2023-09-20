#include "arbitrary_precision_integer.h"

#include <algorithm>

auto ArbitraryPrecision::PlusOne(std::vector<int> number_array) -> std::vector<int>
{
    ++number_array.back();

    for (auto i = static_cast<int>(number_array.size()) - 1; i > 0 && number_array[i] == 10; --i)
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

auto ArbitraryPrecision::StringAddition(const std::string& number_string1, const std::string& number_string2) -> std::vector<int>
{
    const auto size1 = static_cast<int>(number_string1.size());
    const auto size2 = static_cast<int>(number_string2.size());

    const auto larger = size1 >= size2 ? size1 : size2;
    auto sum = std::vector<int>(larger);

    for (auto i = size1 - 1; i >= 0; --i)
    {
        sum[i] += number_string1.at(i) == '1' ? 1 : 0;
    }

    auto carry = 0;
    for (auto i = size2 - 1; i >= 0; --i)
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

auto ArbitraryPrecision::Multiply(std::vector<int>& number_array1, std::vector<int>& number_array2) -> std::vector<int>
{
    const auto sign = ((number_array1.front() < 0) ^ (number_array2.front() < 0)) ? -1 : 1;
    number_array1.front() = std::abs(number_array1.front());
    number_array2.front() = std::abs(number_array2.front());

    std::vector<int> result(number_array1.size() + number_array2.size(), 0);
    for (auto i = static_cast<int>(number_array1.size()) - 1; i >= 0; --i)
    {
        for (auto j = static_cast<int>(number_array2.size()) - 1; j >= 0; --j)
        {
            result[i + j + 1] += number_array1[i] * number_array2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    result = {std::ranges::find_if_not(begin(result), end(result), [](const int i) { return i == 0; }), end(result)};

    if (std::empty(result))
    {
        return {0};
    }

    result.front() *= sign;
    return result;
}
