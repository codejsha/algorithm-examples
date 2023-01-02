package com.example.algorithm.graph;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertEquals;

@ExtendWith(MockitoExtension.class)
@Slf4j
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
        var edges = new int[][]{
                {0, 1},
                {0, 3},
                {1, 4},
                {2, 5},
                {3, 1},
                {4, 3},
                {5, 5}
        };
        var distance = BreadthFirstSearch1.breadthFirstSearch(edges, 0, 4);
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
        var edges = new int[][]{
                {0, 1},
                {0, 3},
                {1, 4},
                {2, 5},
                {3, 1},
                {4, 3},
                {5, 5}
        };
        var distance = BreadthFirstSearch1.breadthFirstSearchPreProcessingVersion(edges, 0, 4);
        assertEquals(2, distance);
    }
}
