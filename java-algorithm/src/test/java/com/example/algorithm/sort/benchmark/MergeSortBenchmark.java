package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.MergeSort;
import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@State(Scope.Thread)
@OutputTimeUnit(TimeUnit.NANOSECONDS)
@Fork(1)
@Warmup(iterations = 1)
@Measurement(iterations = 1)
public class MergeSortBenchmark {
    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(MergeSortBenchmark.class.getSimpleName())
                .build();
        new Runner(options).run();
    }

    @Setup
    public void setUp() {
    }

    @TearDown(Level.Invocation)
    public void tearDown() {
        System.gc();
    }

    @Benchmark
    public void testMergeSort1() {
        var array = new int[]{64, 32, 16, 8, 4};
        MergeSort.mergeSort(array, 0, array.length - 1);
    }
}
