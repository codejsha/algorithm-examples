package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

import java.util.ArrayList;
import java.util.Arrays;

@SpringBootTest
class InsertionSortTest {
    @Autowired
    public InsertionSort insertionSort;
    @Autowired
    public InsertionSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {

    }

    @Test
    void callInsertionSort() {
        var result = insertionSort.callInsertionSort(arrayData);
        Assertions.assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }

    @TestConfiguration
    static class InsertionSortConfig {
        @Bean
        InsertionSort createInsertionSort() {
            return new InsertionSort();
        }

        @Bean
        InsertionSort.ArrayData createArrayData() {
            var data = new InsertionSort.ArrayData();
            data.array = new int[]{64, 32, 16, 8, 4};
            return data;
        }
    }
}
