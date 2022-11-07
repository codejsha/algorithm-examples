#include "depth_first_search.h"

void Graph::DepthFirstSearch::Search(DfsGraph& graph)
{
    for (auto vertex : graph.GetVertices())
    {
        if (vertex->Visit == Unvisited)
        {
            SearchVisit(graph, *vertex);
        }
    }
}

void Graph::DepthFirstSearch::SearchVisit(DfsGraph& graph, DfsVertex& vertex)
{
    vertex.Visit = Visited;
    auto time = graph.GetTime() + 1;
    graph.SetTime(time);
    vertex.DiscoveryTime = time;

    for (const auto neighbor : vertex.Neighbors)
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
