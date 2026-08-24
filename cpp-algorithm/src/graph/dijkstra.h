#ifndef CPP_ALGORITHM_DIJKSTRA_H
#define CPP_ALGORITHM_DIJKSTRA_H

#include <map>
#include <queue>
#include <set>
#include <vector>

/**
 * @brief Dijkstra algorithm
 * @details Dijkstra algorithm is a single source shortest path algorithm that handle non-negative edge weights.
 * @note
 * - class representation: @ref Dijkstra::Graph, @ref Dijkstra::Vertex, @ref Dijkstra::MinComparator
 */
namespace Dijkstra
{
    /**
     * \brief Vertex of Dijkstra algorithm.
     * \details Each vertex has a unique id, a set of neighbors, a predecessor and a distance.
     */
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

    /**
     * \brief Comparator for priority queue.
     */
    class MinComparator
    {
    public:
        bool operator()(const Vertex* l, const Vertex* r) const { return (l->distance > r->distance); }
    };

    /**
     * \brief Graph of Dijkstra algorithm.
     */
    class Graph
    {
    public:
        /**
         * \brief Dijkstra algorithm.
         * \details A single source shortest path algorithm that handle non-negative edge weights.
         * It find the shortest path between two vertices in a graph.
         * Relaxation is the process of updating the distance of a vertex, when a shorter path is found.
         * \param source source vertex
         */
        void DijkstraAlgorithm(Vertex& source);

        /**
         * \brief Reordering elements of the queue.
         * \param min_queue minimum priority queue
         */
        void ReorderQueue(std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>& min_queue);

        void AddVertex(Vertex& v);
        void AddEdge(Vertex& u, Vertex& v, int weight);

    private:
        std::vector<Vertex*> vertices;
        std::vector<std::tuple<Vertex*, Vertex*>> adjacency_list;
        std::map<std::pair<char, char>, int> weight_list;
    };
}

// ----------------------------------------------------------------------------
inline void Dijkstra::Graph::DijkstraAlgorithm(Vertex& source)
{
    std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator> min_queue;
    for (auto v : vertices)
    {
        min_queue.push(v);
    }

    while (!min_queue.empty())
    {
        const auto u = min_queue.top();
        min_queue.pop();
        for (const auto v : u->neighbors)
        {
            // Relaxation
            const auto weight_uv = weight_list.at(std::make_pair(u->id, v->id));
            if (v->distance > (u->distance + weight_uv))
            {
                v->distance = u->distance + weight_uv;
                v->predecessor = u;
            }
            ReorderQueue(min_queue);
        }
    }
}

// ----------------------------------------------------------------------------
inline void Dijkstra::Graph::ReorderQueue(std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>& min_queue)
{
    auto queue = std::priority_queue<Vertex*, std::vector<Vertex*>, MinComparator>{};
    const int min_queue_size = static_cast<int>(min_queue.size());

    for (int i = 0; i < min_queue_size; ++i)
    {
        queue.push(min_queue.top());
        min_queue.pop();
    }

    min_queue = std::move(queue);
}

// ----------------------------------------------------------------------------
inline void Dijkstra::Graph::AddVertex(Vertex& v)
{
    vertices.push_back(&v);
}

// ----------------------------------------------------------------------------
inline void Dijkstra::Graph::AddEdge(Vertex& u, Vertex& v, int weight)
{
    adjacency_list.emplace_back(&u, &v);
    weight_list.insert(std::make_pair(std::make_pair(u.id, v.id), weight));
    u.neighbors.insert(&v);
}

#endif
