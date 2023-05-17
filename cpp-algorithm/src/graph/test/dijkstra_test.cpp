#include "dijkstra.h"

#include <gtest/gtest.h>

GTEST_TEST(Dijkstra, Simple1)
{
    auto vertex_s = Dijkstra::Vertex('S');
    auto vertex_t = Dijkstra::Vertex('T');
    auto vertex_x = Dijkstra::Vertex('X');
    auto vertex_y = Dijkstra::Vertex('Y');
    auto vertex_z = Dijkstra::Vertex('Z');

    const auto graph = new Dijkstra::Graph();

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
    source.distance = 0;
    graph->DijkstraAlgorithm(source);

    // weight
    ASSERT_EQ(0, vertex_s.distance);
    ASSERT_EQ(8, vertex_t.distance);
    ASSERT_EQ(9, vertex_x.distance);
    ASSERT_EQ(5, vertex_y.distance);
    ASSERT_EQ(7, vertex_z.distance);

    // predecessor
    ASSERT_EQ('Y', vertex_t.predecessor->id);
    ASSERT_EQ('T', vertex_x.predecessor->id);
    ASSERT_EQ('S', vertex_y.predecessor->id);
    ASSERT_EQ('Y', vertex_z.predecessor->id);
}
