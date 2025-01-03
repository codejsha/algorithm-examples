package com.example.algorithm.graph;

public class FloydWarshall {
    // the maximum value of an integer
    private static final int INF = 99999;

    /**
     * Floyd-Warshall algorithm for all-pairs the shortest path problem.
     * The graph must not contain negative cycles.
     * <p>
     * Time complexity: O(V^3)
     * Space complexity: O(V^2)
     *
     * @param matrix adjacency matrix
     * @return shortest path matrix
     */
    public static int[][] floydWarshall(int[][] matrix) {
        int length = matrix.length;

        // initialize the shortest path matrix
        int[][] dist = new int[length][length];
        for (int i = 0; i < length; i++) {
            // for (var j = 0; j < length; j++) {
            //     dist[i][j] = matrix[i][j];
            // }
            System.arraycopy(matrix[i], 0, dist[i], 0, length);
        }

        // compute the shortest path weight
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return dist;
    }

    /**
     * Floyd-Warshall algorithm for all-pairs the shortest path problem.
     * The graph must not contain negative weights.
     * <p>
     * Time complexity: O(V^3)
     * Space complexity: O(V^2)
     *
     * @param matrix adjacency matrix
     * @return shortest path matrix
     */
    public static int[][] floydWarshallPositiveWeight(int[][] matrix) {
        int length = matrix.length;

        // initialize the shortest path matrix
        int[][] dist = new int[length][length];
        for (int i = 0; i < length; i++) {
            // for (var j = 0; j < length; j++) {
            //     dist[i][j] = matrix[i][j];
            // }
            System.arraycopy(matrix[i], 0, dist[i], 0, length);
        }

        // compute the shortest path weight
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        return dist;
    }

    /**
     * Initialize adjacency matrix
     *
     * @param matrix adjacency matrix
     * @return initialized adjacency matrix
     */
    public static int[][] initializeMatrix(int[][] matrix) {
        int length = matrix.length;
        int[][] newMatrix = new int[length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (i == j) {
                    newMatrix[i][j] = 0;
                } else if (matrix[i][j] != 0) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = INF;
                }
            }
        }
        return newMatrix;
    }

    /**
     * Print the adjacency matrix.
     *
     * @param matrix adjacency matrix
     */
    private static void printMatrix(int[][] matrix) {
        int length = matrix.length;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (matrix[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}
