package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class DepthFirstSearch1Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testDepthFirstSearch() {
        String[][] edges = new String[][]{
                {"u", "v"},
                {"u", "x"},
                {"v", "y"},
                {"w", "z"},
                {"x", "v"},
                {"y", "x"},
                {"z", "z"}
        };
        String[] path = DepthFirstSearch1.performDepthFirstSearch(edges, "u", "y");
        assertArrayEquals(new String[]{"u", "v", "y"}, path);
    }
}
