package com.example.algorithm.sort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class BucketSort {
    public static Double[] bucketSort(Double[] array) {
        int size = array.length;
        double min = Arrays.stream(array).min(Double::compare).orElse(0.0);
        double max = Arrays.stream(array).max(Double::compare).orElse(0.0);
        double range = max - min;

        // initialize buckets
        ArrayList<LinkedList<Double>> buckets = new ArrayList<LinkedList<Double>>();
        for (int i = 0; i < size; i++) {
            buckets.add(new LinkedList<>());
        }

        // distribute array elements into buckets
        for (Double k : array) {
            int index = (int) Math.floor(size * ((k - min) / range));
            if (index == size) {
                index--;
            }
            buckets.get(index).add(k);
        }

        // sort individual buckets using insertion sort
        for (int i = 0; i < size; i++) {
            Double[] bucketArray = buckets.get(i).toArray(new Double[0]);
            InsertionSort.insertionSort(bucketArray);
            buckets.set(i, new LinkedList<>(Arrays.asList(bucketArray)));
        }

        // concatenate all buckets
        return buckets.stream().flatMap(LinkedList::stream).toArray(Double[]::new);
    }
}
