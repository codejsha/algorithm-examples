#include "dijkstra.h"

void Dijkstra::Graph::DijkstraAlgorithm(Vertex& source)
{
    std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator> min_queue;
    for (auto v : vertices)
    {
        min_queue.push(v);
    }

    while (!min_queue.empty())
    {
        const auto u = min_queue.top();
        min_queue.pop();
        for (const auto v : u->neighbors)
        {
            // Relaxation
            const auto weight_uv = weight_list.at(std::make_pair(u->id, v->id));
            if (v->distance > (u->distance + weight_uv))
            {
                v->distance = u->distance + weight_uv;
                v->predecessor = u;
            }
            ReorderQueue(min_queue);
        }
    }
}

void Dijkstra::Graph::ReorderQueue(std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>& min_queue)
{
    auto queue = std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>{};
    const int min_queue_size = static_cast<int>(min_queue.size());

    for (int i = 0; i < min_queue_size; ++i)
    {
        queue.push(min_queue.top());
        min_queue.pop();
    }

    min_queue = std::move(queue);
}

void Dijkstra::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

void Dijkstra::Graph::AddEdge(Vertex& u, Vertex& v, int weight)
{
    adjacency_list.emplace_back(&u, &v);
    weight_list.insert(std::make_pair(std::make_pair(u.id, v.id), weight));
    u.neighbors.insert(&v);
}
