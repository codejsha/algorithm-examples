package com.example.algorithm.sort;

import static com.example.algorithm.util.ElementUtil.swap;

public class HeapSort {
    public int[] heapSort(int[] array) {
        var heapSize = array.length;
        buildMaxHeap(array);
        for (var i = heapSize - 1; i > 0; i--) {
            swap(array, 0, i);
            heapSize--;
            maxHeapify(array, heapSize, 0);
        }
        return array;
    }

    private void buildMaxHeap(int[] array) {
        var heapSize = array.length;
        var loopIndex = Math.subtractExact(Math.floorDiv(heapSize, 2), 1);

        for (var i = loopIndex; i > -1; i--) {
            maxHeapify(array, heapSize, i);
        }
    }

    private void maxHeapify(int[] array, int heapSize, int index) {
        var largest = index;
        var leftIndex = 2 * index + 1; // 2n + 1
        var rightIndex = 2 * index + 2; // 2n + 2

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
