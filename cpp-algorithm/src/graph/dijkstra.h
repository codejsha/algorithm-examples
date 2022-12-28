#ifndef CPP_ALGORITHM_DIJKSTRA_H
#define CPP_ALGORITHM_DIJKSTRA_H

#include <map>
#include <queue>
#include <set>
#include <vector>

namespace Dijkstra
{
    struct Vertex
    {
        explicit Vertex(const char id)
            : id(id), neighbors(std::set<Vertex*>()), predecessor(nullptr), distance(std::numeric_limits<int>::max())
        {
        }

        char id;
        std::set<Vertex*> neighbors;
        Vertex* predecessor;
        int distance;
    };

    /// @brief Comparator for priority queue.
    class MinComparator
    {
    public:
        auto operator()(const Vertex* l, const Vertex* r) const -> bool
        {
            return (l->distance > r->distance);
        }
    };

    class Graph
    {
    public:
        /// @brief Dijkstra algorithm.
        /// @details A single source shortest path algorithm that handle non-negative edge weights.
        /// It find the shortest path between two vertices in a graph.
        /// Relaxation is the process of updating the distance of a vertex, when a shorter path is found.
        /// @param source source vertex
        void DijkstraAlgorithm(Vertex& source);

        /// @brief Reordering elements of the queue.
        /// @param min_queue minimum priority queue
        void ReorderQueue(std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>& min_queue);

        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v, int weight);

    private:
        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
        std::map<std::pair<char, char>, int> weight_list;
    };
}

#endif
