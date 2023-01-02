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
class DepthFirstSearch3Test {
    DepthFirstSearch3.Vertex vertexU;
    DepthFirstSearch3.Vertex vertexV;
    DepthFirstSearch3.Vertex vertexW;
    DepthFirstSearch3.Vertex vertexX;
    DepthFirstSearch3.Vertex vertexY;
    DepthFirstSearch3.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        vertexU = new DepthFirstSearch3.Vertex("u");
        vertexV = new DepthFirstSearch3.Vertex("v");
        vertexW = new DepthFirstSearch3.Vertex("w");
        vertexX = new DepthFirstSearch3.Vertex("x");
        vertexY = new DepthFirstSearch3.Vertex("y");
        vertexZ = new DepthFirstSearch3.Vertex("z");
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
    void testDepthFirstSearch() {
        assertEquals(vertexY, DepthFirstSearch3.performDepthFirstSearch(vertexU, vertexY));
        assertEquals(2, DepthFirstSearch3.getShortestDistance(vertexY));
    }
}
