#ifndef BTREEPATHS_HPP
#define BTREEPATHS_HPP

#include <vector>
using std::vector;

#include <string>
using std::string; using std::to_string;

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
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result);
    vector<string> binaryTreePaths(TreeNode *root) 
    {
        vector<string> result;
        vector<int> path;
        traversal(root, path, result);
        return result;
    }
};

inline void Solution_recursion::traversal(TreeNode *node, vector<int> &path, vector<string> &result)
{
    // 说明每次递归节点指针都是有效的
    path.push_back(node->val);

    // 递归条件：处理完叶子结点就返回
    if(node->left == nullptr && node->right == nullptr) {
        string newPath;
        bool first = true;
        for (size_t i = 0; i < path.size(); i++)
        {
            if(first)
                first = false;
            else
                newPath += "->";
            newPath += to_string(path[i]);
        }
        result.push_back(newPath);
        return;
    }

    if(node->left) {
        traversal(node->left, path, result);
        path.pop_back();    // 回溯过程
    }
    if(node->right) {
        traversal(node->right, path, result);
        path.pop_back();    // 回溯过程
    }
}

#endif  