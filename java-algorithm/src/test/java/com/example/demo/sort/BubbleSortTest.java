package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class BubbleSortTest {
    @Autowired
    public BubbleSort bubbleSort;
    @Autowired
    public BubbleSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void bubbleSort() {
        var result = bubbleSort.bubbleSort(arrayData);
        Assertions.assertArrayEquals(new int[]{4, 8, 16, 32, 64}, result);
    }

    @TestConfiguration
    static class BubbleSortConfig {
        @Bean
        BubbleSort createBubbleSort() {
            return new BubbleSort();
        }

        @Bean
        BubbleSort.ArrayData createArrayData() {
            var data = new BubbleSort.ArrayData();
            data.array = new int[]{64, 32, 16, 8, 4};
            return data;
        }
    }
}
