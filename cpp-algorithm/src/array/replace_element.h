#ifndef CPP_ALGORITHM_REPLACE_ELEMENT_H
#define CPP_ALGORITHM_REPLACE_ELEMENT_H

#include <string>
#include <vector>

namespace ReplaceElement
{
    /**
     * \brief Replace element and remove element in the array. Keep the array size.
     * \param arr input array
     * \param replace_str replace string
     * \param remove_str remove string
     * \return result array
     */
    std::vector<std::string> ReplaceAndRemoveString1(
        std::vector<std::string>& arr,
        const std::string& replace_str,
        const std::string& remove_str);

    /**
     * \brief Replace element and remove element in the array.
     * Use some STL algorithms.
     * \param arr input array
     * \param replace_str replace string
     * \param remove_str remove string
     * \return result array
     */
    std::vector<std::string> ReplaceAndRemoveString2(
        std::vector<std::string>& arr,
        const std::string& replace_str,
        const std::string& remove_str);

    /**
     * \brief Telex encoding for punctuation marks.
     * Replace '.' with 'DOT', ',' with 'COMMA', '?' with 'QUESTION_MARK', '!' with 'EXCLAMATION_MARK'.
     * \param arr input array (possibly contains punctuation marks)
     * \return result array
     */
    std::vector<std::string> TelexEncoding(
        std::vector<std::string>& arr);
}

// ----------------------------------------------------------------------------
inline std::vector<std::string> ReplaceElement::ReplaceAndRemoveString1(
    std::vector<std::string>& arr,
    const std::string& replace_str,
    const std::string& remove_str)
{
    int write_index = 0;
    int a_count = 0;
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

    int current_index = write_index - 1;
    write_index = write_index + a_count - 1;
    const int final_size = write_index + 1;
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

// ----------------------------------------------------------------------------
inline std::vector<std::string> ReplaceElement::ReplaceAndRemoveString2(
    std::vector<std::string>& arr,
    const std::string& replace_str,
    const std::string& remove_str)
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

// ----------------------------------------------------------------------------
inline std::vector<std::string> ReplaceElement::TelexEncoding(
    std::vector<std::string>& arr)
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

#endif
