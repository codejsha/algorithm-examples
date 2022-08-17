#include "depth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

TEST(DepthFirstSearchTest, SimpleSearch1)
{
    auto vertexU = Graph::DfsVertex('U');
    auto vertexV = Graph::DfsVertex('V');
    auto vertexW = Graph::DfsVertex('W');
    auto vertexX = Graph::DfsVertex('X');
    auto vertexY = Graph::DfsVertex('Y');
    auto vertexZ = Graph::DfsVertex('Z');

    auto graph = new Graph::DfsGraph();

    graph->AddVertex(vertexU);
    graph->AddVertex(vertexV);
    graph->AddVertex(vertexW);
    graph->AddVertex(vertexX);
    graph->AddVertex(vertexY);
    graph->AddVertex(vertexZ);

    // U
    graph->AddEdge(vertexU, vertexV);
    graph->AddEdge(vertexU, vertexX);
    // V
    graph->AddEdge(vertexV, vertexY);
    // W
    graph->AddEdge(vertexW, vertexZ);
    // X
    graph->AddEdge(vertexX, vertexV);
    // Y
    graph->AddEdge(vertexY, vertexX);
    // Z
    graph->AddEdge(vertexZ, vertexZ);

    auto dfs = new Graph::DepthFirstSearch(*graph);

    // test U -> Y
    auto& goal = vertexY;
    auto expectedResult = std::vector<char>{'U', 'V', 'Y'};
    dfs->Search(*graph);

    auto resultPath = std::vector<char>{};
    auto discoveryTime = goal.DiscoveryTime;
    for (int i = discoveryTime; i >= 1; --i)
    {
        resultPath.push_back(goal.Id);
        if (i != 1)
        {
            goal = *goal.Predecessor;
        }
    }

    std::ranges::reverse(resultPath);

    ASSERT_EQ(resultPath, expectedResult);
}
