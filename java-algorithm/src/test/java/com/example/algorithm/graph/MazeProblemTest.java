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
class MazeProblemTest {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testSearchMazePathCase1() {
        var maze = new int[][]{
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
        var maze = new int[][]{
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
        var maze = new int [][] {
                {1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {1, 1, 1, 1}
        };
        assertEquals(7, MazeProblem.searchMazePath(maze));
    }

    @Test
    void testSearchMazePathCase4() {
        var maze = new int [][] {
                {1, 0, 0, 0, 0},
                {1, 1, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {0, 0, 0, 1, 0},
                {1, 1, 1, 1, 1}
        };
        assertEquals(9, MazeProblem.searchMazePath(maze));
    }
}
