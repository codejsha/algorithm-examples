package com.example.algorithm.sort;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class SalaryThresholdTest {
    @Test
    void computeSalaryThreshold() {
        var salaries = new Integer[]{90, 30, 100, 40, 20};
        int target = 210;
        int expected = 60;
        int actual = SalaryThreshold.computeSalaryThreshold(salaries, target);
        assertEquals(expected, actual);
    }
}
