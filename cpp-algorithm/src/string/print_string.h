#ifndef CPP_ALGORITHM_PRINT_STRING_H
#define CPP_ALGORITHM_PRINT_STRING_H

#include <string>

namespace PrintString
{
    /// @brief Manipulate a string to sine wave pattern like snake style.
    /// @param str the string to be manipulated.
    /// @return result string
    std::string SineWaveString(const std::string& str);

    /// @brief Print a string in sine wave pattern like snake style.
    /// @param str input string
    void PrintSineWaveString(const std::string& str);
}

#endif
