#include "depth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(DepthFirstSearchTest, SimpleSearch1)
{
    auto vertex_u = Graph::DfsVertex('U');
    auto vertex_v = Graph::DfsVertex('V');
    auto vertex_w = Graph::DfsVertex('W');
    auto vertex_x = Graph::DfsVertex('X');
    auto vertex_y = Graph::DfsVertex('Y');
    auto vertex_z = Graph::DfsVertex('Z');

    auto graph = new Graph::DfsGraph();

    graph->AddVertex(vertex_u);
    graph->AddVertex(vertex_v);
    graph->AddVertex(vertex_w);
    graph->AddVertex(vertex_x);
    graph->AddVertex(vertex_y);
    graph->AddVertex(vertex_z);

    // U
    graph->AddEdge(vertex_u, vertex_v);
    graph->AddEdge(vertex_u, vertex_x);
    // V
    graph->AddEdge(vertex_v, vertex_y);
    // W
    graph->AddEdge(vertex_w, vertex_z);
    // X
    graph->AddEdge(vertex_x, vertex_v);
    // Y
    graph->AddEdge(vertex_y, vertex_x);
    // Z
    graph->AddEdge(vertex_z, vertex_z);

    auto dfs = new Graph::DepthFirstSearch(*graph);

    // test U -> Y
    auto& goal = vertex_y;
    auto expected = std::vector<char>{'U', 'V', 'Y'};
    dfs->Search(*graph);

    auto result_path = std::vector<char>{};
    auto discovery_time = goal.DiscoveryTime;
    for (auto i = discovery_time; i >= 1; --i)
    {
        result_path.push_back(goal.Id);
        if (i != 1)
        {
            goal = *goal.Predecessor;
        }
    }

    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}
