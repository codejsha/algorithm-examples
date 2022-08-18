#include "bellman_ford.h"

#include <gtest/gtest.h>

TEST(BellmanFordTest, Simple1)
{
    auto vertexS = Graph::BellmanFordVertex('S');
    auto vertexT = Graph::BellmanFordVertex('T');
    auto vertexX = Graph::BellmanFordVertex('X');
    auto vertexY = Graph::BellmanFordVertex('Y');
    auto vertexZ = Graph::BellmanFordVertex('Z');

    const auto graph = new Graph::BellmanFordGraph();

    graph->AddVertex(vertexS);
    graph->AddVertex(vertexT);
    graph->AddVertex(vertexX);
    graph->AddVertex(vertexY);
    graph->AddVertex(vertexZ);

    // S
    graph->AddEdge(vertexS, vertexT, 6);
    graph->AddEdge(vertexS, vertexY, 7);
    // T
    graph->AddEdge(vertexT, vertexX, 5);
    graph->AddEdge(vertexT, vertexY, 8);
    graph->AddEdge(vertexT, vertexZ, -4);
    // X
    graph->AddEdge(vertexX, vertexT, -2);
    // Y
    graph->AddEdge(vertexY, vertexX, -3);
    graph->AddEdge(vertexY, vertexZ, 9);
    // Z
    graph->AddEdge(vertexZ, vertexS, 2);
    graph->AddEdge(vertexZ, vertexX, 7);

    auto& source = vertexS;
    source.Distance = 0;
    graph->BellmanFord(source);

    // weight
    ASSERT_EQ(vertexS.Distance, 0);
    ASSERT_EQ(vertexT.Distance, 2);
    ASSERT_EQ(vertexX.Distance, 4);
    ASSERT_EQ(vertexY.Distance, 7);
    ASSERT_EQ(vertexZ.Distance, -2);

    // predecessor
    ASSERT_EQ(vertexT.Predecessor->Id, 'X');
    ASSERT_EQ(vertexX.Predecessor->Id, 'Y');
    ASSERT_EQ(vertexY.Predecessor->Id, 'S');
    ASSERT_EQ(vertexZ.Predecessor->Id, 'T');
}
