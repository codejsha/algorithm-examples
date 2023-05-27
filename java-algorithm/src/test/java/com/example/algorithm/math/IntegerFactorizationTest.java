package com.example.algorithm.math;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class IntegerFactorizationTest {

    @Test
    void factorizeValidInput() {
        var number = 90;
        var expected = new Integer[]{2, 3, 3, 5};
        var actual = IntegerFactorization.factorize(number);
        assertArrayEquals(expected, actual.toArray());
    }
}
