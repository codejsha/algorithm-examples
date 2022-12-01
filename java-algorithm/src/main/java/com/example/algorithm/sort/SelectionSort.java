package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class SelectionSort {
    public int[] selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            var smallest = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[smallest]) {
                    smallest = j;
                }
            }
            swap(array, i, smallest);
        }
        return array;
    }
}
