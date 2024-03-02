#include "bellman_ford.h"

#include <stdexcept>

void BellmanFord::Graph::BellmanFordAlgorithm(Vertex& source)
{
    for (int i = 0; i < static_cast<int>(vertices.size()) - 1; ++i)
    {
        for (auto& [u, v] : adjacency_list)
        {
            // Relaxation
            const auto weight_uv = weight_list.at(std::make_pair(u->id, v->id));
            if (v->distance > (u->distance + weight_uv))
            {
                v->distance = u->distance + weight_uv;
                v->predecessor = u;
            }
        }
    }
    for (auto& [u, v] : adjacency_list)
    {
        if (v->distance > (u->distance + weight_list.at(std::make_pair(u->id, v->id))))
        {
            throw std::runtime_error("Graph has a negative cycle");
        }
    }
}

void BellmanFord::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

void BellmanFord::Graph::AddEdge(Vertex& u, Vertex& v, int weight)
{
    adjacency_list.emplace_back(&u, &v);
    u.neighbors.insert(&v);
    weight_list.insert(std::make_pair(std::make_pair(u.id, v.id), weight));
}
