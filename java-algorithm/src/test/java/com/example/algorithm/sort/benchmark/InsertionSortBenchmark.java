package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.InsertionSort;
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
public class InsertionSortBenchmark {
    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(InsertionSortBenchmark.class.getSimpleName())
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
    public void testInsertionSort1(Blackhole blackhole) {
        var array = new Integer[]{64, 32, 16, 8, 4};
        InsertionSort.insertionSort(array);
        blackhole.consume(array);
    }
}
