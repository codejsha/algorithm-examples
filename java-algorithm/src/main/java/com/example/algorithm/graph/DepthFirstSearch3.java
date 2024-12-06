package com.example.algorithm.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.NavigableSet;
import java.util.TreeSet;

/**
 * Depth First Search (class representation)
 */
public class DepthFirstSearch3 {
    public static Vertex performDepthFirstSearch(Vertex source, Vertex dest) {
        source.distance = 0;
        return depthFirstSearch(source, dest);
    }

    private static Vertex depthFirstSearch(Vertex source, Vertex dest) {
        source.visited = true;
        if (source == dest) {
            return source;
        }
        for (Vertex v : source.neighbors) {
            if (!v.visited) {
                v.previous = source;
                v.distance = source.distance + 1;
                Vertex u = depthFirstSearch(v, dest);
                if (u != null) {
                    return u;
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
