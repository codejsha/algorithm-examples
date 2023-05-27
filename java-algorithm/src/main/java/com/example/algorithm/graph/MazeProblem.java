package com.example.algorithm.graph;

import java.util.LinkedList;

public class MazeProblem {
    public static int searchMazePath(int[][] maze) {
        var m = maze.length;
        var n = maze[0].length;
        var queue = new LinkedList<Coordinate>();
        var start = new Coordinate(0, 0, 1);
        queue.add(start);
        while (!queue.isEmpty()) {
            var point = queue.poll();
            if (point.x == m - 1 && point.y == n - 1) {
                return point.distance;
            }
            if (point.x - 1 >= 0 && maze[point.x - 1][point.y] == 1) {
                maze[point.x - 1][point.y] = 0;
                queue.add(new Coordinate(point.x - 1, point.y, point.distance + 1));
            }
            if (point.x + 1 < m && maze[point.x + 1][point.y] == 1) {
                maze[point.x + 1][point.y] = 0;
                queue.add(new Coordinate(point.x + 1, point.y, point.distance + 1));
            }
            if (point.y - 1 >= 0 && maze[point.x][point.y - 1] == 1) {
                maze[point.x][point.y - 1] = 0;
                queue.add(new Coordinate(point.x, point.y - 1, point.distance + 1));
            }
            if (point.y + 1 < n && maze[point.x][point.y + 1] == 1) {
                maze[point.x][point.y + 1] = 0;
                queue.add(new Coordinate(point.x, point.y + 1, point.distance + 1));
            }
        }
        return -1;
    }

    public static class Coordinate {
        int x;
        int y;
        boolean visited;
        int distance;

        public Coordinate(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.visited = false;
            this.distance = distance;
        }
    }
}
