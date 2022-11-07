#include "dijkstra.h"

void Graph::DijkstraGraph::AddEdge(DijkstraVertex& u, DijkstraVertex& v, int weight)
{
    AdjacencyList.emplace_back(&u, &v);
    u.Neighbors.insert(&v);
    WeightList.insert(std::make_pair(std::make_pair(u.Id, v.Id), weight));
}

void Graph::DijkstraGraph::AddVertex(DijkstraVertex& v)
{
    Vertices.push_back(&v);
}

void Graph::DijkstraGraph::Relax(DijkstraVertex& u, DijkstraVertex& v)
{
    if (v.Distance > (u.Distance + WeightList[std::make_pair(u.Id, v.Id)]))
    {
        v.Distance = u.Distance + WeightList[std::make_pair(u.Id, v.Id)];
        v.Predecessor = &u;
    }
}

void Graph::DijkstraGraph::ReorderQueue(std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>& minQueue)
{
    auto queue = std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>{};
    const auto minQueueSize = static_cast<int>(minQueue.size());

    for (int i = 0; i < minQueueSize; ++i)
    {
        queue.push(minQueue.top());
        minQueue.pop();
    }

    minQueue = std::move(queue);
}

void Graph::DijkstraGraph::Dijkstra(DijkstraVertex& source)
{
    std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator> minQueue;
    for (auto v : Vertices)
    {
        minQueue.push(v);
    }

    while (!minQueue.empty())
    {
        auto u = minQueue.top();
        minQueue.pop();
        for (auto v : u->Neighbors)
        {
            Relax(*u, *v);
            ReorderQueue(minQueue);
        }
    }
}
