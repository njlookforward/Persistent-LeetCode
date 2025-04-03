#ifndef BALANCED_BTREE_HPP
#define BALANCED_BTREE_HPP

#include <cmath>
using std::abs;

#include <algorithm>
using std::max;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution_post_recursion {
public:
    int getHeight(TreeNode *node);
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) == -1 ? false : true;
    }
};

// key: 巧妙的点是递归的返回值如果这颗子树是平衡的返回子树的最大高度，否则返回-1说明不是平衡二叉树
inline int Solution_post_recursion::getHeight(TreeNode *node)
{
    if(node == nullptr) return 0;
    auto leftHeight = getHeight(node->left);
    if(leftHeight == -1) return -1;
    auto rightHeight = getHeight(node->right);
    if(rightHeight == -1) return -1;

    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}


#endif