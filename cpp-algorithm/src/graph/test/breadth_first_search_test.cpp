#include "breadth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(BreadthFirstSearch, BreadthFirstSearch_Case1)
{
    auto vertex_r = Bfs::Vertex('R');
    auto vertex_s = Bfs::Vertex('S');
    auto vertex_t = Bfs::Vertex('T');
    auto vertex_u = Bfs::Vertex('U');
    auto vertex_v = Bfs::Vertex('V');
    auto vertex_w = Bfs::Vertex('W');
    auto vertex_x = Bfs::Vertex('X');
    auto vertex_y = Bfs::Vertex('Y');

    const auto graph = new Bfs::Graph();

    graph->AddVertex(vertex_r);
    graph->AddVertex(vertex_s);
    graph->AddVertex(vertex_t);
    graph->AddVertex(vertex_u);
    graph->AddVertex(vertex_v);
    graph->AddVertex(vertex_w);
    graph->AddVertex(vertex_x);
    graph->AddVertex(vertex_y);

    // R
    graph->AddEdge(vertex_r, vertex_s);
    graph->AddEdge(vertex_r, vertex_v);
    // S
    graph->AddEdge(vertex_s, vertex_r);
    graph->AddEdge(vertex_s, vertex_w);
    // T
    graph->AddEdge(vertex_t, vertex_u);
    graph->AddEdge(vertex_t, vertex_w);
    graph->AddEdge(vertex_t, vertex_x);
    // U
    graph->AddEdge(vertex_u, vertex_t);
    graph->AddEdge(vertex_u, vertex_x);
    graph->AddEdge(vertex_u, vertex_y);
    // V
    graph->AddEdge(vertex_v, vertex_r);
    // W
    graph->AddEdge(vertex_w, vertex_s);
    graph->AddEdge(vertex_w, vertex_t);
    graph->AddEdge(vertex_w, vertex_x);
    // X
    graph->AddEdge(vertex_x, vertex_t);
    graph->AddEdge(vertex_x, vertex_u);
    graph->AddEdge(vertex_x, vertex_w);
    graph->AddEdge(vertex_x, vertex_y);
    // Y
    graph->AddEdge(vertex_y, vertex_u);
    graph->AddEdge(vertex_y, vertex_x);

    // test U
    auto& start = vertex_s;
    auto& goal = vertex_u;
    auto expected = std::vector{'S', 'W', 'T', 'U'};
    auto result = graph->BreadthFirstSearch(start, goal);
    auto result_path = std::vector<char>{};
    auto distance = result->distance;
    for (auto i = 0; i <= distance; ++i)
    {
        result_path.push_back(result->id);
        result = result->predecessor;
    }
    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}

GTEST_TEST(BreadthFirstSearch, BreadthFirstSearch_Case2)
{
    auto vertex_r = Bfs::Vertex('R');
    auto vertex_s = Bfs::Vertex('S');
    auto vertex_t = Bfs::Vertex('T');
    auto vertex_u = Bfs::Vertex('U');
    auto vertex_v = Bfs::Vertex('V');
    auto vertex_w = Bfs::Vertex('W');
    auto vertex_x = Bfs::Vertex('X');
    auto vertex_y = Bfs::Vertex('Y');

    const auto graph = new Bfs::Graph();

    graph->AddVertex(vertex_r);
    graph->AddVertex(vertex_s);
    graph->AddVertex(vertex_t);
    graph->AddVertex(vertex_u);
    graph->AddVertex(vertex_v);
    graph->AddVertex(vertex_w);
    graph->AddVertex(vertex_x);
    graph->AddVertex(vertex_y);

    // R
    graph->AddEdge(vertex_r, vertex_s);
    graph->AddEdge(vertex_r, vertex_v);
    // S
    graph->AddEdge(vertex_s, vertex_r);
    graph->AddEdge(vertex_s, vertex_w);
    // T
    graph->AddEdge(vertex_t, vertex_u);
    graph->AddEdge(vertex_t, vertex_w);
    graph->AddEdge(vertex_t, vertex_x);
    // U
    graph->AddEdge(vertex_u, vertex_t);
    graph->AddEdge(vertex_u, vertex_x);
    graph->AddEdge(vertex_u, vertex_y);
    // V
    graph->AddEdge(vertex_v, vertex_r);
    // W
    graph->AddEdge(vertex_w, vertex_s);
    graph->AddEdge(vertex_w, vertex_t);
    graph->AddEdge(vertex_w, vertex_x);
    // X
    graph->AddEdge(vertex_x, vertex_t);
    graph->AddEdge(vertex_x, vertex_u);
    graph->AddEdge(vertex_x, vertex_w);
    graph->AddEdge(vertex_x, vertex_y);
    // Y
    graph->AddEdge(vertex_y, vertex_u);
    graph->AddEdge(vertex_y, vertex_x);

    // test Y
    auto& start = vertex_s;
    auto& goal = vertex_y;
    auto expected = std::vector{'S', 'W', 'X', 'Y'};
    auto result = Bfs::Graph::BreadthFirstSearch(start, goal);
    auto result_path = std::vector<char>{};
    auto distance = result->distance;
    for (auto i = 0; i <= distance; ++i)
    {
        result_path.push_back(result->id);
        result = result->predecessor;
    }
    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}
