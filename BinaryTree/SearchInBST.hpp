#ifndef SEARCH_IN_BST_HPP
#define SRARCH_IN_BST_HPP

#include <stack>
using std::stack;

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
    TreeNode *searchBST(TreeNode *root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

class Solution_iteration {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if(cur->val == val)
                return cur;
            else if(cur->val > val) {
                if(cur->left) st.push(cur->left);
            } else {
                if(cur->right) st.push(cur->right);
            }
        }
        return nullptr;
    }
};

class Solution_iteration_answer {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root != nullptr)
        {
            if(root->val == val) return root;
            else if(root->val > val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};

#endif