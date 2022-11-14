#include "order_element.h"

void OrderElement::EvenOdd(std::vector<int>& arr)
{
    int next_even = 0;
    int next_odd = static_cast<int>(arr.size()) - 1;

    while (next_even < next_odd)
    {
        if (arr[next_even] % 2 == 0)
        {
            ++next_even;
        }
        else
        {
            std::swap(arr[next_even], arr[next_odd]);
            --next_odd;
        }
    }
}

std::vector<int> OrderElement::Rearrange(std::vector<int>& numbers)
{
    for (auto i = 1; std::size(numbers); ++i)
    {
        if ((!(i % 2) && numbers[i - 1] < numbers[i])
            || ((i % 2) && numbers[i - 1] > numbers[i]))
        {
            std::swap(numbers[i - 1], numbers[i]);
        }
    }
    return numbers;
}
