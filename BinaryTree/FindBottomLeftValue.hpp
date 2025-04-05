#ifndef FIND_BOTTOM_LEFT_VALUE_HPP
#define FIND_BOTTOM_LEFT_VALUE_HPP

#include <utility>
using std::pair; using std::make_pair;

#include <queue>
using std::queue;

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
public:
    pair<int, int> traversal(TreeNode *node);
    int findBottomLeftValue(TreeNode *root)
    {
        auto result = traversal(root);
        return result.first;
    }
};

// 仍然是从下到上进行遍历，而且是后序遍历
inline pair<int, int> Solution_recursion::traversal(TreeNode *node)
{
    if(node == nullptr) return {0,0};
    if(node->left == nullptr && node->right == nullptr) return {node->val, 1};

    auto leftValue  = traversal(node->left),
         rightValue = traversal(node->right);
    
    return leftValue.second >= rightValue.second
         ? make_pair(leftValue.first, leftValue.second + 1)
         : make_pair(rightValue.first, rightValue.second + 1);
}

class Solution_iteration_level {
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode*> que;
        que.push(root);
        int result = 0;
        while (!que.empty())
        {
            result = que.front()->val;
            auto cnt = que.size();
            while (cnt--)
            {
                auto cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};

class Solution_recursion_depth {
public:
    void traversal(TreeNode *node, int depth, int &maxDepth, int &result);
    int findBottomLeftValue(TreeNode *root)
    {
        int maxDepth = 0;
        int result = 0;
        traversal(root, 1, maxDepth, result);
        return result;
    }
};

// 从上往下进行遍历，找到叶子结点，此时来更新最大深度和结果值
inline void Solution_recursion_depth::traversal(TreeNode *node, int depth, int &maxDepth, int &result)
{
    if(node->left == nullptr && node->right == nullptr)
    {
        if(depth > maxDepth) {
            maxDepth = depth;
            result = node->val;
        }
        return;
    }
    if(node->left) traversal(node->left, depth + 1, maxDepth, result);
    if(node->right) traversal(node->right, depth + 1, maxDepth, result);
}

#endif