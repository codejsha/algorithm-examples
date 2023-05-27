package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class DepthFirstSearch2Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testDepthFirstSearch() {
        var adjacencyMatrix = new int[][]{
                {0, 1, 0, 1, 0, 0},
                {0, 0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0, 1},
                {0, 1, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 1},

        };
        var shortestDistance = DepthFirstSearch2.performDepthFirstSearch(adjacencyMatrix, 0, 3);
        assertEquals(2, shortestDistance);
    }
}
