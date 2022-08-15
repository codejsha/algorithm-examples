#ifndef CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H
#define CPP_ALGORITHM_BREADTH_FIRST_SEARCH_H

#include <set>
#include <vector>

namespace Search
{
    /// <summary>
    /// Vertex of graph
    /// </summary>
    /// <typeparam name="T">type of key</typeparam>
    template <typename T>
    struct Vertex
    {
        explicit Vertex(T id)
            : Id(id), Visited(false), Predecessor(nullptr), Distance(0)
        {
        }

        T Id;
        bool Visited;
        std::set<Vertex<T>*> Neighbors;
        Vertex<T>* Predecessor;
        int Distance;
        auto operator==(const Vertex& v) const -> bool;
    };

    /// <summary>
    /// Equality operator ('equal to')
    /// </summary>
    /// <typeparam name="T">type of key</typeparam>
    /// <param name="v">vertex</param>
    /// <returns>equal/not equal</returns>
    template <typename T>
    auto Vertex<T>::operator==(const Vertex& v) const -> bool
    {
        if (this->Id == v.Id)
        {
            return true;
        }
        return false;
    }

    /// <summary>
    /// Graph
    /// </summary>
    class Graph
    {
    public:
        /// <summary>
        /// Add an edge to the graph
        /// </summary>
        /// <param name="u">vertex</param>
        /// <param name="v">vertex</param>
        /// <returns>void</returns>
        auto AddEdge(Vertex<char>& u, Vertex<char>& v) -> void
        {
            AdjacencyList.emplace_back(&u, &v);
            u.Neighbors.insert(&v);
            v.Neighbors.insert(&u);
        }

        /// <summary>
        /// Add a vertex to the graph
        /// </summary>
        /// <param name="v">vertex to add</param>
        /// <returns>void</returns>
        auto AddVertex(Vertex<char>& v) -> void
        {
            Vertices.push_back(&v);
        }

    private:
        std::vector<Vertex<char>*> Vertices;
        std::vector<std::tuple<Vertex<char>*, Vertex<char>*>> AdjacencyList;
    };

    /// <summary>
    /// Breadth-first search
    /// </summary>
    class BreadthFirstSearch
    {
    public:
        explicit BreadthFirstSearch(Graph& graph)
            : Graph(graph)
        {
        }

        /// <summary>
        /// Search the vertex by key
        /// </summary>
        /// <param name="start">starting vertex</param>
        /// <param name="goal">goal vertex</param>
        /// <returns>goal vertex</returns>
        auto Search(Vertex<char>& start, Vertex<char>& goal) -> Vertex<char>*;

    private:
        Graph& Graph;
    };
} // namespace Search

#endif
