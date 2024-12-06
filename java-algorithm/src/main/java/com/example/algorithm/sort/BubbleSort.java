package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class BubbleSort {
    public static int[] bubbleSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = array.length - 1; j > i; j--) {
                if (array[j] < array[j - 1]) {
                    swap(array, j - 1, j);
                }
            }
        }
        return array;
    }
}
