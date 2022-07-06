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
public class RadixSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(RadixSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    @Benchmark
    public int[] radixSort(ArrayData data) {
        var array = data.array;
        var size = array.length;
        var output = new int[size];

        var max = 0;
        var optionalMax = Arrays.stream(array).max();
        if (optionalMax.isPresent()) {
            max = optionalMax.getAsInt();
        }

        for (int position = 1; max / position > 0; position *= 10) {
            output = countingSort(array, size, position);
        }
        return output;
    }

    private int[] countingSort(int[] array, int size, int position) {
        var output = new int[size];
        var max = 9;
        var count = new int[max + 1];
        Arrays.fill(count, 0);

        for (int k : array) {
            count[(k / position) % 10]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[(array[i] / position) % 10] - 1] = array[i];
            count[(array[i] / position) % 10]--;
        }

        return output;
    }

    @State(Scope.Benchmark)
    public static class ArrayData {
        @Param({"8"})
        int count;

        int min = 100;
        int max = 999;
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
