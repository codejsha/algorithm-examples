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
class InsertionSortTest {
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
    void testInsertionSort() {
        var insertionSort = spy(new InsertionSort());
        var result = insertionSort.insertionSort(array);
        assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }
}
