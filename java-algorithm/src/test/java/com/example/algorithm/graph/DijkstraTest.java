package com.example.algorithm.graph;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

@ExtendWith(MockitoExtension.class)
@Slf4j
class DijkstraTest {
    Dijkstra.Graph graph = new Dijkstra.Graph();
    Dijkstra.Vertex vertexS;
    Dijkstra.Vertex vertexT;
    Dijkstra.Vertex vertexX;
    Dijkstra.Vertex vertexY;
    Dijkstra.Vertex vertexZ;

    @BeforeEach
    void setUp() {
        vertexS = new Dijkstra.Vertex("S");
        vertexT = new Dijkstra.Vertex("T");
        vertexX = new Dijkstra.Vertex("X");
        vertexY = new Dijkstra.Vertex("Y");
        vertexZ = new Dijkstra.Vertex("Z");
        graph.addVertex(vertexS);
        graph.addVertex(vertexT);
        graph.addVertex(vertexX);
        graph.addVertex(vertexY);
        graph.addVertex(vertexZ);
        graph.addEdge(vertexS, vertexT, 10);
        graph.addEdge(vertexS, vertexY, 5);
        graph.addEdge(vertexT, vertexX, 1);
        graph.addEdge(vertexT, vertexY, 2);
        graph.addEdge(vertexX, vertexZ, 4);
        graph.addEdge(vertexY, vertexT, 3);
        graph.addEdge(vertexY, vertexX, 9);
        graph.addEdge(vertexY, vertexZ, 2);
        graph.addEdge(vertexZ, vertexS, 7);
        graph.addEdge(vertexZ, vertexX, 6);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void testDijkstraAlgorithm() {
        Dijkstra.dijkstraAlgorithm(graph, vertexS);
        var pathT = Dijkstra.getShortestPath(vertexT);
        var pathX = Dijkstra.getShortestPath(vertexX);
        var pathY = Dijkstra.getShortestPath(vertexY);
        var pathZ = Dijkstra.getShortestPath(vertexZ);
        assertEquals(3, pathT.length);
        assertEquals(4, pathX.length);
        assertEquals(2, pathY.length);
        assertEquals(3, pathZ.length);
        assertArrayEquals(new Dijkstra.Vertex[]{vertexS, vertexY, vertexT}, pathT);
        assertArrayEquals(new Dijkstra.Vertex[]{vertexS, vertexY, vertexT, vertexX}, pathX);
        assertArrayEquals(new Dijkstra.Vertex[]{vertexS, vertexY}, pathY);
        assertArrayEquals(new Dijkstra.Vertex[]{vertexS, vertexY, vertexZ}, pathZ);
        assertEquals(8, Dijkstra.getShortestDistance(vertexT));
        assertEquals(9, Dijkstra.getShortestDistance(vertexX));
        assertEquals(5, Dijkstra.getShortestDistance(vertexY));
        assertEquals(7, Dijkstra.getShortestDistance(vertexZ));
    }
}
