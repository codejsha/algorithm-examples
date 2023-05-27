package com.example.algorithm.sort;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class BucketSortTest {
    Double[] array;

    @BeforeEach
    void setUp() {
        array = new Double[]{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    }

    @AfterEach
    void tearDown() {
        System.gc();
    }

    @Test
    void testBucketSort() {
        var result = BucketSort.bucketSort(array);
        assertArrayEquals(new Double[]{0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94}, result);
    }
}
