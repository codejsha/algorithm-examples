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
class BreadthFirstSearch2Test {
    BreadthFirstSearch2.Vertex vertexU;
    BreadthFirstSearch2.Vertex vertexV;
    BreadthFirstSearch2.Vertex vertexW;
    BreadthFirstSearch2.Vertex vertexX;
    BreadthFirstSearch2.Vertex vertexY;
    BreadthFirstSearch2.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        vertexU = new BreadthFirstSearch2.Vertex("u");
        vertexV = new BreadthFirstSearch2.Vertex("v");
        vertexW = new BreadthFirstSearch2.Vertex("w");
        vertexX = new BreadthFirstSearch2.Vertex("x");
        vertexY = new BreadthFirstSearch2.Vertex("y");
        vertexZ = new BreadthFirstSearch2.Vertex("z");
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
        assertEquals(vertexY, BreadthFirstSearch2.breadthFirstSearch(vertexU, vertexY));
        assertEquals(2, BreadthFirstSearch2.getShortestDistance(vertexY));
    }
}
