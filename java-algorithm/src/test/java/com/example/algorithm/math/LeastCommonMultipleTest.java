package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LeastCommonMultipleTest {
    @Test
    void lcm() {
        var a = 8;
        var b = 12;
        var expected = 24;
        var actual = LeastCommonMultiple.lcm(a, b);
        assertEquals(expected, actual);
    }
}
