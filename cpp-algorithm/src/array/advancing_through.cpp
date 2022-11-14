#include "advancing_through.h"

bool AdvancingThrough::CanReachEnd(const std::vector<int>& max_advance_steps)
{
    auto furthest_reach_so_far = 0;
    const auto last_index = static_cast<int>(max_advance_steps.size()) - 1;

    for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i)
    {
        furthest_reach_so_far = std::max(furthest_reach_so_far, max_advance_steps[i] + i);
    }

    return furthest_reach_so_far >= last_index;
}
