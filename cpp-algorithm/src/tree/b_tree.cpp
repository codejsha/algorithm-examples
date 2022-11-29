#include "b_tree.h"

void Tree::BTree::SplitChild(BTreeNode* node, const int index)
{
    const auto left_child = node->Children[index];

    //// create a right child node,
    //// and split keys, children of the left child node

    // create right child
    const auto right_child = new BTreeNode{};
    right_child->IsLeaf = left_child->IsLeaf;

    // split keys of the left child
    // copy keys from median+1 to the end
    auto right_keys = std::vector<char>(
        left_child->Keys.begin() + Degree,
        left_child->Keys.end());
    right_child->Keys = std::move(right_keys);
    // get median key
    const auto median_key = left_child->Keys[Degree - 1];
    // erase keys from median to the end
    left_child->Keys.erase(
        left_child->Keys.begin() + Degree - 1,
        left_child->Keys.end());

    // split children of the left child
    if (left_child->IsLeaf == false)
    {
        auto right_children = std::vector<BTreeNode*>(
            left_child->Children.begin() + Degree,
            left_child->Children.end());
        right_child->Children = std::move(right_children);
        left_child->Children.erase(
            left_child->Children.begin() + Degree,
            left_child->Children.end());
    }

    //// insert a new right node,
    //// and move the median key to the parent node

    // move the median key to parent node
    node->Keys.insert(node->Keys.begin() + index, median_key);

    // insert right node as a new child of node
    node->Children.insert(node->Children.begin() + index + 1, right_child);
}

void Tree::BTree::InsertNonFull(BTreeNode* node, const char key)
{
    auto key_count = node->GetKeyCount();

    // insert key to leaf node
    if (node->IsLeaf == true)
    {
        while ((key_count >= 1) && (node->Keys[key_count - 1] > key))
        {
            --key_count;
        }

        node->Keys.insert(node->Keys.begin() + key_count, key);
    }
    else
    {
        while ((key_count >= 1) && (node->Keys[key_count - 1] > key))
        {
            --key_count;
        }
        ++key_count;

        if (node->Children[key_count - 1]->GetKeyCount() == 2 * Degree - 1)
        {
            SplitChild(node, key_count - 1);
            if (key > node->Keys[key_count - 1])
            {
                ++key_count;
            }
        }

        InsertNonFull(node->Children[key_count - 1], key);
    }
}

void Tree::BTree::Insert(const char key)
{
    Insert(Root, key);
}

auto Tree::BTree::Search(const char key) -> std::pair<BTreeNode*, const int>
{
    return Search(Root, key);
}

void Tree::BTree::Insert(BTreeNode* ref, const char key)
{
    const auto root_node = ref;

    if (ref->GetKeyCount() == 2 * Degree - 1)
    {
        const auto new_node = new BTreeNode{};
        Root = new_node;
        new_node->IsLeaf = false;
        new_node->Children.push_back(root_node);
        SplitChild(new_node, 0);
        InsertNonFull(new_node, key);
    }
    else
    {
        InsertNonFull(root_node, key);
    }
}

auto Tree::BTree::Search(BTreeNode* ref, const char key) -> std::pair<BTreeNode*, const int>
{
    auto index = 0;
    const auto key_count = ref->GetKeyCount();

    // find the smallest index that key <= ref->Keys[index]
    while ((key_count > index) && (key > ref->Keys[index]))
    {
        ++index;
    }

    // check to see whether key is found
    if ((key_count > index) && (key == ref->Keys[index]))
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
