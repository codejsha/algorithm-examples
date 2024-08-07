#include "look_and_say.h"

auto LookAndSay::LookAndSayProblem(const std::string& input) -> std::string
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
