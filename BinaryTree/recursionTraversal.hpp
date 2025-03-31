#ifndef RECURSIONTRAVERSAL_HPP
#define RECURSIONTRAVERSAL_HPP

#include <vector>
using std::vector;

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
    void preorder(TreeNode *node, vector<int> &res);
    void inorder(TreeNode *node, vector<int> &res);
    void postorder(TreeNode *node, vector<int> &res);

    vector<int> preorderTraversal(TreeNode *root);
    vector<int> inorderTraversal(TreeNode *root);
    vector<int> postorderTraversal(TreeNode *root);
};

inline void Solution_recursion::preorder(TreeNode *node, vector<int> &res)
{
    if(node == nullptr) return;
    res.push_back(node->val);
    preorder(node->left, res);
    preorder(node->right, res);
}

inline void Solution_recursion::inorder(TreeNode *node, vector<int> &res)
{
    if(node == nullptr) return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

inline void Solution_recursion::postorder(TreeNode *node, vector<int> &res)
{
    if(node == nullptr) return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->val);
}

inline vector<int> Solution_recursion::preorderTraversal(TreeNode *root)
{
    vector<int> result;
    if(!root) return result;
    preorder(root, result);
    return result;
}

inline vector<int> Solution_recursion::inorderTraversal(TreeNode *root)
{
    vector<int> result;
    if(!root) return result;
    inorder(root, result);
    return result;
}

inline vector<int> Solution_recursion::postorderTraversal(TreeNode *root)
{
    vector<int> result;
    if(!root) return result;
    postorder(root, result);
    return result;
}

#endif  // RECURSIONTRAVERSAL_HPP