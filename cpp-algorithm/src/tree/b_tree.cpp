#include "b_tree.h"

auto Tree::BTree::SplitChild(BTreeNode* node, const int index) -> void
{
    const auto leftChild = node->Children[index];

    //// create a right child node,
    //// and split keys, children of the left child node

    // create right child
    const auto rightChild = new BTreeNode{};
    rightChild->IsLeaf = leftChild->IsLeaf;

    // split keys of the left child
    // copy keys from median+1 to the end
    auto rightKeys = std::vector<char>(
        leftChild->Keys.begin() + Degree,
        leftChild->Keys.end());
    rightChild->Keys = std::move(rightKeys);
    // get median key
    const auto medianKey = leftChild->Keys[Degree - 1];
    // erase keys from median to the end
    leftChild->Keys.erase(
        leftChild->Keys.begin() + Degree - 1,
        leftChild->Keys.end());

    // split children of the left child
    if (leftChild->IsLeaf == false)
    {
        auto rightChildChildren = std::vector<BTreeNode*>(
            leftChild->Children.begin() + Degree,
            leftChild->Children.end());
        rightChild->Children = std::move(rightChildChildren);
        leftChild->Children.erase(
            leftChild->Children.begin() + Degree,
            leftChild->Children.end());
    }

    /// insert a new right node, and move the median key to the parent node

    // move the median key to parent node
    node->Keys.insert(node->Keys.begin() + index, medianKey);

    // insert right node as a new child of node
    node->Children.insert(node->Children.begin() + index + 1, rightChild);
}

auto Tree::BTree::InsertNonFull(BTreeNode* node, const char key) -> void
{
    auto keyCount = node->GetKeyCount();

    // insert key to leaf node
    if (node->IsLeaf == true)
    {
        while ((keyCount >= 1) && (node->Keys[keyCount - 1] > key))
        {
            --keyCount;
        }

        node->Keys.insert(node->Keys.begin() + keyCount, key);
    }
    else
    {
        while ((keyCount >= 1) && (node->Keys[keyCount - 1] > key))
        {
            --keyCount;
        }
        ++keyCount;

        if (node->Children[keyCount - 1]->GetKeyCount() == 2 * Degree - 1)
        {
            SplitChild(node, keyCount - 1);
            if (key > node->Keys[keyCount - 1])
            {
                ++keyCount;
            }
        }

        InsertNonFull(node->Children[keyCount - 1], key);
    }
}

auto Tree::BTree::Insert(const char key) -> void
{
    Insert(Root, key);
}

auto Tree::BTree::Search(const char key) -> std::pair<BTreeNode*, const int>
{
    return Search(Root, key);
}

auto Tree::BTree::Insert(BTreeNode* ref, const char key) -> void
{
    const auto rootNode = ref;

    if (ref->GetKeyCount() == 2 * Degree - 1)
    {
        const auto newNode = new BTreeNode{};
        Root = newNode;
        newNode->IsLeaf = false;
        newNode->Children.push_back(rootNode);
        SplitChild(newNode, 0);
        InsertNonFull(newNode, key);
    }
    else
    {
        InsertNonFull(rootNode, key);
    }
}

auto Tree::BTree::Search(BTreeNode* ref, const char key) -> std::pair<BTreeNode*, const int>
{
    auto index = 0;
    const auto keyCount = ref->GetKeyCount();

    // find smallest index that key <= ref->Keys[index]
    while ((keyCount > index) && (key > ref->Keys[index]))
    {
        ++index;
    }

    // check to see whether key is found
    if ((keyCount > index) && (key == ref->Keys[index]))
    {
        return std::make_pair(ref, index);
    }
    // key is not found and if node is a leaf
    else if (ref->IsLeaf == true)
    {
        return std::pair<BTreeNode*, const int>{};
    }
    // key is not found and recurse to search subtree of ref node
    else
    {
        return Search(ref->Children[index], key);
    }
}
