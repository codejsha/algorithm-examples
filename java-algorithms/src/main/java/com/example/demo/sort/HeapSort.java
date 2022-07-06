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
public class HeapSort {
    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(HeapSort.class.getSimpleName())
                .forks(1)
                .build();
        new Runner(opt).run();
    }

    public void heapSort(int[] array) {
        var heapSize = array.length;

        buildMaxHeap(array);
        for (int i = heapSize - 1; i > 0; i--) {
            swap(array, 0, i);
            heapSize--;
            maxHeapfify(array, heapSize, 0);
        }
    }

    public void buildMaxHeap(int[] array) {
        var heapSize = array.length;
        var loopIndex = Math.subtractExact(Math.floorDiv(heapSize, 2), 1);

        for (int i = loopIndex; i > -1; i--) {
            maxHeapfify(array, heapSize, i);
        }
    }

    public void maxHeapfify(int[] array, int heapSize, int index) {
        var largest = index;
        var leftIndex = 2 * index + 1; // 2n + 1
        var rightIndex = 2 * index + 2; // 2n + 2

        if ((leftIndex < heapSize) && (array[largest] < array[leftIndex])) {
            largest = leftIndex;
        }
        if ((rightIndex < heapSize) && (array[largest] < array[rightIndex])) {
            largest = rightIndex;
        }
        if (largest != index) {
            swap(array, index, largest);
            maxHeapfify(array, heapSize, largest);
        }
    }

    private void swap(int[] array, int i, int j) {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    @Benchmark
    public int[] callHeapSort(ArrayData data) {
        heapSort(data.array);
        return data.array;
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
