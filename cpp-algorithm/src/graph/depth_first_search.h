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
        void AddEdge(DfsVertex& u, DfsVertex& v)
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
        /// Perform depth-first search
        /// </summary>
        /// <param name="graph">graph</param>
        /// <returns>void</returns>
        void Search(DfsGraph& graph);

        /// <summary>
        /// Create depth-first forest
        /// </summary>
        /// <param name="graph">graph</param>
        /// <param name="vertex">vertex</param>
        /// <returns>void</returns>
        void SearchVisit(DfsGraph& graph, DfsVertex& vertex);

    private:
        DfsGraph& Graph;
    };
}

#endif
