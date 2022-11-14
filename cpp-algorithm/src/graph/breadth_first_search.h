#ifndef CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H

#include "graph.h"

#include <set>
#include <vector>

namespace Graph
{
    /// @brief Vertex of graph.
    struct BfsVertex : Vertex<char>
    {
        explicit BfsVertex(const char id)
            : Vertex<char>(id), Predecessor(nullptr), Visit(Unvisited), Distance(0)
        {
        }

        std::set<BfsVertex*> Neighbors;
        BfsVertex* Predecessor;
        VisitStatus Visit;
        int Distance;
    };

    /// @brief Breadth first search algorithm.
    class BfsGraph
    {
    public:
        /// @brief Add an edge to the graph.
        /// @param u vertex
        /// @param v vertex
        void AddEdge(BfsVertex& u, BfsVertex& v)
        {
            AdjacencyList.emplace_back(&u, &v);
            u.Neighbors.insert(&v);
            v.Neighbors.insert(&u);
        }

        /// @brief Add a vertex to the graph.
        /// @param v vertex to be added
        void AddVertex(BfsVertex& v)
        {
            Vertices.push_back(&v);
        }

    private:
        std::vector<BfsVertex*> Vertices;
        std::vector<std::tuple<BfsVertex*, BfsVertex*>> AdjacencyList;
    };

    /// @brief Breadth first search.
    class BreadthFirstSearch
    {
    public:
        explicit BreadthFirstSearch(BfsGraph& graph)
            : Graph(graph)
        {
        }

        /// @brief Search the vertex by key.
        /// @param start starting vertex
        /// @param goal goal vertex
        /// @return goal vertex
        BfsVertex* Search(BfsVertex& start, BfsVertex& goal);

    private:
        BfsGraph& Graph;
    };
}

#endif
