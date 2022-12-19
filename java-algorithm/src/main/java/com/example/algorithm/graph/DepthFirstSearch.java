package com.example.algorithm.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.NavigableSet;
import java.util.TreeSet;

public class DepthFirstSearch {
    public Vertex depthFirstSearchWrapper(Vertex source, Vertex dest) {
        source.distance = 0;
        return depthFirstSearch(source, dest);
    }

    public Vertex depthFirstSearch(Vertex source, Vertex dest) {
        source.visited = true;
        if (source == dest) {
            return source;
        }
        for (var v : source.neighbors) {
            if (!v.visited) {
                v.previous = source;
                v.distance = source.distance + 1;
                var u = depthFirstSearch(v, dest);
                if (u != null) {
                    return u;
                }
            }
        }
        return null;
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

    public static class Vertex implements Comparable<Vertex> {
        public String key;
        public int distance;
        public boolean visited;
        public Vertex previous;
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
