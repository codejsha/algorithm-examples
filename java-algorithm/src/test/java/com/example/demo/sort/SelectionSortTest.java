package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class SelectionSortTest {
    @Autowired
    public SelectionSort selectionSort;
    @Autowired
    public SelectionSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {

    }

    @Test
    void selectionSort() {
        var result = selectionSort.selectionSort(arrayData);
        Assertions.assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }

    @TestConfiguration
    static class SelectionSortConfig {
        @Bean
        SelectionSort createSelectionSort() {
            return new SelectionSort();
        }

        @Bean
        SelectionSort.ArrayData createArrayData() {
            var data = new SelectionSort.ArrayData();
            data.array = new int[]{64, 32, 16, 8, 4};
            return data;
        }
    }
}
