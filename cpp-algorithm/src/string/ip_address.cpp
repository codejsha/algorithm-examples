#include "ip_address.h"

#include <format>

bool IsValidPart(const std::string& str)
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

std::vector<std::string> IpAddress::GetValidIpAddress(const std::string& str)
{
    auto result = std::vector<std::string>{};
    for (auto i = 1; i < 4 && i < static_cast<int>(str.size()); ++i)
    {
        for (auto j = 1; j < 4 && i + j < static_cast<int>(str.size()); ++j)
        {
            for (auto k = 1; k < 4 && i + j + k < static_cast<int>(str.size()); ++k)
            {
                const auto first = str.substr(0, i);
                const auto second = str.substr(i, j);
                const auto third = str.substr(i + j, k);
                const auto fourth = str.substr(i + j + k);
                if (IsValidPart(first) && IsValidPart(second) && IsValidPart(third) && IsValidPart(fourth))
                {
                    result.push_back(std::format("{}.{}.{}.{}",
                        first, second, third, fourth));
                }
            }
        }
    }
    return result;
}
