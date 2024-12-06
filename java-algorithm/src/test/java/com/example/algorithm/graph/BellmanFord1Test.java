package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

class BellmanFord1Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testBellmanFordAlgorithm() {
        int[][] edges = new int[][]{
                {0, 1},
                {0, 3},
                {1, 2},
                {1, 3},
                {1, 4},
                {2, 1},
                {3, 2},
                {3, 4},
                {4, 0},
                {4, 2}
        };
        int[] weights = new int[]{6, 7, 5, 8, -4, -2, -3, 9, 2, 7};
        int[] predecessorArray = BellmanFord1.bellmanFordAlgorithm(edges, weights, 0);
        BellmanFord1.printPath(predecessorArray, 0, 2);
        int[] shortestPath = BellmanFord1.shortestPath(predecessorArray, 0, 2);
        int shortestDistance = BellmanFord1.shortestDistance(predecessorArray, 0, 2);
        assertArrayEquals(new int[]{0, 3, 2}, shortestPath);
        assertEquals(2, shortestDistance);
    }
}
