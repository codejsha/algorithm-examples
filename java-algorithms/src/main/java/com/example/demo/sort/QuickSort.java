package com.example.demo.sort;

import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.RunnerException;
import org.openjdk.jmh.runner.options.Options;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.Random;
import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@OutputTimeUnit(TimeUnit.NANOSECONDS)
@State(Scope.Thread)
@Warmup(iterations = 1)
@Measurement(iterations = 1)
public class QuickSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(QuickSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    public void quickSort(int[] array, int low, int high) {
        if (low < high) {
            var pivot = partition(array, low, high);
            quickSort(array, low, pivot - 1);
            quickSort(array, pivot + 1, high);
        }
    }

    public int partition(int[] array, int low, int high) {
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

    private void swap(int[] array, int i, int j) {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    @Benchmark
    public int[] callQuickSort(ArrayData data) {
        quickSort(data.array, 0, data.array.length - 1);
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
