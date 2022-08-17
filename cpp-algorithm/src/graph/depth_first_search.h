#ifndef CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_DEPTH_FIRST_SEARCH_H

#include "graph.h"

#include <set>
#include <vector>

namespace Graph
{
    /// <summary>
    /// Vertex of graph
    /// </summary>
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

    /// <summary>
    /// Depth-first search graph
    /// </summary>
    class DfsGraph
    {
    public:
        explicit DfsGraph()
            : Time(0)
        {
        }

        /// <summary>
        /// Add an edge to the graph
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <returns>void</returns>
        auto AddEdge(DfsVertex& u, DfsVertex& v) -> void
        {
            AdjacencyList.emplace_back(&u, &v);

            // directed
            u.Neighbors.insert(&v);
        }

        /// <summary>
        /// Add a vertex to the graph
        /// </summary>
        /// <param name="v">vertex to add</param>
        /// <returns>void</returns>
        auto AddVertex(DfsVertex& v) -> void
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

        [[nodiscard]] auto GetTime() const -> int
        {
            return Time;
        }

        auto SetTime(const int time) -> void
        {
            Time = time;
        }

    private:
        std::vector<DfsVertex*> Vertices;
        std::vector<std::tuple<DfsVertex*, DfsVertex*>> AdjacencyList;
        int Time;
    };

    /// <summary>
    /// Depth-first search
    /// </summary>
    class DepthFirstSearch
    {
    public:
        explicit DepthFirstSearch(DfsGraph& graph)
            : Graph(graph)
        {
        }

        /// <summary>
        /// Search the vertex by key
        /// </summary>
        /// <param name="start">starting vertex</param>
        /// <param name="goal">goal vertex</param>
        /// <returns>goal vertex</returns>
        auto Search(DfsGraph& graph) -> void;
        auto SearchVisit(DfsGraph& graph, DfsVertex& vertex) -> void;

    private:
        DfsGraph& Graph;
    };
} // namespace Graph

#endif
