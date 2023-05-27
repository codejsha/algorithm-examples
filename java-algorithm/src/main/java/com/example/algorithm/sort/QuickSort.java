package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class QuickSort {
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            var pivot = partition(array, low, high);
            quickSort(array, low, pivot - 1);
            quickSort(array, pivot + 1, high);
        }
    }

    private static int partition(int[] array, int low, int high) {
        var pivot = array[high];
        var i = low - 1;
        for (var j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i + 1, high);
        return i + 1;
    }
}
