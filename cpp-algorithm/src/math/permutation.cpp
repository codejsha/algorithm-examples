#include "permutation.h"

#include <iostream>

void permutation::Permutation(const std::string& str, const std::string& prefix)
{
    const auto size = static_cast<int>(str.length());

    if (size == 0)
    {
        std::cout << prefix << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            const std::string rem = str.substr(0, i) + str.substr(i + 1);
            Permutation(rem, prefix + str[i]);
        }
    }
}
