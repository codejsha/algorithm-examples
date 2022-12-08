#include "check_pair_of_bracket.h"

#include <stack>
#include <unordered_map>

auto PairOfBracket::CheckPairOfBracket(const std::string& input) -> bool
{
    auto stack = std::stack<char>{};
    const std::unordered_map<char, char> bracket_pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (auto ch : input)
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
