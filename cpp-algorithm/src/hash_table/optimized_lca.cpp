#include "optimized_lca.h"

#include <stdexcept>
#include <unordered_set>

auto OptimizedLca::FindOptimizedLowestCommonAncestor(const BinaryTree::ExtendedNode<int>* node1,
                                                     const BinaryTree::ExtendedNode<int>* node2)
    -> const BinaryTree::ExtendedNode<int>*
{
    auto iter1 = node1;
    auto iter2 = node2;
    std::unordered_set<const BinaryTree::ExtendedNode<int>*> nodes_on_path;

    // traverse up node1 and node2 together until they meet
    while (iter1 != nullptr || iter2 != nullptr)
    {
        if (iter1 != nullptr)
        {
            if (nodes_on_path.contains(iter1))
            {
                return iter1;
            }
            nodes_on_path.insert(iter1);
            iter1 = iter1->parent;
        }
        if (iter2 != nullptr)
        {
            if (nodes_on_path.contains(iter2))
            {
                return iter2;
            }
            nodes_on_path.insert(iter2);
            iter2 = iter2->parent;
        }
    }
    throw std::invalid_argument("No common ancestor found.");
}
