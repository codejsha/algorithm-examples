#ifndef CPP_ALGORITHM_BELLMAN_FORD_H
#define CPP_ALGORITHM_BELLMAN_FORD_H

#include "graph.h"

#include <map>
#include <set>
#include <vector>

namespace Graph
{
    /// @brief Vertex of graph.
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

    /// @brief Bellman-Ford algorithm.
    class BellmanFordGraph
    {
    public:

        /// @brief Add an edge to the graph.
        /// @param u vertex
        /// @param v vertex
        /// @param weight weight of the edge
        void AddEdge(BellmanFordVertex& u, BellmanFordVertex& v, int weight);

        /// @brief Add a vertex to the graph.
        /// @param v vertex to be added
        void AddVertex(BellmanFordVertex& v);

        /// @brief Investigate whether the shortest path can be improved, and update.
        /// @param u vertex
        /// @param v vertex
        void Relax(BellmanFordVertex& u, BellmanFordVertex& v);

        /// @brief Find the shortest path from a source vertex to all other vertices.
        /// @param source source vertex
        void BellmanFord(BellmanFordVertex& source);

    private:
        std::vector<BellmanFordVertex*> Vertices;
        std::vector<std::tuple<BellmanFordVertex*, BellmanFordVertex*>> AdjacencyList;
        std::map<std::pair<char, char>, int> WeightList;
    };
}

#endif
