#ifndef CPP_ALGORITHM_CHECK_PAIR_OF_BRACKET_H
#define CPP_ALGORITHM_CHECK_PAIR_OF_BRACKET_H

#include <stack>
#include <string>
#include <unordered_map>

namespace PairOfBracket
{
    /**
     * \brief Checks if the input string contains bracket pairs and is well-formed.
     * \param input The input string.
     * \return True if the input string contains a pair of bracket, false otherwise.
     */
    bool CheckPairOfBracket(const std::string& input);
}

// ----------------------------------------------------------------------------
inline bool PairOfBracket::CheckPairOfBracket(const std::string& input)
{
    std::stack<char> stack;
    const std::unordered_map<char, char> bracket_pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (char ch : input)
    {
        if (!bracket_pairs.contains(ch))
        {
            stack.push(ch);
        }
        else
        {
            if (stack.empty() || stack.top() != bracket_pairs.at(ch))
            {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

#endif
