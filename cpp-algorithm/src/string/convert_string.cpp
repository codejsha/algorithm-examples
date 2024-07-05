#include "convert_string.h"

auto ConvertString::IntToString(int number) -> std::string
{
    std::string str;
    bool is_negative = false;
    if (number < 0)
    {
        is_negative = true;
        number = -number;
    }

    do
    {
        str.push_back('0' + number % 10);
        number /= 10;
    } while (number > 0);

    if (is_negative)
    {
        str.push_back('-');
    }

    std::reverse(str.begin(), str.end());
    return str;
}

auto ConvertString::StringToInt(const std::string& str) -> int
{
    auto number = 0;
    for (char i : str)
    {
        number = (number * 10) + (i - '0');
    }
    return number;
}
