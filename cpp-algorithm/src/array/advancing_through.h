#ifndef CPP_ALGORITHM_ADVANCING_THROUGH_H
#define CPP_ALGORITHM_ADVANCING_THROUGH_H

#include <vector>

namespace AdvancingThrough
{
    /**
     * \brief Check whether the end of the array can be reached.
     * Each element in the array represents the maximum number of steps that can be taken forward from that element.
     * Time complexity: O(n), Space complexity: O(1)
     * \param max_advance_steps maximum number of steps that can be taken from each index
     * \return true if the last index is reachable from index 0, otherwise false
     */
    bool CanReachEnd(
        const std::vector<int>& max_advance_steps);
}

// ----------------------------------------------------------------------------
inline bool AdvancingThrough::CanReachEnd(
    const std::vector<int>& max_advance_steps)
{
    int reach_so_far = 0; // furthest index reachable from the current frontier
    const int last_index = static_cast<int>(max_advance_steps.size()) - 1;

    for (int i = 0; i <= reach_so_far && reach_so_far < last_index; ++i)
    {
        // Expand the furthest reachable position by considering each reachable index.
        reach_so_far = std::max(reach_so_far, max_advance_steps[i] + i);
    }

    return reach_so_far >= last_index;
}

#endif
