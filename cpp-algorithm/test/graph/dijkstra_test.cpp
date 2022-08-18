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
    ASSERT_EQ(vertexS.Distance, 0);
    ASSERT_EQ(vertexT.Distance, 8);
    ASSERT_EQ(vertexX.Distance, 9);
    ASSERT_EQ(vertexY.Distance, 5);
    ASSERT_EQ(vertexZ.Distance, 7);

    // predecessor
    ASSERT_EQ(vertexT.Predecessor->Id, 'Y');
    ASSERT_EQ(vertexX.Predecessor->Id, 'T');
    ASSERT_EQ(vertexY.Predecessor->Id, 'S');
    ASSERT_EQ(vertexZ.Predecessor->Id, 'Y');
}
