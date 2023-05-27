package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class FloydWarshallTest {
    static final int INF = 99999;

    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testFloydWarshall() {
        var matrix = new int[][]{
                {0, 3, 8, INF, -4},
                {INF, 0, INF, 1, 7},
                {INF, 4, 0, INF, INF},
                {2, INF, -5, 0, INF},
                {INF, INF, INF, 6, 0}
        };
        var expected = new int[][]{
                {0, 1, -3, 2, -4},
                {3, 0, -4, 1, -1},
                {7, 4, 0, 5, 3},
                {2, -1, -5, 0, -2},
                {8, 5, 1, 6, 0},
        };
        assertArrayEquals(expected, FloydWarshall.floydWarshall(matrix));
    }

    @Test
    void testFloydWarshallPositiveWeight() {
        var matrix = new int[][]{
                {0, 3, INF, 5},
                {2, 0, INF, 4},
                {INF, 1, 0, INF},
                {INF, INF, 2, 0}
        };
        var expected = new int[][]{
                {0, 3, 7, 5},
                {2, 0, 6, 4},
                {3, 1, 0, 5},
                {5, 3, 2, 0}
        };
        assertArrayEquals(expected, FloydWarshall.floydWarshallPositiveWeight(matrix));
    }
}
