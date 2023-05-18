#include "breadth_first_search.h"

#include <queue>

auto Bfs::Graph::BreadthFirstSearch(Vertex& start, const Vertex& goal) -> Vertex*
{
    if (start.id == goal.id)
    {
        start.visit = Finished;
        return &start;
    }

    start.visit = Visited;
    auto queue = std::queue<Vertex*>{};
    queue.push(&start);

    while (queue.empty() == false)
    {
        const auto vertex = queue.front();
        queue.pop();

        for (auto v : vertex->neighbors)
        {
            if (v->visit == Unvisited)
            {
                v->visit = Visited;
                v->distance = vertex->distance + 1;
                v->predecessor = vertex;
                queue.push(v);

                if (v->id == goal.id)
                {
                    return v;
                }
            }
        }
        vertex->visit = Finished;
    }
    return {};
}

void Bfs::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

void Bfs::Graph::AddEdge(Vertex& u, Vertex& v)
{
    adjacency_list.emplace_back(&u, &v);
    u.neighbors.insert(&v);
    // v.neighbors.insert(&u);
}
