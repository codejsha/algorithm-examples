package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.HeapSort;
import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.infra.Blackhole;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@State(Scope.Thread)
@OutputTimeUnit(TimeUnit.NANOSECONDS)
@Fork(1)
@Warmup(iterations = 1)
@Measurement(iterations = 1)
public class HeapSortBenchmark {
    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(HeapSortBenchmark.class.getSimpleName())
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
    public void testHeapSort1(Blackhole blackhole) {
        var array = new int[]{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
        blackhole.consume(HeapSort.heapSort(array));
    }
}
