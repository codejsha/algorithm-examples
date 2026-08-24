#ifndef CPP_ALGORITHM_ADVANCING_THROUGH_H
#define CPP_ALGORITHM_ADVANCING_THROUGH_H

#include <vector>

namespace AdvancingThrough
{
    /**
     * \brief Advance through the array to the last index.
     * \param max_advance_steps maximum number of steps that can be taken from each index
     * \return either reach the end or not
     */
    bool CanReachEnd(
        const std::vector<int>& max_advance_steps);
}

// ----------------------------------------------------------------------------
inline bool AdvancingThrough::CanReachEnd(
    const std::vector<int>& max_advance_steps)
{
    int reach_so_far = 0; // furthest reach so far
    const int last_index = static_cast<int>(max_advance_steps.size()) - 1;

    for (int i = 0; i <= reach_so_far && reach_so_far < last_index; ++i)
    {
        reach_so_far = std::max(reach_so_far, max_advance_steps[i] + i);
    }

    return reach_so_far >= last_index;
}

#endif
