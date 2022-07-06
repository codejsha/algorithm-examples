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
public class SelectionSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(InsertionSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    @Benchmark
    public int[] selectionSort(ArrayData data) {
        var array = data.array;

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

    private void swap(int[] array, int i, int j) {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
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
