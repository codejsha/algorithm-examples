#include "b_tree.h"

void BTree::Tree::SplitChild(Node* node, int index)
{
    auto left_child = node->children[index];

    //// create a right child node,
    //// and split keys, children of the left child node

    // create right child
    auto right_child = new Node{};
    right_child->is_leaf = left_child->is_leaf;

    // split keys of the left child
    // copy keys from median+1 to the end
    auto right_keys = std::vector<char>(left_child->keys.begin() + degree, left_child->keys.end());
    right_child->keys = std::move(right_keys);
    // get median key
    auto median_key = left_child->keys[degree - 1];
    // erase keys from median to the end
    left_child->keys.erase(left_child->keys.begin() + degree - 1, left_child->keys.end());

    // split children of the left child
    if (left_child->is_leaf == false)
    {
        auto right_children = std::vector<Node*>(left_child->children.begin() + degree, left_child->children.end());
        right_child->children = std::move(right_children);
        left_child->children.erase(left_child->children.begin() + degree, left_child->children.end());
    }

    //// insert a new right node,
    //// and move the median key to the parent node

    // move the median key to parent node
    node->keys.insert(node->keys.begin() + index, median_key);

    // insert right node as a new child of node
    node->children.insert(node->children.begin() + index + 1, right_child);
}

void BTree::Tree::InsertNonFull(Node* node, char key)
{
    auto key_count = static_cast<int>(node->keys.size());

    // insert key to leaf node
    if (node->is_leaf == true)
    {
        while ((key_count >= 1) && (node->keys[key_count - 1] > key))
        {
            --key_count;
        }

        node->keys.insert(node->keys.begin() + key_count, key);
    }
    else
    {
        while ((key_count >= 1) && (node->keys[key_count - 1] > key))
        {
            --key_count;
        }
        ++key_count;

        if (static_cast<int>(node->children[key_count - 1]->keys.size()) == 2 * degree - 1)
        {
            SplitChild(node, key_count - 1);
            if (key > node->keys[key_count - 1])
            {
                ++key_count;
            }
        }

        InsertNonFull(node->children[key_count - 1], key);
    }
}

void BTree::Tree::Insert(Node* node, char key)
{
    auto root_node = node;

    if (static_cast<int>(node->keys.size()) == 2 * degree - 1)
    {
        auto new_node = new Node{};
        root = new_node;
        new_node->is_leaf = false;
        new_node->children.push_back(root_node);
        SplitChild(new_node, 0);
        InsertNonFull(new_node, key);
    }
    else
    {
        InsertNonFull(root_node, key);
    }
}

auto BTree::Tree::Search(Node* node, char key) -> std::pair<Node*, const int>
{
    auto index = 0;
    auto key_count = static_cast<int>(node->keys.size());

    // find the smallest index that key <= node->Keys[index]
    while ((key_count > index) && (key > node->keys[index]))
    {
        ++index;
    }

    // check to see whether key is found
    if ((key_count > index) && (key == node->keys[index]))
    {
        return std::make_pair(node, index);
    }
    // key is not found and if node is a leaf
    if (node->is_leaf == true)
    {
        return std::pair<Node*, const int>{};
    }
    // key is not found and recurse to search subtree of reference node
    return Search(node->children[index], key);
}
