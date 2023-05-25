package com.example.algorithm.sort;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class SortPlayerByHeightTest {
    @Test
    void sortByHeightValidInput() {
        var frontTeam = new Integer[]{5, 3, 2, 6, 1, 4};
        var backTeam = new Integer[]{2, 7, 4, 5, 3, 6};
        var expected = new Integer[]{
                1, 2, 3, 4, 5, 6,
                2, 3, 4, 5, 6, 7};

        var result = SortPlayerByHeight.sortByHeight(frontTeam, backTeam);
        assertArrayEquals(expected, result);
    }

    @Test
    void sortByHeightMergeValidInput() {
        var frontTeam = new Integer[]{5, 3, 2, 6, 1, 4};
        var backTeam = new Integer[]{2, 7, 4, 5, 3, 6};
        var expected = new Integer[]{
                1, 2, 3, 4, 5, 6,
                2, 3, 4, 5, 6, 7};

        var result = SortPlayerByHeight.sortByHeightMerge(frontTeam, backTeam);
        assertArrayEquals(expected, result);
    }
}
