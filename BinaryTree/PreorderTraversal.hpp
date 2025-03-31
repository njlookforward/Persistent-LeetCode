#ifndef PREORDERTRAVERSAL_HPP
#define PREORDERTRAVERSAL_HPP

#include <vector>
using std::vector;

#include <stack>
using std::stack;

struct TreeNode {
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 使用迭代法实现前序遍历，就是使用栈实现
class Solution_iterator {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 可能为空树
        stack<TreeNode *> st;
        vector<int> result;
        if(!root) return result;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right); // 注意入栈的顺序和遍历的顺序是相反的，这样才能保证遍历时顺序正确
            if(cur->left) st.push(cur->left);
        }
        return result;
    }
};


#endif // PREORDERTRAVERSAL_HPP