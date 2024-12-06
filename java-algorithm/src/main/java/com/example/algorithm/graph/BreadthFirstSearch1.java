package com.example.algorithm.graph;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/**
 * Breadth-first search (edge array representation)
 */
public class BreadthFirstSearch1 {
    public static int breadthFirstSearch(int[][] edges, int source, int dest) {
        int[] vertices = Arrays.stream(edges).flatMapToInt(Arrays::stream).distinct().toArray();
        int[] distance = new int[vertices.length];
        var queue = new LinkedList<Integer>();
        Arrays.fill(distance, -1);
        distance[source] = 0;
        queue.add(source);
        while (!queue.isEmpty()) {
            Integer u = queue.poll();
            for (int[] edge : edges) {
                int v = edge[1];
                if (edge[0] == u && distance[v] == -1) {
                    distance[v] = distance[u] + 1;
                    queue.add(v);
                }
            }
        }
        return distance[dest];
    }

    public static int breadthFirstSearchPreProcessingVersion(int[][] edges, int source, int dest) {
        int[] vertices = Arrays.stream(edges).flatMapToInt(Arrays::stream).distinct().toArray();
        int[] distance = new int[vertices.length];
        boolean[] visited = new boolean[vertices.length];
        var queue = new LinkedList<Integer>();
        var neighbors = new HashMap<Integer, List<Integer>>();
        for (int[] edge : edges) {
            int sourceVertex = edge[0];
            int destVertex = edge[1];
            neighbors.putIfAbsent(sourceVertex, new LinkedList<>());
            neighbors.get(sourceVertex).add(destVertex);
        }
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[source] = 0;
        queue.add(source);
        visited[source] = true;
        while (!queue.isEmpty()) {
            Integer u = queue.poll();
            if (neighbors.containsKey(u)) {
                for (Integer v : neighbors.get(u)) {
                    if (!visited[v]) {
                        visited[v] = true;
                        distance[v] = distance[u] + 1;
                        queue.add(v);
                    }
                }
            }
        }
        return distance[dest];
    }
}
