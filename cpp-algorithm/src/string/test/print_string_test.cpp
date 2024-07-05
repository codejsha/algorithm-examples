#include "print_string.h"

#include <gtest/gtest.h>

GTEST_TEST(PrintString, SineWaveString)
{
    const std::string str = "Hello_World!";
    const std::string result = PrintString::SineWaveString(str);
    const std::string expected = "e_lHloWrdlo!";
    EXPECT_EQ(expected, result);

    PrintString::PrintSineWaveString("Hello_World!");
    // Result:
    //   e       _       l
    // H   l   o   W   r   d
    //       l       o       !
}
