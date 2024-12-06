package com.example.algorithm.graph;

/**
 * Depth First Search (adjacency matrix array representation)
 */
public class DepthFirstSearch2 {
    /**
     * Perform depth first search
     *
     * @param matrix adjacency matrix representing a graph
     * @param source the source vertex
     * @param dest   the destination vertex
     * @return the distance from source to dest
     */
    public static int performDepthFirstSearch(int[][] matrix, int source, int dest) {
        boolean[] visited = new boolean[matrix.length];
        return depthFirstSearch(matrix, source, dest, visited) - 1;
    }

    /**
     * Depth-first search.
     *
     * @param matrix  adjacency matrix representing a graph
     * @param source  the source vertex
     * @param dest    the destination vertex
     * @param visited the visited vertices
     * @return the distance from source to dest
     */
    private static int depthFirstSearch(int[][] matrix, int source, int dest, boolean[] visited) {
        if (source == dest) {
            return 0;
        }
        visited[source] = true;
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[source][i] == 1 && !visited[i]) {
                int result = depthFirstSearch(matrix, i, dest, visited);
                if (result != -1) {
                    return result + 1;
                }
            }
        }
        return -1;
    }
}
