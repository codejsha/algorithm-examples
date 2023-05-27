package com.example.algorithm.sort;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class CountingSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        array = new int[]{2, 5, 3, 0, 2, 3, 0, 3};
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testCountingSort() {
        var result = CountingSort.countingSort(array);
        assertArrayEquals(new int[]{0, 0, 2, 2, 3, 3, 3, 5}, result);
    }
}
