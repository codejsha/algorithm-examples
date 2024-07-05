#include "advancing_through.h"

auto AdvancingThrough::CanReachEnd(const std::vector<int>& max_advance_steps) -> bool
{
    int reach_so_far = 0;   // furthest reach so far
    const int last_index = static_cast<int>(max_advance_steps.size()) - 1;

    for (int i = 0; i <= reach_so_far && reach_so_far < last_index; ++i)
    {
        reach_so_far = std::max(reach_so_far, max_advance_steps[i] + i);
    }

    return reach_so_far >= last_index;
}
