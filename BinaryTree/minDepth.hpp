#ifndef MINDEPTH_HPP
#define MINDEPTH_HPP

#include <algorithm>
using std::min;

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

// 最小深度定义：从根节点到最近叶子结点的最长简单路径的节点数
// key: 找到叶子节点，也就是左右孩子为空的节点
class Solution_post_recursion {
public:
    int minDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;
        else if(!root->left && !root->right) return 1;
        // Bug: 忘记+1了
        else if(!root->left) return 1 + minDepth(root->right);
        else if(!root->right) return 1 + minDepth(root->left);
        else {
            int leftHeight = minDepth(root->left);
            int rightHeight = minDepth(root->right);
            return 1 + min(leftHeight, rightHeight);
        }
    }
};

// 不要被高度/深度的概念所捆绑，而是从二叉树的数据结构的角度去理解
// 高度：就是从下往上去思考，去递归，采用后序遍历方式，左右根，在多数场景下这种做法相对简单
// 深度：就是从上往下去思考，因此采用先序遍历方式，根左右
class Solution_pre_recursion {
public:
    void getDepth(TreeNode *node, int depth, int &result);
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        auto result = __INT_MAX__;
        getDepth(root, 1, result);
        return result;
    }
};

// 这个递归就是一层一层的寻找，找到叶子结点时修改最小深度
inline void Solution_pre_recursion::getDepth(TreeNode *node, int depth, int &result)
{
    if(node == nullptr) return;
    if(node->left == nullptr && node->right == nullptr)
    {
        result = min(depth, result);
        return;
    }
    getDepth(node->left, depth + 1, result);
    getDepth(node->right, depth + 1, result);
}

class Solution_iteration_level {
public:
    int minDepth(TreeNode *root)
    {
        int result = 0;
        if(!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            ++result;
            auto cnt = que.size();
            while (cnt--)
            {
                auto cur = que.front();
                que.pop();
                // Bug：这里不能使用break，仅仅是跳出内层循环，还有外层循环没有结束呢，会发生错误
                if(!cur->left && !cur->right) return result;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};

#endif