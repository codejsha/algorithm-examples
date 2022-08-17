#include "depth_first_search.h"

auto Graph::DepthFirstSearch::Search(DfsGraph& graph) -> void
{
    for (auto vertex : graph.GetVertices())
    {
        if (vertex->Visit == Unvisited)
        {
            SearchVisit(graph, *vertex);
        }
    }
}

auto Graph::DepthFirstSearch::SearchVisit(DfsGraph& graph, DfsVertex& vertex) -> void
{
    vertex.Visit = Visited;
    auto time = graph.GetTime() + 1;
    graph.SetTime(time);
    vertex.DiscoveryTime = time;

    for (auto neighbor : vertex.Neighbors)
    {
        if (neighbor->Visit == Unvisited)
        {
            neighbor->Predecessor = &vertex;
            SearchVisit(graph, *neighbor);
        }
    }

    vertex.Visit = Finished;
    time = graph.GetTime() + 1;
    graph.SetTime(time);
    vertex.FinishingTime = time;
}
