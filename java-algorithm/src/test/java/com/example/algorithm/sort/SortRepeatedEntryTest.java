package com.example.algorithm.sort;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

class SortRepeatedEntryTest {
    @Test
    void groupByAgeValidInput() {
        var people = new String[][]{
                {"Greg", "14"},
                {"John", "12"},
                {"Andy", "11"},
                {"Jim", "13"},
                {"Phil", "12"},
                {"Bob", "13"},
                {"Chip", "13"},
                {"Tim", "14"}
        };
        var expected = new String[]{
                "11", "12", "12", "13", "13", "13", "14", "14"
        };

        var result = SortRepeatedEntry.groupByAge(people);
        for (int i = 0; i < expected.length; i++) {
            assertTrue(result[i].endsWith(expected[i]));
        }
    }
}
