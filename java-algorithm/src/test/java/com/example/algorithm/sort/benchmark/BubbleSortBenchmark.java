package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.BubbleSort;
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
public class BubbleSortBenchmark {
    public BubbleSort bubbleSort;

    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(BubbleSortBenchmark.class.getSimpleName())
                .build();
        new Runner(options).run();
    }

    @Setup
    public void setUp() {
        bubbleSort = new BubbleSort();
    }

    @TearDown(Level.Invocation)
    public void tearDown() {
        System.gc();
    }

    @Benchmark
    public void testBubbleSort1(Blackhole blackhole) {
        var array = new int[]{31, 64, 49, 85, 71, 26, 6, 19};
        blackhole.consume(bubbleSort.bubbleSort(array));
    }

    @Benchmark
    public void testBubbleSort2(Blackhole blackhole) {
        var array = new int[]{31, 64, 49, 85, 71, 26, 6, 19, 31, 64, 49, 85, 71, 26, 6, 19};
        blackhole.consume(bubbleSort.bubbleSort(array));
    }
}
