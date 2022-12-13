#include "binary_search_tree.h"
#include "construct_binary_search_tree.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(ConstructBinarySearchTree, PreorderTraversal)
{
    // example tree:
    //             15
    //        /          \
    //      6              18
    //    /    \         /    \
    //   3      7       17     20
    //  /  \     \
    // 2    4     13
    //           /
    //          9

    auto preorder = std::vector{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
    auto inorder = std::vector{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    auto root = BinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.PreorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(preorder.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(preorder, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(ConstructBinarySearchTree, InorderTraversal)
{
    // example tree:
    //             15
    //        /          \
    //      6              18
    //    /    \         /    \
    //   3      7       17     20
    //  /  \     \
    // 2    4     13
    //           /
    //          9

    auto preorder = std::vector{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
    auto inorder = std::vector{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    auto root = BinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.InorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(inorder.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(inorder, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(ConstructBinarySearchTree, PostorderTraversal)
{
    // example tree:
    //             15
    //        /          \
    //      6              18
    //    /    \         /    \
    //   3      7       17     20
    //  /  \     \
    // 2    4     13
    //           /
    //          9

    auto preorder = std::vector{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};
    auto inorder = std::vector{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};
    const auto expected = std::vector<int>{2, 4, 3, 9, 13, 7, 6, 17, 20, 18, 15};

    auto root = BinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.PostorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}
