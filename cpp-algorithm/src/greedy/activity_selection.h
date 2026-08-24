#ifndef CPP_ALGORITHM_ACTIVITY_SELECTION_H
#define CPP_ALGORITHM_ACTIVITY_SELECTION_H

#include <vector>

namespace ActivitySelection
{
    /**
     * \brief Activity selection problem using recursive approach.
     * \param start start times of activities
     * \param finish finish times of activities
     * \param index index of activity
     * \param size size of activities
     * \return the resulting set of selected activities
     */
    std::vector<int> RecursiveActivitySelector(
        const std::vector<int>& start,
        const std::vector<int>& finish,
        int index,
        int size);

    /**
     * \brief Activity selection problem using greedy algorithm.
     * \param start start times of activities
     * \param finish finish times of activities
     * \return the resulting set of selected activities
     */
    std::vector<int> GreedyActivitySelector(
        const std::vector<int>& start,
        const std::vector<int>& finish);
}

// ----------------------------------------------------------------------------
inline std::vector<int> ActivitySelection::RecursiveActivitySelector(
    const std::vector<int>& start,
    const std::vector<int>& finish,
    const int index,
    const int size)
{
    int sub_index = index + 1;

    while ((sub_index < size) && (start[sub_index] < finish[index]))
    {
        ++sub_index;
    }

    if (sub_index < size)
    {
        std::vector<int> activities = RecursiveActivitySelector(start, finish, sub_index, size);
        activities.push_back(sub_index);

        return activities;
    }
    return {};
}

// ----------------------------------------------------------------------------
inline std::vector<int> ActivitySelection::GreedyActivitySelector(
    const std::vector<int>& start,
    const std::vector<int>& finish)
{
    const int size = static_cast<int>(start.size());
    std::vector<int> selected;

    selected.push_back(0);

    int index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (start[i] >= finish[index])
        {
            selected.push_back(i);
            index = i;
        }
    }

    return selected;
}

#endif
