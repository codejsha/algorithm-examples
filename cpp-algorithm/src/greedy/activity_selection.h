#ifndef CPP_ALGORITHM_ACTIVITY_SELECTION_H
#define CPP_ALGORITHM_ACTIVITY_SELECTION_H

#include <vector>

namespace ActivitySelection
{
    /// <summary>
    /// Activity selection problem using recursive approach
    /// </summary>
    /// <param name="start">start times of activities</param>
    /// <param name="finish">finish times of activities</param>
    /// <param name="index">index of activity</param>
    /// <param name="size">size of activities</param>
    /// <returns>the resulting set of selected activities</returns>
    std::vector<int> RecursiveActivitySelector(const std::vector<int>& start, const std::vector<int>& finish,
        const int index, const int size);

    /// <summary>
    /// Activity selection problem using greedy algorithm
    /// </summary>
    /// <param name="start">start times of activities</param>
    /// <param name="finish">finish times of activities</param>
    /// <returns>the resulting set of selected activities</returns>
    std::vector<int> GreedyActivitySelector(const std::vector<int>& start, const std::vector<int>& finish);
}

#endif
