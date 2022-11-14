#include "dijkstra.h"

#include <gtest/gtest.h>

GTEST_TEST(DijkstraTest, Simple1)
{
    auto vertex_s = Graph::DijkstraVertex('S');
    auto vertex_t = Graph::DijkstraVertex('T');
    auto vertex_x = Graph::DijkstraVertex('X');
    auto vertex_y = Graph::DijkstraVertex('Y');
    auto vertex_z = Graph::DijkstraVertex('Z');

    const auto graph = new Graph::DijkstraGraph();

    graph->AddVertex(vertex_s);
    graph->AddVertex(vertex_t);
    graph->AddVertex(vertex_x);
    graph->AddVertex(vertex_y);
    graph->AddVertex(vertex_z);

    // S
    graph->AddEdge(vertex_s, vertex_t, 10);
    graph->AddEdge(vertex_s, vertex_y, 5);
    // T
    graph->AddEdge(vertex_t, vertex_x, 1);
    graph->AddEdge(vertex_t, vertex_y, 2);
    // X
    graph->AddEdge(vertex_x, vertex_z, 4);
    // Y
    graph->AddEdge(vertex_y, vertex_t, 3);
    graph->AddEdge(vertex_y, vertex_x, 9);
    graph->AddEdge(vertex_y, vertex_z, 2);
    // Z
    graph->AddEdge(vertex_z, vertex_s, 7);
    graph->AddEdge(vertex_z, vertex_x, 6);

    auto& source = vertex_s;
    source.Distance = 0;
    graph->Dijkstra(source);

    // weight
    ASSERT_EQ(0, vertex_s.Distance);
    ASSERT_EQ(8, vertex_t.Distance);
    ASSERT_EQ(9, vertex_x.Distance);
    ASSERT_EQ(5, vertex_y.Distance);
    ASSERT_EQ(7, vertex_z.Distance);

    // predecessor
    ASSERT_EQ('Y', vertex_t.Predecessor->Id);
    ASSERT_EQ('T', vertex_x.Predecessor->Id);
    ASSERT_EQ('S', vertex_y.Predecessor->Id);
    ASSERT_EQ('Y', vertex_z.Predecessor->Id);
}
