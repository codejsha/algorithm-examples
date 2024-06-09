#ifndef CPP_ALGORITHM_SMALLEST_SUBARRAY_H
#define CPP_ALGORITHM_SMALLEST_SUBARRAY_H

#include <string>
#include <vector>

namespace SmallestSubarray
{
    /**
     * \brief Find the smallest subarray that covers all the elements in a set.
     * \param paragraph an array
     * \param keywords a set
     * \return a tuple of the start and end indices of the smallest subarray
     */
    auto FindSmallestSubarrayCoveringSubset(const std::vector<std::string>& paragraph,
                                            const std::vector<std::string>& keywords) -> std::tuple<int, int>;

    /**
     * \brief Find the smallest subarray that sequentially covers all the elements in a set.
     * \param paragraph an array
     * \param keywords a set
     * \return a tuple of the start and end indices of the smallest subarray
     */
    auto FindSmallestSubarraySequentiallyCoveringSubset(const std::vector<std::string>& paragraph,
                                                        const std::vector<std::string>& keywords)
        -> std::tuple<int, int>;
}

#endif
