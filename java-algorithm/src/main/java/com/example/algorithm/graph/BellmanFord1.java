package com.example.algorithm.graph;

import java.util.Arrays;
import java.util.LinkedList;

/**
 * Bellman-Ford algorithm (edge array representation)
 */
public class BellmanFord1 {
    /**
     * Perform Bellman-Ford algorithm
     * @param edges  the edges of the graph
     * @param weight the weight of the edges
     * @param source the source vertex
     * @return the predecessor array of the shortest path
     */
    public static int[] bellmanFordAlgorithm(int[][] edges, int[] weight, int source) {
        var vertices = Arrays.stream(edges).flatMapToInt(Arrays::stream).distinct().toArray();
        var distance = new int[vertices.length];
        var predecessor = new int[vertices.length];
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(predecessor, -1);
        distance[source] = 0;
        for (var i = 0; i < vertices.length - 1; i++) {
            for (var j = 0; j < edges.length; j++) {
                var u = edges[j][0];
                var v = edges[j][1];
                var newDistance = distance[u] + weight[j];
                if (distance[u] != Integer.MAX_VALUE && newDistance < distance[v]) {
                    distance[v] = newDistance;
                    predecessor[v] = u;
                }
            }
        }
        return predecessor;
    }

    public static int[] shortestPath(int[] predecessor, int source, int dest) {
        var path = new LinkedList<Integer>();
        var current = dest;
        while (current != source) {
            path.addFirst(current);
            current = predecessor[current];
        }
        path.addFirst(source);
        return path.stream().mapToInt(Integer::intValue).toArray();
    }

    public static int shortestDistance(int[] predecessor, int source, int dest) {
        var distance = 0;
        var current = dest;
        while (current != source) {
            distance++;
            current = predecessor[current];
        }
        return distance;
    }

    public static void printPath(int[] predecessor, int source, int dest) {
        if (source == dest) {
            System.out.print(source);
        } else if (predecessor[dest] == -1) {
            System.out.print("No path from " + source + " to " + dest + " exists.");
        } else {
            printPath(predecessor, source, predecessor[dest]);
            System.out.print(" -> " + dest);
        }
    }
}
