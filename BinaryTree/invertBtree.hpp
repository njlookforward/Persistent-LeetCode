#ifndef INVERTBTREE_HPP
#define INVERTBTREE_HPP

#include <utility>
using std::swap;

#include <stack>
using std::stack;

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

class Solution_recursion_preorder {
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(root == nullptr) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

class Solution_iteration_preorder {
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(!root) return root;
        // 因此需要保存左右节点，然后逐一处理左右节点，这种能够保存之后待处理值的数据结构，只有栈能够满足
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return root;
    }
};

class Solution_levelorder {
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(!root) return root;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto cnt = que.size();
            while (cnt--)
            {
                TreeNode *cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};

#endif