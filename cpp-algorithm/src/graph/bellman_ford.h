#ifndef CPP_ALGORITHM_BELLMAN_FORD_H
#define CPP_ALGORITHM_BELLMAN_FORD_H

#include <map>
#include <set>
#include <vector>

namespace BellmanFord
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

    class Graph
    {
    public:
        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v, int weight);

        /// @brief Bellman-Ford algorithm. Find the shortest path from a source vertex to all other vertices.
        /// @details A single source shortest path algorithm that can handle negative edge weights.
        /// It finds the shortest path from a source vertex to all other vertices in a weighted graph.
        /// @param source source vertex
        void BellmanFordAlgorithm(Vertex& source);

        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
        std::map<std::pair<char, char>, int> weight_list;
    };
}

#endif
