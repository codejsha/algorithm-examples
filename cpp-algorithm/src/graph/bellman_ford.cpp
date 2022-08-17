#include "bellman_ford.h"

#include <stdexcept>

auto Graph::BellmanFordGraph::AddEdge(BellmanFordVertex& u, BellmanFordVertex& v, int weight) -> void
{
    AdjacencyList.emplace_back(&u, &v);
    u.Neighbors.insert(&v);
    WeightList.insert(std::make_pair(std::make_pair(u.Id, v.Id), weight));
}

auto Graph::BellmanFordGraph::AddVertex(BellmanFordVertex& v) -> void
{
    Vertices.push_back(&v);
}

auto Graph::BellmanFordGraph::Relax(BellmanFordVertex& u, BellmanFordVertex& v) -> void
{
    if (v.Distance > (u.Distance + WeightList[std::make_pair(u.Id, v.Id)]))
    {
        v.Distance = u.Distance + WeightList[std::make_pair(u.Id, v.Id)];
        v.Predecessor = &u;
    }
}

auto Graph::BellmanFordGraph::BellmanFord(BellmanFordVertex& source) -> void
{
    for (int i = 0; i < static_cast<int>(Vertices.size()) - 1; ++i)
    {
        for (auto& [u, v] : AdjacencyList)
        {
            Relax(*u, *v);
        }
    }
    for (auto& [u, v] : AdjacencyList)
    {
        if (v->Distance > (u->Distance + WeightList[std::make_pair(u->Id, v->Id)]))
        {
            throw std::runtime_error("Graph has a negative cycle");
        }
    }
}
