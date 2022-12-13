#include "bellman_ford.h"

#include <gtest/gtest.h>

GTEST_TEST(BellmanFord, Simple1)
{
    auto vertex_s = Graph::BellmanFordVertex('S');
    auto vertex_t = Graph::BellmanFordVertex('T');
    auto vertex_x = Graph::BellmanFordVertex('X');
    auto vertex_y = Graph::BellmanFordVertex('Y');
    auto vertex_z = Graph::BellmanFordVertex('Z');

    const auto graph = new Graph::BellmanFordGraph();

    graph->AddVertex(vertex_s);
    graph->AddVertex(vertex_t);
    graph->AddVertex(vertex_x);
    graph->AddVertex(vertex_y);
    graph->AddVertex(vertex_z);

    // S
    graph->AddEdge(vertex_s, vertex_t, 6);
    graph->AddEdge(vertex_s, vertex_y, 7);
    // T
    graph->AddEdge(vertex_t, vertex_x, 5);
    graph->AddEdge(vertex_t, vertex_y, 8);
    graph->AddEdge(vertex_t, vertex_z, -4);
    // X
    graph->AddEdge(vertex_x, vertex_t, -2);
    // Y
    graph->AddEdge(vertex_y, vertex_x, -3);
    graph->AddEdge(vertex_y, vertex_z, 9);
    // Z
    graph->AddEdge(vertex_z, vertex_s, 2);
    graph->AddEdge(vertex_z, vertex_x, 7);

    auto& source = vertex_s;
    source.Distance = 0;
    graph->BellmanFord(source);

    // weight
    ASSERT_EQ(0, vertex_s.Distance);
    ASSERT_EQ(2, vertex_t.Distance);
    ASSERT_EQ(4, vertex_x.Distance);
    ASSERT_EQ(7, vertex_y.Distance);
    ASSERT_EQ(-2, vertex_z.Distance);

    // predecessor
    ASSERT_EQ('X', vertex_t.Predecessor->Id);
    ASSERT_EQ('Y', vertex_x.Predecessor->Id);
    ASSERT_EQ('S', vertex_y.Predecessor->Id);
    ASSERT_EQ('T', vertex_z.Predecessor->Id);
}
