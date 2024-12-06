package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class HeapSort {
    public static int[] heapSort(int[] array) {
        int heapSize = array.length;
        buildMaxHeap(array);
        for (int i = heapSize - 1; i > 0; i--) {
            swap(array, 0, i);
            heapSize--;
            maxHeapify(array, heapSize, 0);
        }
        return array;
    }

    private static void buildMaxHeap(int[] array) {
        int heapSize = array.length;
        int loopIndex = Math.subtractExact(Math.floorDiv(heapSize, 2), 1);

        for (int i = loopIndex; i > -1; i--) {
            maxHeapify(array, heapSize, i);
        }
    }

    private static void maxHeapify(int[] array, int heapSize, int index) {
        int largest = index;
        int leftIndex = 2 * index + 1; // 2n + 1
        int rightIndex = 2 * index + 2; // 2n + 2

        if ((leftIndex < heapSize) && (array[largest] < array[leftIndex])) {
            largest = leftIndex;
        }
        if ((rightIndex < heapSize) && (array[largest] < array[rightIndex])) {
            largest = rightIndex;
        }
        if (largest != index) {
            swap(array, index, largest);
            maxHeapify(array, heapSize, largest);
        }
    }
}
