package com.example.algorithm.graph;

public class GraphUtil {
    public static int[][] edgeToAdjacencyMatrix(int[][] edges, int n) {
        int[][] matrix = new int[n][n];
        for (int[] edge : edges) {
            matrix[edge[0]][edge[1]] = 1;
        }
        return matrix;
    }

    public static void printAdjacencyMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
