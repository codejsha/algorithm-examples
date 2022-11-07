#include "dijkstra.h"

#include <gtest/gtest.h>

TEST(DijkstraTest, Simple1)
{
    auto vertexS = Graph::DijkstraVertex('S');
    auto vertexT = Graph::DijkstraVertex('T');
    auto vertexX = Graph::DijkstraVertex('X');
    auto vertexY = Graph::DijkstraVertex('Y');
    auto vertexZ = Graph::DijkstraVertex('Z');

    const auto graph = new Graph::DijkstraGraph();

    graph->AddVertex(vertexS);
    graph->AddVertex(vertexT);
    graph->AddVertex(vertexX);
    graph->AddVertex(vertexY);
    graph->AddVertex(vertexZ);

    // S
    graph->AddEdge(vertexS, vertexT, 10);
    graph->AddEdge(vertexS, vertexY, 5);
    // T
    graph->AddEdge(vertexT, vertexX, 1);
    graph->AddEdge(vertexT, vertexY, 2);
    // X
    graph->AddEdge(vertexX, vertexZ, 4);
    // Y
    graph->AddEdge(vertexY, vertexT, 3);
    graph->AddEdge(vertexY, vertexX, 9);
    graph->AddEdge(vertexY, vertexZ, 2);
    // Z
    graph->AddEdge(vertexZ, vertexS, 7);
    graph->AddEdge(vertexZ, vertexX, 6);

    auto& source = vertexS;
    source.Distance = 0;
    graph->Dijkstra(source);

    // weight
    ASSERT_EQ(0, vertexS.Distance);
    ASSERT_EQ(8, vertexT.Distance);
    ASSERT_EQ(9, vertexX.Distance);
    ASSERT_EQ(5, vertexY.Distance);
    ASSERT_EQ(7, vertexZ.Distance);

    // predecessor
    ASSERT_EQ('Y', vertexT.Predecessor->Id);
    ASSERT_EQ('T', vertexX.Predecessor->Id);
    ASSERT_EQ('S', vertexY.Predecessor->Id);
    ASSERT_EQ('Y', vertexZ.Predecessor->Id);
}
