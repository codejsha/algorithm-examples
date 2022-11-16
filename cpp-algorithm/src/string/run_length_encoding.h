#ifndef CPP_ALGORITHM_RUN_LENGTH_ENCODING_H
#define CPP_ALGORITHM_RUN_LENGTH_ENCODING_H

#include <string>

namespace RunLengthEncoding
{
    /// @brief Run-length encoding is a form of data compression,
    /// where runs are replaced by just one data value and count.
    /// @param str raw string
    /// @return compressed string
    std::string RunLengthEncoding(const std::string& str);

    /// @brief Run-length decoding is the reverse of run-length encoding.
    /// @param str compressed string
    /// @return raw string
    std::string RunLengthDecoding(const std::string& str);
}

#endif
