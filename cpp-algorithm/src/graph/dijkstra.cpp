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

void Graph::DijkstraGraph::ReorderQueue(std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>& min_queue)
{
    auto queue = std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>{};
    const auto min_queue_size = static_cast<int>(min_queue.size());

    for (auto i = 0; i < min_queue_size; ++i)
    {
        queue.push(min_queue.top());
        min_queue.pop();
    }

    min_queue = std::move(queue);
}

void Graph::DijkstraGraph::Dijkstra(DijkstraVertex& source)
{
    std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator> min_queue;
    for (auto v : Vertices)
    {
        min_queue.push(v);
    }

    while (!min_queue.empty())
    {
        auto u = min_queue.top();
        min_queue.pop();
        for (auto v : u->Neighbors)
        {
            Relax(*u, *v);
            ReorderQueue(min_queue);
        }
    }
}
