#include "breadth_first_search.h"

#include <queue>

Graph::BfsVertex* Graph::BreadthFirstSearch::Search(BfsVertex& start, BfsVertex& goal)
{
    if (start == goal)
    {
        start.Visit = Finished;
        return &start;
    }

    start.Visit = Visited;
    auto queue = std::queue<BfsVertex*>{};
    queue.push(&start);

    while (queue.empty() == false)
    {
        const auto vertex = queue.front();
        queue.pop();

        for (auto neighbor : vertex->Neighbors)
        {
            if (neighbor->Visit == Unvisited)
            {
                neighbor->Visit = Visited;
                neighbor->Distance = vertex->Distance + 1;
                neighbor->Predecessor = vertex;
                queue.push(neighbor);

                if (neighbor->Id == goal.Id)
                {
                    return neighbor;
                }
            }
        }
        vertex->Visit = Finished;
    }
    return {};
}
