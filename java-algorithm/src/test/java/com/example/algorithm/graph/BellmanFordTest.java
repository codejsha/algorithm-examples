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
class BellmanFordTest {
    BellmanFord graph = new BellmanFord();
    BellmanFord.Vertex vertexS;
    BellmanFord.Vertex vertexT;
    BellmanFord.Vertex vertexX;
    BellmanFord.Vertex vertexY;
    BellmanFord.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        vertexS = new BellmanFord.Vertex("S");
        vertexT = new BellmanFord.Vertex("T");
        vertexX = new BellmanFord.Vertex("X");
        vertexY = new BellmanFord.Vertex("Y");
        vertexZ = new BellmanFord.Vertex("Z");
        graph.addVertex(vertexS);
        graph.addVertex(vertexT);
        graph.addVertex(vertexX);
        graph.addVertex(vertexY);
        graph.addVertex(vertexZ);
        graph.addEdge(vertexS, vertexT, 6);
        graph.addEdge(vertexS, vertexY, 7);
        graph.addEdge(vertexT, vertexX, 5);
        graph.addEdge(vertexT, vertexY, 8);
        graph.addEdge(vertexT, vertexZ, -4);
        graph.addEdge(vertexX, vertexT, -2);
        graph.addEdge(vertexY, vertexX, -3);
        graph.addEdge(vertexY, vertexZ, 9);
        graph.addEdge(vertexZ, vertexS, 2);
        graph.addEdge(vertexZ, vertexX, 7);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testGetShortestPath() {
        graph.bellmanFordAlgorithm(vertexS);
        graph.printAllPaths();
        var pathT = graph.getShortestPath(vertexT);
        var pathX = graph.getShortestPath(vertexX);
        var pathY = graph.getShortestPath(vertexY);
        var pathZ = graph.getShortestPath(vertexZ);
        assertEquals(4, pathT.length);
        assertEquals(3, pathX.length);
        assertEquals(2, pathY.length);
        assertEquals(5, pathZ.length);
    }

    @Test
    void testGetShortestDistance() {
        graph.bellmanFordAlgorithm(vertexS);
        assertEquals(2, graph.getShortestDistance(vertexT));
        assertEquals(4, graph.getShortestDistance(vertexX));
        assertEquals(7, graph.getShortestDistance(vertexY));
        assertEquals(-2, graph.getShortestDistance(vertexZ));
    }
}
