package com.example.demo.sort;

import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.RunnerException;
import org.openjdk.jmh.runner.options.Options;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.TimeUnit;

@BenchmarkMode(Mode.AverageTime)
@OutputTimeUnit(TimeUnit.NANOSECONDS)
@State(Scope.Thread)
@Warmup(iterations = 1)
@Measurement(iterations = 1)
public class BucketSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(BucketSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    public Double[] bucketSort(Double[] array) {
        var size = array.length;
        var bucket = new ArrayList<LinkedList<Double>>();
        for (int i = 0; i < size; i++) {
            bucket.add(new LinkedList<>());
        }

        for (Double k : array) {
            var list = bucket.get((int) Math.floor(size * k));
            list.add(k);
        }

        for (int i = 0; i < size; i++) {
            array = insertionSort(array);
        }
        return array;
    }

    public Double[] insertionSort(Double[] array) {
        for (int i = 1; i < array.length; i++) {
            var key = array[i];
            var j = i - 1;
            while ((j > -1) && (array[j] > key)) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
        return array;
    }

    @Benchmark
    public Double[] callBucketSort(ArrayData data) {
        return bucketSort(data.array);
    }

    @State(Scope.Benchmark)
    public static class ArrayData {
        @Param({"8"})
        int count;

        Double[] array;

        @Setup
        public void setup() {
            Random random = new Random(42);
            array = new Double[count];
            for (int i = 0; i < count; i++) {
                array[i] = random.nextDouble();
            }
        }
    }
}
