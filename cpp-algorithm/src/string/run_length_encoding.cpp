#include "run_length_encoding.h"

auto RunLengthEncoding::RunLengthEncoding(const std::string& str) -> std::string
{
    int count = 0;
    std::string result;

    for (int i = 0; i < static_cast<int>(str.size()); ++i)
    {
        ++count;

        if (i + 1 == static_cast<int>(str.size()) || str[i] != str[i + 1])
        {
            result += std::to_string(count) + str[i];
            count = 0;
        }
    }

    return result;
}

auto RunLengthEncoding::RunLengthDecoding(const std::string& str) -> std::string
{
    int count = 0;
    std::string result;

    for (const char& c : str)
    {
        if (std::isdigit(c))
        {
            count = c - '0';
        }
        else
        {
            result.append(count, c);
        }
    }

    return result;
}
