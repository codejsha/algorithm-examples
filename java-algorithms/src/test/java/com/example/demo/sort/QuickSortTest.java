package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class QuickSortTest {
    @Autowired
    public QuickSort quickSort;
    @Autowired
    public QuickSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void callQuickSort() {
        var result = quickSort.callQuickSort(arrayData);
        Assertions.assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6, 7, 8}, result);
    }

    @TestConfiguration
    static class QuickSortConfig {
        @Bean
        QuickSort createQuickSort() {
            return new QuickSort();
        }

        @Bean
        QuickSort.ArrayData createArrayData() {
            var data = new QuickSort.ArrayData();
            data.array = new int[]{2, 8, 7, 1, 3, 5, 6, 4};
            return data;
        }
    }
}
