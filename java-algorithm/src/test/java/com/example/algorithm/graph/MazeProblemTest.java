package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MazeProblemTest {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testSearchMazePathCase1() {
        int[][] maze = new int[][]{
                {1, 0, 1, 1, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 0, 1},
                {0, 0, 0, 0, 1}
        };
        assertEquals(11, MazeProblem.searchMazePath(maze));
    }

    @Test
    void testSearchMazePathCase2() {
        int[][] maze = new int[][]{
                {1, 0, 1, 1, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 0, 0},
                {0, 0, 0, 0, 1}
        };
        assertEquals(-1, MazeProblem.searchMazePath(maze));
    }

    @Test
    void testSearchMazePathCase3() {
        int[][] maze = new int[][]{
                {1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {1, 1, 1, 1}
        };
        assertEquals(7, MazeProblem.searchMazePath(maze));
    }

    @Test
    void testSearchMazePathCase4() {
        int[][] maze = new int[][]{
                {1, 0, 0, 0, 0},
                {1, 1, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {0, 0, 0, 1, 0},
                {1, 1, 1, 1, 1}
        };
        assertEquals(9, MazeProblem.searchMazePath(maze));
    }
}
