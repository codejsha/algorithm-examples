package com.example.algorithm.graph;

import java.util.*;

public class Kruskal {
    /**
     * Kruskal's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The minimum spanning tree of the graph.
     */
    public static Graph kruskalAlgorithm(Graph graph) {
        var mst = new Graph();
        var queue = new PriorityQueue<Edge>();
        queue.addAll(graph.edges);
        while (!queue.isEmpty()) {
            var edge = queue.poll();
            var u = edge.source;
            var v = edge.sink;
            if (findSet(u) != findSet(v)) {
                mst.addEdge(edge);
                union(u, v);
            }
        }
        return mst;
    }

    /**
     * Kruskal's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The minimum spanning tree of the graph.
     */
    public static Graph kruskalAlgorithmSorted(Graph graph) {
        var mst = new Graph();
        var sortedEdges = new ArrayList<>(graph.edges);
        sortedEdges.sort(Comparator.comparing(Edge::getWeight)
                .thenComparing(Edge::getSource).thenComparing(Edge::getSink));
        for (var edge : sortedEdges) {
            var u = edge.source;
            var v = edge.sink;
            if (findSet(u) != findSet(v)) {
                mst.addEdge(edge);
                union(u, v);
            }
        }
        return mst;
    }

    /**
     * Kruskal's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The edges of the minimum spanning tree of the graph.
     */
    public static Edge[] kruskalAlgorithmEdge(Graph graph) {
        var mst = new Edge[graph.vertices.size() - 1];
        var i = 0;
        var sortedEdges = new ArrayList<>(graph.edges);
        sortedEdges.sort(Comparator.comparing(Edge::getWeight)
                .thenComparing(Edge::getSource).thenComparing(Edge::getSink));
        for (var edge : sortedEdges) {
            var u = edge.source;
            var v = edge.sink;
            if (findSet(u) != findSet(v)) {
                mst[i++] = edge;
                union(u, v);
            }
        }
        return mst;
    }

    /**
     * Find the representative of the set containing the vertex.
     * Path compression is used to improve the performance.
     * @param vertex the vertex
     * @return the representative of the set
     */
    private static Vertex findSet(Vertex vertex) {
        if (vertex != vertex.parent) {
            vertex.parent = findSet(vertex.parent);
        }
        return vertex.parent;
    }

    /**
     * Union two sets containing the vertices.
     * Union by rank is used to improve the performance.
     * @param u the vertex of the first set
     * @param v the vertex of the second set
     */
    private static void union(Vertex u, Vertex v) {
        var uParent = findSet(u);
        var vParent = findSet(v);
        if (uParent.rank > vParent.rank) {
            vParent.parent = uParent;
        } else if (uParent.rank < vParent.rank) {
            uParent.parent = vParent;
        } else {
            vParent.parent = uParent;
            uParent.rank++;
        }
    }

    public static class Graph {
        Set<Vertex> vertices = new HashSet<>();
        Set<Edge> edges = new LinkedHashSet<>();

        public void addVertex(Vertex vertex) {
            vertices.add(vertex);
        }

        public void addEdge(Edge edge) {
            edges.add(edge);
        }
    }

    public static class Vertex implements Comparable<Vertex> {
        char key;
        Vertex parent;
        int rank;

        public Vertex(char key) {
            this.key = key;
            this.parent = this;
            this.rank = 0;
        }

        @Override
        public int compareTo(Vertex other) {
            return Integer.compare(key, other.key);
        }
    }

    public static class Edge implements Comparable<Edge> {
        Vertex source;
        Vertex sink;
        int weight;

        public Edge(Vertex source, Vertex sink, int weight) {
            this.source = source;
            this.sink = sink;
            this.weight = weight;
        }

        Vertex getSource() {
            return source;
        }

        Vertex getSink() {
            return sink;
        }

        int getWeight() {
            return weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(weight, other.weight);
        }
    }
}
