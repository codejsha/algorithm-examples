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
class QuickSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        array = new int[]{2, 8, 7, 1, 3, 5, 6, 4};
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testQuickSort() {
        var quickSort = spy(new QuickSort());
        quickSort.quickSort(array, 0, array.length - 1);
        assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6, 7, 8}, array);
    }
}
