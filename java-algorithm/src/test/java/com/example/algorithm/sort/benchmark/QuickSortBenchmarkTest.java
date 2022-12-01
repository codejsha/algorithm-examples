package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.QuickSort;
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
public class QuickSortBenchmarkTest {
    public QuickSort quickSort;

    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(QuickSortBenchmarkTest.class.getSimpleName())
                .build();
        new Runner(options).run();
    }

    @Setup
    public void setUp() {
        quickSort = new QuickSort();
    }

    @TearDown(Level.Invocation)
    public void tearDown() {
        System.gc();
    }

    @Benchmark
    public void testQuickSort1() {
        var array = new int[]{2, 8, 7, 1, 3, 5, 6, 4};
        quickSort.quickSort(array, 0, array.length - 1);
    }
}
