#ifndef LEVELORDERTRAVERSAL_HPP
#define LEVELORDERTRAVERSAL_HPP

#include <vector>
using std::vector;

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

class Solution_iteration {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto cnt = que.size();
            vector<int> singLevelRes;
            while (cnt--)
            {
                TreeNode *cur = que.front();
                que.pop();
                singLevelRes.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(singLevelRes);
        }
        return result;
    }
};

// 在leetcode上说明使用recursion is faster, 0ms and less memory
class Solution_recursion {
public:
    void level(TreeNode *node, vector<vector<int>> &result, int depth);
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if(!root) return result;
        level(root, result, 0);
        return result;
    }
};

// recursion不能贪婪，只需要想单层递归的逻辑，不能被下一层递归所干扰
inline void Solution_recursion::level(TreeNode *node, vector<vector<int>> &result, int depth)
{
    if(node == nullptr) return;
    if(result.size() == depth) result.push_back(vector<int>());
    result[depth].push_back(node->val);
    level(node->left, result, depth+1);
    level(node->right, result, depth+1); 
}

#endif