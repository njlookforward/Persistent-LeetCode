#ifndef MINIMUM_ABSOLUTE_DIFFERENCE_HPP
#define MINIMUM_ABSOLUTE_DIFFERENCE_HPP

#include <climits>
#include <algorithm>
using std::min;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// idea: use BST's trait which is in order of inorder traversal, 因此两个节点的最小绝对值差值应该在
// 二叉树的中序遍历的两个相邻节点之间，使用双指针进行遍历，找到最小值
class Solution_recursion_doublePointer {
public:
    // Bug: pre的类型应该是&,随着遍历的过程一直在改变，址传递要用引用
    void inOrderGetMin(TreeNode *&pre, TreeNode *cur, int &minVal)
    {
        if(cur == nullptr) return;
        inOrderGetMin(pre, cur->left, minVal);
        // if(pre == nullptr)
        //     pre = cur;
        // else {
        //     int tmp = cur->val - pre->val;
        //     minVal = tmp < minVal ? tmp : minVal;
        //     pre = cur;
        // }
        // 重构：
        if(pre != nullptr)
            minVal = min(minVal, cur->val - pre->val);
        pre = cur;
        inOrderGetMin(pre, cur->right, minVal);
    }
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        int minVal = INT_MAX;
        inOrderGetMin(pre, root, minVal);
        return minVal;
    }
};

#endif