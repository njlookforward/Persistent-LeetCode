#ifndef MAXDEPTH_HPP
#define MAXDEPTH_HPP

#include <algorithm>
using std::max;

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

// 一颗二叉树的最大深度就是根节点的高度，求根节点的高度使用后序遍历，左右中
class Solution_post_recursion {
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;
        int leftHeight = maxDepth(root->left),
            rightHeight = maxDepth(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

class Solution_pre_recursion {
public:
    // 思考：在一个函数中如何返回多个结果，使用引用参数，就可以返回多个结果
    // 如果非得用返回值的话，可以使用tuple对象
    // 这里求的是深度，node节点表示的是根节点，getDepth求得的就是根节点到最远叶子结点的最大深度
    void getDepth(TreeNode *node, int depth, int &result);
    int maxDepth(TreeNode *root)
    {
        int result = 0;
        if(!root) return result;
        getDepth(root, 1, result);
        return result;
    }
};

// 求深度，就是根节点到目标节点的最长简单路径中所包含的节点数，因此需要使用前序遍历
// inline void Solution_pre_recursion::getDepth(TreeNode *node, int depth, int &result)
// {
//     // 这个逻辑就是一层一层的确定
//     // 中 - 左 - 右
//     result = depth > result ? depth : result;
//     if(node->left == nullptr && node->right == nullptr) return;

//     if(node->left) {
//         ++depth;
//         getDepth(node->left, depth, result);
//         --depth;    // 回溯
//     }
//     if(node->right) {
//         ++depth;
//         getDepth(node->right, depth, result);
//         --depth;
//     }
// }

// 从上往下一层层迭代最大深度
inline void Solution_pre_recursion::getDepth(TreeNode *node, int depth, int &result)
{
    if(node == nullptr) return;
    result = max(depth, result);
    getDepth(node->left, depth + 1, result);
    getDepth(node->right, depth + 1, result);
}

class Solution_iteration_level {
public:
    int maxDepth(TreeNode *root)
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
                TreeNode *cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};

#endif