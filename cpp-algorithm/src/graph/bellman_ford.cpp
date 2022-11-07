#include "bellman_ford.h"

#include <stdexcept>

void Graph::BellmanFordGraph::AddEdge(BellmanFordVertex& u, BellmanFordVertex& v, int weight)
{
    AdjacencyList.emplace_back(&u, &v);
    u.Neighbors.insert(&v);
    WeightList.insert(std::make_pair(std::make_pair(u.Id, v.Id), weight));
}

void Graph::BellmanFordGraph::AddVertex(BellmanFordVertex& v)
{
    Vertices.push_back(&v);
}

void Graph::BellmanFordGraph::Relax(BellmanFordVertex& u, BellmanFordVertex& v)
{
    if (v.Distance > (u.Distance + WeightList[std::make_pair(u.Id, v.Id)]))
    {
        v.Distance = u.Distance + WeightList[std::make_pair(u.Id, v.Id)];
        v.Predecessor = &u;
    }
}

void Graph::BellmanFordGraph::BellmanFord(BellmanFordVertex& source)
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
