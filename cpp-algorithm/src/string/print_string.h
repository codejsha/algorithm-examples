#ifndef CPP_ALGORITHM_PRINT_STRING_H
#define CPP_ALGORITHM_PRINT_STRING_H

#include <iostream>
#include <string>

namespace PrintString
{
    /**
     * \brief Manipulate a string to sine wave pattern like snake style.
     * \param str the string to be manipulated.
     * \return result string
     */
    std::string SineWaveString(const std::string& str);

    /**
     * \brief Print a string in sine wave pattern like snake style.
     * \param str input string
     */
    void PrintSineWaveString(const std::string& str);
}

// ----------------------------------------------------------------------------
inline std::string PrintString::SineWaveString(const std::string& str)
{
    std::string result;
    for (int i = 1; i < static_cast<int>(str.size()); i += 4)
    {
        result += str[i];
    }
    for (int i = 0; i < static_cast<int>(str.size()); i += 2)
    {
        result += str[i];
    }
    for (int i = 3; i < static_cast<int>(str.size()); i += 4)
    {
        result += str[i];
    }

    return result;
}

// ----------------------------------------------------------------------------
inline void PrintString::PrintSineWaveString(const std::string& str)
{
    for (int i = 1; i < static_cast<int>(str.size()); i += 4)
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
    for (int i = 0; i < static_cast<int>(str.size()); i += 2)
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
    for (int i = 3; i < static_cast<int>(str.size()); i += 4)
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

#endif
