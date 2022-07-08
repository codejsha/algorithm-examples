package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class HeapSortTest {
    @Autowired
    public HeapSort heapSort;
    @Autowired
    public HeapSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void callHeapSort() {
        var result = heapSort.callHeapSort(arrayData);
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4, 7, 8, 9, 10, 14, 16}, result);
    }

    @TestConfiguration
    static class HeapSortConfig {
        @Bean
        HeapSort createHeapSort() {
            return new HeapSort();
        }

        @Bean
        HeapSort.ArrayData createArrayData() {
            var data = new HeapSort.ArrayData();
            data.array = new int[]{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
            return data;
        }
    }
}
