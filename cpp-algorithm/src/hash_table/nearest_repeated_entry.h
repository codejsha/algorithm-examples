#ifndef CPP_ALGORITHM_NEAREST_REPEATED_ENTRY_H
#define CPP_ALGORITHM_NEAREST_REPEATED_ENTRY_H

#include <string>
#include <vector>

namespace NearestRepeatedEntry
{
    /// @brief Find the nearest repeated entry in an array of strings.
    /// @details Given an array of strings, find the distance between the closest pair of equal entries.
    /// @param paragraph an array of strings
    /// @return the distance between the closest pair of equal entries
    auto FindNearestRepeatedEntry(const std::vector<std::string>& paragraph) -> int;
}

#endif
