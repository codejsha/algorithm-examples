#include "ip_address.h"

#include <gtest/gtest.h>

GTEST_TEST(IpAddress, GetValidIpAddress1)
{
    const auto expected = std::vector<std::string>{"255.255.11.135", "255.255.111.35"};
    EXPECT_EQ(expected, IpAddress::GetValidIpAddress("25525511135"));
}

GTEST_TEST(IpAddress, GetValidIpAddress2)
{
    const auto expected = std::vector<std::string>{"0.0.0.0"};
    EXPECT_EQ(expected, IpAddress::GetValidIpAddress("0000"));
}

GTEST_TEST(IpAddress, GetValidIpAddress3)
{
    const auto expected = std::vector<std::string>{
        "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    EXPECT_EQ(expected, IpAddress::GetValidIpAddress("101023"));
}
