#ifndef CPP_ALGORITHM_DIJKSTRA_H
#define CPP_ALGORITHM_DIJKSTRA_H

#include "graph.h"

#include <map>
#include <queue>
#include <set>
#include <vector>

namespace Graph
{
    /// <summary>
    /// Vertex of graph
    /// </summary>
    struct DijkstraVertex : Vertex<char>
    {
        explicit DijkstraVertex(const char id)
            : Vertex<char>(id), Predecessor(nullptr), Distance(std::numeric_limits<int>::max())
        {
        }

        std::set<DijkstraVertex*> Neighbors;
        DijkstraVertex* Predecessor;
        int Distance;
    };

    /// <summary>
    /// Comparator
    /// </summary>
    class MinComparator
    {
    public:
        bool operator()(const DijkstraVertex* l, const DijkstraVertex* r) const
        {
            return (l->Distance > r->Distance);
        }
    };

    /// <summary>
    /// Dijkstra graph
    /// </summary>
    class DijkstraGraph
    {
    public:
        /// Add an edge to the graph
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <param name="weight">weight of edge</param>
        /// <returns>void</returns>
        auto AddEdge(DijkstraVertex& u, DijkstraVertex& v, int weight) -> void;

        /// <summary>
        /// Add a vertex to the graph
        /// </summary>
        /// <param name="v">vertex to add</param>
        /// <returns>void</returns>
        auto AddVertex(DijkstraVertex& v) -> void;

        /// <summary>
        /// Investigate whether the shortest path can be improved, and update
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <returns>void</returns>
        auto Relax(DijkstraVertex& u, DijkstraVertex& v) -> void;

        /// <summary>
        /// Reordering elements of the queue
        /// </summary>
        /// <param name="minQueue">mininum priority queue</param>
        /// <returns>void</returns>
        auto ReorderQueue(std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>& minQueue) -> void;

        /// <summary>
        /// Perform Dijkstra's algorithm on the graph
        /// </summary>
        /// <param name="source">source vertex</param>
        /// <returns>void</returns>
        auto Dijkstra(DijkstraVertex& source) -> void;

    private:
        std::vector<DijkstraVertex*> Vertices;
        std::vector<std::tuple<DijkstraVertex*, DijkstraVertex*>> AdjacencyList;
        std::map<std::pair<char, char>, int> WeightList;
    };
} // namespace Graph

#endif
