#include "delete_element.h"

#include <algorithm>

auto DeleteElement::DeleteDuplicates(std::vector<int>& numbers) -> std::vector<int>
{
    if (numbers.empty())
    {
        return {};
    }

    int write_index = 1;
    for (int i = 1; i < static_cast<int>(numbers.size()); ++i)
    {
        if (numbers[write_index - 1] != numbers[i])
        {
            numbers[write_index] = numbers[i];
            ++write_index;
        }
    }

    return std::vector<int>{numbers.begin(), numbers.begin() + write_index};
}

auto DeleteElement::DeleteDuplicateElements(std::vector<int>& numbers) -> std::vector<int>
{
    if (numbers.empty())
    {
        return {};
    }

    std::ranges::sort(numbers);
    numbers.erase(std::ranges::unique(numbers).begin(), numbers.end());

    return numbers;
}

auto DeleteElement::DeleteSpecificElements(std::vector<int>& numbers, const int element) -> std::vector<int>
{
    if (numbers.empty())
    {
        return {};
    }

    std::erase(numbers, element);
    return numbers;
}
