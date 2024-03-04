#include "run_length_encoding.h"

auto RunLengthEncoding::RunLengthEncoding(const std::string& str) -> std::string
{
    auto count = 0;
    auto result = std::string{};

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
    auto count = 0;
    auto result = std::string{};

    for (const auto& c : str)
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
