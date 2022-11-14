#include "arbitrary_precision_integer.h"

#include <bitset>
#include <ranges>

std::vector<int> ArbitraryPrecision::PlusOne(std::vector<int> v)
{
    ++v.back();

    for (int i = static_cast<int>(v.size()) - 1; i > 0 && v[i] == 10; --i)
    {
        v[i] = 0;
        ++v[i - 1];
    }

    if (v[0] == 10)
    {
        v[0] = 1;
        v.emplace_back(0);
    }
    return v;
}

std::vector<int> ArbitraryPrecision::StringAddition(const std::string& str1, const std::string& str2)
{
    const auto size1 = static_cast<int>(str1.size());
    const auto size2 = static_cast<int>(str2.size());

    const auto larger = size1 >= size2 ? size1 : size2;
    auto sum = std::vector<int>(larger);

    for (int i = size1 - 1; i >= 0; --i)
    {
        sum[i] += str1.at(i) == '1' ? 1 : 0;
    }

    auto carry = 0;
    for (int i = size2 - 1; i >= 0; --i)
    {
        sum[i] += carry;
        sum[i] += str2.at(i) == '1' ? 1 : 0;

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

std::vector<int> ArbitraryPrecision::Multiply(std::vector<int>& num1, std::vector<int>& num2)
{
    const int sign = ((num1.front() < 0) ^ (num2.front() < 0)) ? -1 : 1;
    num1.front() = std::abs(num1.front());
    num2.front() = std::abs(num2.front());

    std::vector<int> result(num1.size() + num2.size(), 0);
    for (int i = static_cast<int>(num1.size()) - 1; i >= 0; --i)
    {
        for (int j = static_cast<int>(num2.size()) - 1; j >= 0; --j)
        {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    result = {
        std::ranges::find_if_not(begin(result), end(result), [](int i)
            { return i == 0; }),
        end(result)};

    if (std::empty(result))
    {
        return {0};
    }

    result.front() *= sign;
    return result;
}
