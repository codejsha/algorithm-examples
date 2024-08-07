#include "ip_address.h"

auto IsValidPart(const std::string& str) -> bool
{
    if (str.empty() || str.size() > 3)
    {
        return false;
    }

    if (str.size() > 1 && str[0] == '0')
    {
        return false;
    }

    const int value = std::stoi(str);
    return value >= 0 && value <= 255;
}

#if defined(_MSC_VER)
#include <format>

auto IpAddress::GetValidIpAddress(const std::string& str) -> std::vector<std::string>
{
    std::vector<std::string> result;
    for (int i = 1; i < 4 && i < static_cast<int>(str.size()); ++i)
    {
        for (int j = 1; j < 4 && i + j < static_cast<int>(str.size()); ++j)
        {
            for (int k = 1; k < 4 && i + j + k < static_cast<int>(str.size()); ++k)
            {
                const std::string first = str.substr(0, i);
                const std::string second = str.substr(i, j);
                const std::string third = str.substr(i + j, k);
                const std::string fourth = str.substr(i + j + k);
                if (IsValidPart(first) && IsValidPart(second) && IsValidPart(third) && IsValidPart(fourth))
                {
                    result.push_back(std::format("{}.{}.{}.{}", first, second, third, fourth));
                }
            }
        }
    }
    return result;
}

#elif defined(__GNUG__)
#include <fmt/format.h>

auto IpAddress::GetValidIpAddress(const std::string& str) -> std::vector<std::string>
{
    std::vector<std::string> result;
    for (int i = 1; i < 4 && i < static_cast<int>(str.size()); ++i)
    {
        for (int j = 1; j < 4 && i + j < static_cast<int>(str.size()); ++j)
        {
            for (int k = 1; k < 4 && i + j + k < static_cast<int>(str.size()); ++k)
            {
                const std::string first = str.substr(0, i);
                const std::string second = str.substr(i, j);
                const std::string third = str.substr(i + j, k);
                const std::string fourth = str.substr(i + j + k);
                if (IsValidPart(first) && IsValidPart(second) && IsValidPart(third) && IsValidPart(fourth))
                {
                    result.push_back(fmt::format("{}.{}.{}.{}", first, second, third, fourth));
                }
            }
        }
    }
    return result;
}

#else

#endif
