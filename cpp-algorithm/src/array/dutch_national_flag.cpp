#include "dutch_national_flag.h"

auto DutchFlag::DutchFlagPartition1(const int pivot_index, std::vector<Color>& arr) -> std::vector<Color>
{
    const auto pivot = arr[pivot_index];

    for (int i = 0; i < static_cast<Color>(arr.size()); ++i)
    {
        for (int j = i + 1; j < static_cast<Color>(arr.size()); ++j)
        {
            if (arr[j] < pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }
    for (int i = static_cast<Color>(arr.size()) - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }

    return arr;
}

auto DutchFlag::DutchFlagPartition2(const int pivot_index, std::vector<Color>& arr) -> std::vector<Color>
{
    const auto pivot = arr[pivot_index];

    auto smaller = 0;
    for (int i = 0; i < static_cast<Color>(arr.size()); ++i)
    {
        if (arr[i] < pivot)
        {
            std::swap(arr[i], arr[smaller++]);
        }
    }

    auto larger = static_cast<Color>(arr.size()) - 1;
    for (int i = static_cast<Color>(arr.size()) - 1; i >= 0; --i)
    {
        if (arr[i] > pivot)
        {
            std::swap(arr[i], arr[larger--]);
        }
    }

    return arr;
}

auto DutchFlag::DutchFlagPartition3(const int pivot_index, std::vector<Color>& arr) -> std::vector<Color>
{
    const auto pivot = arr[pivot_index];

    auto smaller = 0;
    auto equal = 0;
    int larger = static_cast<Color>(arr.size());

    while (equal < larger)
    {
        if (arr[equal] < pivot)
        {
            std::swap(arr[smaller++], arr[equal++]);
        }
        else if (arr[equal] == pivot)
        {
            ++equal;
        }
        else
        {
            std::swap(arr[equal], arr[--larger]);
        }
    }

    return arr;
}
