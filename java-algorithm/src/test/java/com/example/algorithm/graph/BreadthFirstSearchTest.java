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
class BreadthFirstSearchTest {
    BreadthFirstSearch bfs;
    BreadthFirstSearch.Vertex vertexU;
    BreadthFirstSearch.Vertex vertexV;
    BreadthFirstSearch.Vertex vertexW;
    BreadthFirstSearch.Vertex vertexX;
    BreadthFirstSearch.Vertex vertexY;
    BreadthFirstSearch.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        bfs = new BreadthFirstSearch();
        vertexU = new BreadthFirstSearch.Vertex("u");
        vertexV = new BreadthFirstSearch.Vertex("v");
        vertexW = new BreadthFirstSearch.Vertex("w");
        vertexX = new BreadthFirstSearch.Vertex("x");
        vertexY = new BreadthFirstSearch.Vertex("y");
        vertexZ = new BreadthFirstSearch.Vertex("z");
        vertexU.addNeighbour(vertexV);
        vertexU.addNeighbour(vertexX);
        vertexV.addNeighbour(vertexY);
        vertexW.addNeighbour(vertexZ);
        vertexX.addNeighbour(vertexV);
        vertexY.addNeighbour(vertexX);
        vertexZ.addNeighbour(vertexZ);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testBreadthFirstSearch() {
        assertEquals(vertexY, bfs.breadthFirstSearch(vertexU, vertexY));
        assertEquals(2, bfs.getShortestDistance(vertexY));
    }
}
