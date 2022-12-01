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
class HeapSortTest {
    int[] array;

    @BeforeEach
    void setUp() {
        array = new int[]{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testHeapSort() {
        var heapSort = spy(new HeapSort());
        var result = heapSort.heapSort(array);
        assertArrayEquals(new int[]{1, 2, 3, 4, 7, 8, 9, 10, 14, 16}, result);
    }
}
