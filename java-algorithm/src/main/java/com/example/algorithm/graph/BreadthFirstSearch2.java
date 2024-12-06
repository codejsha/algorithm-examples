package com.example.algorithm.graph;

import java.util.*;

/**
 * Breadth First Search (class representation)
 */
public class BreadthFirstSearch2 {
    public static Vertex breadthFirstSearch(Vertex source, Vertex dest) {
        source.visited = true;
        source.distance = 0;
        var queue = new ArrayDeque<Vertex>();
        queue.add(source);
        while (!queue.isEmpty()) {
            Vertex u = queue.poll();
            if (u == dest) {
                return u;
            }
            for (Vertex v : u.neighbors) {
                if (!v.visited) {
                    v.visited = true;
                    v.distance = u.distance + 1;
                    v.previous = u;
                    queue.add(v);
                }
            }
        }
        return null;
    }

    public static Vertex[] getShortestPath(Vertex dest) {
        var path = new ArrayList<Vertex>();
        for (Vertex vertex = dest; vertex != null; vertex = vertex.previous) {
            path.add(vertex);
        }
        Collections.reverse(path);
        return path.toArray(Vertex[]::new);
    }

    public static int getShortestDistance(Vertex dest) {
        return dest.distance;
    }

    public static void printPath(Vertex dest) {
        if (dest.previous != null) {
            printPath(dest.previous);
            System.out.print(" -> ");
        }
        System.out.print(dest.key);
    }

    public static class Vertex implements Comparable<Vertex> {
        String key;
        int distance;
        boolean visited;
        Vertex previous;
        NavigableSet<Vertex> neighbors = new TreeSet<>();

        public Vertex(String key) {
            this.key = key;
            this.distance = Integer.MAX_VALUE;
            this.visited = false;
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
