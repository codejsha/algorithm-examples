#ifndef CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H
#define CPP_ALGORITHM_ARBITRARY_PRECISION_INTEGER_H

#include <string>
#include <vector>

namespace ArbitraryPrecision
{
    /**
     * \brief  Add one to the number represented by the array.
     * \param number_array given number array
     * \return result array
     */
    auto PlusOne(std::vector<int> number_array) -> std::vector<int>;

    /**
     * \brief Add two numbers represented by strings.
     * \param number_string1 number string 1
     * \param number_string2 number string 2
     * \return result array
     */
    auto StringAddition(const std::string& number_string1, const std::string& number_string2) -> std::vector<int>;

    /**
     * \brief Multiply two numbers represented by array.
     * \param number_array1 number array 1
     * \param number_array2 number array 2
     * \return result array
     */
    auto Multiply(std::vector<int>& number_array1, std::vector<int>& number_array2) -> std::vector<int>;
}

#endif
