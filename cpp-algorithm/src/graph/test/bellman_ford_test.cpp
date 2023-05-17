#include "bellman_ford.h"

#include <gtest/gtest.h>

GTEST_TEST(BellmanFord, BellmanFord_Case1)
{
    auto vertex_s = BellmanFord::Vertex('S');
    auto vertex_t = BellmanFord::Vertex('T');
    auto vertex_x = BellmanFord::Vertex('X');
    auto vertex_y = BellmanFord::Vertex('Y');
    auto vertex_z = BellmanFord::Vertex('Z');

    const auto graph = new BellmanFord::Graph();

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
    source.distance = 0;
    graph->BellmanFordAlgorithm(source);

    // weight
    ASSERT_EQ(0, vertex_s.distance);
    ASSERT_EQ(2, vertex_t.distance);
    ASSERT_EQ(4, vertex_x.distance);
    ASSERT_EQ(7, vertex_y.distance);
    ASSERT_EQ(-2, vertex_z.distance);

    // predecessor
    ASSERT_EQ('X', vertex_t.predecessor->id);
    ASSERT_EQ('Y', vertex_x.predecessor->id);
    ASSERT_EQ('S', vertex_y.predecessor->id);
    ASSERT_EQ('T', vertex_z.predecessor->id);
}
