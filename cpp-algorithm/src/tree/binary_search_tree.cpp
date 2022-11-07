#include "binary_search_tree.h"

void Tree::BinarySearchTree::Insert(const int key)
{
    if (Root == nullptr)
    {
        Root = new BinarySearchNode(key);
        return;
    }
    Insert(Root, key);
}

void Tree::BinarySearchTree::Delete(const int key)
{
    if (Root == nullptr)
    {
        return;
    }
    Delete(Root, key);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeMinimum()
{
    return TreeMinimum(Root);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeMaximum()
{
    return TreeMaximum(Root);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreePredecessor(const int key)
{
    auto node = IterativeTreeSearch(key);

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->Left != nullptr)
    {
        return TreeMaximum(node->Left);
    }

    auto parent = node->Parent;
    while ((parent != nullptr) && (node == parent->Left))
    {
        node = parent;
        parent = parent->Parent;
    }

    return parent;
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeSuccessor(const int key)
{
    auto node = IterativeTreeSearch(key);

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->Right != nullptr)
    {
        return TreeMinimum(node->Right);
    }

    auto parent = node->Parent;
    while ((parent != nullptr) && (node == parent->Right))
    {
        node = parent;
        parent = parent->Parent;
    }

    return parent;
}

Tree::BinarySearchNode* Tree::BinarySearchTree::RecursiveTreeSearch(const int key)
{
    return RecursiveTreeSearch(Root, key);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::IterativeTreeSearch(const int key)
{
    return IterativeTreeSearch(Root, key);
}

void Tree::BinarySearchTree::Insert(BinarySearchNode*& ref, const int key)
{
    if (ref == nullptr)
    {
        ref = new BinarySearchNode(key);
        return;
    }
    if (key < ref->Key)
    {
        Insert(ref->Left, key);
        ref->Left->Parent = ref;
    }
    else
    {
        Insert(ref->Right, key);
        ref->Right->Parent = ref;
    }
}

void Tree::BinarySearchTree::Delete(BinarySearchNode*& ref, const int key)
{
    if (ref == nullptr)
    {
        return;
    }
    if (key < ref->Key)
    {
        Delete(ref->Left, key);
    }
    else if (key > ref->Key)
    {
        Delete(ref->Right, key);
    }
    else
    {
        // leaf node
        if (ref->Left == nullptr && ref->Right == nullptr)
        {
            delete ref;
            ref = nullptr;
        }
        // ref node does not have left child node
        else if (ref->Left == nullptr)
        {
            const auto temp = ref;
            ref = ref->Right;
            ref->Parent = temp->Parent;
            delete temp;
        }
        // ref node does not have right child node
        else if (ref->Right == nullptr)
        {
            const auto temp = ref;
            ref = ref->Left;
            ref->Parent = temp->Parent;
            delete temp;
        }
        // ref node has left and right child node
        else
        {
            const auto temp = TreeMinimum(ref->Right);
            ref->Key = temp->Key;
            Delete(ref->Right, temp->Key);
        }
    }
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeMinimum(BinarySearchNode* ref)
{
    while (ref->Left != nullptr)
    {
        ref = ref->Left;
    }
    return ref;
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeMaximum(BinarySearchNode* ref)
{
    while (ref->Right != nullptr)
    {
        ref = ref->Right;
    }
    return ref;
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreePredecessor(BinarySearchNode* ref)
{
    return TreePredecessor(ref->Key);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::TreeSuccessor(BinarySearchNode* ref)
{
    return TreeSuccessor(ref->Key);
}

Tree::BinarySearchNode* Tree::BinarySearchTree::RecursiveTreeSearch(BinarySearchNode* ref, const int key)
{
    if ((ref == nullptr) || key == ref->Key)
    {
        return ref;
    }

    if (key < ref->Key)
    {
        return RecursiveTreeSearch(ref->Left, key);
    }
    else
    {
        return RecursiveTreeSearch(ref->Right, key);
    }
}

Tree::BinarySearchNode* Tree::BinarySearchTree::IterativeTreeSearch(BinarySearchNode* ref, const int key)
{
    while ((ref != nullptr) && (key != ref->Key))
    {
        if (key < ref->Key)
        {
            ref = ref->Left;
        }
        else
        {
            ref = ref->Right;
        }
    }
    return ref;
}
