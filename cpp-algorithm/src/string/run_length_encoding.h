#ifndef CPP_ALGORITHM_RUN_LENGTH_ENCODING_H
#define CPP_ALGORITHM_RUN_LENGTH_ENCODING_H

#include <string>

namespace RunLengthEncoding
{
    /**
     * \brief Run-length encoding is a form of data compression,
     * where runs are replaced by just one data value and count.
     * \param str raw string
     * \return compressed string
     */
    std::string RunLengthEncoding(const std::string& str);

    /**
     * \brief Run-length decoding is the reverse of run-length encoding.
     * \param str compressed string
     * \return raw string
     */
    std::string RunLengthDecoding(const std::string& str);
}

// ----------------------------------------------------------------------------
inline std::string RunLengthEncoding::RunLengthEncoding(const std::string& str)
{
    int count = 0;
    std::string result;

    for (int i = 0; i < static_cast<int>(str.size()); ++i)
    {
        ++count;

        if (i + 1 == static_cast<int>(str.size()) || str[i] != str[i + 1])
        {
            result += std::to_string(count) + str[i];
            count = 0;
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
inline std::string RunLengthEncoding::RunLengthDecoding(const std::string& str)
{
    int count = 0;
    std::string result;

    for (const char& c : str)
    {
        if (std::isdigit(c))
        {
            count = c - '0';
        }
        else
        {
            result.append(count, c);
        }
    }

    return result;
}

#endif
