package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class MergeSortTest {
    @Autowired
    public MergeSort mergeSort;
    @Autowired
    public MergeSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void callMergeSort() {
        var result = mergeSort.callMergeSort(arrayData);
        Assertions.assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }

    @TestConfiguration
    static class MergeSortConfig {
        @Bean
        MergeSort createMergeSort() {
            return new MergeSort();
        }

        @Bean
        MergeSort.ArrayData createArrayData() {
            var data = new MergeSort.ArrayData();
            data.array = new int[]{64, 32, 16, 8, 4};
            return data;
        }
    }
}
