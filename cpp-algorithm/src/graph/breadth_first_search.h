#ifndef CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H

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
        static auto BreadthFirstSearch(Vertex& start, const Vertex& goal) -> Vertex*;

        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v);

        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
    };
}

#endif
