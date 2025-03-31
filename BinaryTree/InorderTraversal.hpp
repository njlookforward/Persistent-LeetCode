#ifndef INORDERTRAVERSAL_HPP
#define INORDERTRAVERSAL_HPP

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

// 迭代法，用栈实现中序遍历
class Solution_iterator {
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if(!root) return result;
        
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            // Bug: 逻辑出问题了
            // 脑袋出问题了，!cur代表cur为空啊
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
};

#endif  // INORDERTRAVERSAL_HPP