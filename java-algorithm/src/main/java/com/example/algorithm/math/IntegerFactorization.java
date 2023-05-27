package com.example.algorithm.math;

import java.util.ArrayList;
import java.util.List;

public class IntegerFactorization {
    public static List<Integer> factorize(int number) {
        var factors = new ArrayList<Integer>();
        for (int i = 2; i <= number; i++) {
            while (number % i == 0) {
                factors.add(i);
                number /= i;
            }
        }
        return factors;
    }
}
