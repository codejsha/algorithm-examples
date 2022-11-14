#ifndef CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H

#include "graph.h"

#include <set>
#include <vector>

namespace Graph
{
    /// @brief Vertex of graph.
    struct DfsVertex : Vertex<char>
    {
        explicit DfsVertex(const char id)
            : Vertex<char>(id), Predecessor(nullptr), Visit(Unvisited), DiscoveryTime(0), FinishingTime(0)
        {
        }

        std::set<DfsVertex*> Neighbors;
        DfsVertex* Predecessor;
        VisitStatus Visit;
        int DiscoveryTime;
        int FinishingTime;
    };

    /// @brief Depth first search graph.
    class DfsGraph
    {
    public:
        explicit DfsGraph()
            : Time(0)
        {
        }

        /// @brief Add an edge to the graph.
        /// @param u vertex
        /// @param v vertex
        void AddEdge(DfsVertex& u, DfsVertex& v)
        {
            AdjacencyList.emplace_back(&u, &v);

            // directed
            u.Neighbors.insert(&v);
        }

        /// @brief Add a vertex to the graph.
        /// @param v vertex to be added
        void AddVertex(DfsVertex& v)
        {
            Vertices.push_back(&v);
        }

        [[nodiscard]] std::vector<DfsVertex*> GetVertices() const
        {
            return Vertices;
        }

        [[nodiscard]] std::vector<std::tuple<DfsVertex*, DfsVertex*>> GetAdjacencyList() const
        {
            return AdjacencyList;
        }

        [[nodiscard]] int GetTime() const
        {
            return Time;
        }

        void SetTime(const int time)
        {
            Time = time;
        }

    private:
        std::vector<DfsVertex*> Vertices;
        std::vector<std::tuple<DfsVertex*, DfsVertex*>> AdjacencyList;
        int Time;
    };

    /// @brief Depth first search algorithm.
    class DepthFirstSearch
    {
    public:
        explicit DepthFirstSearch(DfsGraph& graph)
            : Graph(graph)
        {
        }

        /// @brief Perform depth first search.
        /// @param graph graph
        void Search(DfsGraph& graph);

        /// @brief Create depth-first forest.
        /// @param graph graph 
        /// @param vertex vertex
        void SearchVisit(DfsGraph& graph, DfsVertex& vertex);

    private:
        DfsGraph& Graph;
    };
}

#endif
