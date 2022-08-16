#ifndef CPP_ALGORITHM_GRAPH_H
#define CPP_ALGORITHM_GRAPH_H

namespace Graph
{
    /// <summary>
    /// Visit status of the node
    /// </summary>
    enum VisitStatus
    {
        Unvisited,
        Visited,
        Finished
    };

    /// <summary>
    /// Vertex of graph
    /// </summary>
    /// <typeparam name="T">type of key</typeparam>
    template <typename T>
    struct Vertex
    {
        explicit Vertex(T id)
            : Id(id), Visit(Unvisited)
        {
        }

        T Id;
        VisitStatus Visit;
        auto operator==(const Vertex& v) const -> bool;
    };

    /// <summary>
    /// Equality operator ('equal to')
    /// </summary>
    /// <typeparam name="T">type of key</typeparam>
    /// <param name="v">vertex</param>
    /// <returns>equal or not equal</returns>
    template <typename T>
    auto Vertex<T>::operator==(const Vertex& v) const -> bool
    {
        if (this->Id == v.Id)
        {
            return true;
        }
        return false;
    }

} // namespace Graph

#endif
