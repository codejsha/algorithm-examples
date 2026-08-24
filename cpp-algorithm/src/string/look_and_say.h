#ifndef CPP_ALGORITHM_LOOK_AND_SAY_H
#define CPP_ALGORITHM_LOOK_AND_SAY_H

#include <string>

namespace LookAndSay
{
    /**
     * \brief Look and say problem.
     * \param input input string
     * \return result string
     */
    std::string LookAndSayProblem(const std::string& input);
}

// ----------------------------------------------------------------------------
inline std::string LookAndSay::LookAndSayProblem(const std::string& input)
{
    std::string result;
    for (int i = 0; i < static_cast<int>(input.size()); ++i)
    {
        int count = 1;
        while (i + 1 < static_cast<int>(input.size()) && input[i] == input[i + 1])
        {
            ++count;
            ++i;
        }
        result += std::to_string(count) + input[i];
    }
    return result;
}

#endif
