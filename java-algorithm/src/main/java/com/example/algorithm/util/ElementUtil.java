package com.example.algorithm.util;

public class ElementUtil {
    public static void swap(int[] array, int i, int j) {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
