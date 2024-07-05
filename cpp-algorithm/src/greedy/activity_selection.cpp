#include "activity_selection.h"

auto ActivitySelection::RecursiveActivitySelector(const std::vector<int>& start,
                                                  const std::vector<int>& finish,
                                                  const int index,
                                                  const int size)
    -> std::vector<int>
{
    int sub_index = index + 1;

    while ((sub_index < size) && (start[sub_index] < finish[index]))
    {
        ++sub_index;
    }

    if (sub_index < size)
    {
        auto activities = RecursiveActivitySelector(start, finish, sub_index, size);
        activities.push_back(sub_index);

        return activities;
    }
    return {};
}

auto ActivitySelection::GreedyActivitySelector(const std::vector<int>& start, const std::vector<int>& finish)
    -> std::vector<int>
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
