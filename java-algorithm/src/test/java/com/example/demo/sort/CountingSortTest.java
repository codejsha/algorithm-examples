package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class CountingSortTest {
    @Autowired
    public CountingSort countingSort;
    @Autowired
    public CountingSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void countingSort() {
        var result = countingSort.countingSort(arrayData);
        Assertions.assertArrayEquals(new int[]{0, 0, 2, 2, 3, 3, 3, 5}, result);
    }

    @TestConfiguration
    static class CountingSortConfig {
        @Bean
        CountingSort createCountingSort() {
            return new CountingSort();
        }

        @Bean
        CountingSort.ArrayData createArrayData() {
            var data = new CountingSort.ArrayData();
            data.array = new int[]{2, 5, 3, 0, 2, 3, 0, 3};
            return data;
        }
    }
}
