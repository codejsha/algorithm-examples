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
    auto ReplaceAndRemoveString1(std::vector<std::string>& arr,
                                 const std::string& replace_str,
                                 const std::string& remove_str)
        -> std::vector<std::string>;

    /**
     * \brief Replace element and remove element in the array.
     * Use some STL algorithms.
     * \param arr input array
     * \param replace_str replace string
     * \param remove_str remove string
     * \return result array
     */
    auto ReplaceAndRemoveString2(std::vector<std::string>& arr,
                                 const std::string& replace_str,
                                 const std::string& remove_str)
        -> std::vector<std::string>;

    /**
     * \brief Telex encoding for punctuation marks.
     * Replace '.' with 'DOT', ',' with 'COMMA', '?' with 'QUESTION_MARK', '!' with 'EXCLAMATION_MARK'.
     * \param arr input array (possibly contains punctuation marks)
     * \return result array
     */
    auto TelexEncoding(std::vector<std::string>& arr) -> std::vector<std::string>;
}

#endif
