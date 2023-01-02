package com.example.algorithm.graph;

import java.util.*;

/**
 * Bellman-Ford algorithm (class representation)
 */
public class BellmanFord2 {
    public static void bellmanFordAlgorithm(Graph graph, Vertex source) {
        source.distance = 0;
        for (var i = 0; i < graph.vertices.size() - 1; i++) {
            for (var edge : graph.edges.keySet()) {
                var u = edge.keySet().iterator().next();
                var v = edge.values().iterator().next();
                var newDistance = u.distance + graph.edges.get(edge);
                if (u.distance != Integer.MAX_VALUE && newDistance < v.distance) {
                    v.distance = newDistance;
                    v.previous = u;
                }
            }
        }
    }

    public static Vertex[] shortestPath(Vertex dest) {
        var path = new ArrayList<Vertex>();
        for (var vertex = dest; vertex != null; vertex = vertex.previous) {
            path.add(vertex);
        }
        Collections.reverse(path);
        return path.toArray(Vertex[]::new);
    }

    public static int shortestDistance(Vertex dest) {
        return dest.distance;
    }

    public static void printPath(Vertex dest) {
        if (dest.previous != null) {
            printPath(dest.previous);
            System.out.print(" -> ");
        }
        System.out.print(dest.key);
    }

    public static void printAllPaths(Graph graph) {
        for (var v : graph.vertices) {
            printPath(v);
            System.out.println();
        }
    }


    public static class Graph {
        Set<Vertex> vertices = new HashSet<>();
        Map<Map<Vertex, Vertex>, Integer> edges = new HashMap<>();

        public void addVertex(Vertex vertex) {
            vertices.add(vertex);
        }

        public void addEdge(Vertex source, Vertex sink, int weight) {
            source.addNeighbour(sink);
            edges.put(Map.of(source, sink), weight);
        }
    }

    public static class Vertex implements Comparable<Vertex> {
        String key;
        int distance;
        Vertex previous;
        NavigableSet<Vertex> neighbors = new TreeSet<>();

        public Vertex(String key) {
            this.key = key;
            this.distance = Integer.MAX_VALUE;
            this.previous = null;
        }

        void addNeighbour(Vertex vertex) {
            neighbors.add(vertex);
        }

        @Override
        public int compareTo(Vertex other) {
            if (distance == other.distance) {
                return key.compareTo(other.key);
            }
            return Integer.compare(distance, other.distance);
        }
    }
}
