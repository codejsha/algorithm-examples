#include "depth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(DepthFirstSearch, DepthFirstSearch_Case1)
{
    auto vertex_u = Dfs::Vertex('U');
    auto vertex_v = Dfs::Vertex('V');
    auto vertex_w = Dfs::Vertex('W');
    auto vertex_x = Dfs::Vertex('X');
    auto vertex_y = Dfs::Vertex('Y');
    auto vertex_z = Dfs::Vertex('Z');

    auto graph = new Dfs::Graph();

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

    // test U -> Y
    auto& source = vertex_u;
    auto& goal = vertex_y;
    auto expected = std::vector{'U', 'V', 'Y'};
    graph->DepthFirstSearch2(source);

    auto result_path = std::vector<char>{};
    auto discovery_time = goal.discovery_time;
    for (auto i = discovery_time; i >= 1; --i)
    {
        result_path.push_back(goal.id);
        if (i != 1)
        {
            goal = *goal.predecessor;
        }
    }
    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}
