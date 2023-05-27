package com.example.algorithm.sort;

import java.util.Arrays;

public class MergeSort {
    public static void mergeSort(int[] array, int start, int end) {
        if (start < end) {
            var middle = Math.floorDiv(start + end, 2);
            mergeSort(array, start, middle);
            mergeSort(array, middle + 1, end);
            merge(array, start, middle, end);
        }
    }

    private static void merge(int[] array, int start, int middle, int end) {
        var leftSize = middle - start + 1;
        var rightSize = end - middle;

        var leftArray = Arrays.copyOfRange(array, start, middle + 1);
        var rightArray = Arrays.copyOfRange(array, middle + 1, end + 1);

        var i = 0;
        var j = 0;
        var outOfLeft = false;
        var outOfRight = false;

        for (var k = start; k < end + 1; k++) {
            if (leftSize <= i) {
                outOfLeft = true;
            }
            if (rightSize <= j) {
                outOfRight = true;
            }

            if (!outOfLeft && !outOfRight) {
                if (leftArray[i] <= rightArray[j]) {
                    array[k] = leftArray[i];
                    i++;
                } else {
                    array[k] = rightArray[j];
                    j++;
                }
            }
            if (!outOfLeft && outOfRight) {
                array[k] = leftArray[i];
                i++;
            } else if (outOfLeft && !outOfRight) {
                array[k] = rightArray[j];
                j++;
            }
        }
    }
}
