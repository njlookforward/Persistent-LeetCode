#ifndef TRIMBST_HPP
#define TRIMBST_HPP

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

/* 这道题的leetcode的测试框架有问题，我下面的答案会执行出错，必须不删除bound范围外的节点，答案
 * 才能被测试框架通过，这是有问题的
*/

// 我的想法是先序遍历
class Solution_recursion {
public:
    void clearSubTree(TreeNode *root) {
        // 使用后序遍历删除一整棵树
        if(root == nullptr) return;
        clearSubTree(root->left);
        clearSubTree(root->right);
        delete root;
    }
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if(!root) return root;
        if(root->val < low) {
            // root + root->left need to clear
            clearSubTree(root->left);
            TreeNode *newRoot = root->right;
            delete root;
            return trimBST(newRoot, low, high);
        } else if (root->val > high) {
            clearSubTree(root->right);
            TreeNode *newRoot = root->left;
            delete root;
            return trimBST(newRoot, low, high);
        } else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};

#endif  // TRIMBST_HPP