#include "right_sibling.h"

void RightSibling::PopulateRightSibling(const BinaryTree::NextExtendedNode<char>* tree)
{
    // if child level is not null, populate the next pointer of the child level
    while (tree && tree->left)
    {
        auto node = tree;
        while (node)
        {
            node->left->next = node->right;

            // if current node has sibling, set the sibling of the right child
            // to the left child of the sibling of the current node
            if (node->next)
            {
                node->right->next = node->next->left;
            }

            node = node->next;
        }
        tree = tree->left;
    }
}
