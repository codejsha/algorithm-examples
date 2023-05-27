package com.example.algorithm.sort;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class MergeSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        array = new int[]{64, 32, 16, 8, 4};
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testMergeSort() {
        MergeSort.mergeSort(array, 0, array.length - 1);
        assertArrayEquals(new int[]{4, 8, 16, 32, 64}, array);
    }
}
