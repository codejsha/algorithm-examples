package com.example.algorithm.sort.benchmark;

import com.example.algorithm.sort.BucketSort;
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
public class BucketSortBenchmarkTest {
    public BucketSort bucketSort;

    public static void main(String[] args) throws Exception {
        var options = new OptionsBuilder()
                .include(BucketSortBenchmarkTest.class.getSimpleName())
                .build();
        new Runner(options).run();
    }

    @Setup
    public void setUp() {
        bucketSort = new BucketSort();
    }

    @TearDown(Level.Invocation)
    public void tearDown() {
        System.gc();
    }

    @Benchmark
    public void testBucketSort1(Blackhole blackhole) {
        var array = new Double[]{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
        blackhole.consume(bucketSort.bucketSort(array));
    }
}
