#include "print_string.h"

#include <iostream>

std::string PrintString::SineWaveString(const std::string& str)
{
    auto result = std::string{};
    for (auto i = 1; i < static_cast<int>(str.size()); i += 4)
    {
        result += str[i];
    }
    for (auto i = 0; i < static_cast<int>(str.size()); i += 2)
    {
        result += str[i];
    }
    for (auto i = 3; i < static_cast<int>(str.size()); i += 4)
    {
        result += str[i];
    }

    return result;
}

void PrintString::PrintSineWaveString(const std::string& str)
{
    for (auto i = 1; i < static_cast<int>(str.size()); i += 4)
    {
        if (i == 1)
        {
            std::cout << std::string(2, ' ') << str[i];
        }
        else
        {
            std::cout << std::string(7, ' ') << str[i];
        }
    }
    std::cout << std::endl;
    for (auto i = 0; i < static_cast<int>(str.size()); i += 2)
    {
        if (i == 0)
        {
            std::cout << str[i];
        }
        else
        {
            std::cout << std::string(3, ' ') << str[i];
        }
    }
    std::cout << std::endl;
    for (auto i = 3; i < static_cast<int>(str.size()); i += 4)
    {
        if (i == 3)
        {
            std::cout << std::string(6, ' ') << str[i];
        }
        else
        {
            std::cout << std::string(7, ' ') << str[i];
        }
    }
    std::cout << std::endl;
}
