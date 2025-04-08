#ifndef ITERATIONTRAVERSAL_HPP
#define ITERATIONTRAVERSAL_HPP

#include <stack>
using std::stack;

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

class Solution_uniform_iteration {
public:
    vector<int> preorderTraversal(TreeNode *root);
    vector<int> inorderTraversal(TreeNode *root);
    vector<int> postorderTraversal(TreeNode *root);
};

inline vector<int> Solution_uniform_iteration::preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if(root != nullptr) st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if(node != nullptr) {
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            st.push(node);
            st.push(nullptr);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

inline vector<int> Solution_uniform_iteration::inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if(root) st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if(node) {
            st.pop();
            if(node->right) st.push(node->right);
            st.push(node);
            st.push(nullptr);
            if(node->left) st.push(node->left);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

inline vector<int> Solution_uniform_iteration::postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if(root) st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if(node) {
            st.push(nullptr);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

class Solution_iteration_recap1 {
public:
    vector<int> preorder(TreeNode *root);
    vector<int> inorder(TreeNode *root);
};

inline vector<int> Solution_iteration_recap1::preorder(TreeNode *root) {
    vector<int> result;
    if(!root) return result;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        result.push_back(cur->val);
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
    }
    return result;
}

inline vector<int> Solution_iteration_recap1::inorder(TreeNode *root)
{
    vector<int> result;
    if(!root) return result;
    stack<TreeNode*> st;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty())
    {
        if(cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

#endif  // ITERATIONTRAVERSAL_HPP