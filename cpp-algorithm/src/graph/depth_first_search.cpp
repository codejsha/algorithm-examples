#include "depth_first_search.h"

auto Dfs::Graph::DepthFirstSearch(Vertex& source, const Vertex& dest) -> Vertex*
{
    source.visit = Visited;
    if (source.id == dest.id)
    {
        return &source;
    }
    for (const auto v : source.neighbors)
    {
        if (v->visit == Unvisited)
        {
            v->predecessor = &source;
            v->discovery_time = source.discovery_time + 1;
            const auto u = DepthFirstSearch(*v, dest);
            if (u != nullptr)
            {
                return u;
            }
        }
    }
    return nullptr;
}

void Dfs::Graph::DepthFirstSearch2(Vertex& source)
{
    source.visit = Visited;
    ++time;
    source.discovery_time = time;

    for (const auto neighbor : source.neighbors)
    {
        if (neighbor->visit == Unvisited)
        {
            neighbor->predecessor = &source;
            DepthFirstSearch2(*neighbor);
        }
    }

    source.visit = Finished;
    ++time;
    source.finishing_time = time;
}

void Dfs::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

void Dfs::Graph::AddEdge(Vertex& u, Vertex& v)
{
    adjacency_list.emplace_back(&u, &v);
    u.neighbors.insert(&v);
    // v.neighbors.insert(&u);
}
