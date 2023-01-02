package com.example.algorithm.graph;

public class GraphUtil {
    public static int[][] edgeToAdjacencyMatrix(int[][] edges, int n) {
        var matrix = new int[n][n];
        for (var edge : edges) {
            matrix[edge[0]][edge[1]] = 1;
        }
        return matrix;
    }

    public static void printAdjacencyMatrix(int[][] matrix) {
        for (var i = 0; i < matrix.length; i++) {
            for (var j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
