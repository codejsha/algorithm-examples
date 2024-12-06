package com.example.algorithm.sort;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class BubbleSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        // data preparation (size 8, lower bound 1, upper bound 100, seed 42)
        // array data: [31, 64, 49, 85, 71, 26, 6, 19]
        int size = 8;
        int min = 1;
        int max = 100;
        var random = new Random(42);
        array = random.ints(size, min, max + 1).toArray();
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testBubbleSort() {
        var result = BubbleSort.bubbleSort(array);
        assertArrayEquals(new int[]{6, 19, 26, 31, 49, 64, 71, 85}, result);
    }
}
