#ifndef CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H

#include <queue>
#include <set>
#include <vector>

namespace Bfs
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
            : id(id), neighbors(std::set<Vertex*>()), predecessor(nullptr), visit(Unvisited), distance(0)
        {
        }

        char id;
        std::set<Vertex*> neighbors;
        Vertex* predecessor;
        VisitStatus visit;
        int distance;
    };

    class Graph
    {
    public:
        /**
         * \brief Breadth first search algorithm.
         * \details A search algorithm that traverses a graph layer by layer.
         * \param start starting vertex
         * \param goal goal vertex
         * \return goal vertex
         */
        static Vertex* BreadthFirstSearch(Vertex& start, const Vertex& goal);

        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v);

        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
    };
}

// ----------------------------------------------------------------------------
inline Bfs::Vertex* Bfs::Graph::BreadthFirstSearch(Vertex& start, const Vertex& goal)
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

// ----------------------------------------------------------------------------
inline void Bfs::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

// ----------------------------------------------------------------------------
inline void Bfs::Graph::AddEdge(Vertex& u, Vertex& v)
{
    adjacency_list.emplace_back(&u, &v);
    u.neighbors.insert(&v);
    // v.neighbors.insert(&u);
}

#endif
