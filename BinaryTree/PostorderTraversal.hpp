#ifndef POSTORDERTRAVERSAL_HPP
#define POSTORDERTRAVERSAL_HPP

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution_iterator {
public:
    vector<int> postorderTraversal(TreeNode  *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if(!root) return result;

        // 中-右-左   <--> 左-右-中
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


#endif  // POSTORDERTRAVERSAL_HPP