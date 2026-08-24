#ifndef CPP_ALGORITHM_GRAPH_H
#define CPP_ALGORITHM_GRAPH_H

namespace Graph
{
    std::vector<std::vector<int>> InitializeAdjacencyMatrix(int row, int col, std::vector<std::vector<int, int>>& edges)

    {
        auto adjacency_matrix = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
        for (const auto& [x, y] : edges)
        {
            if (x < row && y < col)
            {
                adjacency_matrix[x][y] = 1;
            }
        }
        return adjacency_matrix;
    }

    std::vector<std::vector<int>> InitializeAdjacencyMatrixWithZero(int row, int col)
    {
        auto adjacency_matrix = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
        return adjacency_matrix;
    }

    std::vector<std::vector<int>> InitializeAdjacencyMatrixWithOne(int row, int col)
    {
        auto adjacency_matrix = std::vector<std::vector<int>>(row, std::vector<int>(col, 1));
        return adjacency_matrix;
    }
}
