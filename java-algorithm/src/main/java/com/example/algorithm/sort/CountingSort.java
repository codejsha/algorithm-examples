package com.example.algorithm.sort;

import java.util.Arrays;

public class CountingSort {
    public static int[] countingSort(int[] array) {
        var size = array.length;
        var output = new int[size];

        var max = 0;
        var optionalMax = Arrays.stream(array).max();
        if (optionalMax.isPresent()) {
            max = optionalMax.getAsInt();
        }
        var count = new int[max + 1];
        Arrays.fill(count, 0);

        for (var k : array) {
            count[k]++;
        }

        for (var i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (var i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        return output;
    }
}
