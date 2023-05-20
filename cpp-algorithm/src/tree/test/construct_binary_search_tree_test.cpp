#include "binary_search_tree.h"
#include "construct_binary_search_tree.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(ConstructTreeFromPreorderInorder, PreorderTraversal)
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

    auto root = ConstructBinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.PreorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(preorder.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(preorder, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(ConstructTreeFromPreorderInorder, InorderTraversal)
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

    auto root = ConstructBinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.InorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(inorder.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(inorder, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(ConstructTreeFromPreorderInorder, PostorderTraversal)
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

    auto root = ConstructBinarySearchTree::ConstructTreeFromPreorderInorder(preorder, inorder);

    auto tree = BinarySearchTree::Tree<int>{};
    auto result = std::vector<int>{};
    tree.PostorderTraversal(root, result);

    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(ConstructTreeFromMarkerPreorder, PreorderTraversal)
{
    // example tree:
    //              H
    //        /          \
    //       B             C
    //    /      \       /   \
    //   F        E           D
    //  /  \     /  \       /   \
    //          A                G
    //         /  \            /   \
    //                        I
    //                       /  \

    auto preorder = std::vector<char>{'H', 'B', 'F', NULL, NULL, 'E', 'A', NULL, NULL, NULL,
                                      'C', NULL, 'D', NULL, 'G', 'I', NULL, NULL, NULL};

    auto root = ConstructBinarySearchTree::ConstructTreeFromMarkerPreorder(preorder);
    auto tree = BinarySearchTree::Tree<char>{};
    auto result = std::vector<char>{};
    tree.PreorderTraversal(root, result);
    preorder.erase(std::ranges::remove(preorder, NULL).begin(), preorder.end());

    ASSERT_EQ(static_cast<int>(preorder.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(preorder, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}
