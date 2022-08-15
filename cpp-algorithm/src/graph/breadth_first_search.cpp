#include "breadth_first_search.h"

#include <queue>

auto Search::BreadthFirstSearch::Search(Vertex<char>& start, Vertex<char>& goal) -> Vertex<char>*
{
    start.Visited = true;

    if (start == goal)
    {
        return &start;
    }

    auto queue = std::queue<Vertex<char>*>{};
    queue.push(&start);

    while (queue.empty() == false)
    {
        const auto vertex = queue.front();
        queue.pop();

        for (auto neighbor : vertex->Neighbors)
        {
            if (neighbor->Visited == false)
            {
                neighbor->Visited = true;
                neighbor->Distance = vertex->Distance + 1;
                neighbor->Predecessor = vertex;
                queue.push(neighbor);

                if (neighbor->Id == goal.Id)
                {
                    return neighbor;
                }
            }
        }
    }
    return {};
}
