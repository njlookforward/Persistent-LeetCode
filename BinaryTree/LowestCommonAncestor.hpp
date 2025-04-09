#ifndef LOWEST_COMMON_ANCESTOR_HPP
#define LOWEST_COMMON_ANCESTOR_HPP

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

#include <functional>
using std::equal_to;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution_recursion {
    bool buildPath(TreeNode *root, TreeNode *aim, vector<TreeNode*> &path)
    {
        // 我仍然使用的是后序遍历，这样方便后面寻找最低的公共祖先
        if(root == aim) {
            path.push_back(root);
            return true;
        } else if(root == nullptr)
            return false;
        bool left = buildPath(root->left, aim, path);
        bool right = buildPath(root->right, aim, path);
        if(left || right) {
            path.push_back(root);
            return true;
        } else
            return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode*> pPath, qPath;
        buildPath(root, p, pPath);
        buildPath(root, q, qPath);
        for (size_t i = 0; i < pPath.size(); i++)
        {
            for (size_t j = 0; j < qPath.size(); j++)
            {
                if(equal_to<TreeNode*>()(pPath[i], qPath[j])) {
                    return pPath[i];
                }
            }
        }
        return nullptr;
    }
};

// 使用回溯，回溯必然使用后序遍历
class Solution_recurison_backtrack {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 找交汇点
        if(left != nullptr && right != nullptr)
            return root;
        else if(left != nullptr && right == nullptr)
            return left;
        else if(left == nullptr && right != nullptr)
            return right;
        else
            return nullptr;
    }
};

#endif