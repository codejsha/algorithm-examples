package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class BreadthFirstSearch1Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testBreadthFirstSearch() {
        // edges:
        // var edges = new String[][]{
        //         {"u", "v"},
        //         {"u", "x"},
        //         {"v", "y"},
        //         {"w", "z"},
        //         {"x", "v"},
        //         {"y", "x"},
        //         {"z", "z"}
        // };
        int[][] edges = new int[][]{
                {0, 1},
                {0, 3},
                {1, 4},
                {2, 5},
                {3, 1},
                {4, 3},
                {5, 5}
        };
        int distance = BreadthFirstSearch1.breadthFirstSearch(edges, 0, 4);
        assertEquals(2, distance);
    }

    @Test
    void testBreadthFirstSearchPreProcessingVersion() {
        // edges:
        // var edges = new String[][]{
        //         {"u", "v"},
        //         {"u", "x"},
        //         {"v", "y"},
        //         {"w", "z"},
        //         {"x", "v"},
        //         {"y", "x"},
        //         {"z", "z"}
        // };
        int[][] edges = new int[][]{
                {0, 1},
                {0, 3},
                {1, 4},
                {2, 5},
                {3, 1},
                {4, 3},
                {5, 5}
        };
        int distance = BreadthFirstSearch1.breadthFirstSearchPreProcessingVersion(edges, 0, 4);
        assertEquals(2, distance);
    }
}
