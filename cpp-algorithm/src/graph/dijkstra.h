#ifndef CPP_ALGORITHM_DIJKSTRA_H
#define CPP_ALGORITHM_DIJKSTRA_H

#include "graph.h"

#include <map>
#include <queue>
#include <set>
#include <vector>

namespace Graph
{
    /// @brief Vertex of graph.
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

    /// @brief Comparator for priority queue.
    class MinComparator
    {
    public:
        auto operator()(const DijkstraVertex* l, const DijkstraVertex* r) const -> bool
        {
            return (l->Distance > r->Distance);
        }
    };

    /// @brief Dijkstra algorithm.
    class DijkstraGraph
    {
    public:
        /// @brief Add an edge to the graph.
        /// @param u vertex
        /// @param v vertex
        /// @param weight weight of the edge
        void AddEdge(DijkstraVertex& u, DijkstraVertex& v, int weight);

        /// @brief Add a vertex to the graph.
        /// @param v vertex to be added
        void AddVertex(DijkstraVertex& v);
        
        /// @brief Investigate whether the shortest path can be improved, and update.
        /// @param u vertex
        /// @param v vertex
        void Relax(DijkstraVertex& u, DijkstraVertex& v);

        /// @brief Reordering elements of the queue.
        /// @param min_queue minimum priority queue
        void ReorderQueue(std::priority_queue<DijkstraVertex*, std::vector<DijkstraVertex*>, MinComparator>& min_queue);

        /// @brief Perform Dijkstra's algorithm on the graph.
        /// @param source source vertex
        void Dijkstra(DijkstraVertex& source);

    private:
        std::vector<DijkstraVertex*> Vertices;
        std::vector<std::tuple<DijkstraVertex*, DijkstraVertex*>> AdjacencyList;
        std::map<std::pair<char, char>, int> WeightList;
    };
}

#endif
