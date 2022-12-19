package com.example.algorithm.graph;

import java.util.*;

public class BreadthFirstSearch {
    public Vertex breadthFirstSearch(Vertex source, Vertex dest) {
        source.visited = true;
        source.distance = 0;
        var queue = new ArrayDeque<Vertex>();
        queue.add(source);
        while (!queue.isEmpty()) {
            var u = queue.poll();
            if (u == dest) {
                return u;
            }
            for (var v : u.neighbors) {
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
