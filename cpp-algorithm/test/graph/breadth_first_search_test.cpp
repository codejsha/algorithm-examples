#include "breadth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(BreadthFirstSearchTest, SimpleSearch1)
{
    auto vertex_r = Graph::BfsVertex('R');
    auto vertex_s = Graph::BfsVertex('S');
    auto vertex_t = Graph::BfsVertex('T');
    auto vertex_u = Graph::BfsVertex('U');
    auto vertex_v = Graph::BfsVertex('V');
    auto vertex_w = Graph::BfsVertex('W');
    auto vertex_x = Graph::BfsVertex('X');
    auto vertex_y = Graph::BfsVertex('Y');

    const auto graph = new Graph::BfsGraph();

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

    const auto bfs = new Graph::BreadthFirstSearch(*graph);

    auto& start = vertex_s;

    // test U
    auto& goal = vertex_u;
    auto expected = std::vector<char>{'S', 'W', 'T', 'U'};
    auto result = bfs->Search(start, goal);

    auto result_path = std::vector<char>{};
    auto distance = result->Distance;
    for (int i = 0; i <= distance; ++i)
    {
        result_path.push_back(result->Id);
        result = result->Predecessor;
    }

    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}

GTEST_TEST(BreadthFirstSearchTest, SimpleSearch2)
{
    auto vertex_r = Graph::BfsVertex('R');
    auto vertex_s = Graph::BfsVertex('S');
    auto vertex_t = Graph::BfsVertex('T');
    auto vertex_u = Graph::BfsVertex('U');
    auto vertex_v = Graph::BfsVertex('V');
    auto vertex_w = Graph::BfsVertex('W');
    auto vertex_x = Graph::BfsVertex('X');
    auto vertex_y = Graph::BfsVertex('Y');

    const auto graph = new Graph::BfsGraph();

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

    const auto bfs = new Graph::BreadthFirstSearch(*graph);

    auto& start = vertex_s;

    // test Y
    auto& goal = vertex_y;
    auto expected = std::vector<char>{'S', 'W', 'X', 'Y'};
    auto result = bfs->Search(start, goal);

    auto result_path = std::vector<char>{};
    auto distance = result->Distance;
    for (int i = 0; i <= distance; ++i)
    {
        result_path.push_back(result->Id);
        result = result->Predecessor;
    }

    std::ranges::reverse(result_path);

    ASSERT_EQ(expected, result_path);
}
