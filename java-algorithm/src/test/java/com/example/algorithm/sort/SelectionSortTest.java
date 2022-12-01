package com.example.algorithm.sort;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
@Slf4j
class SelectionSortTest {
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
    void testSelectionSort() {
        var selectionSort = new SelectionSort();
        var result = selectionSort.selectionSort(array);
        assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }
}
