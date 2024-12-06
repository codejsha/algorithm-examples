package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class GreatestCommonDivisorTest {
    @Test
    void gcdValidInput() {
        int a = 8;
        int b = 12;
        int expected = 4;
        int actual = GreatestCommonDivisor.gcd(a, b);
        assertEquals(expected, actual);
    }

    @Test
    void gcdRecursiveValidInput() {
        int a = 8;
        int b = 12;
        int expected = 4;
        int actual = GreatestCommonDivisor.gcdRecursive(a, b);
        assertEquals(expected, actual);
    }
}
