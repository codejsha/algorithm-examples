package com.example.algorithm.sort;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.mockito.Mockito.spy;

@ExtendWith(MockitoExtension.class)
@Slf4j
class BubbleSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        // data preparation (size 8, lower bound 1, upper bound 100, seed 42)
        // array data: [31, 64, 49, 85, 71, 26, 6, 19]
        var size = 8;
        var min = 1;
        var max = 100;
        var random = new Random(42);
        array = random.ints(size, min, max + 1).toArray();
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testBubbleSort() {
        var bubbleSort = spy(new BubbleSort());
        var result = bubbleSort.bubbleSort(array);
        assertArrayEquals(new int[]{6, 19, 26, 31, 49, 64, 71, 85}, result);
    }
}
