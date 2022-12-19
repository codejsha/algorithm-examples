package com.example.algorithm.graph;

import java.util.*;

public class Dijkstra {
    private final Set<Vertex> vertices = new HashSet<>();
    private final Map<Map<Vertex, Vertex>, Integer> edges = new HashMap<>();

    public void dijkstraAlgorithm(Vertex source) {
        source.distance = 0;
        NavigableSet<Vertex> queue = new TreeSet<>();
        queue.add(source);

        while (!queue.isEmpty()) {
            var u = queue.pollFirst();
            assert u != null;
            for (var v : u.neighbors) {
                var newDistance = u.distance + edges.get(Map.of(u, v));
                if (newDistance < v.distance) {
                    queue.remove(v);
                    v.distance = newDistance;
                    v.previous = u;
                    queue.add(v);
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
            this.distance = Integer.MAX_VALUE;
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
