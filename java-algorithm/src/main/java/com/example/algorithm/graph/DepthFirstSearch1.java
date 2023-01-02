package com.example.algorithm.graph;

import java.util.LinkedList;

/**
 * Depth First Search (edge array representation)
 */
public class DepthFirstSearch1 {
    /**
     * Perform depth-first search
     * @param edges  the edges of the graph
     * @param source the source vertex
     * @param dest   the destination vertex
     * @return the distance from source to dest
     */
    public static String[] performDepthFirstSearch(String[][] edges, String source, String dest) {
        var visited = new LinkedList<String>();
        return depthFirstSearch(edges, source, dest, visited);
    }

    /**
     * Depth-first search.
     * @param edges   the edges of the graph
     * @param source  the source vertex
     * @param dest    the destination vertex
     * @param visited the visited vertices
     * @return the distance from source to dest
     */
    private static String[] depthFirstSearch(String[][] edges, String source, String dest, LinkedList<String> visited) {
        visited.add(source);
        if (source.equals(dest)) {
            return visited.toArray(String[]::new);
        }
        for (var edge : edges) {
            var u = edge[0];
            var v = edge[1];
            if (u.equals(source) && !visited.contains(v)) {
                var path = depthFirstSearch(edges, v, dest, visited);
                if (path != null) {
                    return path;
                }
            }
        }
        visited.removeLast();
        return null;
    }
}
