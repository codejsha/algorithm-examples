package com.example.algorithm.sort;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.mockito.Mockito.spy;

@ExtendWith(MockitoExtension.class)
@Slf4j
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
        var bucketSort = spy(new BucketSort());
        var result = bucketSort.bucketSort(array);
        assertArrayEquals(new Double[]{0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94}, result);
    }
}
