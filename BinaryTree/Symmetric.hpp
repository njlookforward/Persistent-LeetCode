#ifndef SYMMETRIC_HPP
#define SYMMETRIC_HPP

#include <queue>
using std::queue;

#include <stack>
using std::stack;

#include <functional>
using std::equal_to;

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
    bool checkSymmetric(TreeNode *left, TreeNode *right);
    bool isSymmetric(TreeNode *root) {
        return checkSymmetric(root->left, root->right);
    }
};

inline bool Solution_recursion::checkSymmetric(TreeNode *left, TreeNode *right)
{
    // 首先认为这个递归就是一个单层
    if(left == nullptr && right != nullptr) return false;
    else if(left != nullptr && right == nullptr) return false;
    else if(left == nullptr && right == nullptr) return true;   // 他是最终的叶子结点的判断返回值
    else if(left->val != right->val) return false;
    else {
        // 这一单层是对称的，然后比较里侧和外侧
        bool outside = checkSymmetric(left->left, right->right);
        bool inside = checkSymmetric(left->right, right->left);
        return outside && inside;
    }
}

class Solution_iteration_queue {
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            auto lhs = que.front();
            que.pop();
            auto rhs = que.front();
            que.pop();
            if(lhs && !rhs) return false;
            else if(!lhs && rhs) return false;
            else if(!lhs && !rhs) continue;
            else {
                // 不要忘记equal_to是函数对象
                if(!equal_to<int>()(lhs->val, rhs->val)) return false;
                // 若是相等，那么就去比较外侧和内侧孩子
                // Bug: 在此题中，不应该继续判断是否为空，因为该题中包含空指针的判断，若是空指针也必须是对称的
                que.push(lhs->left);
                que.push(rhs->right);
                que.push(lhs->right);
                que.push(rhs->left);
            }
        }
        return true;
    }
};

class Solution_stack {
public:
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> st;
        st.push(root->right);
        st.push(root->left);
        while (!st.empty())
        {
            auto lhs = st.top();
            st.pop();
            auto rhs = st.top();
            st.pop();
            if(lhs && !rhs) return false;
            else if(!lhs && rhs) return false;
            else if(!lhs && !rhs) continue;
            else {
                if(!equal_to<int>()(lhs->val, rhs->val)) return false;
                st.push(rhs->right);
                st.push(lhs->left);
                st.push(rhs->left);
                st.push(lhs->right);
            }
        }
        return true;
    }
};

#endif  // SYMMETRIC_HPP