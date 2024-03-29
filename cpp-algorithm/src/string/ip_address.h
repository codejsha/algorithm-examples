#ifndef CPP_ALGORITHM_IP_ADDRESS_H
#define CPP_ALGORITHM_IP_ADDRESS_H

#include <string>
#include <vector>

namespace IpAddress
{
    /**
     * \brief Validate IP address.
     * \param str address string omitted with '.'
     * \return valid ip addresses
     */
    auto GetValidIpAddress(const std::string& str) -> std::vector<std::string>;
}

#endif
