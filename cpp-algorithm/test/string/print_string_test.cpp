#include "print_string.h"

#include <gtest/gtest.h>

GTEST_TEST(PrintString, SineWaveString)
{
    const auto str = "Hello_World!";
    const auto result = PrintString::SineWaveString(str);
    const auto expected = "e_lHloWrdlo!";
    EXPECT_EQ(expected, result);

    PrintString::PrintSineWaveString("Hello_World!");
    // Result:
    //   e       _       l
    // H   l   o   W   r   d
    //       l       o       !
}
