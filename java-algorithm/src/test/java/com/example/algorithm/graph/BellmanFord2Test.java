package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class BellmanFord2Test {
    BellmanFord2.Graph graph = new BellmanFord2.Graph();
    BellmanFord2.Vertex vertexS;
    BellmanFord2.Vertex vertexT;
    BellmanFord2.Vertex vertexX;
    BellmanFord2.Vertex vertexY;
    BellmanFord2.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        vertexS = new BellmanFord2.Vertex("S");
        vertexT = new BellmanFord2.Vertex("T");
        vertexX = new BellmanFord2.Vertex("X");
        vertexY = new BellmanFord2.Vertex("Y");
        vertexZ = new BellmanFord2.Vertex("Z");
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
    void testBellmanFordAlgorithm() {
        BellmanFord2.bellmanFordAlgorithm(graph, vertexS);
        BellmanFord2.printAllPaths(graph);
        BellmanFord2.Vertex[] pathT = BellmanFord2.shortestPath(vertexT);
        BellmanFord2.Vertex[] pathX = BellmanFord2.shortestPath(vertexX);
        BellmanFord2.Vertex[] pathY = BellmanFord2.shortestPath(vertexY);
        BellmanFord2.Vertex[] pathZ = BellmanFord2.shortestPath(vertexZ);

        assertEquals(4, pathT.length);
        assertEquals(3, pathX.length);
        assertEquals(2, pathY.length);
        assertEquals(5, pathZ.length);

        assertEquals(2, BellmanFord2.shortestDistance(vertexT));
        assertEquals(4, BellmanFord2.shortestDistance(vertexX));
        assertEquals(7, BellmanFord2.shortestDistance(vertexY));
        assertEquals(-2, BellmanFord2.shortestDistance(vertexZ));
    }
}
