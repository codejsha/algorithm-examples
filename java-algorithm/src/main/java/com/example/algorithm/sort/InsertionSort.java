package com.example.algorithm.sort;

public class InsertionSort {
    public static int[] insertionSort(int[] array) {
        for (var i = 1; i < array.length; i++) {
            var key = array[i];
            var j = i - 1;
            while ((j > -1) && (array[j] > key)) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
        return array;
    }

    public static Double[] insertionSort(Double[] array) {
        for (var i = 1; i < array.length; i++) {
            var key = array[i];
            var j = i - 1;
            while ((j > -1) && (array[j] > key)) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
        return array;
    }
}
