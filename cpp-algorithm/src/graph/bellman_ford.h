#ifndef CPP_ALGORITHM_BELLMAN_FORD_H
#define CPP_ALGORITHM_BELLMAN_FORD_H

#include "graph.h"

#include <map>
#include <set>
#include <vector>

namespace Graph
{
    /// <summary>
    /// Vertex of graph
    /// </summary>
    struct BellmanFordVertex : Vertex<char>
    {
        explicit BellmanFordVertex(const char id)
            : Vertex<char>(id), Predecessor(nullptr), Distance(std::numeric_limits<int>::max())
        {
        }

        std::set<BellmanFordVertex*> Neighbors;
        BellmanFordVertex* Predecessor;
        int Distance;
    };

    /// <summary>
    /// Bellman ford graph
    /// </summary>
    class BellmanFordGraph
    {
    public:
        /// <summary>
        /// Add an edge to the graph
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <param name="weight">weight of edge</param>
        /// <returns>void</returns>
        void AddEdge(BellmanFordVertex& u, BellmanFordVertex& v, int weight);

        /// <summary>
        /// Add a vertex to the graph
        /// </summary>
        /// <param name="v">vertex to add</param>
        /// <returns>void</returns>
        void AddVertex(BellmanFordVertex& v);

        /// <summary>
        /// Investigate whether the shortest path can be improved, and update
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <returns>void</returns>
        void Relax(BellmanFordVertex& u, BellmanFordVertex& v);

        /// <summary>
        /// Find the shortest path from a source vertex to all other vertices
        /// </summary>
        /// <param name="source">source vertex</param>
        /// <returns>void</returns>
        void BellmanFord(BellmanFordVertex& source);

    private:
        std::vector<BellmanFordVertex*> Vertices;
        std::vector<std::tuple<BellmanFordVertex*, BellmanFordVertex*>> AdjacencyList;
        std::map<std::pair<char, char>, int> WeightList;
    };
}

#endif
