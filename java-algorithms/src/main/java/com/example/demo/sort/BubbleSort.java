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
public class BubbleSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(BubbleSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    @Benchmark
    public int[] bubbleSort(ArrayData data) {
        var array =  data.array;

        for (int i = 0; i < array.length; i++) {
            for (int j = array.length - 1; j > i; j--) {
                if (array[j] < array[j - 1]) {
                    swap(array, j - 1, j);
                }
            }
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
