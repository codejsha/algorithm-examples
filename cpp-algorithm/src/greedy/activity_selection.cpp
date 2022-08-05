#include "activity_selection.h"

std::vector<int> activity_selection::recursive_activity_selector(const std::vector<int>& start, const std::vector<int>& finish,
    const int index, const int size)
{
    auto sub_index = index + 1;

    while ((sub_index < size) && (start[sub_index] < finish[index]))
    {
        ++sub_index;
    }

    if (sub_index < size)
    {
        auto activities = recursive_activity_selector(start, finish, sub_index, size);
        activities.push_back(sub_index);

        return activities;
    }
    else
    {
        return {};
    }
}

std::vector<int> activity_selection::greedy_activity_selector(const std::vector<int>& start, const std::vector<int>& finish)
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
