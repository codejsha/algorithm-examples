package com.example.algorithm.sort;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class InsertionSortTest {
    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testInsertionSort() {
        var array = new Integer[]{64, 32, 16, 8, 4};
        InsertionSort.insertionSort(array);
        assertArrayEquals(new Integer[]{4, 8, 16, 32, 64}, array);
    }

    @Test
    void testInsertionSort2() {
        var array = new Double[]{64.5, 32.5, 16.5, 8.5, 4.5};
        InsertionSort.insertionSort(array);
        assertArrayEquals(new Double[]{4.5, 8.5, 16.5, 32.5, 64.5}, array);
    }
}
