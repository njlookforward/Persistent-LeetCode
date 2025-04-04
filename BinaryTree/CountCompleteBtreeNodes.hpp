#ifndef COUNT_COMPLETE_BTREE_NODES_HPP
#define COUNT_COMPLETE_BTREE_NODES_HPP

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
    void preTraversal(TreeNode *cur, int &result);
    int countNodes(TreeNode *root)
    {
        int result = 0;
        if(!root) return result;
        preTraversal(root, result);
        return result;
    }
};

inline void Solution_recursion::preTraversal(TreeNode *cur, int &result)
{
    if(cur == nullptr) return;
    ++result;
    preTraversal(cur->left, result);
    preTraversal(cur->right, result);
}

class Solution_iteration_level {
public:
    int countNodes(TreeNode *root) 
    {
        int result = 0;
        if(!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            auto sz = que.size();
            result += sz;
            while (sz--)
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


#endif  