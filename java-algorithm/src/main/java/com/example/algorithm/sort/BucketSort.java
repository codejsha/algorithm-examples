package com.example.algorithm.sort;

import java.util.ArrayList;
import java.util.LinkedList;

public class BucketSort {
    private final InsertionSort insertionSort = new InsertionSort();

    public Double[] bucketSort(Double[] array) {
        var size = array.length;
        var bucket = new ArrayList<LinkedList<Double>>();
        for (int i = 0; i < size; i++) {
            bucket.add(new LinkedList<>());
        }

        for (Double k : array) {
            var list = bucket.get((int) Math.floor(size * k));
            list.add(k);
        }

        for (int i = 0; i < size; i++) {
            array = insertionSort.insertionSort(array);
        }
        return array;
    }
}
