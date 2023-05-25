package com.example.algorithm.sort;

import java.util.Arrays;

public class SalaryThreshold {
    /**
     * Find the salary threshold to meet the target.
     * Given the salary array and budget, calculate the salary cap so that the total salary is equal to the budget.
     *
     * @param salaries salary array of employees
     * @param target   budget
     * @return salary threshold
     */
    public static int computeSalaryThreshold(Integer[] salaries, Integer target) {
        var currentSalaries = Arrays.stream(salaries).sorted().toArray(Integer[]::new);

        // total salary threshold
        var sum = 0;
        for (Integer salary : salaries) {
            sum += salary;
        }

        // check if salary threshold is less than target
        if (sum < target) {
            return -1;
        }

        // compute salary threshold
        var unadjustedSum = 0;
        for (var i = 0; i < salaries.length; i++) {
            var adjustedPeople = salaries.length - i;
            var adjustedSum = currentSalaries[i] * adjustedPeople;
            if (unadjustedSum + adjustedSum >= target) {
                return (target - unadjustedSum) / adjustedPeople;
            }
            unadjustedSum += currentSalaries[i];
        }
        return -1;
    }
}
