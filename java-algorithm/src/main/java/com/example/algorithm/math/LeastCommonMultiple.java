package com.example.algorithm.math;

public class LeastCommonMultiple {
    public static int lcm(int a, int b) {
        return a * b / GreatestCommonDivisor.gcd(a, b);
    }
}
