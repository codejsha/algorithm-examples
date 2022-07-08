package com.example.demo.sort;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@SpringBootTest
class BucketSortTest {
    @Autowired
    public BucketSort bucketSort;
    @Autowired
    public BucketSort.ArrayData arrayData;

    @BeforeEach
    void setUp() {
    }

    @Test
    void callBucketSort() {
        var result = bucketSort.callBucketSort(arrayData);
        Assertions.assertArrayEquals(
                new Double[]{0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94}, result);
    }

    @TestConfiguration
    static class BucketSortConfig {
        @Bean
        BucketSort createBucketSort() {
            return new BucketSort();
        }

        @Bean
        BucketSort.ArrayData createArrayData() {
            var data = new BucketSort.ArrayData();
            data.array = new Double[]{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
            return data;
        }
    }
}