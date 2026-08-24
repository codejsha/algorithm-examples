#ifndef CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H

#include <set>
#include <vector>

namespace Dfs
{
    enum VisitStatus
    {
        Unvisited,
        Visited,
        Finished
    };

    struct Vertex
    {
        explicit Vertex(const char id)
            : id(id), predecessor(nullptr), visit(Unvisited), discovery_time(0), finishing_time(0)
        {
        }

        char id;
        std::set<Vertex*> neighbors;
        Vertex* predecessor;
        VisitStatus visit;
        int discovery_time;
        int finishing_time;
    };

    class Graph
    {
    public:
        /**
         * \brief Depth first search algorithm.
         * \details Traverses a graph by exploring as far as possible along each branch before backtracking.
         * \param source source node
         * \param dest destination node
         * \return destination node
         */
        static Vertex* DepthFirstSearch(Vertex& source, const Vertex& dest);

        /**
         * \brief Depth first search algorithm.
         * \details Traverses a graph by exploring as far as possible along each branch before backtracking.
         * Each vertex is initially white, is grayed when it is discovered and is black when it is finished.
         * This guarantees that each vertex ends up it exactly one depth-first tree, so that trees are disjoint.
         */
        void DepthFirstSearch2(Vertex& source);

        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v);

        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
        int time;
    };
}

// ----------------------------------------------------------------------------
inline Dfs::Vertex* Dfs::Graph::DepthFirstSearch(Vertex& source, const Vertex& dest)
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

// ----------------------------------------------------------------------------
inline void Dfs::Graph::DepthFirstSearch2(Vertex& source)
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

// ----------------------------------------------------------------------------
inline void Dfs::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

// ----------------------------------------------------------------------------
inline void Dfs::Graph::AddEdge(Vertex& u, Vertex& v)
{
    adjacency_list.emplace_back(&u, &v);
    u.neighbors.insert(&v);
    // v.neighbors.insert(&u);
}

#endif
