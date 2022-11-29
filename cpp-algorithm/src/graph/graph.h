#ifndef CPP_ALGORITHM_GRAPH_H
#define CPP_ALGORITHM_GRAPH_H

namespace Graph
{
    /// @brief Vertex of graph.
    /// @tparam T type of key
    template <typename T>
    struct Vertex
    {
        explicit Vertex(T id)
            : Id(id)
        {
        }

        T Id;
        auto operator==(const Vertex& v) const -> bool;
    };

    /// @brief Equality operator ('equal to').
    /// @tparam T type of key
    /// @param v vertex
    /// @return whether equal or not
    template <typename T>
    auto Vertex<T>::operator==(const Vertex& v) const -> bool
    {
        if (this->Id == v.Id)
        {
            return true;
        }
        return false;
    }

    /// @brief Visit status of the node.
    enum VisitStatus
    {
        Unvisited,
        Visited,
        Finished
    };
}

#endif
