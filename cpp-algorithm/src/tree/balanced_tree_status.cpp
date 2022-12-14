#include "balanced_tree_status.h"

#include <algorithm>

auto BalancedTree::IsBalanced(const BinaryTree::ExtendedNode<int>* tree) -> bool
{
   return CheckBalanced(tree).is_balanced;
}

auto BalancedTree::CheckBalanced(const BinaryTree::ExtendedNode<int>* tree) -> BalancedStatus
{
   if (tree == nullptr)
   {
       return {true, -1};
   }

   const auto [is_left_balanced, left_height] = CheckBalanced(tree->left);
   if (!is_left_balanced)
   {
       return {false, 0};
   }

   const auto [is_right_balanced, right_height] = CheckBalanced(tree->right);
   if (!is_right_balanced)
   {
       return {false, 0};
   }

   const auto is_balanced = std::abs(left_height - right_height) <= 1;
   const auto height = std::max(left_height, right_height) + 1;
   return {is_balanced, height};
}
