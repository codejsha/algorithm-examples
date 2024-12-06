package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LeastCommonMultipleTest {
    @Test
    void lcm() {
        int a = 8;
        int b = 12;
        int expected = 24;
        int actual = LeastCommonMultiple.lcm(a, b);
        assertEquals(expected, actual);
    }
}
