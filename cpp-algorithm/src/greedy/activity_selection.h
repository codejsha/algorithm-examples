#ifndef CPP_ALGORITHM_ACTIVITY_SELECTION_H
#define CPP_ALGORITHM_ACTIVITY_SELECTION_H

#include <vector>

namespace ActivitySelection
{
    /// @brief Activity selection problem using recursive approach.
    /// @param start start times of activities
    /// @param finish finish times of activities
    /// @param index index of activity
    /// @param size size of activities
    /// @return the resulting set of selected activities
    std::vector<int> RecursiveActivitySelector(const std::vector<int>& start, const std::vector<int>& finish,
        int index, int size);

    /// @brief Activity selection problem using greedy algorithm.
    /// @param start start times of activities
    /// @param finish finish times of activities
    /// @return the resulting set of selected activities
    std::vector<int> GreedyActivitySelector(const std::vector<int>& start, const std::vector<int>& finish);
}

#endif
