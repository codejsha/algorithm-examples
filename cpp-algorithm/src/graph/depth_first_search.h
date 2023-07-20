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
        static auto DepthFirstSearch(Vertex& source, const Vertex& dest) -> Vertex*;

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

#endif
