package com.example.demo.sort;

import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.RunnerException;
import org.openjdk.jmh.runner.options.Options;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@OutputTimeUnit(TimeUnit.NANOSECONDS)
@State(Scope.Thread)
@Warmup(iterations = 1)
@Measurement(iterations = 1)
public class MergeSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(MergeSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    public void mergeSort(int[] array, int start, int end) {
        if (start < end) {
            var middle = Math.floorDiv(start + end, 2);
            mergeSort(array, start, middle);
            mergeSort(array, middle + 1, end);
            merge(array, start, middle, end);
        }
    }

    public void merge(int[] array, int start, int middle, int end) {
        var leftSize = middle - start + 1;
        var rightSize = end - middle;

        var leftArray = Arrays.copyOfRange(array, start, middle + 1);
        var rightArray = Arrays.copyOfRange(array, middle + 1, end + 1);

        var i = 0;
        var j = 0;
        var outOfLeft = false;
        var outOfRight = false;

        for (int k = start; k < end + 1; k++) {
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

    @Benchmark
    public int[] callMergeSort(ArrayData data) {
        mergeSort(data.array, 0, data.array.length - 1);
        return data.array;
    }

    @State(Scope.Benchmark)
    public static class ArrayData {
        @Param({"8"})
        int count;

        int min = 1;
        int max = 100;
        int[] array;

        @Setup
        public void setup() {
            Random random = new Random(42);
            array = random.ints(min, max + 1)
                    .distinct().limit(count)
                    .toArray();
        }
    }
}
