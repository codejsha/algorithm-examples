#include "right_sibling.h"

#include <gtest/gtest.h>

GTEST_TEST(RightSibling, PopulateRightSibling)
{
    // example tree:
    //              A
    //        /           \
    //       B              C
    //    /     \         /    \
    //   D       E       F       G
    //  / \     / \     / \     / \
    // H   I   J   K   L   M   N   O

    auto node_a = BinaryTree::NextExtendedNode{'A'};
    auto node_b = BinaryTree::NextExtendedNode{'B'};
    auto node_c = BinaryTree::NextExtendedNode{'C'};
    auto node_d = BinaryTree::NextExtendedNode{'D'};
    auto node_e = BinaryTree::NextExtendedNode{'E'};
    auto node_f = BinaryTree::NextExtendedNode{'F'};
    auto node_g = BinaryTree::NextExtendedNode{'G'};
    auto node_h = BinaryTree::NextExtendedNode{'H'};
    auto node_i = BinaryTree::NextExtendedNode{'I'};
    auto node_j = BinaryTree::NextExtendedNode{'J'};
    auto node_k = BinaryTree::NextExtendedNode{'K'};
    auto node_l = BinaryTree::NextExtendedNode{'L'};
    auto node_m = BinaryTree::NextExtendedNode{'M'};
    auto node_n = BinaryTree::NextExtendedNode{'N'};
    auto node_o = BinaryTree::NextExtendedNode{'O'};
    node_a.left = &node_b;
    node_a.right = &node_c;
    node_b.left = &node_d;
    node_b.right = &node_e;
    node_c.left = &node_f;
    node_c.right = &node_g;
    node_d.left = &node_h;
    node_d.right = &node_i;
    node_e.left = &node_j;
    node_e.right = &node_k;
    node_f.left = &node_l;
    node_f.right = &node_m;
    node_g.left = &node_n;
    node_g.right = &node_o;

    RightSibling::PopulateRightSibling(&node_a);

    EXPECT_EQ(&node_c, node_b.next);
    EXPECT_EQ(&node_e, node_d.next);
    EXPECT_EQ(&node_f, node_e.next);
    EXPECT_EQ(&node_g, node_f.next);
    EXPECT_EQ(nullptr, node_g.next);
    EXPECT_EQ(&node_i, node_h.next);
    EXPECT_EQ(&node_j, node_i.next);
    EXPECT_EQ(&node_l, node_k.next);
    EXPECT_EQ(&node_n, node_m.next);
    EXPECT_EQ(nullptr, node_o.next);
}
