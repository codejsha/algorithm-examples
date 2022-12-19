package com.example.algorithm.graph;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

@ExtendWith(MockitoExtension.class)
@Slf4j
class KruskalTest {
    Kruskal.Graph graph;
    Kruskal.Vertex vertexA, vertexB, vertexC, vertexD, vertexE, vertexF, vertexG, vertexH, vertexI;
    Kruskal.Edge edgeAB, edgeAH, edgeBC, edgeBH, edgeCD, edgeCF, edgeCI, edgeDE, edgeDF, edgeEF, edgeFG, edgeGH, edgeGI, edgeHI;

    @BeforeEach
    void setUp() {
        graph = new Kruskal.Graph();
        vertexA = new Kruskal.Vertex('a');
        vertexB = new Kruskal.Vertex('b');
        vertexC = new Kruskal.Vertex('c');
        vertexD = new Kruskal.Vertex('d');
        vertexE = new Kruskal.Vertex('e');
        vertexF = new Kruskal.Vertex('f');
        vertexG = new Kruskal.Vertex('g');
        vertexH = new Kruskal.Vertex('h');
        vertexI = new Kruskal.Vertex('i');
        graph.addVertex(vertexA);
        graph.addVertex(vertexB);
        graph.addVertex(vertexC);
        graph.addVertex(vertexD);
        graph.addVertex(vertexE);
        graph.addVertex(vertexF);
        graph.addVertex(vertexG);
        graph.addVertex(vertexH);
        graph.addVertex(vertexI);
        edgeAB = new Kruskal.Edge(vertexA, vertexB, 4);
        edgeAH = new Kruskal.Edge(vertexA, vertexH, 8);
        edgeBC = new Kruskal.Edge(vertexB, vertexC, 8);
        edgeBH = new Kruskal.Edge(vertexB, vertexH, 11);
        edgeCD = new Kruskal.Edge(vertexC, vertexD, 7);
        edgeCF = new Kruskal.Edge(vertexC, vertexF, 4);
        edgeCI = new Kruskal.Edge(vertexC, vertexI, 2);
        edgeDE = new Kruskal.Edge(vertexD, vertexE, 9);
        edgeDF = new Kruskal.Edge(vertexD, vertexF, 14);
        edgeEF = new Kruskal.Edge(vertexE, vertexF, 10);
        edgeFG = new Kruskal.Edge(vertexF, vertexG, 2);
        edgeGH = new Kruskal.Edge(vertexG, vertexH, 1);
        edgeGI = new Kruskal.Edge(vertexG, vertexI, 6);
        edgeHI = new Kruskal.Edge(vertexH, vertexI, 7);
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
    void testKruskalAlgorithmForSorted() {
        var expected = new Kruskal.Edge[]{edgeGH, edgeCI, edgeFG, edgeAB, edgeCF, edgeCD, edgeAH, edgeDE};
        var actual = Kruskal.kruskalAlgorithmSorted(graph).edges.toArray(Kruskal.Edge[]::new);
        assertArrayEquals(expected, actual);
    }

    @Test
    void testKruskalAlgorithmForSortedArray() {
        var expected = new Kruskal.Edge[]{edgeGH, edgeCI, edgeFG, edgeAB, edgeCF, edgeCD, edgeAH, edgeDE};
        var actual = Kruskal.kruskalAlgorithmEdge(graph);
        assertArrayEquals(expected, actual);
    }
}
