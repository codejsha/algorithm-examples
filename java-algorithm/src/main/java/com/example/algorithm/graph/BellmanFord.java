package com.example.algorithm.graph;

import java.util.*;

public class BellmanFord {
    private final Set<Vertex> vertices = new HashSet<>();
    private final Map<Map<Vertex, Vertex>, Integer> edges = new HashMap<>();

    public void bellmanFordAlgorithm(Vertex source) {
        source.distance = 0;
        for (var i = 0; i < vertices.size() - 1; i++) {
            for (var edge : edges.keySet()) {
                var u = edge.keySet().iterator().next();
                var v = edge.values().iterator().next();
                var newDistance = u.distance + edges.get(edge);
                if (newDistance < v.distance) {
                    v.distance = newDistance;
                    v.previous = u;
                }
            }
        }
    }

    public Vertex[] getShortestPath(Vertex dest) {
        var path = new ArrayList<Vertex>();
        for (var vertex = dest; vertex != null; vertex = vertex.previous) {
            path.add(vertex);
        }
        Collections.reverse(path);
        return path.toArray(Vertex[]::new);
    }

    public int getShortestDistance(Vertex dest) {
        return dest.distance;
    }

    public void printPath(Vertex dest) {
        if (dest.previous != null) {
            printPath(dest.previous);
            System.out.print(" -> ");
        }
        System.out.print(dest.key);
    }

    public void printAllPaths() {
        for (var v : vertices) {
            printPath(v);
            System.out.println();
        }
    }

    public void addVertex(Vertex vertex) {
        vertices.add(vertex);
    }

    public void addEdge(Vertex source, Vertex sink, int weight) {
        source.addNeighbour(sink);
        edges.put(Map.of(source, sink), weight);
    }

    public static class Vertex implements Comparable<Vertex> {
        public String key;
        public int distance;
        public Vertex previous;
        NavigableSet<Vertex> neighbors = new TreeSet<>();

        public Vertex(String key) {
            this.key = key;
            this.distance = 99999;
            this.previous = null;
        }

        public void addNeighbour(Vertex vertex) {
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
