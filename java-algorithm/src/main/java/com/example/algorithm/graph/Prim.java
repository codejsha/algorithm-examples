package com.example.algorithm.graph;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.PriorityQueue;
import java.util.Set;

/**
 * Prim's algorithm (class representation)
 */
public class Prim {
    /**
     * Prim's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The minimum spanning tree of the graph.
     */
    public static Graph primAlgorithm(Graph graph) {
        var mst = new Graph();
        var queue = new PriorityQueue<Edge>();
        var visited = new HashSet<Vertex>();
        var start = graph.vertices.iterator().next();
        mst.addVertex(start);
        visited.add(start);
        queue.addAll(start.edges);
        while (!queue.isEmpty()) {
            var edge = queue.poll();
            var u = edge.source;
            var v = edge.sink;
            if (visited.contains(u) && visited.contains(v)) {
                continue;
            }
            mst.addEdge(edge);
            if (!visited.contains(u)) {
                visited.add(u);
                queue.addAll(u.edges);
            }
            if (!visited.contains(v)) {
                visited.add(v);
                queue.addAll(v.edges);
            }
        }
        return mst;
    }

    /**
     * Prim's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The vertices of the minimum spanning tree of the graph.
     */
    public static Vertex[] primAlgorithmVertex(Graph graph, Vertex start) {
        var queue = new PriorityQueue<Edge>();
        var visited = new LinkedHashSet<Vertex>();
        visited.add(start);
        queue.addAll(start.edges);
        while (!queue.isEmpty()) {
            var edge = queue.poll();
            var u = edge.source;
            var v = edge.sink;
            if (visited.contains(u) && visited.contains(v)) {
                continue;
            }
            if (!visited.contains(u)) {
                visited.add(u);
                queue.addAll(u.edges);
            }
            if (!visited.contains(v)) {
                visited.add(v);
                queue.addAll(v.edges);
            }
        }
        return visited.toArray(Vertex[]::new);
    }

    /**
     * Prim's algorithm for finding the minimum spanning tree of a graph.
     * <p>
     * Time complexity: O(E log V)
     * @param graph The graph to find the minimum spanning tree of.
     * @return The edges of the minimum spanning tree of the graph.
     */
    public static Edge[] primAlgorithmEdge(Graph graph, Vertex start) {
        var mst = new LinkedHashSet<Edge>();
        var queue = new PriorityQueue<Edge>();
        var visited = new HashSet<Vertex>();
        visited.add(start);
        queue.addAll(start.edges);
        while (!queue.isEmpty()) {
            var edge = queue.poll();
            var u = edge.source;
            var v = edge.sink;
            if (visited.contains(u) && visited.contains(v)) {
                continue;
            }
            mst.add(edge);
            if (!visited.contains(u)) {
                visited.add(u);
                queue.addAll(u.edges);
            }
            if (!visited.contains(v)) {
                visited.add(v);
                queue.addAll(v.edges);
            }
        }
        return mst.toArray(Edge[]::new);
    }

    public static class Graph {
        Set<Vertex> vertices = new HashSet<>();
        Set<Edge> edges = new HashSet<>();

        public void addVertex(Vertex vertex) {
            vertices.add(vertex);
        }

        public void addEdge(Edge edge) {
            edges.add(edge);
            edge.source.edges.add(edge);
            edge.sink.edges.add(edge);
        }
    }

    public static class Vertex {
        char key;
        Set<Edge> edges = new HashSet<>();

        public Vertex(char key) {
            this.key = key;
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

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(weight, other.weight);
        }
    }
}
