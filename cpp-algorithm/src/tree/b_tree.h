#ifndef CPP_ALGORITHM_B_TREE_H
#define CPP_ALGORITHM_B_TREE_H

#include <vector>

namespace BTree
{
    template <typename T>
    struct Node
    {
        Node() = default;

        std::vector<T> keys;
        std::vector<Node<T>*> children;
        bool is_leaf{};

        [[nodiscard]] auto GetKeyCount() const -> int
        {
            return keys.size();
        }
    };

    template <typename T>
    class Tree
    {
    public:
        Tree() = default;

        [[nodiscard]] auto GetRoot() const -> Node<T>*
        {
            return root_;
        }

        void SetRoot(Node<T>* node)
        {
            root_ = node;
        }

        [[nodiscard]] auto GetNodes() const -> std::vector<Node<T>*>
        {
            return nodes_;
        }

        [[nodiscard]] auto GetDegree() const -> int
        {
            return degree_;
        }

        void SetDegree(const int value)
        {
            degree_ = value;
        }

        /// @brief Split the node
        /// @param node internal node
        /// @param index index
        void SplitChild(Node<T>* node, int index);

        /// @brief Insert key
        /// @param node internal node
        /// @param key key
        void InsertNonFull(Node<T>* node, T key);

        /// @brief Insert the key to the tree
        /// @param node reference node for insert
        /// @param key key to insert
        void Insert(Node<T>* node, T key);

        /// @brief Search the key
        /// @param node reference node for tree search
        /// @param key key to search for
        /// @return node and key index pair
        auto Search(Node<T>* node, T key) -> std::pair<Node<T>*, const int>;

    private:
        Node<T>* root_{};
        std::vector<Node<T>*> nodes_{};
        int degree_{};
    };

    template <typename T> void Tree<T>::SplitChild(Node<T>* node, int index)
    {
        auto left_child = node->children[index];

        //// create a right child node,
        //// and split keys, children of the left child node

        // create right child
        auto right_child = new Node<T>{};
        right_child->is_leaf = left_child->is_leaf;

        // split keys of the left child
        // copy keys from median+1 to the end
        auto right_keys = std::vector<T>(
            left_child->keys.begin() + degree_,
            left_child->keys.end());
        right_child->keys = std::move(right_keys);
        // get median key
        auto median_key = left_child->keys[degree_ - 1];
        // erase keys from median to the end
        left_child->keys.erase(
            left_child->keys.begin() + degree_ - 1,
            left_child->keys.end());

        // split children of the left child
        if (left_child->is_leaf == false)
        {
            auto right_children = std::vector<Node<T>*>(
                left_child->children.begin() + degree_,
                left_child->children.end());
            right_child->children = std::move(right_children);
            left_child->children.erase(
                left_child->children.begin() + degree_,
                left_child->children.end());
        }

        //// insert a new right node,
        //// and move the median key to the parent node

        // move the median key to parent node
        node->keys.insert(node->keys.begin() + index, median_key);

        // insert right node as a new child of node
        node->children.insert(node->children.begin() + index + 1, right_child);
    }

    template <typename T> void Tree<T>::InsertNonFull(Node<T>* node, T key)
    {
        auto key_count = node->GetKeyCount();

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

            if (node->children[key_count - 1]->GetKeyCount() == 2 * degree_ - 1)
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

    template <typename T> void Tree<T>::Insert(Node<T>* node, T key)
    {
        auto root_node = node;

        if (node->GetKeyCount() == 2 * degree_ - 1)
        {
            auto new_node = new Node<T>{};
            root_ = new_node;
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

    template <typename T> auto Tree<T>::Search(Node<T>* node, T key) -> std::pair<Node<T>*, const int>
    {
        auto index = 0;
        auto key_count = node->GetKeyCount();

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
        else if (node->is_leaf == true)
        {
            return std::pair<Node<T>*, const int>{};
        }
        // key is not found and recurse to search subtree of reference node
        else
        {
            return Search(node->children[index], key);
        }
    }
}

#endif
