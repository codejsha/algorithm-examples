package com.example.algorithm.graph;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class PrimTest {
    Prim.Graph graph;
    Prim.Vertex vertexA, vertexB, vertexC, vertexD, vertexE, vertexF, vertexG, vertexH, vertexI;
    Prim.Edge edgeAB, edgeAH, edgeBC, edgeBH, edgeCD, edgeCF, edgeCI, edgeDE, edgeDF, edgeEF, edgeFG, edgeGH, edgeGI, edgeHI;

    @BeforeEach
    void setUp() {
        graph = new Prim.Graph();
        vertexA = new Prim.Vertex('a');
        vertexB = new Prim.Vertex('b');
        vertexC = new Prim.Vertex('c');
        vertexD = new Prim.Vertex('d');
        vertexE = new Prim.Vertex('e');
        vertexF = new Prim.Vertex('f');
        vertexG = new Prim.Vertex('g');
        vertexH = new Prim.Vertex('h');
        vertexI = new Prim.Vertex('i');
        graph.addVertex(vertexA);
        graph.addVertex(vertexB);
        graph.addVertex(vertexC);
        graph.addVertex(vertexD);
        graph.addVertex(vertexE);
        graph.addVertex(vertexF);
        graph.addVertex(vertexG);
        graph.addVertex(vertexH);
        graph.addVertex(vertexI);
        edgeAB = new Prim.Edge(vertexA, vertexB, 4);
        edgeAH = new Prim.Edge(vertexA, vertexH, 8);
        edgeBC = new Prim.Edge(vertexB, vertexC, 8);
        edgeBH = new Prim.Edge(vertexB, vertexH, 11);
        edgeCD = new Prim.Edge(vertexC, vertexD, 7);
        edgeCF = new Prim.Edge(vertexC, vertexF, 4);
        edgeCI = new Prim.Edge(vertexC, vertexI, 2);
        edgeDE = new Prim.Edge(vertexD, vertexE, 9);
        edgeDF = new Prim.Edge(vertexD, vertexF, 14);
        edgeEF = new Prim.Edge(vertexE, vertexF, 10);
        edgeFG = new Prim.Edge(vertexF, vertexG, 2);
        edgeGH = new Prim.Edge(vertexG, vertexH, 1);
        edgeGI = new Prim.Edge(vertexG, vertexI, 6);
        edgeHI = new Prim.Edge(vertexH, vertexI, 7);
        graph.addEdge(edgeAB);
        graph.addEdge(edgeAH);
        graph.addEdge(edgeBC);
        graph.addEdge(edgeBH);
        graph.addEdge(edgeCD);
        graph.addEdge(edgeCF);
        graph.addEdge(edgeCI);
        graph.addEdge(edgeDE);
        graph.addEdge(edgeDF);
        graph.addEdge(edgeEF);
        graph.addEdge(edgeFG);
        graph.addEdge(edgeGH);
        graph.addEdge(edgeGI);
        graph.addEdge(edgeHI);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void primAlgorithmVertex() {
        var expected = new Prim.Vertex[]{vertexA, vertexB, vertexC, vertexI, vertexF, vertexG, vertexH, vertexD, vertexE};
        var actual = Prim.primAlgorithmVertex(graph, vertexA);
        assertArrayEquals(expected, actual);
    }

    @Test
    void primAlgorithmEdge() {
        var expected = new Prim.Edge[]{edgeAB, edgeBC, edgeCI, edgeCF, edgeFG, edgeGH, edgeCD, edgeDE};
        var actual = Prim.primAlgorithmEdge(graph, vertexA);
        assertArrayEquals(expected, actual);
    }
}
