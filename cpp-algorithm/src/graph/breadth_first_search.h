#ifndef CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H

#include "graph.h"

#include <set>
#include <vector>

namespace Graph
{
    /// <summary>
    /// Vertex of graph
    /// </summary>
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

    /// <summary>
    /// Breadth-first search graph
    /// </summary>
    class BfsGraph
    {
    public:
        /// <summary>
        /// Add an edge to the graph
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <returns>void</returns>
        void AddEdge(BfsVertex& u, BfsVertex& v)
        {
            AdjacencyList.emplace_back(&u, &v);
            u.Neighbors.insert(&v);
            v.Neighbors.insert(&u);
        }

        /// <summary>
        /// Add a vertex to the graph
        /// </summary>
        /// <param name="v">vertex to add</param>
        /// <returns>void</returns>
        void AddVertex(BfsVertex& v)
        {
            Vertices.push_back(&v);
        }

    private:
        std::vector<BfsVertex*> Vertices;
        std::vector<std::tuple<BfsVertex*, BfsVertex*>> AdjacencyList;
    };

    /// <summary>
    /// Breadth-first search
    /// </summary>
    class BreadthFirstSearch
    {
    public:
        explicit BreadthFirstSearch(BfsGraph& graph)
            : Graph(graph)
        {
        }

        /// <summary>
        /// Search the vertex by key
        /// </summary>
        /// <param name="start">starting vertex</param>
        /// <param name="goal">goal vertex</param>
        /// <returns>goal vertex</returns>
        BfsVertex* Search(BfsVertex& start, BfsVertex& goal);

    private:
        BfsGraph& Graph;
    };
}

#endif
