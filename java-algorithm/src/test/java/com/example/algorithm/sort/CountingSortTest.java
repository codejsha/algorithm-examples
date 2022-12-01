package com.example.algorithm.sort;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.mockito.Mockito.spy;

@ExtendWith(MockitoExtension.class)
@Slf4j
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
        var countingSort = spy(new CountingSort());
        var result = countingSort.countingSort(array);
        assertArrayEquals(new int[]{0, 0, 2, 2, 3, 3, 3, 5}, result);
    }
}
