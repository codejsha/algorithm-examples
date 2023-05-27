package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class GreatestCommonDivisorTest {
    @Test
    void gcdValidInput() {
        var a = 8;
        var b = 12;
        var expected = 4;
        var actual = GreatestCommonDivisor.gcd(a, b);
        assertEquals(expected, actual);
    }

    @Test
    void gcdRecursiveValidInput() {
        var a = 8;
        var b = 12;
        var expected = 4;
        var actual = GreatestCommonDivisor.gcdRecursive(a, b);
        assertEquals(expected, actual);
    }
}
