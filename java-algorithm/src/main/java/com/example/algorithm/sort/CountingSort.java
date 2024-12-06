package com.example.algorithm.sort;

import java.util.Arrays;
import java.util.OptionalInt;

public class CountingSort {
    public static int[] countingSort(int[] array) {
        int size = array.length;
        int[] output = new int[size];

        int max = 0;
        OptionalInt optionalMax = Arrays.stream(array).max();
        if (optionalMax.isPresent()) {
            max = optionalMax.getAsInt();
        }
        int[] count = new int[max + 1];
        Arrays.fill(count, 0);

        for (int k : array) {
            count[k]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        return output;
    }
}
