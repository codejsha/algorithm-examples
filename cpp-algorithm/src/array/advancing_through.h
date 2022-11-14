#ifndef CPP_ALGORITHM_ADVANCING_THROUGH_H
#define CPP_ALGORITHM_ADVANCING_THROUGH_H

#include <vector>

namespace AdvancingThrough
{
    /// @brief Advance through the array to the last index.
    /// @param max_advance_steps maximum number of steps that can be taken from each index
    /// @return either reach the end or not
    bool CanReachEnd(const std::vector<int>& max_advance_steps);
}

#endif
