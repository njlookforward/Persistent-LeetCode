#ifndef PATHSUM_II_HPP
#define PATHSUM_II_HPP

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

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
    void traversal(TreeNode *node, int targetSum, vector<int> &path, 
                                        vector<vector<int>> &result);
    void traversal_v2(TreeNode *node, int targetSum, vector<int> &path,
                                    vector<vector<int>> &result);
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> path;
        path.push_back(root->val);
        // traversal(root, targetSum, path, result);
        traversal_v2(root, targetSum, path, result);
        return result;
    }
};

inline void Solution_recursion::traversal(TreeNode *node, int targetSum, vector<int> &path,
                                                vector<vector<int>> &result)
{
    if(!node->left && !node->right) {
        if(accumulate(path.cbegin(), path.cend(), 0) == targetSum)
            result.push_back(path);
        return;
    }
    if(node->left) {
        path.push_back(node->left->val);
        traversal(node->left, targetSum, path, result);
        path.pop_back();
    }
    if(node->right) {
        path.push_back(node->right->val);
        traversal(node->right, targetSum, path, result);
        path.pop_back();
    }
}

inline void Solution_recursion::traversal_v2(TreeNode *node, int targetSum,
        vector<int> &path, vector<vector<int>> &result)
{
    if(!node->left && !node->right)
    {
        if(targetSum == node->val)
            result.push_back(path);
        return;
    }
    if(node->left) {
        path.push_back(node->left->val);
        traversal_v2(node->left, targetSum - node->val, path, result);
        path.pop_back();
    }
    if(node->right) {
        path.push_back(node->right->val);
        traversal_v2(node->right, targetSum - node->val, path, result);
        path.pop_back();
    }
}

#endif  