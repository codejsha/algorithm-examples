package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class SelectionSort {
    public static int[] selectionSort(int[] array) {
        for (var i = 0; i < array.length - 1; i++) {
            var smallest = i;
            for (var j = i + 1; j < array.length; j++) {
                if (array[j] < array[smallest]) {
                    smallest = j;
                }
            }
            swap(array, i, smallest);
        }
        return array;
    }
}
