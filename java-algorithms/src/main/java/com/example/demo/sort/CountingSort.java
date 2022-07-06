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
public class CountingSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(CountingSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    @Benchmark
    public int[] countingSort(ArrayData data) {
        var array = data.array;
        var size = array.length;
        var output = new int[size];

        var max = 0;
        var OptionalMax = Arrays.stream(array).max();
        if (OptionalMax.isPresent()) {
            max = OptionalMax.getAsInt();
        }
        var count = new int[max + 1];
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
