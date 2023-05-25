package com.example.algorithm.sort;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SalaryThresholdTest {
    @Test
    void computeSalaryThreshold() {
        var salaries = new Integer[]{90, 30, 100, 40, 20};
        var target = 210;
        var expected = 60;
        var actual = SalaryThreshold.computeSalaryThreshold(salaries, target);
        assertEquals(expected, actual);
    }
}
