#include "replace_element.h"

auto ReplaceElement::ReplaceAndRemoveString1(std::vector<std::string>& arr, const std::string& replace_str,
                                             const std::string& remove_str) -> std::vector<std::string>
{
    auto write_index = 0;
    auto a_count = 0;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        if (arr[i] != remove_str)
        {
            arr[write_index++] = arr[i];
        }
        if (arr[i] == replace_str)
        {
            ++a_count;
        }
    }

    auto current_index = write_index - 1;
    write_index = write_index + a_count - 1;
    auto final_size = write_index + 1;
    while (current_index >= 0)
    {
        if (arr[current_index] == replace_str)
        {
            arr[write_index--] = "d";
            arr[write_index--] = "d";
        }
        else
        {
            arr[write_index--] = arr[current_index];
        }
        --current_index;
    }

    return std::vector<std::string>{arr.begin(), arr.begin() + final_size};
}

auto ReplaceElement::ReplaceAndRemoveString2(std::vector<std::string>& arr, const std::string& replace_str,
                                             const std::string& remove_str) -> std::vector<std::string>
{
    std::erase(arr, remove_str);
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        if (arr[i] == replace_str)
        {
            arr[i] = "d";
            arr.insert(arr.begin() + i + 1, "d");
        }
    }

    return arr;
}

auto ReplaceElement::TelexEncoding(std::vector<std::string>& arr) -> std::vector<std::string>
{
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        if (arr[i] == ".")
        {
            auto str = std::vector<std::string>{"D", "O", "T"};
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin() + i, str.begin(), str.end());
        }
        else if (arr[i] == ",")
        {
            auto str = std::vector<std::string>{"C", "O", "M", "M", "A"};
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin() + i, str.begin(), str.end());
        }
        else if (arr[i] == "?")
        {
            auto str = std::vector<std::string>{"Q", "U", "E", "S", "T", "I", "O", "N", "_", "M", "A", "R", "K"};
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin() + i, str.begin(), str.end());
        }
        else if (arr[i] == "!")
        {
            auto str = std::vector<std::string>{"E", "X", "C", "L", "A", "M", "A", "T",
                                                "I", "O", "N", "_", "M", "A", "R", "K"};
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin() + i, str.begin(), str.end());
        }
    }
    return arr;
}
