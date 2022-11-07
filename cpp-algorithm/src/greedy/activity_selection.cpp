#include "activity_selection.h"

std::vector<int> ActivitySelection::RecursiveActivitySelector(const std::vector<int>& start, const std::vector<int>& finish,
    const int index, const int size)
{
    auto subIndex = index + 1;

    while ((subIndex < size) && (start[subIndex] < finish[index]))
    {
        ++subIndex;
    }

    if (subIndex < size)
    {
        auto activities = RecursiveActivitySelector(start, finish, subIndex, size);
        activities.push_back(subIndex);

        return activities;
    }
    else
    {
        return {};
    }
}

std::vector<int> ActivitySelection::GreedyActivitySelector(const std::vector<int>& start, const std::vector<int>& finish)
{
    const auto size = static_cast<int>(start.size());
    auto selected = std::vector<int>{};

    selected.push_back(0);

    auto index = 0;
    for (auto i = 1; i < size; ++i)
    {
        if (start[i] >= finish[index])
        {
            selected.push_back(i);
            index = i;
        }
    }

    return selected;
}
