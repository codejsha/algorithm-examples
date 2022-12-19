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
class DepthFirstSearchTest {
    private DepthFirstSearch dfs;
    private DepthFirstSearch.Vertex vertexU;
    private DepthFirstSearch.Vertex vertexV;
    private DepthFirstSearch.Vertex vertexW;
    private DepthFirstSearch.Vertex vertexX;
    private DepthFirstSearch.Vertex vertexY;
    private DepthFirstSearch.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        dfs = new DepthFirstSearch();
        vertexU = new DepthFirstSearch.Vertex("u");
        vertexV = new DepthFirstSearch.Vertex("v");
        vertexW = new DepthFirstSearch.Vertex("w");
        vertexX = new DepthFirstSearch.Vertex("x");
        vertexY = new DepthFirstSearch.Vertex("y");
        vertexZ = new DepthFirstSearch.Vertex("z");
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
    void testDepthFirstSearchRecursiveWrapper() {
        assertEquals(vertexY, dfs.depthFirstSearchWrapper(vertexU, vertexY));
        assertEquals(2, dfs.getShortestDistance(vertexY));
    }
}
