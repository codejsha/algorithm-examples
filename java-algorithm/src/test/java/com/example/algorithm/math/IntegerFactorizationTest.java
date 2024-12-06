package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class IntegerFactorizationTest {
    @Test
    void factorizeValidInput() {
        int number = 90;
        var expected = new Integer[]{2, 3, 3, 5};
        List<Integer> actual = IntegerFactorization.factorize(number);
        assertArrayEquals(expected, actual.toArray());
    }
}
