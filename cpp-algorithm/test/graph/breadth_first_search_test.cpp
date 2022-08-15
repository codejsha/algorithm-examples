#include "breadth_first_search.h"

#include <algorithm>
#include <gtest/gtest.h>

TEST(BreadthFirstSearchTest, SimpleSearch1)
{
    auto vertexR = Search::Vertex<char>('R');
    auto vertexS = Search::Vertex<char>('S');
    auto vertexT = Search::Vertex<char>('T');
    auto vertexU = Search::Vertex<char>('U');
    auto vertexV = Search::Vertex<char>('V');
    auto vertexW = Search::Vertex<char>('W');
    auto vertexX = Search::Vertex<char>('X');
    auto vertexY = Search::Vertex<char>('Y');

    const auto graph = new Search::Graph();

    graph->AddVertex(vertexR);
    graph->AddVertex(vertexS);
    graph->AddVertex(vertexT);
    graph->AddVertex(vertexU);
    graph->AddVertex(vertexV);
    graph->AddVertex(vertexW);
    graph->AddVertex(vertexX);
    graph->AddVertex(vertexY);

    // R
    graph->AddEdge(vertexR, vertexS);
    graph->AddEdge(vertexR, vertexV);
    // S
    graph->AddEdge(vertexS, vertexR);
    graph->AddEdge(vertexS, vertexW);
    // T
    graph->AddEdge(vertexT, vertexU);
    graph->AddEdge(vertexT, vertexW);
    graph->AddEdge(vertexT, vertexX);
    // U
    graph->AddEdge(vertexU, vertexT);
    graph->AddEdge(vertexU, vertexX);
    graph->AddEdge(vertexU, vertexY);
    // V
    graph->AddEdge(vertexV, vertexR);
    // W
    graph->AddEdge(vertexW, vertexS);
    graph->AddEdge(vertexW, vertexT);
    graph->AddEdge(vertexW, vertexX);
    // X
    graph->AddEdge(vertexX, vertexT);
    graph->AddEdge(vertexX, vertexU);
    graph->AddEdge(vertexX, vertexW);
    graph->AddEdge(vertexX, vertexY);
    // Y
    graph->AddEdge(vertexY, vertexU);
    graph->AddEdge(vertexY, vertexX);

    const auto bfs = new Search::BreadthFirstSearch(*graph);

    auto& start = vertexS;

    // test U
    auto& goal = vertexU;
    auto expectedResult = std::vector<char>{'S', 'W', 'T', 'U'};
    auto result = bfs->Search(start, goal);

    auto resultPath = std::vector<char>{};
    auto distance = result->Distance;
    for (int i = 0; i <= distance; ++i)
    {
        resultPath.push_back(result->Id);
        result = result->Predecessor;
    }

    std::ranges::reverse(resultPath);

    ASSERT_EQ(resultPath, expectedResult);
}

TEST(BreadthFirstSearchTest, SimpleSearch2)
{
    auto vertexR = Search::Vertex<char>('R');
    auto vertexS = Search::Vertex<char>('S');
    auto vertexT = Search::Vertex<char>('T');
    auto vertexU = Search::Vertex<char>('U');
    auto vertexV = Search::Vertex<char>('V');
    auto vertexW = Search::Vertex<char>('W');
    auto vertexX = Search::Vertex<char>('X');
    auto vertexY = Search::Vertex<char>('Y');

    const auto graph = new Search::Graph();

    graph->AddVertex(vertexR);
    graph->AddVertex(vertexS);
    graph->AddVertex(vertexT);
    graph->AddVertex(vertexU);
    graph->AddVertex(vertexV);
    graph->AddVertex(vertexW);
    graph->AddVertex(vertexX);
    graph->AddVertex(vertexY);

    // R
    graph->AddEdge(vertexR, vertexS);
    graph->AddEdge(vertexR, vertexV);
    // S
    graph->AddEdge(vertexS, vertexR);
    graph->AddEdge(vertexS, vertexW);
    // T
    graph->AddEdge(vertexT, vertexU);
    graph->AddEdge(vertexT, vertexW);
    graph->AddEdge(vertexT, vertexX);
    // U
    graph->AddEdge(vertexU, vertexT);
    graph->AddEdge(vertexU, vertexX);
    graph->AddEdge(vertexU, vertexY);
    // V
    graph->AddEdge(vertexV, vertexR);
    // W
    graph->AddEdge(vertexW, vertexS);
    graph->AddEdge(vertexW, vertexT);
    graph->AddEdge(vertexW, vertexX);
    // X
    graph->AddEdge(vertexX, vertexT);
    graph->AddEdge(vertexX, vertexU);
    graph->AddEdge(vertexX, vertexW);
    graph->AddEdge(vertexX, vertexY);
    // Y
    graph->AddEdge(vertexY, vertexU);
    graph->AddEdge(vertexY, vertexX);

    const auto bfs = new Search::BreadthFirstSearch(*graph);

    auto& start = vertexS;

    // test Y
    auto& goal = vertexY;
    auto expectedResult = std::vector<char>{'S', 'W', 'X', 'Y'};
    auto result = bfs->Search(start, goal);

    auto resultPath = std::vector<char>{};
    auto distance = result->Distance;
    for (int i = 0; i <= distance; ++i)
    {
        resultPath.push_back(result->Id);
        result = result->Predecessor;
    }

    std::ranges::reverse(resultPath);

    ASSERT_EQ(resultPath, expectedResult);
}
