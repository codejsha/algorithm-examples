package com.example.algorithm.graph;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
@Slf4j
class DepthFirstSearch1Test {
    @BeforeEach
    void setUp() {
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testDepthFirstSearch() {
        var edges = new String[][]{
                {"u", "v"},
                {"u", "x"},
                {"v", "y"},
                {"w", "z"},
                {"x", "v"},
                {"y", "x"},
                {"z", "z"}
        };
        var path = DepthFirstSearch1.performDepthFirstSearch(edges, "u", "y");
        assertArrayEquals(new String[]{"u", "v", "y"}, path);
    }
}
