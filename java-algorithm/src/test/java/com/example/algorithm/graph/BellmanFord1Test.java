package com.example.algorithm.graph;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

@ExtendWith(MockitoExtension.class)
@Slf4j
class BellmanFord1Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testBellmanFordAlgorithm() {
        var edges = new int[][]{
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
        var weights = new int[]{6, 7, 5, 8, -4, -2, -3, 9, 2, 7};
        var predecessorArray = BellmanFord1.bellmanFordAlgorithm(edges, weights, 0);
        BellmanFord1.printPath(predecessorArray, 0, 2);
        var shortestPath = BellmanFord1.shortestPath(predecessorArray, 0, 2);
        var shortestDistance = BellmanFord1.shortestDistance(predecessorArray, 0, 2);
        assertArrayEquals(new int[]{0, 3, 2}, shortestPath);
        assertEquals(2, shortestDistance);
    }
}
