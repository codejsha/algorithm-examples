#include "dijkstra.h"

auto Graph::DijkstraGraph::AddEdge(DijkstraVertex& u, DijkstraVertex& v, int weight) -> void
{
    AdjacencyList.emplace_back(&u, &v);
    u.Neighbors.insert(&v);
    WeightList.insert(std::make_pair(std::make_pair(u.Id, v.Id), weight));
}

auto Graph::DijkstraGraph::AddVertex(DijkstraVertex& v) -> void
{
    Vertices.push_back(&v);
}

auto Graph::DijkstraGraph::Relax(DijkstraVertex& u, DijkstraVertex& v) -> void
{
    if (v.Distance > (u.Distance + WeightList[std::make_pair(u.Id, v.Id)]))
    {
        v.Distance = u.Distance + WeightList[std::make_pair(u.Id, v.Id)];
        v.Predecessor = &u;
    }
}

auto Graph::DijkstraGraph::ReorderQueue(std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>& minQueue) -> void
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

auto Graph::DijkstraGraph::Dijkstra(DijkstraVertex& source) -> void
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
